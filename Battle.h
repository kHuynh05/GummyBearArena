#pragma once
#ifndef BATTLE_H
#define BATTLE_H

#include "Character.h"
#include "Gummy.h"
#include "Opponent.h"
//the battle class that mangages everything
class Battle{
    public:
        Battle();
        //the main function that manages every battle
        bool battle(Gummy& p,Opponent& e);
        //functions used in the battle function
        void playerTurn(Gummy& p,Opponent& e);
        void enemyTurn(Gummy& p,Opponent& e);
        int calculateDamage(Character& attacker, Character& target, int baseDamage);
        bool dodge(Character& character);
        void setComplete();
    private:
        //checks when the battle is over so main method can stop
        bool complete;
};

#endif