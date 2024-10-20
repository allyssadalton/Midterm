#ifndef CANDYMONSTERS_H
#define CANDYMONSTERS_H

#include <string>
#include <iostream>
using namespace std;

class CandyMonster {
public:
    string name;
    int health;
    int attack;
    int defense;

    CandyMonster(string n, int h, int a, int d); //constructor

    ~CandyMonster(); //destructor

    void displayInfo();

    void resetHealth();

    void decreaseHealth(int h);

    bool isDefeated();

    int getHealth();

    int getAttack();

    int getDefense();

    
};

#endif
