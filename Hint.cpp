#include "Hint.h"
#include <iostream>
using namespace std;

// if both teams share the same conference we let the player know, otherwise we just tell them which one the answer is in
string ConferenceHint::getHint(Team* guessed, Team* answer) const {
    if (guessed->conference == answer->conference)
        return "[Conference:    CORRECT - " + answer->conference + "]";
    return "[Conference:    WRONG   - answer is " + answer->conference + "]";
}

// same idea as conference but for division
string DivisionHint::getHint(Team* guessed, Team* answer) const {
    if (guessed->division == answer->division)
        return "[Division:      CORRECT - " + answer->division + "]";
    return "[Division:      WRONG   - answer is in the " + answer->division + " division]";
}

// instead of just saying wrong we tell the player which direction to go so they can narrow it down
string FoundedHint::getHint(Team* guessed, Team* answer) const {
    int diff = answer->founded - guessed->founded;
    if (diff == 0)
        return "[Founded:       CORRECT - " + to_string(answer->founded) + "]";
    else if (diff > 0)
        return "[Founded:       Go LATER   (by " + to_string(diff) + " yrs)]";
    else
        return "[Founded:       Go EARLIER (by " + to_string(-diff) + " yrs)]";
}

// same warmer/colder approach but for championships so the player knows if theyre thinking too high or too low
string ChampionshipsHint::getHint(Team* guessed, Team* answer) const {
    int diff = answer->championships - guessed->championships;
    if (diff == 0)
        return "[Championships: CORRECT - " + to_string(answer->championships) + "]";
    else if (diff > 0)
        return "[Championships: Go HIGHER (by " + to_string(diff) + ")]";
    else
        return "[Championships: Go LOWER  (by " + to_string(-diff) + ")]";
}

// partial credit here, if at least one color matches we tell them which one so its not a total loss
string ColorHint::getHint(Team* guessed, Team* answer) const {
    bool primaryMatch = guessed->primaryColor == answer->primaryColor;
    bool secondaryMatch = guessed->secondaryColor == answer->secondaryColor;

    if (primaryMatch && secondaryMatch)
        return "[Colors:        BOTH match!]";
    else if (primaryMatch)
        return "[Colors:        Primary matches, secondary differs]";
    else if (secondaryMatch)
        return "[Colors:        Secondary matches, primary differs]";
    else
        return "[Colors:        Neither color matches]";
}