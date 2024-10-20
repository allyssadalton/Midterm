#ifndef PLAYER1STACK_H
#define PLAYER1STACK_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Node {
public:
    int value;
    Node* next;

    Node(int val);
};
class LinkedListStack1 {
private:
    Node* top;
    


public:
    LinkedListStack1();
    ~LinkedListStack1();

    const string filename = "player1stackdata.txt";

    bool isEmpty();
    void push(int value);
    int pop();
    int peek();
    void saveToFile();
    void loadFromFile();
};

#endif