#pragma once
#include "Opponent.h"
#include <iostream>

using namespace std;

Opponent::Opponent(string name, int level, int health, int attack, int defense, int speed, string id)
    : Character(name, level, health, attack, defense, speed), id(id) {}

void Opponent::displayInfo() {
    Character::displayInfo();
    cout << "ID: " << id << endl;
}
