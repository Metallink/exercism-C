//
//  main.c
//  Exercism
//
//  Created by Sameh EL AWADI on 05/06/2018.
//  Copyright © 2018 Sameh EL AWADI. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "word_count.h"

int main(int argc, const char * argv[]) {
	
	word_count_word_t test;
	
	char yolo[100] = "I LOVE PROGRAMMING, I LOVE CODING";
	
	int res = word_count(yolo, &test);
	
	printf("NOMBRE DE MOT: %d\n", res);
	
	return 0;
}
