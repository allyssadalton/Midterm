#include "PlayerQueue.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;


// Constructor implementation
Node3::Node3(const string& name) {
    playerName = name;  // Initialize the playerName member variable with the provided name
    next = nullptr;     // Set the next pointer to nullptr, indicating no next node
}

PlayerQueue::PlayerQueue() {
    front = nullptr; // Initialize the front pointer to nullptr
    rear = nullptr;  // Initialize the rear pointer to nullptr
    size = 0;       // Set the initial size of the queue to 0
}

// Destructor
PlayerQueue::~PlayerQueue() {
    while (!isEmpty()) {
        dequeue();
    }
}

// Add a player to the queue
void PlayerQueue::enqueue(const string& playerName) {
    Node3* newNode = new Node3(playerName);
    if (isEmpty()) {
        front = newNode; // If queue is empty, set both front and rear to new node
        rear = newNode;
    } 
    else {
        rear -> next = newNode;   // Link the new node at the end of the queue
        rear = newNode;         // Update rear to the new node
    }
    size++;
}

// Remove a player from the queue
string PlayerQueue::dequeue() {
    if (isEmpty()) {
        return ""; // Indicate an empty queue
    }
    string playerName = front -> playerName; // Get the player name from the front
    Node3* temp = front;       // Store the current front node
    front = front -> next;      // Move front to the next node
    delete temp;              // Free the memory of the old front
    size--;
    if (isEmpty()) {rear = nullptr;} // Reset rear if the queue is empty
    return playerName; // Return the dequeued player's name
}

// Check if the queue is empty
bool PlayerQueue::isEmpty() {
    return size == 0; // Check if the queue is empty
}

// Peek at the front player
string PlayerQueue::peek() {
    if (isEmpty()) {
        return ""; // Indicate an empty queue
    }
    return front -> playerName; // Return the front player's name
}

// Get the size of the queue
int PlayerQueue::getSize() {
    return size; // Return the size of the queue
}