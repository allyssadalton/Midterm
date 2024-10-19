#include "Player.h"
#include <string>
#include <iostream>
#include <ctime> 
using namespace std;


player::~player(){delete[] statsInfo;}


player::player(int *stats){
    statsInfo = new int[6];
    for (int i = 0; i < 6; i++){statsInfo[i] = stats[i];}
}

void player::displayStats(){
    cout << "Health: " << statsInfo[0] << endl;
    cout << "Attack: " << statsInfo[1] << endl;
    cout << "Defense: " << statsInfo[2] << endl;
    cout << "Coins: " << statsInfo[3] << endl;

}

void player::displayCoordinates(){
    cout << "Row " << statsInfo[4] << endl;
    cout << "Spot " << statsInfo[5] << endl;}

void player::setHealth(int h){statsInfo[0] = h;}

void player::setAttack(int att){statsInfo[1] = att;}

void player::setDefense(int d){statsInfo[2] = d;}

void player::setCoins(int c){statsInfo[3] = c;}

void player::setCoordinates(int x, int y){
    statsInfo[4] = x;
    statsInfo[5] = y;
}


void player::increaseHealth(int h){statsInfo[0] += h;}

void player::increaseAttack(int att){statsInfo[1] += att;}

void player::increaseDefense(int d){statsInfo[2] += d;}

void player::increaseCoins(int c){statsInfo[3] += c;}

void player::increaseCoordinates(int x){
    statsInfo[4] += x;
    if (statsInfo[4] > 9){statsInfo[4] = 9;}
}

void player::increaseRow(){
    statsInfo[4] = 0;
    statsInfo[5] += 1;
}

void player::decreaseHealth(int h){statsInfo[0] -= h;}

void player::decreaseAttack(int att){statsInfo[1] -= att;}

void player::decreaseDefense(int d){statsInfo[2] -= d;}

void player::decreaseCoins(int c){statsInfo[3] -= c;}

void player::decreaseCoordinates(){statsInfo[4] = 0;}

void player::foundShop(){
    char response;
    int cost;
    //outputs shop menu
    cout << "You are at a shop." << endl;
    cout << "Here are your stats:" << endl;
    displayStats();
    cout << "Would you like to upgrade your stats?(Y/N) " << endl;
    cin >> response;
    cout << endl;
    //if they want to upgrade
    if (response == 'Y' || response == 'y'){
        //ATTACK UPGRADE
        int attackupgrade; //their response
        cout << "How many levels would you like to increase your attack level?"  << endl;
        cout << "Please type a digit. If you don't want to upgrade, type 0" << endl;
        while (true) { //while loop incase they choose too big of upgrade.
            cin >> attackupgrade;
            cout << endl;
            cost = 0; //this will be reused to calculate the cost of each upgrade
            if (attackupgrade != 0){
                cout << "It will cost ";
                int newattack = statsInfo[1] + attackupgrade; //what their new attack level will be
                for (int i = statsInfo[1]; i < newattack; i++){cost += i;}
                if (cost > statsInfo[3]){
                    cout << cost << " coins. You do not have enough coins." << endl;
                    cout << "Please type a lesser amount of levels you want to upgrade your attack level. " << endl;
                }
                else{
                    cout << cost << " coins. Would you like to upgrade your attack level to ";
                    cout << newattack << " still?(Y/N) " << endl;;
                    cin >> response;
                    cout << endl;
                    if (response == 'Y' || response == 'y'){
                        increaseAttack(newattack);
                        decreaseCoins(cost);
                        //ADD TO STACK 
                        break;
                    }
                    else{
                        cout << "It seems you don't want to upgrade your attack." << endl;
                        break;
                    }
                }
            }
            else{
                cout << "It seems you don't want to upgrade your attack." << endl;
                break;
            }
        } 

        int defenseupgrade; //their response
        cout << "How many levels would you like to increase your defense level?"  << endl;
        cout << "Please type a digit. If you don't want to upgrade, type 0" << endl;
        while (true){ //while loop incase they choose too big of upgrade.
            cin >> defenseupgrade;
            cout << endl;
            cost = 0; //this will be reused to calculate the cost of each upgrade
            if (defenseupgrade != 0){
                cout << "It will cost ";
                int  newdefense = statsInfo[2] + defenseupgrade; //what their new attack level will be
                for (int i = statsInfo[2]; i < newdefense; i++){cost += i;}
                if (cost > statsInfo[3]){
                    cout << cost << " coins. You do not have enough coins." << endl;
                    cout << "Please type a lesser amount of levels you want to upgrade your defense level. " << endl;
                }
                else{
                    cout << cost << " coins. Would you like to upgrade your defense level to ";
                    cout << newdefense << " still?(Y/N) " << endl;
                    cout << endl;
                    cin >> response;
                    if (response == 'Y' || response == 'y'){
                        increaseDefense(newdefense);
                        decreaseCoins(cost);
                        //ADD TO STACK 
                        break;
                    }
                    else{
                        cout << "It seems you don't want to upgrade your defense." << endl;
                        break;
                    }
                }
                
            }
            
        }
    }
}

void player::foundCoins(){
    int coinsFound = rand() % 20 + 5;
    cout << "You found " << coinsFound << " coins!" << endl;
    increaseCoins(coinsFound);
    cout << "You now have " << statsInfo[3] << " coins." << endl;
    //update to stack 
}

void player::foundHazard(){
    int hazard = rand() % 5 + 1;
    int randomOopsies;
    cout << "Uh oh..." << endl;
    if (hazard == 1){
        cout << "You accidentally tripped on a rock and fell down a hole." << endl;
        randomOopsies = rand() % 4 + 1; 
        cout << "You have lost " << randomOopsies << " health." << endl;
        decreaseHealth(randomOopsies);
        cout << "You now have " << statsInfo[0] << " health." << endl;
    }
    else if (hazard == 2){ //this creates a hazard based on row theme
        if (statsInfo[4] == 0){
            cout << "A licorice rope plant stole some of your coins!" << endl;
            decreaseCoins(statsInfo[3]/2);
            cout << "You now have " << statsInfo[3] << " coins." << endl;
        }
        else if (statsInfo[4] == 1){
            cout << "A candy corn rainstorm just happened. You were concussed by the candy corn and lost some health.";
            decreaseHealth(1);
            cout << endl << "You now have " << statsInfo[0] << " health." << endl;
        }
        else if (statsInfo[4] == 2){
            cout << "A jelly bean was thrown at you and knocked your coin pouch out of your hand.";
            cout << "You lost some coins." << endl;
            decreaseCoins(statsInfo[3]/2);
            cout << "You now have " << statsInfo[3] << " coins." << endl;
        }
        else if (statsInfo[4] == 3){
            cout << "A lollipop stick tripped you and you lost some health!" << endl;
            decreaseHealth(1);
            cout << "You now have " << statsInfo[0] << " health." << endl;
        }
        else if (statsInfo[4] == 4){ 
            cout << "You dropped your coin pouch in a taffy pool and some of your coins are stuck in the taffy now!";
            decreaseCoins(statsInfo[3]/2);
            cout << endl << "You now have " << statsInfo[3] << " coins." << endl;  
        }
        else if (statsInfo[4] == 5){
            cout << "You were pelted with marshmallows and lost some health!";
            decreaseHealth(1);
            cout << endl << "You now have " << statsInfo[0] << " health." << endl;
        }
        else if (statsInfo[4] == 6){
            cout << "You experienced a fudge rainstorm. You lost some coins when your coin pouch filled with fudge.";
            decreaseCoins(statsInfo[3]/2);
            cout << endl << "You now have " << statsInfo[3] << " coins." << endl;
            
        }
        else if (statsInfo[4] == 7){
            cout << "A group of gummy gnomes just started a fight with you. You lost some health." << endl;
            decreaseHealth(1);
            cout <<  "You now have " << statsInfo[0] << " health." << endl;
        }
        else if (statsInfo[4] == 8){
            cout << "You tripped over rock candy and spilled your coin pouch!" << endl;
            decreaseCoins(statsInfo[3]/2);
            cout << "You now have " << statsInfo[3] << " coins." << endl;
        }
        else if (statsInfo[4] == 9){
            cout << "You were tripped by cotton candy floss and lost some health!" << endl;
            decreaseHealth(1);
            cout << endl << "You now have " << statsInfo[0] << " health." << endl;
        }
        
    }
    else if (hazard == 3){
        cout << "An invisible force shoved you off the path and casted a spell on you.";
        cout << endl << "You lost some attack power." << endl;
        decreaseAttack(1);
        cout << "You now have " << statsInfo[1] << " attack power." << endl;
    }
    else if (hazard == 4){
        cout << "You were attacked by a ghost and lost some defense power." << endl;
        decreaseDefense(1);
        cout << "You now have " << statsInfo[2] << " defense power." << endl;
    }
    else if (hazard == 5){
        cout << "You were attacked by a ghost and a grelim! You lost some health, attack power, and defense power!";
        decreaseHealth(1);
        decreaseAttack(1);
        decreaseDefense(1);
        cout << endl << "You now have " << statsInfo[0] << " health." << endl;
        cout << "You now have " << statsInfo[1] << " attack power." << endl;
        cout << "You now have " << statsInfo[2] << " defense power." << endl;
    }
    //update to stack 
}

int player::getHealth(){return statsInfo[0];}
int player::getAttack(){return statsInfo[1];}
int player::getDefense(){return statsInfo[2];}
int player::getColumn(){return statsInfo[6];}
int player::getRow(){return statsInfo[5];}
