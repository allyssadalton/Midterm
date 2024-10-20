#include "PlayerQueue.h"

// Constructor implementation
Node3::Node3(const string& name) {
    playerName = name;  
    next = nullptr; 
}

PlayerQueue::PlayerQueue() {
    head = nullptr; 
    tail = nullptr;  
    size = 0;       
}

// Destructor
PlayerQueue::~PlayerQueue() {
    while (!isEmpty()){dequeue();}
}

// Add a player to the queue
void PlayerQueue::enqueue(const string& playerName) {
    Node3* newNode = new Node3(playerName);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } 
    else {
        tail -> next = newNode;   
        tail = newNode;        
    }
    size++;
}

// Remove a player from the queue
string PlayerQueue::dequeue() {
    if (isEmpty()) {return "";}
    string playerName = head -> playerName; 
    Node3* temp = head;       
    head = head -> next;    
    delete temp;             
    size--;
    if (isEmpty()) {tail = nullptr;} 
    return playerName; 
}

// Check if the queue is empty
bool PlayerQueue::isEmpty() {return size == 0;}

// Peek at the front player
string PlayerQueue::peek() {
    if (isEmpty()) {return "";}
    return head -> playerName; 
}

// Get the size of the queue
int PlayerQueue::getSize() {return size;}