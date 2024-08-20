#include "Menu.h"
#include <iostream>

using namespace std;
Menu::Menu(){}
//simply prints out the menu
void Menu::displayStartMenu(){
    cout << "Welcome to the Gummy Bear Adventure Game!" << endl;
    cout << "1. Start New Game" << endl;
    cout << "2. Load Previous Game" << endl;
    cout << "3. See stats" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}
void Menu::displayMainMenu() {
    cout << "Main Menu" << endl;
    cout << "1. Roam the Sugar Land" << endl;
    cout << "2. Challenge the Gym" << endl;
    cout << "3. See stats" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}