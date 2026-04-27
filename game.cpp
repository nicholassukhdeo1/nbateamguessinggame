#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game()
{

    ifstream teamInfo("teamInfo.txt")
    string name, conference, division;
    int foundedWhen;


    //NO SPACES IN THE FILE NAME! WONT READ RIGHT

    while(file >> name >> conference >> division >> foundedWhen){ //initialize all 30 teams    
        
        allTeams.push_back(Team(name, conference, division, foundedWhen))

    }

    srand(time(0));
    answer = &allTeams[rand() % 30]; //random answer team out of the 30.

    guessesLeft = 6; //you start with 6 guesses.
}

// logic to check if player won w/ his current guess
bool Game::hasWon(string guessedTeam)
{
    if(guessedTeam == allTeams.name){ //if the guessed name is the answer's name
        return true;
    }

    return false;

}

int Game::getguessesLeft()
{
    return guessesLeft;
}


bool Game::turnLogic(string guessedTeam)
{
    if(hasWon(guessedTeam)){
        return true;
    }

    //hint logic
    guessesLeft--;
    return false;
    
}