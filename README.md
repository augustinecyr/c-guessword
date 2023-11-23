## Guessing Game

This C program implements a simple guessing game where Player 1 enters a word and Player 2 tries to guess it within a limited number of attempts.

### Files:

- **main.c**: Contains the main code for the guessing game.
- **Readme.md**: Readme file explaining the program.

### Program Overview:

#### Structures:
- `struct GuessWord`: Contains the game state variables.
  - `word`: Stores the original word entered by Player 1.
  - `guessedWord`: Tracks the progress of guesses made by Player 2.
  - `incorrectGuesses`: Counts the number of incorrect guesses made by Player 2.

#### Functions:

- `void startGuessing(struct GuessWord *game, const char *word)`: Initializes the game state by copying the word entered by Player 1 and setting up the guessedWord with underscores.
- `bool isValid(const char *word)`: Validates whether the entered word meets the game's criteria (contains only English letters and is within the word limit).

#### Main Function:

- **Input**:
  - Player 1 enters a word within the specified character limit.
  - Player 2 makes guesses to reveal the word.
  
- **Gameplay**:
  - Player 1 enters a word.
  - Player 2 makes guesses until they either:
    - Correctly guess the word.
    - Reach the maximum number of incorrect guesses allowed.

### Running the Program:

1. Compile the program: `gcc guessword.c -o guessword`.
2. Run the executable: `./guessword`.
3. Follow the prompts to play the game.

### Notes:

- The game validates input to ensure it contains only English letters and does not exceed the character limit.
- Player 2 has a limited number of guesses (defined by `max_guesses`).
- The game tracks incorrect guesses and reveals correctly guessed letters in the word.

### Example Output:

```
Player 1, enter a word of no more than 7 letters:
[Player 1 enters a word]

Player 2 has so far guessed: _______   (Displays underscores for each letter)
Player 2, you have 7 guesses remaining. Enter your next guess:
[Player 2 enters a letter]

[Game continues until Player 2 either wins or reaches maximum incorrect guesses]
```

---

Feel free to expand this readme with additional information or instructions as needed!
