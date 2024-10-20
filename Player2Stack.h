#ifndef PLAYER2STACK_H
#define PLAYER2STACK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Node2{
    
public:
    int value;
    Node2* next;

    Node2(int val);
};

class LinkedListStack2 {
private:
    Node2* top;
    


public:
    LinkedListStack2();
    ~LinkedListStack2();

    const string filename = "player2stackdata.txt";

    bool isEmpty();
    void push(int value);
    int pop();
    int peek();
    void saveToFile();
    void loadFromFile();
};

#endif