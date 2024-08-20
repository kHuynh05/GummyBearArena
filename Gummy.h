#pragma once
#ifndef GUMMY_H
#define GUMMY_H
#include <iostream>
#include "Character.h"

using namespace std;
//inherits from the character class
class Gummy : public Character{
    //unique elments to gummy
    private:
        string id;
        int xpThreshold;
        int xp;
    public:
        //constructor
        Gummy(string name, int level, int health, int attack, int defense, int speed, int xp, int xpThreshold, string id);

        void displayInfo();

        //Getter and setter for experience points
        int getXP();
        int getXpThreshold();
        void setXP(int xpValue);
        string getID();
        void setID(string ID);
        void checkXP();
};

#endif