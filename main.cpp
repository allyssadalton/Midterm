#include <queue>
#include <array>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <string>
#include <iostream>
#include "CandyMonsters.h"
#include "CandyMonsters.cpp"
#include "Map.h"
#include "Map.cpp"
#include "Player.h"
#include "Player.cpp"

using namespace std;

//creates random number for dice roll
int rollDice() {
    return rand() % 6 + 1; // Roll a 6-sided die
}



int main(){
    //creates monsters
    CandyMonster licorice("Licorice Lizard", 10, 4, 4);
    CandyMonster candycorn("Corn Clown", 10, 5, 5);
    CandyMonster jelly("Jelly Bean Giant", 10, 6, 6);
    CandyMonster lollipop("Lollipop Lalaloopsie", 10, 7, 7);
    CandyMonster taffy("Taffy Toddler", 10, 8, 8);
    CandyMonster marshmallow("Stay Puft Marshmallow Man", 10, 9, 9);
    CandyMonster fudge("Fudgenator", 10, 10, 10);
    CandyMonster gummy("Gummy Bear Goblin", 10, 11, 11);
    CandyMonster rockcandy("Rock Reaper", 10, 12, 12);
    CandyMonster cottoncandy("Candyfloss Phantom", 10, 13, 13);
    CandyMonster candylord("Candy Lord", 10, 15, 15);

    //creates players & their stats
    int stats[] = {10, 1, 1, 10, 0, 0};
    player p1(stats);
    player p2(stats);
    p1.setHealth(10);
    p1.setAttack(1);
    p1.setDefense(1);
    p1.setCoins(10);
    p1.setCoordinates(0,0);
    p2.setHealth(10);
    p2.setAttack(1);
    p2.setDefense(1);
    p2.setCoins(10);
    p2.setCoordinates(0,0);


    /*
    UPDATE STACK AND SEND TO TEXT FILE
    ASK IF THE PLAYER WANTS TO LOAD THEIR GAME FROM THE LAST SAVED FILED
    UPLOAD FILE TO STACK 
    AND USE TOP OF STACK AS CURRENT PLAYER STATS
    */

    int dice;
    int coord; //coordinates
    
    //first turn
    cout << "Here are Player 1's stats: " << endl;
    p1.displayStats();
    cout << endl << endl;
    cout << "Here are Player 2's stats: " << endl;
    p2.displayStats();

    //player 1 turn 1 
    cout << "Player 1, it's your turn!" << endl;
    p1.foundShop();
    dice = rollDice();
    cout << "You rolled a " << dice << "!" << endl;
    p1.increaseCoordinates(dice);
    coord = p1.getCoordinates();
    //checks position for S C or H
    if (coord % 3 == 0){p1.foundShop();}
    else if (coord % 3 == 1){p1.foundCoins();}
    else if (coord % 3 == 2){p1.foundHazard();}

    //player 2 turn 1
    cout << "Player 2, it's your turn!" << endl;
    p2.foundShop();
    dice = rollDice();
    cout << "You rolled a " << dice << "!" << endl;
    p2.increaseCoordinates(dice);
    coord = p2.getCoordinates();
    //checks position for S C or H
    if (coord % 3 == 0){p2.foundShop();}
    else if (coord % 3 == 1){p2.foundCoins();}
    else if (coord % 3 == 2){p2.foundHazard();}
    
    
    //actual game play
    while (true){
        int dice;
        int attacklikelyhood;
        cout << "Player 1, it's your turn!" << endl;
        dice = rollDice();
        cout << "You rolled a " << dice << "!" << endl;
        if (coord == 9){
            cout << "You have reached the portal to the ";
            if (p1.getRow() == 0){
                cout << "next row, the row of the Candy Corn. However, you must defeat the Licorice Lizard first!" << endl;
                licorice.displayInfo();
                if (p1.getHealth() >= licorice.getHealth() && p1.getAttack() >= licorice.getAttack() && p1.getDefense() >= licorice.getDefense()){
                    cout << "All of your stats are higher than the Licorice Lizards! The Licorice Lizard retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && licorice.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Licorice Lizard!" << endl;
                            licorice.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Licorice Lizard attacked you!" << endl;
                            p1.decreaseHealth(licorice.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                licorice.resetHealth();
            }
                
            else if (p1.getRow() == 1){
                cout << "next row, the row of the Jelly Bean. However, you must defeat the Corn Clown first!" << endl;
                    candycorn.displayInfo();
                if (p1.getHealth() >= candycorn.getHealth() && p1.getAttack() >= candycorn.getAttack() && p1.getDefense() >= candycorn.getDefense()){
                    cout << "All of your stats are higher than the Candy Clown! The Candy Clown retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && candycorn.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Candy Clown!" << endl;
                                candycorn.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Candy Clown attacked you!" << endl;
                            p1.decreaseHealth(candycorn.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                candycorn.resetHealth();
            }
                
            else if (p1.getRow() == 2){
                cout << "next row, the row of the Lollipop. However, you must defeat the Jelly Bean Giant first!" << endl;
                    jelly.displayInfo();
                if (p1.getHealth() >= jelly.getHealth() && p1.getAttack() >= jelly.getAttack() && p1.getDefense() >= jelly.getDefense()){
                    cout << "All of your stats are higher than the Jelly Bean Giant! The Jelly Bean Giant retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && jelly.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Jelly Bean Giant!" << endl;
                                jelly.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Jelly Bean Giant attacked you!" << endl;
                            p1.decreaseHealth(jelly.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                jelly.resetHealth();
            }
                
            else if (p1.getRow() == 3){
                cout << "next row, the row of the Taffy. However, you must defeat the Lollipop Lalaloopsie first!" << endl;
                    lollipop.displayInfo();
                if (p1.getHealth() >= lollipop.getHealth() && p1.getAttack() >= lollipop.getAttack() && p1.getDefense() >= lollipop.getDefense()){
                    cout << "All of your stats are higher than the Lollipop Lalaloopsie! The Lollipop Lalaloopsie retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && lollipop.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Lollipop Lalaloopsie!" << endl;
                                lollipop.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Lollipop Lalaloopsie attacked you!" << endl;
                            p1.decreaseHealth(lollipop.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                lollipop.resetHealth();
            }
                
            else if (p1.getRow() == 4){
                cout << "next row, the row of the Marshmallow. However, you must defeat the Taffy Toddler first!" << endl;
                    taffy.displayInfo();
                if (p1.getHealth() >= taffy.getHealth() && p1.getAttack() >= taffy.getAttack() && p1.getDefense() >= taffy.getDefense()){
                    cout << "All of your stats are higher than the Taffy Toddler! The Taffy Toddler retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && taffy.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Taffy Toddler!" << endl;
                                taffy.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Taffy Toddler attacked you!" << endl;
                            p1.decreaseHealth(taffy.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                taffy.resetHealth();
            }
                
            else if (p1.getRow() == 5){
                cout << "next row, the row of the Fudge. However, you must defeat the Stay Puft Marshmallow Man first!" << endl;
                    marshmallow.displayInfo();
                if (p1.getHealth() >= marshmallow.getHealth() && p1.getAttack() >= marshmallow.getAttack() && p1.getDefense() >= marshmallow.getDefense()){
                    cout << "All of your stats are higher than the Stay Puft Marshmallow Man! The Stay Puft Marshmallow Man retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && marshmallow.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Stay Puft Marshmallow Man!" << endl;
                                marshmallow.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Stay Puft Marshmallow Man attacked you!" << endl;
                            p1.decreaseHealth(marshmallow.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }  
                marshmallow.resetHealth();
            }
                
            else if (p1.getRow() == 6){
                cout << "next row, the row of the Gummy Bear. However, you must defeat the Fudgenator first!" << endl;
                    fudge.displayInfo();
                if (p1.getHealth() >= fudge.getHealth() && p1.getAttack() >= fudge.getAttack() && p1.getDefense() >= fudge.getDefense()){
                    cout << "All of your stats are higher than the Fudgenator! The Fudgenator retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && fudge.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Fudgenator!" << endl;
                                fudge.decreaseHealth(p1.getAttack()/2);
                        }
                        else{
                            cout << "The Fudgenator attacked you!" << endl;
                            p1.decreaseHealth(fudge.getAttack()/2);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                fudge.resetHealth();
            }
                
            else if (p1.getRow() == 7){
                cout << "next row, the row of the Rock Candy. However, you must defeat the Gummy Bear Goblin first!" << endl;
                    gummy.displayInfo();
                if (p1.getHealth() >= gummy.getHealth() && p1.getAttack() >= gummy.getAttack() && p1.getDefense() >= gummy.getDefense()){
                    cout << "All of your stats are higher than the Gummy Bear Goblin! The Gummy Bear Goblin retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && gummy.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Gummy Bear Goblin!" << endl;
                                gummy.decreaseHealth(p1.getAttack()/3);
                        }
                        else{
                            cout << "The Gummy Bear Goblin attacked you!" << endl;
                            p1.decreaseHealth(gummy.getAttack()/3);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                gummy.resetHealth();
            }
                
            else if (p1.getRow() == 8){
                cout << "next row, the row of the Cotton Candy. However, you must defeat the Rock Reaper first!" << endl;
                    rockcandy.displayInfo();
                if (p1.getHealth() >= rockcandy.getHealth() && p1.getAttack() >= rockcandy.getAttack() && p1.getDefense() >= rockcandy.getDefense()){
                    cout << "All of your stats are higher than the Rock Reaper! The Rock Reaper retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && rockcandy.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Rock Reaper!" << endl;
                                rockcandy.decreaseHealth(p1.getAttack()/3);
                        }
                        else{
                            cout << "The Rock Reaper attacked you!" << endl;
                            p1.decreaseHealth(rockcandy.getAttack()/3);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                rockcandy.resetHealth();
            }

            else if (p1.getRow() == 9){
                cout << "Candy Castle! However, you must defeat the Candyfloss Phantom first!" << endl;
                    cottoncandy.displayInfo();
                if (p1.getHealth() >= cottoncandy.getHealth() && p1.getAttack() >= cottoncandy.getAttack() && p1.getDefense() >= cottoncandy.getDefense()){
                    cout << "All of your stats are higher than the Candyfloss Phantom! The Candyfloss Phantom retreated.";
                    cout << endl << "You win!" << endl;
                }
                else {
                    while (p1.getHealth() != 0 && cottoncandy.getHealth() != 0){
                        attacklikelyhood = rand() % 10 + 1;
                        if (attacklikelyhood < p1.getAttack()){
                            cout << "You attacked the Candyfloss Phantom!" << endl;
                                cottoncandy.decreaseHealth(p1.getAttack()/3);
                        }
                        else{
                            cout << "The Candyfloss Phantom attacked you!" << endl;
                            p1.decreaseHealth(cottoncandy.getAttack()/3);
                        }
                    }
                    if (p1.getHealth() == 0){
                        cout << "You lost!" << endl;
                        cout << "You have to go back to the start of the row!" << endl;
                        p1.setCoordinates(0, p1.getRow());
                    }
                    else{ 
                        cout << "You won!" << endl;
                        p1.setHealth(10);
                        p1.increaseRow();
                    }
                }
                cottoncandy.resetHealth();
            }
        }
        else if (coord % 3 == 0){p1.foundShop();}
        else if (coord % 3 == 1){p1.foundCoins();}
        else if (coord % 3 == 2){p1.foundHazard();}
        
        
    }

    return 0;
};
