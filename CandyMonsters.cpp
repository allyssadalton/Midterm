#include "CandyMonsters.h"
#include <string>
#include <iostream>
using namespace std;

CandyMonster::CandyMonster(string n, int h, int a, int d){
    name = n;
    health = h;
    attack = a;
    defense = d;
}

CandyMonster::~CandyMonster(){}

void CandyMonster::displayInfo(){
    cout << endl;
    cout << "Monster: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << endl; 
}

void CandyMonster::decreaseHealth(int h){health -= h;}

void CandyMonster::resetHealth(){health = 10;}

int CandyMonster::getHealth(){return health;}

int CandyMonster::getAttack(){return attack;}

int CandyMonster::getDefense(){return defense;}

bool CandyMonster::isDefeated(){return health <= 0;}
