//
//  word_count.c
//  Exercism
//
//  Created by Sameh EL AWADI on 05/06/2018.
//  Copyright © 2018 Sameh EL AWADI. All rights reserved.
//

#include "word_count.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int exist(char *word, word_count_word_t *words) {
	
	//		printf("YOLOOOOOOOOOOOOO: %d\n", sizeof(words) / sizeof(words[0]));
	
//	if ((sizeof(words) / sizeof(words[0]) == 0)) {
//		return FALSE;
//	}
	
	for (int i = 0; i < MAX_WORDS; i++) {
		if (strcmp(words[i].text, word) == 0) {
			printf("JE SUIS LAAAAAAAAAA\n");
			return TRUE;
		}
	}
	return FALSE;
}




int number_occurence(char *word, const char *input_text) {
	
	int count = 0;
	int found = 1;
	
	int word_len = (int)strlen(word);
	//	char *yolo = malloc(sizeof(input_text));
	//	char yolo[100];
	//	strcpy(yolo, input_text);
	
	//	printf("WORD: %s\n", word);
	
	// I LOVE PROGRAMMING, I LOVE CODING
	
	for (int i = 0; i <= (strlen(input_text) - strlen(word)); i++) {
		found = 1;
		for (int j = 0; j < word_len; j++) {
			if (input_text[i+j] != word[j]) {
				found = 0;
				break;
			}
		}
		
		//		!isalpha(input_text[i+word_len]);
		//		if (found == 1 && input_text[i+word_len] == ' ') {
		if ((found == 1 && (isalpha(input_text[i+word_len])) == 0) || ( found == 1 && input_text[i+word_len] == '\0')) {
			count++;
		}
	}
	
	printf("VALEUR DU COUNT DE %s: %d\n", word, count);
	return count;
}


int word_count(const char *input_text, word_count_word_t *words) {
	
	char *temp = malloc(sizeof(input_text));
	int occurence = 0;
	int i = 0;
	
	if (input_text == NULL && strlen(input_text) == 0)
		return -1;
	
	char *copy = malloc(sizeof(input_text));
	strcpy(copy, input_text);
	
	// first time
	temp = strtok(copy, " .,;-_/:");
	//	printf("valeur de TEMP avant: %s\n", temp);
	
	while (temp != NULL) {
		
		occurence = number_occurence(temp, input_text);
		
		if (occurence != 0) {
			if (exist(temp, words) == FALSE) {
//				printf("JE SUISS LALLALALALALALALA\n");
				strcpy(words[i].text, temp);
				words[i].count = occurence;
				i++;
			}
		}
		temp = strtok(NULL, " .,;-_/:");
		//		printf("valeur de TEMP apres: %s\n", temp);
	}
	
	printf("valeur de i apres: %d\n", i);
	for (int j = 0; j<i; j++) {
		printf("%s: %d\n", words[j].text, words[j].count);
	}
	
	return i;
}
