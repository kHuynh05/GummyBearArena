#pragma once
#ifndef OPPONENT_H
#define OPPONENT_H

#include "Character.h"
//like gummy but more simpilified
class Opponent : public Character {
private:
    string id;

public:
    Opponent(string name, int level, int health, int attack, int defense, int speed, string id);

    void displayInfo();
};

#endif