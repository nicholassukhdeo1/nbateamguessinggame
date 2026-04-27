#include <iostream>
#include <string>
#include <vector>
#include "team.h"

using namespace std;



class Game{

public:

Game();

bool hasWon(string guessedTeam);

bool turnLogic(string guessedTeam);

int getguessesLeft();



private:


    
    vector<Team> allTeams;
    int guessesLeft;

    Team* answer;

};