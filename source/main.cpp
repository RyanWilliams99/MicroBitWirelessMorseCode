/**
 * File: main.cpp
 * Author: Ryan Williams
 * Date: 01-03-2019
 * Desc: Morse code sender and reciever written in c++ on a MicroBit
 */

#include <string.h>
#include "MicroBit.h"

MicroBit uBit;


uint64_t system_timer_current_time();
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A);


typedef struct //Used to convert Morse to ASCII
{
    char* const morse;
    char* const ascii;
} morse_table_t;

char input[] = "";

morse_table_t table[] = {{".-",    "A"},
                         {"-...",  "B"},
                         {"-.-.",  "C"},
                         {"-..",   "D"},
                         {".",     "E"},
                         {"..-.",  "F"},
                         {"--.",   "G"},
                         {"....",  "H"},
                         {"..",    "I"},
                         {".---",  "J"},
                         {"-.-",   "K"},
                         {".-..",  "L"},
                         {"--",    "M"},
                         {"-.",    "N"},
                         {"---",   "O"},
                         {".--.",  "P"},
                         {"--.-",  "Q"},
                         {".-.",   "R"},
                         {"...",   "S"},
                         {"-",     "T"},
                         {"..-",   "U"},
                         {"...-",  "V"},
                         {".--",   "W"},
                         {"-..-",  "X"},
                         {"-.--",  "Y"},
                         {"--..",  "Z"},
                         {"-----", "0"},
                         {".----", "1"},
                         {"..---", "2"},
                         {"...--", "3"},
                         {"....-", "4"},
                         {".....", "5"},
                         {"-....", "6"},
                         {"--...", "7"},
                         {"---..", "8"},
                         {"----.", "9"}

};

void onData(MicroBitEvent)
{
    ManagedString s = uBit.radio.datagram.recv();
    bool validMessage = false;
    if (s == "1")
    {
        uBit.display.print(".");
        uBit.sleep(1000);
        strcat(input, ".");

    }
    if (s == "2")
    {
        uBit.display.print("-");
        uBit.sleep(1000);
        strcat(input, "-");
    }
    if (s == "3")
    {
        uBit.display.clear();
        char *segment;
        int i;
        segment = strtok(input, " ");
        while (segment) {
            for (i = 0; i < 36; ++i) {
                if (!strcmp(segment, table[i].morse)) {
                    validMessage = true;
                    uBit.sleep(1000);
                    uBit.display.scroll(table[i].ascii);
                }
            }
            segment = strtok(nullptr, " ");
        }
        if (!validMessage) //If message invalid alight top right pixel
        {
            uBit.display.image.setPixelValue(4, 0, 255);
            uBit.sleep(2000);
        }
        memset(input, 0, sizeof input); //Clear input string for next char
    }

}

int main() {

    uBit.init();
    uBit.radio.enable();

    uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);


    //For reading button presses
    bool pressed = false;
    bool pinRead = false;

    while (1) {
        uBit.messageBus.listen(MICROBIT_ID_RADIO, MICROBIT_RADIO_EVT_DATAGRAM, onData);
        ///////////////////////////////WRITING//////////////////////////////////

        // Start counting Button
        uint64_t reading = system_timer_current_time();

        // Button held down
        while (buttonA.isPressed()) {
            pressed = true;
        }

        // How long was the button pressed
        uint64_t delta = system_timer_current_time() - reading;

        // After button press
        if (pressed) { // Is it a dot
            if (delta < 500) {
                uBit.display.print(".");
                uBit.radio.datagram.send("1");
                uBit.sleep(100);

            } // is it a dash
            else if (delta > 500 && delta < 1000) {
                uBit.display.print("-");
                uBit.radio.datagram.send("2");
                uBit.sleep(100);

            }
            else { // Is it an END OF MESSAGE
                uBit.display.print("E");
                uBit.radio.datagram.send("3");
                uBit.sleep(100);

            }

            // Reset
            pressed = false;
            uBit.display.clear();
        }

        ///////////////////////////////READING//////////////////////////////////

        ManagedString s = uBit.radio.datagram.recv();
        uBit.display.print(s);
        uBit.sleep(100);
        uBit.display.clear();
    }
}
