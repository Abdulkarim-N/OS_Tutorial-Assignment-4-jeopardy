/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <strings.h> // For strcasecmp
 #include "questions.h"
 
 // Define the categories array
 char categories[NUM_CATEGORIES][MAX_LEN] = {
     "programming", 
     "algorithms", 
     "databases"
 };
 
 // Define the questions array
 question questions[NUM_QUESTIONS];
 
 // Initializes the array of questions for the game
 void initialize_game(void) {
     // Initialize each question struct and assign it to the questions array
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         strcpy(questions[i].category, categories[i % NUM_CATEGORIES]);
         questions[i].answered = false;
         strcpy(questions[i].question, "Q");
         strcpy(questions[i].answer, "A");
     }
     // Set specific questions and answers
     questions[0].value = 300;
     strcpy(questions[0].question, "Is Afghanistan part of the South Asian demographic or Middle Eastern demographic?");
     strcpy(questions[0].answer, "South Asian");
 
     questions[1].value = 200;
     strcpy(questions[1].question, "What is the capital of Germany?");
     strcpy(questions[1].answer, "Berlin");
 
     questions[2].value = 500;
     strcpy(questions[2].question, "Which bit in a computer system indicates whether a page in memory has been modified and needs to be written back to storage?");
     strcpy(questions[2].answer, "Dirty Bit");
 
     questions[3].value = 100;
     strcpy(questions[3].question, "What is the value of 25 × 4?");
     strcpy(questions[3].answer, "100");
 
     questions[4].value = 200;
     strcpy(questions[4].question, "If a rectangle has a length of 12 cm and a width of 5 cm, what is its area?");
     strcpy(questions[4].answer, "60");
 
     questions[5].value = 200;
     strcpy(questions[5].question, "Identify the verb in the sentence: She quickly finished her homework.");
     strcpy(questions[5].answer, "quickly");
 
     questions[6].value = 200;
     strcpy(questions[6].question, "What is the capital city of Canada?");
     strcpy(questions[6].answer, "Ottawa");
 
     questions[7].value = 200;
     strcpy(questions[7].question, "This part of a computer acts as its brain, performing calculations and processing tasks");
     strcpy(questions[7].answer, "CPU");
 
     questions[8].value = 300;
     strcpy(questions[8].question, "This document, signed in 1776, declared the independence of the American colonies.");
     strcpy(questions[8].answer, "Declaration of Independence");
 
     questions[9].value = 400;
     strcpy(questions[9].question, "This type of attack floods a network with traffic to disrupt its services.");
     strcpy(questions[9].answer, "DDOS attacks");
 
     questions[10].value = 200;
     strcpy(questions[10].question, "This element has the atomic number 8 and is essential for respiration.");
     strcpy(questions[10].answer, "Oxygen");
 
     questions[11].value = 300;
     strcpy(questions[11].question, "This molecule is known as the blueprint of life.");
     strcpy(questions[11].answer, "DNA");
 }
 
 // Displays each of the remaining categories and question dollar values that have not been answered
 void display_categories(void) {
     int width = 20;
     printf("\n------------------------ CATEGORIES ------------------------\n");
     for (int i = 0; i < NUM_CATEGORIES; i++) {
         printf("%-*s", width, categories[i]);
     }
     printf("\n-----------------------------------------------------------\n");
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (!questions[i].answered) {
             printf("%-*d |", width, questions[i].value);
         } else {
             printf("%-*s |", width, " - ");
         }
         if (i % NUM_CATEGORIES == NUM_CATEGORIES - 1) {
             printf("\n");
         }
     }
     printf("-----------------------------------------------------------\n");
 }
 
 // Displays the question for the category and dollar value
 void display_question(char *category, int value) {
     int num = get_question_number(category, value);
     if (num == -1) {
         printf("Question %s not found for value %d\n", category, value);
         return;
     }
     printf("Question %s for $%d:\n", category, value);
     printf("%s\n", questions[num].question);
 }
 
 // Returns true if the answer is correct for the question for that category and dollar value
 bool valid_answer(char *category, int value, char *answer) {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (strcmp(questions[i].category, category) == 0 && questions[i].value == value && !questions[i].answered) {
             if (strcasecmp(questions[i].answer, answer) == 0) {
                 questions[i].answered = true;
                 return true;
             }
             return false;
         }
     }
     return false;
 }
 
 // Returns true if the question has already been answered
 bool already_answered(char *category, int value) {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
             return questions[i].answered;
         }
     }
     return false;
 }
 
 // Returns the index of the question in the questions array
 int get_question_number(char *category, int value) {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
             return i;
         }
     }
     return -1; // Question not found
 }
 
 // Marks a question as answered
 void question_answered(char *category, int value) {
     for (int i = 0; i < NUM_QUESTIONS; i++) {
         if (strcmp(questions[i].category, category) == 0 && questions[i].value == value) {
             questions[i].answered = true;
             break;
         }
     }
 }