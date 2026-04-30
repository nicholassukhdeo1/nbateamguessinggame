#pragma once
#include <string>
using namespace std;

class Team {
public:
    string name, conference, division, primaryColor, secondaryColor;
    int championships, founded;

    Team(string n, string conf, string div, string pc, string sc, int champs, int f)
        : name(n), conference(conf), division(div),
        primaryColor(pc), secondaryColor(sc),
        championships(champs), founded(f) {
    }
};