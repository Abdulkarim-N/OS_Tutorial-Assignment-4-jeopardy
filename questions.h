#ifndef QUESTIONS_H_
#define QUESTIONS_H_

#include <stdbool.h>

#define MAX_LEN 256
#define NUM_CATEGORIES 3
#define NUM_QUESTIONS 12

// List of 3 categories as array of strings
extern char categories[NUM_CATEGORIES][MAX_LEN];

// Questions struct for each question
typedef struct {
    char category[MAX_LEN];
    char question[MAX_LEN];
    char answer[MAX_LEN];
    int value;
    bool answered;
} question;

// An array of 12 questions (4 for each category)
extern question questions[NUM_QUESTIONS];

// Function declarations
void initialize_game(void);
void display_categories(void);
void display_question(char *category, int value);
bool valid_answer(char *category, int value, char *answer);
bool already_answered(char *category, int value);
int get_question_number(char *category, int value);
void question_answered(char *category, int value);

#endif /* QUESTIONS_H_ */