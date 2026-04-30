#include "game.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game()
{
    ifstream file("team_data.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue; // skip the comment/header line at the top

        // split each line by the pipe character to get the individual fields
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, '|'))
            tokens.push_back(token);

        // FORMAT: Name|Conference|Division|PrimaryColor|SecondaryColor|Championships|Founded
        allTeams.push_back(Team(
            tokens[0], tokens[1], tokens[2],
            tokens[3], tokens[4],
            stoi(tokens[5]), stoi(tokens[6])
        ));
    }

    srand(time(0));
    answer = &allTeams[rand() % 30]; // pick a random team as the answer
    guessesLeft = 6;
}

bool Game::hasWon(string guessedTeam)
{
    // just check if the player typed the exact name of the answer team
    return guessedTeam == answer->name;
}

int Game::getGuessesLeft()
{
    return guessesLeft;
}

bool Game::turnLogic(string guessedTeam)
{
    if (hasWon(guessedTeam))
        return true;

    // find the team object that matches what the player typed
    Team* guessed = nullptr;
    for (auto& team : allTeams) {
        if (team.name == guessedTeam) {
            guessed = &team;
            break;
        }
    }

    if (guessed) {
        // store all hint types in one vector so we can just loop through them
        // this is where polymorphism kicks in, each getHint() call runs differently depending on the subclass
        vector<Hint*> hints = {
            new ConferenceHint(),
            new DivisionHint(),
            new FoundedHint(),
            new ChampionshipsHint(),
            new ColorHint()
        };

        cout << "\n--- Hints ---" << endl;
        for (Hint* h : hints)
            cout << h->getHint(guessed, answer) << endl;
        cout << "-------------\n" << endl;

        // clean up after ourselves so we dont leak memory
        for (Hint* h : hints) delete h;
    }
    else {
        cout << "Team not found, check your spelling!" << endl;
    }

    guessesLeft--;
    return false;
}