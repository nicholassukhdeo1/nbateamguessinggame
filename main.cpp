#include "game.h"
#include <iostream>
using namespace std;

int main() {
    Game game;
    string guess;

    cout << "Welcome to the NBA Team Guessing Game!" << endl;
    cout << "You have " << game.getGuessesLeft() << " guesses." << endl;

    while (game.getGuessesLeft() > 0) {
        cout << "\nGuess the NBA team: ";
        getline(cin, guess);

        if (game.turnLogic(guess)) {
            cout << "Correct! You guessed the team!" << endl;
            return 0;
        }

        cout << "Guesses left: " << game.getGuessesLeft() << endl;
    }

    cout << "Out of guesses! Better luck next time." << endl;
    return 0;
}
