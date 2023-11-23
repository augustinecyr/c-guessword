#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define word_limit 7
#define max_guesses 7

// Test Case 10 still unsolved due to the blank line issue.

// create the structure based on topic 4, create and store inside all the variables that will be used in this structure.
struct GuessWord
{
    char word[word_limit + 1];        // array to store the input
    char guessedWord[word_limit + 1]; // array to use for comparison between word
    int incorrectGuesses;             // a counter for incorrect guesses.
};

// Function to initialize the game state
void startGuessing(struct GuessWord *game, const char *word)
{
    strcpy(game->word, word);        // copy the string
    strcpy(game->guessedWord, word); // copy the string to word.

    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(game->guessedWord[i]))
        {
            game->guessedWord[i] = '_';
        }
    }
    game->incorrectGuesses = 0;
}

// validation for the word, try to put all conditions/rules of the game in here?
bool isValid(const char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isalpha(word[i]) || strlen(word) > word_limit)
        {
            return 0; // Invalid word
        }
    }
    return 1; // Valid word
}

int main()
{
    char word[word_limit + 1];
    printf("Player 1, enter a word of no more than %d letters:\n", word_limit); // prompt input

    do
    {
        scanf("%s", word);
        for (int i = 0; word[i] != '\0'; i++)
        {
            word[i] = tolower(word[i]); // convert to lowercase
        }
        if (!isValid(word))
        {
            printf("Sorry, the word must contain only English letters.\n");
            printf("Player 1, enter a word of no more than %d letters:\n", word_limit);
        }
    } while (!isValid(word));

    struct GuessWord game;
    startGuessing(&game, word);
    printf("Player 2 has so far guessed: %s\n", game.guessedWord);

    while (game.incorrectGuesses < max_guesses)
    {
        char guess;
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", max_guesses - game.incorrectGuesses);
        scanf(" %c", &guess);
        guess = tolower(guess); // lowercase before comparison
        int wordLength = strlen(game.word);
        int match = 0;
        for (int i = 0; i < wordLength; i++)
        {
            if (game.word[i] == guess)
            {
                game.guessedWord[i] = guess;
                match = 1;
            }
        }

        if (match)
        {
            printf("Player 2 has so far guessed: %s\n", game.guessedWord);
        }
        else
        {
            game.incorrectGuesses++; // add 1 to the counter
            printf("Player 2 has so far guessed: %s\n", game.guessedWord);
        }

        if (strcmp(game.word, game.guessedWord) == 0) // if words are the same , player 2 wins
        {
            printf("Player 2 wins.\n");
            break;
        }
    }

    if (game.incorrectGuesses == max_guesses) // if 7 = 7 , player 1 wins
    {
        printf("Player 2 has failed to guess the word %s. Player 1 wins.\n", game.word);
    }

    return 0;
}
