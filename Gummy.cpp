#include "Gummy.h"
//constructors
Gummy::Gummy(string name,int level,int health, int attack, int defense, int speed, int xp, int xpThreshold, string id)
: Character(name, level, health, attack, defense, speed), xp(xp), xpThreshold(xpThreshold), id(id){}

void Gummy::displayInfo(){
    Character::displayInfo();
    cout << "ID: " << id << endl;
    cout << "XP: " << xp << endl;
    cout << "Xp threshold: " << xpThreshold << endl;
}
//accessors and mutators
string Gummy::getID(){
    return id;
}
void Gummy::setID(string ID){
    id = ID;
}
int Gummy::getXP(){
    return xp;
}
int Gummy::getXpThreshold(){
    return xpThreshold;
}
void Gummy::setXP(int xpValue){
    xp = xpValue;
}

void Gummy::checkXP(){
    //Check if experience is greater than xp threshold
    if(xp >= xpThreshold && getLevel() < 10){
        //Increase level and reset xp
        setLevel(getLevel() + 1);
        xp = 0;
        xpThreshold += getLevel();

        //Increase other stats except stamina
        setAttack(getAttack() + 1);
        setDefense(getDefense() + 1);
        setSpeed(getSpeed() + 1);
        
        setHealth(getHealth() + 10);

        cout << "Congratulations! You leveled up to level " << getLevel() << "!" << endl;
    }else if(getLevel() == 10 && xp == 0){
        cout <<"You have reached the max level of your gummybear! " << getName() << "stats will no longer increase." << endl;
    }
}

