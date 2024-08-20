#include "Battle.h"
#include <iostream>

using namespace std;
// constructor
Battle::Battle()
{
    complete = false;
}

void Battle::setComplete(){
    complete = false;
}
// actual battle
bool Battle::battle(Gummy &player, Opponent &enemy)
{
    //displays infor of player and enemy
    player.displayInfo();
    cout << endl;
    enemy.displayInfo();
    cout << endl;
    
    while (!complete)
    {
       
        // Check who's faster to see who attacks first; this is dependent on speed
        // player speed is faster so will attack first
        if (player.getSpeed() > enemy.getSpeed())
        {
            cout << player.getName() << " is faster than " << enemy.getName() << endl << endl;
            //player's turn commences here
            playerTurn(player, enemy);
            //print out stamina so player know's how much stmains they have left
            cout << "You have " << player.getStamina() << " stamina." << endl;
            cout << endl;
            //checks if enemy's health is less than 0 to check for win condition
            if (enemy.getHealth() <= 0)
            {
                //increase the player xp by enemy level and delete the enemy
                //also set the player speed back to original speed
                cout << "You win!" << endl;
                player.setXP(player.getXP() + enemy.getLevel());
                delete &enemy;
                complete = true;
                player.setSpeed(player.getLevel());
                return true;
            }
            //enemy's turn commences here
            enemyTurn(player, enemy);
                //check's if player's health is lower than 0 for lose condition
                if (player.getHealth() <= 0)
                {
                    cout << "You lose!" << endl;
                    player.setHealth(player.getLevel() * 10);
                    complete = true;
                    player.setSpeed(player.getLevel());
                    return false;
                }
            //after each round, print out the enemy and player's health
            cout << endl;
            cout << player.getName() << "'s health: " << player.getHealth() << endl;
            cout << enemy.getName() << "'s health: " << enemy.getHealth() << endl << endl;
            cout << " ------------------------------------------------" << endl;
        }
        // same case but for enemy being faster
        else if (player.getSpeed() < enemy.getSpeed())
        {
            cout << enemy.getName() << " is faster than " << player.getName() << endl << endl;
            enemyTurn(player, enemy);
            cout << endl;
            if (player.getHealth() <= 0)
            {
                cout << "You lose!" << endl;
                player.setHealth(player.getLevel() * 10);
                complete = true;
                player.setSpeed(player.getLevel());
                return false;
            }
            playerTurn(player, enemy);
            if (enemy.getHealth() <= 0)
            {
                cout << "You win!" << endl;
                player.setXP(player.getXP() + enemy.getLevel());
                delete &enemy;
                complete = true;
                player.setSpeed(player.getLevel());
                return true;
            }
            cout << "You have " << player.getStamina() << " stamina." << endl;
            cout << endl;
            cout << player.getName() << "'s health: " << player.getHealth() << endl;
            cout << enemy.getName() << "'s health: " << enemy.getHealth() << endl << endl;
            cout << " ------------------------------------------------" << endl;
            
        }
        // enemy speed and player speed is the same so will randomly decide
        else
        {
            int random = rand() % 2;
            if (random == 0)
            {
                cout << player.getName() << " put a little effort in and went faster than " << enemy.getName() << endl << endl;
                playerTurn(player, enemy);
                cout << "You have " << player.getStamina() << " stamina." << endl;
                cout << endl;
                if (enemy.getHealth() <= 0)
                {
                    cout << "You win!" << endl;
                    player.setXP(player.getXP() + enemy.getLevel());
                    delete &enemy;
                    complete = true;
                    player.setSpeed(player.getLevel());
                    return true;
                }
                enemyTurn(player, enemy);
                if (player.getHealth() <= 0)
                {
                    cout << "You lose!" << endl;
                    player.setHealth(player.getLevel() * 10);
                    complete = true;
                    player.setSpeed(player.getLevel());
                    return false;
                }
                cout << endl;
                cout << player.getName() << "'s health: " << player.getHealth() << endl;
                cout << enemy.getName() << "'s health: " << enemy.getHealth() << endl << endl;
                cout << " ------------------------------------------------" << endl;
            }
            else
            {
                cout << enemy.getName() << " put a little effort in and went faster than " << player.getName() << endl << endl;
                enemyTurn(player, enemy);
                if (player.getHealth() <= 0)
                {
                    cout << "You lose!" << endl << endl;
                    player.setHealth(player.getLevel() * 10 + 100);
                    complete = true;
                    player.setSpeed(player.getLevel());
                    return false;
                }
                cout << endl;
                playerTurn(player, enemy);
                if (enemy.getHealth() <= 0)
            {
                cout << "You win!" << endl;
                player.setXP(player.getXP() + enemy.getLevel());
                delete &enemy;
                complete = true;
                player.setSpeed(player.getLevel());
                return true;
            }
                cout << "You have " << player.getStamina() << " stamina." << endl;
                cout << endl;
                cout << player.getName() << "'s health: " << player.getHealth() << endl;
                cout << enemy.getName() << "'s health: " << enemy.getHealth() << endl << endl;
                cout << " ------------------------------------------------" << endl;
            }
        }
    }
    return true;
}

// functions used to manage the battle
void Battle::playerTurn(Gummy &player, Opponent &enemy)
{
    cout << "Your turn! Choose an action by typing the number!" << endl;
    cout << " ------------------------------------------------" << endl;
    cout << "|1.GummyJab              |2.GumDrop Grenade      |" << endl;
    cout << "|(2 ⚡, 1 attack)        | (3 ⚡, 3 attack)      |" << endl;
    cout << "|------------------------------------------------|" << endl;
    cout << "|3.SugarySurge           |4.Run (coward)         |" << endl;
    cout << "| (+1 speed)             |                       |" << endl;
    cout << " ------------------------------------------------" << endl;
    int choice;
    cin >> choice;
    cout << endl;
    //checks if choice is a valid choice
    while (!(choice == 1 || choice == 2 || choice == 3 || choice == 4))
    {
        // checks if they have enough stamina to use move 2
        if(choice == 2){
            if(!(player.getStamina() >= 3)){
                cout << "Enter a valid choice:" ;
                cin >> choice;
            }
        }else{
            cout << "Enter a valid choice:" ;
            cin >> choice;
        }
    }
    //first checks if the enemy dodged the move, if so move on
    if (dodge(enemy)){
        cout << enemy.getName() << " dodged the attack!" << endl;
    }else{
        switch (choice)
        {
        //different cases are all the different moves
        case 1:
            if (player.getStamina() < 2)
            {
                cout << "Not enough Stamina to use Gummy Jab" << endl;
                break;
            }
            cout << ". .∧＿∧   ∧_∧." << endl;
            cout << "(  `・ω・)つ)゜Д゜)・゜" << endl;
            cout << "(つ　   ｒ⊂　⊂)'" << endl;
            cout << "｜　 _つ ⊂_⊂ノ" << endl;
            cout << "`し´" << endl;
            calculateDamage(player, enemy, 1);
            player.setStamina(player.getStamina() - 1);
            break;
        case 2:
            if (player.getStamina() < 3)
            {
                cout << "Not enough Stamina to use GumDrop Grenade" << endl;
                break;
            }
        cout << "       .-^^---....,,--       " << endl;
        cout << "  _--                  --_  " << endl;
        cout << "<                        >)" << endl;
        cout << "|                         | " << endl;
        cout << " \._                   _./  " << endl;
        cout << "    ```--. . , ; .--'''  " << endl; 
        cout << "           | |   |        ∧＿∧　♪" << endl;    
        cout << "        .-=||  | |=-.    ∩・ω・）" << endl;
        cout << "        `-=#$%&%$#=-'    |    ⊂ﾉ" << endl;
        cout << "           | ;  :|       |    _⊃   ♪" << endl;
        cout << "  _____.,-#%&$@%#&#~,.____し⌒  " << endl;
            calculateDamage(player, enemy, 3);
            player.setStamina(player.getStamina() - 3);
            break;
        case 3:
            player.setSpeed(player.getSpeed() + 1);
            cout << "You used Sugary Surge! Speed increased by 1" << endl;
            break;
        case 4:
            cout << "You ran away from the battle!" << endl;
            complete = true;
            break;
        }
    }
    //keeps stamina locked at 10
    if(player.getStamina() <= 10){
        player.setStamina(player.getStamina() + player.getLevel());
        if(player.getStamina() > 10){
            player.setStamina(10);
        }
    }
    
    cout << endl;
}
//enemy's turn that randomly chooses one of the abilities above
void Battle::enemyTurn(Gummy &player, Opponent &enemy)
{
    cout << enemy.getName() << "'s turn!" << endl;
    if (dodge(player)){
        cout << player.getName() << " dodged the attack!" << endl;
    }else
    {
        int r = rand() % 3;
        switch (r)
        {
        case 0:
            calculateDamage(enemy, player, 1);
            break;
        case 1:
            calculateDamage(enemy, player, 3);
            break;
        case 2:
            enemy.setSpeed(enemy.getSpeed() + 1);
            cout << "Enemy speed increased to " << enemy.getSpeed() << endl;
            break;
        }
    }
    cout << endl;
}
//calculates the damage between the player and enemy
int Battle::calculateDamage(Character &attacker, Character &target, int baseDamage)
{
    int damage = (attacker.getAttack() * attacker.getLevel()) / target.getLevel() * baseDamage;
    target.setHealth(target.getHealth() - damage);
    cout << attacker.getName() << " attacked " << target.getName() << " for " << damage << " damage!" << endl;
    cout << endl;
    return damage;
}
//dodge function
bool Battle::dodge(Character &Character)
{   
    int dodgeChance = rand() % 100;
    if (Character.getSpeed() > dodgeChance)
    {
        return true;
    }
    return false;
}
