#include "SaveLoad.h"
#include <fstream>

using namespace std;
//save and load function
void SaveLoad::saveGame(string& filename, Gummy& gummy) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for writing." << endl;
        return;
    }

    // Write character attributes to the file
    file << "Name: " << gummy.getName() << endl;
    file << "Level: " << gummy.getLevel() << endl;
    file << "Health: " << gummy.getHealth() << endl;
    file << "Attack: " << gummy.getAttack() << endl;
    file << "Defense: " << gummy.getDefense() << endl;
    file << "Speed: " << gummy.getSpeed() << endl;
    file << "XP: " << gummy.getXP() << endl;
    file << "XPT: " << gummy.getXpThreshold() << endl;
    file << "ID: " << gummy.getID() << endl;

    file.close();

    cout << "Game saved successfully." << endl;
}

void SaveLoad::loadGame(string filename, Gummy& gummy) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Could not open file for reading." << endl;
        return;
    }

    string name, temp, id, h;
    int level, health, attack, defense, speed, stamina, xp, xpThreshold;
    while (file >> temp) {
        if (temp == "Name:") {
            getline(file, name);
        } else if (temp == "Level:") {
            file >> level;
        } else if (temp == "Health:") {
            file >> health;
        } else if (temp == "Attack:") {
            file >> attack;
        } else if (temp == "Defense:") {
            file >> defense;
        } else if (temp == "Speed:") {
            file >> speed;
        } else if (temp == "XP:") {
            file >> xp;
        } else if (temp == "XPT:") {
            file >> xpThreshold;
        }else if (temp == "ID:") {
            file >> id;
        }
    }

    // Construct the Gummy object with the retrieved data
    gummy = Gummy(name, level, health, attack, defense, speed, xp, xpThreshold, id);
    cout << "Loaded character information:" << endl;
    gummy.displayInfo();
}