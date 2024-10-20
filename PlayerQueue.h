#ifndef PLAYERQUEUE_H
#define PLAYERQUEUE_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node3 {
    string playerName; 
    Node3* next;          

    Node3(const string& name);
};

class PlayerQueue {
private:
    Node3* head; 
    Node3* tail;  
    int size;   

public:
    PlayerQueue();
    ~PlayerQueue();
    
    void enqueue(const string& playerName); 
    string dequeue();                        
    bool isEmpty();                               
    string peek();                         
    int getSize();                                
};
#endif
