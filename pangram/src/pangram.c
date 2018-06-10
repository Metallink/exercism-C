#include "pangram.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_pangram(const char *sentence) {

        char ref_letter[26];
        memset (ref_letter, 0, 26);

        int count = 26;
        int letter = 0;

        if (sentence == NULL || strlen(sentence) == 0)
                return false;

        char *copy = NULL;
        copy = malloc(strlen(sentence) * sizeof(char));
        strcpy(copy, sentence);

        int len = strlen(copy);

        for (int i = 0; i < len; i++) {
                copy[i] = tolower(sentence[i]);
                letter = (int)copy[i]-97;
                if (isalpha(copy[i]) != 0  && ref_letter[letter] != 1) {
                        ref_letter[letter] = 1;
                        count--;
                }
        }

        return (count == 0);
}
