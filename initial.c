#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// define macros
#define max_guesses 7
#define letter_limit 7

// function to use for validating input instead of inside int main()
bool isValid(const char *word) {
    for (int i = 0; i < strlen(word); ++i) {
        if (!isalpha(word[i]) || strlen(word) > letter_limit) {
            return false;
        }
    }
    return true;
}

int main() {
    // all the variables
    char player1_word[letter_limit + 1];
    char player2_guess;
    char player2_guesses[letter_limit];
    int remaining_guesses = 7;

    printf("Player 1, enter a word of no more than 7 letters:\n");
  
    do {
        fgets(player1_word, sizeof(player1_word), stdin);
        player1_word[strcspn(player1_word, "\n")] = '\0';

        if (!isValid(player1_word)) {
            printf("Sorry, the word must contain only English letters.\n");
        } continue;

    } while (strlen(player1_word) == 0 || strlen(player1_word) > letter_limit);

    for (int i = 0; i < strlen(player1_word); ++i) {
        player1_word[i] = tolower(player1_word[i]);
        player2_guesses[i] = '_';
    }
    player2_guesses[strlen(player1_word)] = '\0';
  
    printf("Player 2 has so far guessed: %s\n", player2_guesses);

    int count = 0;
    while (count < max_guesses && remaining_guesses > 0) {
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", remaining_guesses);
        scanf(" %c", &player2_guess);
        getchar();

        if (!isalpha(player2_guess)) {
            remaining_guesses--;
            printf("Player 2 has so far guessed: %s\n", player2_guesses);
            continue;
        }
        player2_guess = tolower(player2_guess);
        bool correct_guess = false;
        for (int i = 0; i < strlen(player1_word); ++i) {
            if (player1_word[i] == player2_guess) {
                player2_guesses[i] = player2_guess;
                correct_guess = true;
            }
        }

        printf("Player 2 has so far guessed: %s\n", player2_guesses);

        if (strcmp(player2_guesses, player1_word) == 0) {
            printf("Player 2 wins.\n");
            return 0;
        }
        if (!correct_guess) {
            remaining_guesses--;
        } else {
            count++;
        }
    }
    printf("Player 2 has failed to guess the word %s. Player 1 wins.\n", player1_word);
    return 0;
}
