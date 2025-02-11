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
 #include <unistd.h> // For sleep
 #include "questions.h"
 #include "players.h"
 #include "jeopardy.h"
 
 // Put macros or constants here using #define
 #define NUM_PLAYERS 4
 
 // Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
 void tokenize(char *input, char **tokens);
 
 // Displays the game results for each player, their name and final score, ranked from first to last place
 void show_results(player *players, int num_players);
 
 int main(int argc, char *argv[])
 {
	 (void)argc; // Explicitly mark as unused
	 (void)argv; // Explicitly mark as unused
 
	 // An array of 4 players, may need to be a pointer if you want it set dynamically
	 player players[NUM_PLAYERS];
 
	 // Display the game introduction and initialize the questions
	 initialize_game();
 
	 // Prompt for players names
	 printf("Welcome to Jeopardy!:\n");
	 
	 // Initialize each of the players in the array
	 int num_players = 4;
	 for (int p = 0; p < num_players; p++) {
		 printf("Please enter the player's name: ");
		 scanf("%s", players[p].name);
		 players[p].score = 0;
		 system("clear");
	 }
	 printf("All players ready to play!\n");
	 sleep(2);
	 system("clear");
 
	 // Execute the game
	 char token[4][MAX_LEN] = {{ 0 }}; // Use MAX_LEN from jeopardy.h
	 execute_game((char **)token, players);
 
	 return 0;
 }
 
 void tokenize(char *input, char **tokens) {
	 char *token_extra = strtok(input, " ");
	 for (int i = 0; token_extra != NULL; i++) {
		 strcpy(tokens[i], token_extra);
		 token_extra = strtok(NULL, " ");
	 }
 }
 
 void execute_game(char **token, player *players) {
	 int num_players = 4;
	 char message[MAX_LEN] = {0}; // Use MAX_LEN from jeopardy.h
	 char question_category[MAX_LEN] = {0}; // Use MAX_LEN from jeopardy.h
	 bool numOfCorrect;
	 int questions_left = NUM_QUESTIONS;
	 int question_val = 0; // Initialize to 0
 
	 while (questions_left > 0) {
		 for (int i = 0; i < num_players; i++) {
			 printf("~~ Player Turn: %s ~~\n", players[i].name);
			 printf("Enter the category for the question you want to answer:\n");
			 display_categories();
			 scanf("%s", question_category);
			 printf("Enter the value for the question you want to answer:\n");
			 scanf("%d", &question_val); // Pass address of question_val
				 
			 if (already_answered(question_category, question_val)) {
				 printf("This question has already been answered. Please choose another question and value.\n");
				 i--;
			 } else {
				 display_question(question_category, question_val);
				 printf("Please enter your response: ");
				 scanf(" %[^\n]", message); // Read the entire line, including spaces
				 tokenize(message, token);
				 numOfCorrect = valid_answer(question_category, question_val, token[2]);
				 if (numOfCorrect) {
					 printf("Your answer was correct! Please choose another question.\n");
					 players[i].score += question_val;
					 i--;
				 } else {
					 printf("Your answer was incorrect.\n");
				 }
				 question_answered(question_category, question_val);
				 questions_left--;
				 if (questions_left <= 0)
					 break;
			 }
		 }
	 }
	 show_results(players, num_players);
 }
 
 void show_results(player *players, int num_players) {
	 printf("\nFinal Results:\n");
	 for (int i = 0; i < num_players; i++) {
		 printf("Player Name: %s\tPlayer Score: %d\n", players[i].name, players[i].score);
	 }
 }