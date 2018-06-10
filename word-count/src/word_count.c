#include "word_count.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* function that tests if a word already exists in our struct */
int exist(char *word, word_count_word_t *words) {

        for (int i = 0; i < MAX_WORDS; i++) {
                if (strcmp(words[i].text, word) == 0)
                        return TRUE;
        }
        return FALSE;
}

/* function that counts the number of appearances of a ward in the input sentence */
int number_occurence(char *word, const char *input_text) {

        int count = 0;
        int found = 1;

        //lenght
        int word_len = (int)strlen(word);
        int input_text_len = (int)strlen(input_text);
        int len_to_control = input_text_len - word_len + 1;

        // test if there is no quotation marks around the current word
        if (word[0] == '\'' && word[word_len-1] == '\'') {
                for (int i = 0; i < word_len - 2; i++) {
                        // we overwrite the current word without the quotation marks
                        word[i] = word[i+1];
                }
                word_len -= 2; // length is reduced by 2 (quotation marks)
                len_to_control -= 2; // we adjust the length
                word[word_len] = '\0'; // complete the overwrite of the word

                count++;
        }

        for (int i = 0; i < len_to_control; i++) {
                found = 1;
                for (int j = 0; j < word_len; j++) {
                        // test each letters of our current word
                        if (input_text[i+j] != word[j]) {
                                found = 0;
                                break;
                        }
                }
                // if found and the word is surrounded by spaces, quotes etc.. (non alpha char)
                if (found == 1 && (isalpha(input_text[i+word_len])) == 0 && (isalpha(input_text[i-1])) == 0)
                        count++;
        }
        return count;
}
/* function that counts the number of unique words in a give sentance */
int word_count(const char *input_text, word_count_word_t *words) {

        char *temp = NULL;
        int occurence = 0;
        int i = 0;
        int n = 0;
        char copy_for_strtok_and_to_lower[strlen(input_text)];
        char copy_to_lower[strlen(input_text)];

        memset(words->text, 0, 1100); // clear to start with a known value

        // test the input text
        if (input_text == NULL && strlen(input_text) == 0)
                return EMPTY_INPUT;

        strcpy(copy_for_strtok_and_to_lower, input_text);
        strcpy(copy_to_lower, input_text);
        // lower case
        while (copy_to_lower[n]) {
                copy_to_lower[n] = tolower(copy_to_lower[n]);
                copy_for_strtok_and_to_lower[n] = tolower(copy_for_strtok_and_to_lower[n]);
                n++;
        }

        // begin separation
        temp = strtok(copy_for_strtok_and_to_lower, " .,;-_:/\n!&@$%^&");

        while (temp != NULL && i < MAX_WORDS) {
                // word not too long?
                if (MAX_WORD_LENGTH < strlen(temp)) {
                        return EXCESSIVE_LENGTH_WORD;
                }
                // count the number of occurences of the word
                occurence = number_occurence(temp, copy_to_lower);
                if (occurence != 0) {
                        // we register only one occurence of one word in our struct
                        if (exist(temp, words) == FALSE) {
                                memcpy(words[i].text, temp, strlen(temp));
                                words[i].count = occurence;
                                i++;
                        }
                }
                // split next word of the sentence
                temp = strtok(NULL, " .,;-_:/\n!&@$%^&");
        }

        // print the words and their number of appearances in the sentence
        for (int j = 0; j<i; j++) {
                printf("%s: %d\n", words[j].text, words[j].count);
        }

        // the number of words of the sentence exceed the max number of words
        if (temp != NULL)
                return EXCESSIVE_NUMBER_OF_WORDS;

        // return the number of counted words
        return i;
}
