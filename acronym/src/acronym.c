#include "acronym.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


char *abbreviate(const char *phrase) {

        char *acronym = NULL;
        acronym = malloc(sizeof(phrase));
        int i = 0;

        // first, we test if the string input is non null
        // and it's not empty
        if (phrase == NULL || strlen(phrase) == 0)
                return NULL;

        char *copy = NULL;
        copy = malloc(sizeof(phrase));
        // the original string is a const so we cannot modify it
        // ==> we create and will work on the copy
        strcpy(copy, phrase);

        char *token = strtok(copy, " ,-");
        while(token != NULL && isalpha(token[0])) {

                acronym[i] = toupper(token[0]);
                i++;

                //we go to the next word
                token = strtok(NULL, " ,-");
        }

        acronym[i] = '\0';

        return acronym;
}
