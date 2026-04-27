#include <iostream>
#include <string>
#include "game.h"

using namespace std;


int main(){

    string guessTeam;

    Game currentGame; //make an instance of Game.

    while(currentGame.getguessesLeft() > 0){
        cin >> guessTeam;
        if(currentGame.turnLogic(guessTeam)){
            cout << "Correct! You won." << endl;
            break;
        }
        cout << "Wrong guess, try again: " << endl;
    }

    if(getguessesLeft() == 0){
        cout << "All guesses exhausted. You lost!" << endl;
    }








    return 0;
}