//
// Created by ryan on 27/03/19.
//

#ifndef MICROBITWIRELESSMORSECODE_MORSETABLE_H
#define MICROBITWIRELESSMORSECODE_MORSETABLE_H

#endif //MICROBITWIRELESSMORSECODE_MORSETABLE_H

typedef struct //Used to convert Morse to ASCII
{
    char* const morse;
    char* const ascii;
} morse_table_t;

char input[] = ""; //Declare char array

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