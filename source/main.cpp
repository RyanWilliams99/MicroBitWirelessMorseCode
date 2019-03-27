/**
 * File: main.cpp
 * Author: Ryan Williams
 * Date: 01-03-2019
 * Desc: Morse code sender and reciever written in c++ on a MicroBit
 */

#include <string.h>
#include "MicroBit.h"
#include "morseTable.h"

MicroBit uBit;


uint64_t system_timer_current_time(); //Used when sending
MicroBitButton buttonA(MICROBIT_PIN_BUTTON_A, MICROBIT_ID_BUTTON_A); //Buttons for sending

void onData(MicroBitEvent) //Function which is called when recieved
{
    ManagedString s = uBit.radio.datagram.recv(); //Get string from microbit radio
    bool validMessage = false;
    if (s == "1") //If 1 then dot
    {
        uBit.display.print(".");
        uBit.sleep(1000);
        strcat(input, ".");

    }
    if (s == "2") //if 2 then dash
    {
        uBit.display.print("-");
        uBit.sleep(1000);
        strcat(input, "-");
    }
    if (s == "3") //Prints passsed char then clear
    {
        uBit.display.clear();
        char *segment;
        int i;
        segment = strtok(input, " ");
        while (segment) { //For every possible morse see if valid then print
            for (i = 0; i < 36; ++i) {
                if (!strcmp(segment, table[i].morse)) {
                    validMessage = true;
                    uBit.sleep(1000);
                    uBit.display.scroll(table[i].ascii); //Display the char
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

    uBit.init(); //Init Radio
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
            else { // Is it an end of message
                uBit.display.print("E");
                uBit.radio.datagram.send("3");
                uBit.sleep(100);

            }

            // Reset
            pressed = false;
            uBit.display.clear(); //Clear display
        }

        ///////////////////////////////READING//////////////////////////////////

        ManagedString s = uBit.radio.datagram.recv(); //Get radio string
        uBit.display.print(s);
        uBit.sleep(100);
        uBit.display.clear(); //Clear display after showing char
    }
}