#include "game.h"
#include <stdlib.h>
#include <stdio.h>


void spawnLetter(char letters[], int* idx){
	char c = (rand() % 26) + 65;

	letters[++(*idx)] = c;

	printf("\r%s ", CURSOR);

	for(int i = GAME_WIDTH-1; i >= 0; i--){
		if(letters[i] == 0) printf(" ");
		else printf("%c", letters[i]);
	}
	printf("<=");
	fflush(stdout);
}

void killLetter(char letters[], int* idx){

	letters[(*idx)--] = 0;

	printf("\r%s",CURSOR);
	
	for(int i = GAME_WIDTH-1; i >= 0; i--){
		if(letters[i] == 0) printf(" ");
		else printf("%c", letters[i]);

	}

	printf("<=");
	fflush(stdout);

}

void spawnPhrase(char letters[], char phrase[], int* idx){ //non funge bene

	letters[*idx] = phrase[*idx];
	(*idx)++;

	printf("\r%s", CURSOR);

	for(int i = GAME_WIDTH-1; i >= 0; i--){
		if(letters[i] == 0) printf(" ");
		else printf("%c", letters[i]);
	}

	printf("<=");
	fflush(stdout);
}

void fixPhrase(char phrase[], int len){
	char* tmp = phrase;

	for(int i = len-2, j = 0; i>=0 && j < len-2  ; i++, j++){
		phrase[i] = tmp[j];
	}

}
