#include <iostream>
#include <string>
#include <vector>
#include "Team.h"
#include "Hint.h"

using namespace std;



class Game{

public:

Game();

bool hasWon(string guessedTeam);

bool turnLogic(string guessedTeam);

int getGuessesLeft();



private:


    
    vector<Team> allTeams;
    int guessesLeft;

    Team* answer;

};