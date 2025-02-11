# OS_Tutorial-Assignment-4-jeopardy

This is Tutorial 4 for OS, Jeopardy. Everything was split so each person would do a C file, one C file was shared and we also worked together in person to help eachother.

SOFE 3950U - Operating Systems
Tutorial 4
CRN: 74027




Affan Abdulkhader - 100820838
Mohammad Ali - 100817859
Abdulkarim Noorzaie - 100748590
Umer Rabbani - 100821754



# Instructions to compile and run:

Download and extract the .zip file in a Linux environment or WSL. Directory into the file and run the jeopardy.exe executable to run the program. Upon starting, you will be prompted to enter the names of the players participating in the game, and when finished, will be presented the game board, categories, and question values. You are initially prompted to enter the category, then the value, and then answer questions!

# Explanation of each .c file

players.c has two essential functions, which reports if a player exists and to update the score, which are important to the core functionality of the game. It runs continuous checks to see if a player exists in the game, and update their scores and points.

questions.c's main functionality is to store and present the questions for answering. Creates and stores the values of each question and appropriately awards it to the player that submits a correct solution. It matches with strcasecmp, marks correct or incorrect, prevents duplicate attempts, and ensures the game is played fairly.

jeopardy.c is the main driver program file, housing all the function calls across all files and displaying everything in order. Tokenize processes player input by breaking input into spaces and delimiters. A method, execute_game, handles the core running of the program. valid_answer checks if the player's response is correct and updates their score. The show_results function displays the final rankings when the game has completed.




