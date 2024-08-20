#pragma once
#include <iostream>

using namespace std;
//parent class which gummy and opponent inherits from
//has virtual methods such as the deconstructor and displayInfo as the other classes will override it.
class Character{
    public: 
        Character(string name, int level, int health, int attack, int defense, int speed);
        //accessors and muttators
        string getName();
        int getLevel();
        int getHealth();
        int getAttack();
        int getDefense();
        int getSpeed();
        int getStamina();

        void setName(string s);
        void setLevel(int l);
        void setHealth(int h);
        void setAttack(int a);
        void setDefense(int d);
        void setSpeed(int s);
        void setStamina(int s);

        virtual void displayInfo();
        virtual ~Character();

    private:
        string name;
        int level;
        int health;
        int attack;
        int defense;
        int speed;
        int stamina;
};