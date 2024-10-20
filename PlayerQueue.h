#ifndef PLAYERQUEUE_H
#define PLAYERQUEUE_H

#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node3 {
    string playerName; // The name of the player
    Node3* next;             // Pointer to the next node

    Node3(const string& name);
};

class PlayerQueue {
private:
    Node3* front; // Pointer to the front of the queue
    Node3* rear;  // Pointer to the rear of the queue
    int size;    // Size of the queue

public:
    PlayerQueue();
    ~PlayerQueue();
    
    void enqueue(const string& playerName); // Add a player to the queue
    string dequeue();                        // Remove a player from the queue
    bool isEmpty();                               // Check if the queue is empty
    string peek();                           // Peek at the front player
    int getSize();                                // Get the size of the queue
};
#endif
