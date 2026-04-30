#include <iostream>
#include <string>
#include "game.h"
using namespace std;

int main() {
    string guessedTeam;

    Game currentGame;

    cout << "Guess the NBA team! You have 6 tries." << endl;
    cout << "Enter the full team name (ex: Los Angeles Lakers): " << endl;

    while (currentGame.getGuessesLeft() > 0) {
        cout << "\nGuesses left: " << currentGame.getGuessesLeft() << endl;
        getline(cin, guessedTeam); // getline handles team names with spaces

        if (currentGame.turnLogic(guessedTeam)) {
            cout << "Correct! You won." << endl;
            return 0;
        }

        if (currentGame.getGuessesLeft() > 0)
            cout << "Wrong guess, try again!" << endl;
    }

    cout << "Out of guesses. You lost!" << endl;
    return 0;
}
