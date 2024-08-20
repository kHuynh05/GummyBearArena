#include <iostream>
#include "Character.cpp"
#include "Menu.cpp"
#include "Gummy.cpp"
#include "Opponent.cpp"
#include "Battle.cpp"
#include "SaveLoad.cpp"
#include <iostream>

using namespace std;

int main()
{
    //initates all the classes and variables hat are needed to run
    Menu menu;
    menu.displayStartMenu();
    int choice;
    cin >> choice;
    bool gameRunning = true;
    Gummy *g = nullptr;    // Declare g as a pointer and initialize it to nullptr
    Opponent *x = nullptr; // Declare x as a pointer and initialize it to nullptr
    int l, h, a, d, s;
    bool win = true;
    Battle battle1;
    string filename;
    switch (choice)
    {
    case 1://starting a new game
    {
        cout << "Starting new game..." << endl
             << endl;
        string name;
        cout << "Enter a name for your gummy:" << endl;
        cin >> name;
        cout << "----------------------------------------------------------------" << endl;
        g = new Gummy(name, 1, 10, 1, 1, 1, 0, 1, "1"); // Dynamically allocate memory for g
        g->displayInfo();
        cout << "----------------------------------------------------------------" << endl;
        while (gameRunning)//runs the game till gameRunning is false
        {
            cout << endl;
            menu.displayMainMenu();
            int mainChoice;
            cin >> mainChoice;
            cout << endl;
            //main menu pops up and now this is where the player is able to choose to challnege gym or fight one enemy to level up
            switch (mainChoice)
            {
            case 1:
                //creates stats based off the player's stats
                l = g->getLevel() - 1 + (rand() % 2);
                h = g->getHealth() - 5 + (rand() % 10);
                a = g->getAttack() - 1 + (rand() % 2);
                d = g->getDefense() - 1 + (rand() % 2);
                s = g->getSpeed() - 1 + (rand() % 2);
                x = new Opponent("Enemy", l, h, a, d, s, "2");
                battle1.battle(*g, *x); // Call battle() on the battle1 object
                battle1.setComplete();
                //checks xp and set health and stamina back to normal
                g->checkXP();
                g->setStamina(10);
                g->setHealth(g->getLevel() * 10);
                break;
            case 2:
            // challenging the gym
            //player will go on till they lose
            // creates 3 enemies with increasing stats
                if (win == true)
                {
                    x = new Opponent("Sugar Cookie", 3, 30, 3, 3, 3, "2"); // Dynamically allocate memory for x
                    win = battle1.battle(*g, *x);
                    battle1.setComplete();
                    g->setStamina(10);
                    g->checkXP();
                    g->setHealth(g->getLevel() * 10);
                }
                else
                {
                    cout << "You lost against the gym! Come back when you're stronger!";
                }
                if (win == true)
                {
                    x = new Opponent("Donut", 6, 60, 6, 6, 6, "2");
                    win = battle1.battle(*g, *x);
                    battle1.setComplete();
                    g->checkXP();
                    g->setStamina(10);
                    g->setHealth(g->getLevel() * 10);
                }
                else
                {
                    cout << "You lost against the gym! Come back when you're stronger!";
                }
                if (win == true)
                {
                    x = new Opponent("Human", 10, 100, 10, 10, 10, "2");
                    win = battle1.battle(*g, *x);
                    battle1.setComplete();
                    g->checkXP();
                    g->setStamina(10);
                    g->setHealth(g->getLevel() * 10);
                }
                else
                {
                    cout << "You lost against the gym! Come back when you're stronger!";
                }
                win = true;
                break;
            case 3:
                g->displayInfo();
                break;
            case 4:
                filename = "savedGame.txt";
                SaveLoad::saveGame(filename, *g);
                cout << "Exiting the game. Goodbye!" << endl;
                gameRunning = false;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
        }
        delete g; // Don't forget to delete dynamically allocated memory when no longer needed
        delete x;
        break;
    }
    case 2:
    //this loades the prvious game and then just does everything which is done above when it is a new gmae
    {
        cout << "Loading previous game..." << endl;
        g = new Gummy("", 1, 10, 1, 1, 1, 0, 10, "1"); // Dynamically allocate memory for g
        SaveLoad::loadGame("savedGame.txt", *g);

        while (gameRunning)
        {
            menu.displayMainMenu();
            int mainChoice;
            cin >> mainChoice;

            switch (mainChoice)
            {
            case 1:
                l = g->getLevel() - 1 + (rand() % 2);
                h = g->getHealth() - 5 + (rand() % 10);
                ;
                a = g->getAttack() - 1 + (rand() % 2);
                d = g->getDefense() - 1 + (rand() % 2);
                s = g->getSpeed() - 1 + (rand() % 2);
                x = new Opponent("Ken", l, h, a, d, s, "2");
                battle1.battle(*g, *x);
                battle1.setComplete();
                g->setStamina(10);
                g->checkXP();
                g->setHealth(g->getLevel() * 10);
                break;
            case 2:
                if (win == true)
                {
                    x = new Opponent("Ken", 3, 30, 3, 3, 3, "2"); // Dynamically allocate memory for x
                    win = battle1.battle(*g, *x);
                    battle1.setComplete();
                    g->setStamina(10);
                    g->checkXP();
                    g->setHealth(g->getLevel() * 10);
                }
                else
                {
                    cout << "You lost against the gym! Come back when you're stronger!";
                }
                if (win == true)
                {
                    x = new Opponent("Rich", 6, 60, 6, 6, 6, "2");
                    win = battle1.battle(*g, *x);
                    battle1.setComplete();
                    g->setStamina(10);
                    g->checkXP();
                    g->setHealth(g->getLevel() * 10);
                }
                else
                {
                    cout << "You lost against the gym! Come back when you're stronger!";
                }
                if (win == true)
                {
                    x = new Opponent("Kenrich", 10, 100, 10, 10, 10, "2");
                    win = battle1.battle(*g, *x);
                    battle1.setComplete();
                    g->setStamina(10);
                    g->checkXP();
                    g->setHealth(g->getLevel() * 10);
                }
                else
                {
                    cout << "You lost against the gym! Come back when you're stronger!";
                }
                win = true;
                break;
            case 3:
                g->displayInfo();
                break;
            case 4:
                filename = "savedGame.txt";
                SaveLoad::saveGame(filename, *g);
                cout << "Exiting the game. Goodbye!" << endl;
                gameRunning = false;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
            }
        }
        delete g; // delete dynamically allocated memory when no longer needed
        delete x;
        break;
    }
    case 3:
        //displays info of character
        g->displayInfo();
        break;
    case 4:
        //this is to save the game whenever the player exits
        filename = "savedGame.txt";
        SaveLoad::saveGame(filename, *g);
        cout << "Exiting the game. Goodbye!" << endl;
        gameRunning = false;
        break;
    default:
        cout << "Invalid choice. Please enter a valid option." << endl;
        break;
    }
    return 0;
}