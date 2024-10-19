#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
using namespace std;

class player{
private: 
    int *stats;
    int *statsInfo;

public:
    player(int *stats); //constructor
    ~player(); //destructor
    void displayStats();
    void displayCoordinates();

    void setHealth(int h);
    void setAttack(int att);
    void setDefense(int d);
    void setCoins(int c);
    void setCoordinates(int x, int y);

    void increaseHealth(int h);
    void increaseAttack(int att);
    void increaseDefense(int d);
    void increaseCoins(int c);
    void increaseCoordinates(int x);

    void increaseRow();

    void decreaseHealth(int h);
    void decreaseAttack(int att);
    void decreaseDefense(int d);
    void decreaseCoins(int c);
    void decreaseCoordinates();

    void foundShop();
    void foundCoins();
    void foundHazard();

    int getHealth();
    int getAttack();
    int getDefense();
    int getCoordinates(); //soley for while loop
    int getRow();
    int* getInfo();

};

#endif
