#include "Character.h"
#include <iostream>

using namespace std;

Character::Character(string name, int level, int health, int attack, int defense, int speed){
    this->name = name;
    this->level = level;
    this->health = health;
    this->attack = attack;
    this->defense = defense;
    this->speed = speed;
    this->stamina = 10;
}

string Character::getName(){
    return name;
}

int Character::getLevel(){
    return level;
}

int Character::getHealth(){
    return health;
}

int Character::getAttack(){
    return attack;
}

int Character::getDefense(){
    return defense;
}

int Character::getSpeed(){
    return speed;
}

int Character::getStamina(){
    return stamina;
}

void Character::setName(string name){
    this->name = name;
}

void Character::setLevel(int level){
    this->level = level;
}

void Character::setHealth(int health){
    this->health = health;
}

void Character::setAttack(int attack){
    this->attack = attack;
}

void Character::setDefense(int defense){
    this->defense = defense;
}

void Character::setSpeed(int speed){
    this->speed = speed;
}

void Character::setStamina(int stamina){
    this->stamina = stamina;
}

void Character::displayInfo(){
    cout << "Name: " << name << "\nLevel: " << level << "\nHealth: " << health << "\nAttack: " << attack << "\nDefense: " << defense << "\nSpeed: " << speed << endl;
}

Character::~Character(){}