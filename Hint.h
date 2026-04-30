#pragma once
#include <string>
#include "team.h"
using namespace std;

// base class for all hints, every hint type inherits from this
class Hint {
public:
    virtual string getHint(Team* guessed, Team* answer) const = 0; // each subclass has to implement this their own way
    virtual ~Hint() {}
};

// checks if both teams are in the same conference
class ConferenceHint : public Hint {
public:
    string getHint(Team* guessed, Team* answer) const override;
};

// checks if both teams are in the same division
class DivisionHint : public Hint {
public:
    string getHint(Team* guessed, Team* answer) const override;
};

// tells you if the answer was founded earlier or later than your guess
class FoundedHint : public Hint {
public:
    string getHint(Team* guessed, Team* answer) const override;
};

// tells you if the answer has more or fewer championships than your guess
class ChampionshipsHint : public Hint {
public:
    string getHint(Team* guessed, Team* answer) const override;
};

// checks how many of the team colors match up
class ColorHint : public Hint {
public:
    string getHint(Team* guessed, Team* answer) const override;
};