/*
LAB 3 ASSIGNMENT - GUESSWORD
Student ID: 2300411
Name: Augustine Chan Yi Ren
*/
#include <stdio.h>
// define what macros are needed, keep it simple.
#define max_guesses 7
#define word_limit 7

int main()
{
    int player1_guess;
    int player2_guess;

    printf("Player 1, enter a word of no more than 7 letters:\n");
    do
    {
        scanf("%d", &player1_guess); // store input to player1_guess, must include '&'

        if () // using || means AND for conditions.
        {
            printf("Sorry, the word must contain only English letters.\n");
            printf("Player 1, enter a word of no more than 7 letters:\n");
        }
    } while ();

    int count = 0;              // set this to 0 first.
    while (count < max_guesses) // primary condition in the game?, 7 guesses allowed.
    {
        // one letter per guess.
        printf("Player 2, you have %d guesses remaining.\n", max_guesses - count);
        printf("/n");
        scanf("%d", &player2_guess);
        printf("Player 2 has so far guessed:\n");
        // special characters = minus 1 count.
        if ()
        {
            count--;

            printf("Player 2 has so far guessed:\n"); /* must include "_"
            e.g the word is "cat", player 2 guessed "a", the printf should print "_a_". */
        }
        // blank entry = minus 1 count.
        else if ()
        {
            count--;

            printf("Player 2 has so far guessed:\n");
            /* must include "_"
            e.g the word is "cat", player 2 guessed "a", the printf should print "_a_". */
        }
        /* multiple letters e.g "aaa" will be given as "a", if a number with letters is given e.g "8a", this is will count as "8"
        and will be a incorrect guess. condition is first character of each guess will be the primary and only deciding factor. */
        else if ()
        {
            count--;

            printf("Player 2 has so far guessed:\n");
            /* must include "_"
            e.g the word is "cat", player 2 guessed "a", the printf should print "_a_". */
        }
        else
        {
            printf("Player 2 wins.\n");
            break; // stop the loop
        }
        count++; // this will give a +1 count for every attempt , use max_guesses against this to get the remainder.
    }
    if (count == max_guesses)
    {
        printf("Player 1 wins.\n");
    }
    return 0;
}