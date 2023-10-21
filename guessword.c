#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define word_limit 7
#define max_guesses 7

// Test Case 10 still unsolved due to the blank line issue.

// create the structure based on topic 3, create and store inside all the variables that will be used in this structure.
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

// idk why but this function doesn't seem to do anything for me LOL or maybe i don't see it being executed?
/*
void removeBlankLine()
{
    while (getchar() != '\n')
        ;
}
*/

/*
bool isEmpty(const char *word)
{
    while (*word)
    {
        if (!isspace(*word))
        {
            return 0; // Non-whitespace character found
        }
          word++; // Move to the next character
    }
    return 1;
}
*/

// i realised that is the !isalpha doing triggering the invalid input, like it's overriding this function?
/*
bool containsSpecial(char word)
{
    const char *specialCharacters = "'^!~,. "; // test case 9 problem.
    return strchr(specialCharacters, word) != NULL;
}
*/

/*
// this was from the tinygrep exercise, i tried to reference it but i still couldn't solve the blank input and just <ENTER> issue.
bool containsSpecial(char input, char pattern)
{

    return (pattern == '.' || (pattern == '_' && isspace(input)) || input == pattern);
}

bool containsSpecial(char word)
{
    return (word == '.' || word == '_' || word == '^' || word == '!' || word == '?' || word = '.' || word = ',' || word = '\n');
}
*/

// validation for the word, try to put all conditions/rules of the game in here?
bool isValid(const char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isalpha(word[i]) || strlen(word) > word_limit)
        // if (!isalpha(word[i]) || strlen(word) > word_limit || isspace(word[i]))
        // if (!isalpha(word[i]) || strlen(word) > word_limit || containsSpecial(word[i])) - this did not work anyway, isalpha is doing all the work instead...
        {
            //  removeBlankLine();
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
        // removeBlankLine(); // intended to clear the blank but it didnt work.
        for (int i = 0; word[i] != '\0'; i++)
        {
            word[i] = tolower(word[i]); // convert to lowercase
        }
        if (!isValid(word))
        //  if (!isValid(word) || isEmpty(word)) // did not work as well.
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
        // i need some insight on this, i tried using fgets() but i kept getting errors.
        /*
            printf("Enter a line of text up to 35 characters in length ->\n");
            fgets(input, sizeof(input), stdin);
            */
        char guess;
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", max_guesses - game.incorrectGuesses);
        scanf(" %c", &guess);
        // fgets(guess, sizeof(input), stdin);
        //   removeBlankLine(); // this doesn't seem to clear the blank line.
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
