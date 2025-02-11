#ifndef JEOPARDY_H_
#define JEOPARDY_H_

#include <unistd.h> // For sleep
#include <strings.h> // For strcasecmp

#define MAX_LEN 256 // Define BUFFER_LEN as MAX_LEN

// Function declarations
void tokenize(char *input, char **tokens);
void show_results(player *players, int num_players);
void execute_game(char **token, player *players);

#endif /* JEOPARDY_H_ */