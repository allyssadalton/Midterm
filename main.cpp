#include <queue>
#include <array>
#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "CandyMonsters.h"
#include "CandyMonsters.cpp"
#include "Player.h"
#include "Player.cpp"
#include "Player1Stack.h"
#include "Player1Stack.cpp"
#include "Player2Stack.h"
#include "Player2Stack.cpp"
#include "PlayerQueue.h"
#include "PlayerQueue.cpp"

using namespace std;

//creates random number for dice roll
int rollDice() {return rand() % 6 + 1; }

int main(){
    //creates stack instances
    LinkedListStack1 p1stack;
    LinkedListStack2 p2stack;

    //queue
    PlayerQueue q;
    q.enqueue("Player 1");
    q.enqueue("Player 2");

    //player p1;
    //player p2;

    cout << "If you'd like to end the game, type 'E' at any prompt asking you if you want your stats displayed!" << endl;
    cout << endl;
    cout << endl;
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


    int dice;
    int coord; //coordinates
    int stats[] = {10, 1, 1, 10, 0, 0};
    player p1(stats);
    player p2(stats);

    //Asks if the player wants to load their stats
    while (true){ //incase they give invalid response
        char load;
        if (!p1stack.isEmpty()){
            cout << "Do you have a saved file you want to load for the players? (Y/N) " << endl;
            cout << endl;
            cin >> load;
        }
        else{
            load = 'N';
        }
        if (load == 'Y' || load == 'y'){
            //LOADS UP STACK
            p1stack.loadFromFile();
            int stats[6] = {p1stack.pop(), p1stack.pop(), p1stack.pop(), p1stack.pop(), p1stack.pop(), p1stack.pop()};
            p1.setHealth(stats[0]);
            p1.setAttack(stats[1]);
            p1.setDefense(stats[2]);
            p1.setCoins(stats[3]);
            p1.setCoordinates(stats[4],stats[5]);

            p2stack.loadFromFile();
            p2.setHealth(p2stack.pop());
            p2.setAttack(p2stack.pop());
            p2.setDefense(p2stack.pop());
            p2.setCoins(p2stack.pop());
            p2.setCoordinates(p2stack.pop(),p2stack.pop());

            //displays stats
            cout << "Here are Player 1's stats: " << endl;
            p1.displayStats();
            cout << endl;
            cout << "Here are Player 2's stats: " << endl;
            p2.displayStats();
            cout << endl;
            cout << endl;
            break;
        }

        else if (load == 'N' || load == 'n'){
            //creates players & their stats
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

            //displays stats 
            cout << "Here are Player 1's stats: " << endl;
            p1.displayStats();
            cout << endl;
            cout << endl;
            cout << "Here are Player 2's stats: " << endl;
            p2.displayStats();
            cout << endl;
            cout << endl;

            //player 1 turn 1 
            cout << endl;
            cout << "Player 1, it's your turn!" << endl;
            cout << endl;
            p1.foundShop();
            cout << endl;
            cout << endl;
            dice = rollDice();
            cout << "You rolled a " << dice << "!" << endl;
            p1.increaseCoordinates(dice);
            coord = p1.getColumn();
            cout << endl;
            //checks position for S C or H
            if (coord % 3 == 0){p1.foundShop();}
            else if (coord % 3 == 1){p1.foundCoins();}
            else if (coord % 3 == 2){p1.foundHazard();}
            cout << endl;
            p1stack.push(p1.getRow());
            p1stack.push(p1.getColumn());
            p1stack.push(p1.getDefense());
            p1stack.push(p1.getAttack());
            p1stack.push(p1.getHealth());
            //player 2 turn 1
            cout << "Player 2, it's your turn!" << endl;
            cout << endl;
            p2.foundShop();
            cout << endl;
            cout << endl;
            dice = rollDice();
            cout << "You rolled a " << dice << "!" << endl;
            p2.increaseCoordinates(dice);
            coord = p2.getColumn();
            cout << endl;
            //checks position for S C or H
            if (coord % 3 == 0){p2.foundShop();}
            else if (coord % 3 == 1){p2.foundCoins();}
            else if (coord % 3 == 2){p2.foundHazard();}
            break;
        }
        else{
            cout << "That is an invalid response. You should type Y or N." << endl;
            cout << endl;
            continue;
        }
    }

    //actual game play
    while (true){
        int dice;
        char yn;
        int attacklikelyhood;
        cout << endl;
        if (!q.isEmpty()) {
            string currentPlayer = q.dequeue();
            cout << currentPlayer << "'s turn!" << endl;
            q.enqueue(currentPlayer);
        }
        cout << endl;
        cout << "Would you like to see your stats?(Y/N) " << endl;
        cin >> yn;
        cout << endl;
        cout << endl;
        if (yn == 'E' || yn == 'e'){break;}
        if (yn == 'Y' || yn == 'y'){
            p1.displayStats();
            p1.displayCoordinates();
             cout << endl;
            cout << endl;
        }
        else if (yn == 'N' || yn == 'n'){cout << "Okay!";}
        else {
            cout << "Please type Y or N next time. Here are your stats anyways" << endl;
            p1.displayStats();
            p1.displayCoordinates();
            cout << endl;
            cout << endl;
        }
        if (p1.getHealth() == 0){
            cout << "Your health is 0! You have to go back to the start of the row." << endl;
            p1.setHealth(10);
            p1.setCoordinates(0, p1.getRow());
        } 
        else{
            dice = rollDice();
            p1.increaseCoordinates(dice);
            cout << "You rolled a " << dice << "!" << endl;
        }
        cout << endl;
        
        if (p1.getColumn() == 9){
            cout << "You have reached the portal to the ";
            if (p1.getRow() == 0){
                cout << "next row, the row of the Candy Corn. However, you must defeat the Licorice Lizard first!" << endl;
                licorice.displayInfo();
                if (p1.getHealth() >= licorice.getHealth() && p1.getAttack() >= licorice.getAttack() && p1.getDefense() >= licorice.getDefense()){
                    cout << "All of your stats are higher than the Licorice Lizards! The Licorice Lizard retreated.";
                    cout << endl << "You win!" << endl;
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && licorice.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && candycorn.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && jelly.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && lollipop.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && taffy.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && marshmallow.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && fudge.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && gummy.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && rockcandy.getHealth() > 0){
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
                    p1.setHealth(10);
                    p1.increaseRow();
                }
                else {
                    while (p1.getHealth() > 0 && cottoncandy.getHealth() > 0){
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
            p1.setHealth(10);
        }
        if (p1.getRow() == 10){
            cout << "You have reached the Candy Castle. You must defeat the Candy Lord to take the candy crown and";
            cout << "the leader of the Candy World." << endl;
            while (p1.getHealth() > 0 && candylord.getHealth() > 0){
                attacklikelyhood = rand() % p1.getAttack() * 2 + 1;
                    if (attacklikelyhood < p1.getAttack()){
                        cout << "You attacked the Candy Lord!" << endl;
                        candylord.decreaseHealth(p1.getAttack()/2);
                    }
                    else{
                        cout << "The Candy Lord attacked you!" << endl;
                        p1.decreaseHealth(candylord.getAttack()/2);
                    }
            }
            if (p1.getHealth() == 0){
                cout << "You lost!" << endl;
                cout << "You have to go back to the start of the last row!" << endl;
                candylord.resetHealth();
                p1.setCoordinates(0, p1.getRow());
            }
            else{ 
                cout << "You won the game! You are now the leader of the Candy World" << endl;
                break;
            }
        }
        else if (p1.getColumn() % 3 == 0){p1.foundShop();}
        else if (p1.getColumn() % 3 == 1){p1.foundCoins();}
        else if (p1.getColumn() % 3 == 2){
            if (p1.getHealth() > 0){
                p1.foundHazard();
                cout << endl;
            }
            else{
                cout << "You got lucky and found a health boosting potion!" << endl;
                cout << "You now have 10 health." << endl;
                cout << endl;
                p1.setHealth(10);
            }
        }
        p1stack.push(p1.getRow());
        p1stack.push(p1.getColumn());
        p1stack.push(p1.getCoins());
        p1stack.push(p1.getDefense());
        p1stack.push(p1.getAttack());
        p1stack.push(p1.getHealth());
        
        if (!q.isEmpty()) {
            string currentPlayer = q.dequeue();
            cout << currentPlayer << "'s turn!" << endl;
            q.enqueue(currentPlayer);
        }
        cout << "Would you like to see your stats?(Y/N) " << endl;
        cin >> yn;
        if (yn == 'E' || yn == 'e'){break;}
        if (yn == 'Y' || yn == 'y'){
            p2.displayStats();
            p2.displayCoordinates();
            cout << endl;
            cout << endl;
        }
        else if (yn == 'N' || yn == 'n'){cout << "Okay!";}
        else {
            cout << "Please type Y or N next time. Here are your stats anyways" << endl;
            p2.displayStats();
            p2.displayCoordinates();
            cout << endl;
            cout << endl;
        }
        if (p2.getHealth() == 0){
            cout << "Your health is 0! You have to go back to the start of the row." << endl;
            p2.setHealth(10);
            p2.setCoordinates(0, p2.getRow());
        } 
        else{
            dice = rollDice();
            p2.increaseCoordinates(dice);
            cout << "You rolled a " << dice << "!" << endl;
        }
       cout << endl;
       if (p2.getColumn() == 9){
           cout << "You have reached the portal to the ";
           if (p2.getRow() == 0){
               cout << "next row, the row of the Candy Corn. However, you must defeat the Licorice Lizard first!" << endl;
               licorice.displayInfo();
               if (p2.getHealth() >= licorice.getHealth() && p2.getAttack() >= licorice.getAttack() && p2.getDefense() >= licorice.getDefense()){
                   cout << "All of your stats are higher than the Licorice Lizards! The Licorice Lizard retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() != 0 && licorice.getHealth() != 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Licorice Lizard!" << endl;
                           licorice.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Licorice Lizard attacked you!" << endl;
                           p2.decreaseHealth(licorice.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               licorice.resetHealth();
           }
              
           else if (p2.getRow() == 1){
               cout << "next row, the row of the Jelly Bean. However, you must defeat the Corn Clown first!" << endl;
                   candycorn.displayInfo();
               if (p2.getHealth() >= candycorn.getHealth() && p2.getAttack() >= candycorn.getAttack() && p2.getDefense() >= candycorn.getDefense()){
                   cout << "All of your stats are higher than the Candy Clown! The Candy Clown retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && candycorn.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Candy Clown!" << endl;
                               candycorn.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Candy Clown attacked you!" << endl;
                           p2.decreaseHealth(candycorn.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               candycorn.resetHealth();
           }
              
           else if (p2.getRow() == 2){
               cout << "next row, the row of the Lollipop. However, you must defeat the Jelly Bean Giant first!" << endl;
                   jelly.displayInfo();
               if (p2.getHealth() >= jelly.getHealth() && p2.getAttack() >= jelly.getAttack() && p2.getDefense() >= jelly.getDefense()){
                   cout << "All of your stats are higher than the Jelly Bean Giant! The Jelly Bean Giant retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && jelly.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Jelly Bean Giant!" << endl;
                               jelly.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Jelly Bean Giant attacked you!" << endl;
                           p2.decreaseHealth(jelly.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               jelly.resetHealth();
           }
              
           else if (p2.getRow() == 3){
               cout << "next row, the row of the Taffy. However, you must defeat the Lollipop Lalaloopsie first!" << endl;
                   lollipop.displayInfo();
               if (p2.getHealth() >= lollipop.getHealth() && p2.getAttack() >= lollipop.getAttack() && p2.getDefense() >= lollipop.getDefense()){
                   cout << "All of your stats are higher than the Lollipop Lalaloopsie! The Lollipop Lalaloopsie retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && lollipop.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Lollipop Lalaloopsie!" << endl;
                               lollipop.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Lollipop Lalaloopsie attacked you!" << endl;
                           p2.decreaseHealth(lollipop.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               lollipop.resetHealth();
           }
              
           else if (p2.getRow() == 4){
               cout << "next row, the row of the Marshmallow. However, you must defeat the Taffy Toddler first!" << endl;
                   taffy.displayInfo();
               if (p2.getHealth() >= taffy.getHealth() && p2.getAttack() >= taffy.getAttack() && p2.getDefense() >= taffy.getDefense()){
                   cout << "All of your stats are higher than the Taffy Toddler! The Taffy Toddler retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && taffy.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Taffy Toddler!" << endl;
                               taffy.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Taffy Toddler attacked you!" << endl;
                           p2.decreaseHealth(taffy.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               taffy.resetHealth();
           }
              
           else if (p2.getRow() == 5){
               cout << "next row, the row of the Fudge. However, you must defeat the Stay Puft Marshmallow Man first!" << endl;
                   marshmallow.displayInfo();
               if (p2.getHealth() >= marshmallow.getHealth() && p2.getAttack() >= marshmallow.getAttack() && p2.getDefense() >= marshmallow.getDefense()){
                   cout << "All of your stats are higher than the Stay Puft Marshmallow Man! The Stay Puft Marshmallow Man retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && marshmallow.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Stay Puft Marshmallow Man!" << endl;
                               marshmallow.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Stay Puft Marshmallow Man attacked you!" << endl;
                           p2.decreaseHealth(marshmallow.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               } 
               marshmallow.resetHealth();
           }
              
           else if (p2.getRow() == 6){
               cout << "next row, the row of the Gummy Bear. However, you must defeat the Fudgenator first!" << endl;
                   fudge.displayInfo();
               if (p2.getHealth() >= fudge.getHealth() && p2.getAttack() >= fudge.getAttack() && p2.getDefense() >= fudge.getDefense()){
                   cout << "All of your stats are higher than the Fudgenator! The Fudgenator retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && fudge.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Fudgenator!" << endl;
                               fudge.decreaseHealth(p2.getAttack()/2);
                       }
                       else{
                           cout << "The Fudgenator attacked you!" << endl;
                           p2.decreaseHealth(fudge.getAttack()/2);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               fudge.resetHealth();
           }
              
           else if (p2.getRow() == 7){
               cout << "next row, the row of the Rock Candy. However, you must defeat the Gummy Bear Goblin first!" << endl;
                   gummy.displayInfo();
               if (p2.getHealth() >= gummy.getHealth() && p2.getAttack() >= gummy.getAttack() && p2.getDefense() >= gummy.getDefense()){
                   cout << "All of your stats are higher than the Gummy Bear Goblin! The Gummy Bear Goblin retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }

               else {
                   while (p2.getHealth() > 0 && gummy.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Gummy Bear Goblin!" << endl;
                               gummy.decreaseHealth(p2.getAttack()/3);
                       }
                       else{
                           cout << "The Gummy Bear Goblin attacked you!" << endl;
                           p2.decreaseHealth(gummy.getAttack()/3);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               gummy.resetHealth();
           }
              
           else if (p2.getRow() == 8){
               cout << "next row, the row of the Cotton Candy. However, you must defeat the Rock Reaper first!" << endl;
                   rockcandy.displayInfo();
               if (p2.getHealth() >= rockcandy.getHealth() && p2.getAttack() >= rockcandy.getAttack() && p2.getDefense() >= rockcandy.getDefense()){
                   cout << "All of your stats are higher than the Rock Reaper! The Rock Reaper retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && rockcandy.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Rock Reaper!" << endl;
                               rockcandy.decreaseHealth(p2.getAttack()/3);
                       }
                       else{
                           cout << "The Rock Reaper attacked you!" << endl;
                           p2.decreaseHealth(rockcandy.getAttack()/3);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               rockcandy.resetHealth();
           }


           else if (p2.getRow() == 9){
               cout << "Candy Castle! However, you must defeat the Candyfloss Phantom first!" << endl;
                   cottoncandy.displayInfo();
               if (p2.getHealth() >= cottoncandy.getHealth() && p2.getAttack() >= cottoncandy.getAttack() && p2.getDefense() >= cottoncandy.getDefense()){
                   cout << "All of your stats are higher than the Candyfloss Phantom! The Candyfloss Phantom retreated.";
                   cout << endl << "You win!" << endl;
                   p2.setHealth(10);
                   p2.increaseRow();
               }
               else {
                   while (p2.getHealth() > 0 && cottoncandy.getHealth() > 0){
                       attacklikelyhood = rand() % 10 + 1;
                       if (attacklikelyhood < p2.getAttack()){
                           cout << "You attacked the Candyfloss Phantom!" << endl;
                               cottoncandy.decreaseHealth(p2.getAttack()/3);
                       }
                       else{
                           cout << "The Candyfloss Phantom attacked you!" << endl;
                           p2.decreaseHealth(cottoncandy.getAttack()/3);
                       }
                   }
                   if (p2.getHealth() == 0){
                       cout << "You lost!" << endl;
                       cout << "You have to go back to the start of the row!" << endl;
                       p2.setCoordinates(0, p2.getRow());
                   }
                   else{
                       cout << "You won!" << endl;
                       p2.setHealth(10);
                       p2.increaseRow();
                   }
               }
               cottoncandy.resetHealth();
           }
            p1.setHealth(10);
       }
       if (p2.getRow() == 10){
            cout << "You have reached the Candy Castle. You must defeat the Candy Lord to take the candy crown and";
            cout << "the leader of the Candy World." << endl;
            while (p2.getHealth() != 0 && candylord.getHealth() != 0){
                attacklikelyhood = rand() % p2.getAttack() * 2 + 1;
                    if (attacklikelyhood < p2.getAttack()){
                        cout << "You attacked the Candy Lord!" << endl;
                        candylord.decreaseHealth(p2.getAttack()/2);
                    }
                    else{
                        cout << "The Candy Lord attacked you!" << endl;
                        p2.decreaseHealth(candylord.getAttack()/2);
                    }
            }
            if (p2.getHealth() == 0){
                cout << "You lost!" << endl;
                cout << "You have to go back to the start of the last row!" << endl;
                candylord.resetHealth();
                p2.setCoordinates(0, p2.getRow());
            }
            else{ 
                cout << "You won the game! You are now the leader of the Candy World" << endl;
                break;
            }
        }
       else if (p2.getColumn() % 3 == 0){p2.foundShop();}
       else if (p2.getColumn() % 3 == 1){p2.foundCoins();}
       else if (p2.getColumn() % 3 == 2){
            if (p1.getHealth() > 0){
                p1.foundHazard();
            }
            else{
                cout << "You got lucky and found a health boosting potion!" << endl;
                cout << "You now have 10 health." << endl;
                p1.setHealth(10);
            }
       }

        p2stack.push(p2.getRow());
        p2stack.push(p2.getColumn());
        p2stack.push(p2.getCoins());
        p2stack.push(p2.getDefense());
        p2stack.push(p2.getAttack());
        p2stack.push(p2.getHealth());

    
    } //while loop closing bracket

    return 0;
};
