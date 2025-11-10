/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Maximum length of the secret word
#define MAX_LENGTH 20

int main() {
    char secretWord[MAX_LENGTH] = "coders";  // Word player needs to guess
    char guessedLetters[MAX_LENGTH] = {0};   // Letters guessed correctly, initialized with zeros
    int maxWrongGuesses = 6;                  // Max wrong tries allowed
    int wrongGuesses = 0;                     // Wrong guess counter
    int wordLength = strlen(secretWord);
    int lettersFound = 0;                     // Number of letters found so far
    char guess;
    
    printf("Welcome to Beginner Hangman Game!\n");
    printf("Try to guess the word, letter by letter.\n");

    // Convert secretWord to uppercase to handle case-insensitive guesses
    for (int i = 0; i < wordLength; i++) {
        secretWord[i] = toupper(secretWord[i]);
    }

    // Initialize guessedLetters array with underscores
    for (int i = 0; i < wordLength; i++) {
        guessedLetters[i] = '_';
    }
    
    // Start game loop
    while (wrongGuesses < maxWrongGuesses && lettersFound < wordLength) {
        printf("\nWord: ");
        for (int i = 0; i < wordLength; i++) {
            printf("%c ", guessedLetters[i]);
        }
        printf("\n");

        printf("You have %d wrong guesses left.\n", maxWrongGuesses - wrongGuesses);
        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);
        
        // Convert guessed letter to uppercase for matching
        guess = toupper(guess);

        // Check if the guess is correct
        int foundInWord = 0;    // Flag to check if letter found in word
        int alreadyGuessed = 0; // Flag to check if letter already guessed

        // Check if letter was already guessed
        for (int i = 0; i < wordLength; i++) {
            if (guessedLetters[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }

        if (alreadyGuessed) {
            printf("You already guessed the letter '%c'. Try another.\n", guess);
            continue;   // Skip rest of loop, guess again
        }

        // Check if guessed letter is in secret word
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess && guessedLetters[i] != guess) {
                guessedLetters[i] = guess;
                lettersFound++;
                foundInWord = 1;
            }
        }

        if (foundInWord) {
            printf("Good job! Letter '%c' is in the word.\n", guess);
        } else {
            wrongGuesses++;
            printf("Sorry! Letter '%c' is not in the word.\n", guess);
        }
    }

    // End of game messages
    if (lettersFound == wordLength) {
        printf("\nCongratulations! You guessed the word: %s\n", secretWord);
    } else {
        printf("\nGame Over! You've used all your chances.\n");
        printf("The correct word was: %s\n", secretWord);
    }

    return 0;
}
