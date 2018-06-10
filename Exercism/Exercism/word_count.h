//
//  word_count.h
//  Exercism
//
//  Created by Sameh EL AWADI on 05/06/2018.
//  Copyright © 2018 Sameh EL AWADI. All rights reserved.
//

#ifndef WORD_COUNT_H
#define WORD_COUNT_H

#define MAX_WORDS 20            // at most MAX_WORDS can be found in the test input string
#define MAX_WORD_LENGTH 50      // no individual word can exceed this length

// results structure
typedef struct word_count_word {
	char text[MAX_WORD_LENGTH];
	int count;
} word_count_word_t;

#define EXCESSIVE_LENGTH_WORD     -1
#define EXCESSIVE_NUMBER_OF_WORDS -2
#define EMPTY_INPUT -3
#define TRUE 10
#define FALSE -10

// word_count - routine to classify the unique words and their frequency in a test input string
// inputs:
//    input_text =  a null-terminated string containing that is analyzed
//
// outputs:
//    words = allocated structure to record the words found and their frequency
//    uniqueWords - number of words in the words structure
//           returns a negative number if an error.
//           words will contain the results up to that point.
int word_count(const char *input_text, word_count_word_t * words);
int exist(char *word, word_count_word_t *words);
int number_occurence(char *word, const char *input_text);

#endif

