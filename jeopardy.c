/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <Affan Abdulkhader, Mohammad Ali, Abdulkarim Noorzaie, Umer Rabbani>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players);


int main(int argc, char *argv[])
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    printf("Welcome to Jeopardy!:\n");
	
    // initialize each of the players in the array
	for (int p = 0; p < 4; p++) {
		printf("Please enter the player's name: ");
		scanf("%s", (char *) &players[p].name);
		players[p].score = 0;
		system("clear");
	}
	printf("All players ready to play!\n");
	sleep(2);
	system("clear");
	
    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
		char token[4][BUFFER_LEN] = {{ 0 }};
		initialize_game();
		execute_game(token, players);
		return 0;
    }	
}
	void tokenize(char *input, char **tokens){
		char *token_extra = strtok(input, " ");
		token_extra = strtok(NULL, " ");
		
		for(int i = 0; token_extra != NULL; i++){
			strcpy(tokens[i], token_extra);
			token_extra = strtok(NULL, " ");
		}
	}
	
	void execute_game(char **token, player *players){
		char message[BUFFER_LEN] = {0};
		char *question_category;
		bool numOfCorrect;
		int questions_left = sizeof(questions);
		int question_val;
		
		question_category = (char *) calloc(BUFFER_LEN, sizeof(char));

		while(questions_left > 0){
			for(int i = 0; i < sizeof(players); i++){
				printf("~~ Player Turn: %s ~~\n", players[i].name);
				printf("Enter the category for the question you want to answer:\n");
				display_categories();
				scanf("%s", question_category);
				scanf("%d", question_val);
				
				if (already_answered(question_category, question_val)){
					printf("This question has already been answered. Please choose another question and value.\n");
					i--;
				}
				
				else{
					display_question(question_category, question_val);
					printf("Please enter your response:");
					scanf("%s", message)
					tokenize(message, token);
					numOfCorrect = valid_answer(question_category, question_val, token[2]);
					if (numOfCorrect){
						printf("Your answer was correct! Please choose another question.\n");
						players[i].score += question_val;
						i--;
					}
					else
						printf("Your answer was incorrect.\n");
					question_answered(question_category, question_val);
					questions_left--;
					if (questions_left <= 0)
						break;
				}
			}
			free(question_category);
		}
		show_results(players);
	}
	void show_results(player *players){
		for(int i = 0; i < 4; i++){
			printf("Player Name: %s\tPlayer Score:%d\n", players[i].name, players[i].score);
	
		}
	}
}
