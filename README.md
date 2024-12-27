# Hangman-game
This project is a console-based implementation of the classic Hangman word-guessing game, written entirely in C++. The game challenges players to guess a randomly chosen word, letter by letter, within a limited number of attempts.

**Features**
1. Random word selection from a pre-defined list of words across various categories (e.g., fruits, animals, geography).
2. Real-time feedback on correct and incorrect guesses.
3. Efficient handling of duplicate letters, ensuring all occurrences are revealed when guessed correctly.
4. Input validation to ensure guesses are valid lowercase letters.
5. A clear and interactive user interface that displays the progress using a masked word format (e.g., _ _ p p _ for "apple").
6. Structured and modular design with functions for masking the word and handling gameplay logic.
   
Endgame conditions:
-Win: Displays a congratulatory message upon guessing all letters.
-Lose: Displays a message with the correct word when all attempts are used.

**How to play**
1. Run the program in a terminal or console.
2. Follow the prompts to guess one letter at a time.
3. Reveal all the letters before running out of guesses to win!

