
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "game.h"
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <ctype.h>

int main(int argc, char* argv[]) {//qualsiasi cosa abbia a che fare con gli argomenti non funge
	srand(time(NULL));
	char shot = 0;
	char game[GAME_WIDTH] = {0};
	int curr = -1, len = 0;
	initscr();
    	cbreak();          
	noecho();


	
	printf("\nType the right letter starting from left\n");

	if(argc != 2){
		for (int i = 0; i <= GAME_WIDTH/2; i++) {
        		spawnLetter(game, &curr);
        	
        		usleep(20000); 
    		}
	} else {//si può personalizzare la larghezza con un argomento se non si vuole modificare l'header
		
		if(atoi(argv[1]) < GAME_WIDTH){

			for (int i = 0; i <= atoi(argv[1])/2; i++) {
        			spawnLetter(game, &curr);
        		
        			usleep(20000); 
    			}
		} else {
		
			printf("Width exceeds GAME_WIDTH= %d. Insert a smaller value or set GAME_WIDTH higher in the file \"game.h\"", GAME_WIDTH);

		}
		
		//non funge bene //non ricordo che volevo fare
		/*
		for(int i = 0; *(argv[1]+i) != '\0'; i++){
			len++;
		}
		fixPhrase(argv[1], len);
		for(int i = 0; i <= len; i++){
			spawnPhrase(game, argv[1], &curr);
		
			usleep(20000);
		}*/
	}

	while(curr != -1 && curr < GAME_WIDTH){
		scanf("%c", &shot);
		
		shot = toupper(shot);

		if(shot == game[curr]){
			killLetter(game, &curr);
		}
		else{
			spawnLetter(game, &curr);
		};
	}
	printf("\nGame over\n");
	endwin();
    
    return 0;
}	
