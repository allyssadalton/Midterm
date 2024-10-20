#include "Player2Stack.h"

// Node constructor
Node2::Node2(int val) {
    value = val;
    next = nullptr;
}

// LinkedListStack constructor
LinkedListStack2::LinkedListStack2(){
    top = nullptr;
    loadFromFile();
}

// LinkedListStack destructor
LinkedListStack2::~LinkedListStack2() {
    while (!isEmpty()) {
        pop();
    }
}

// Check if the stack is empty
bool LinkedListStack2::isEmpty() {
    return top == nullptr;
}

// Push a value onto the stack
void LinkedListStack2::push(int value) {
    Node2* newNode = new Node2(value);
    newNode -> next = top;
    top = newNode;
    saveToFile();
}

// Pop a value from the stack
int LinkedListStack2::pop() {
    if (isEmpty()) {return -1;}
    int poppedValue = top -> value;
    Node2* temp = top;
    top = top -> next;
    delete temp;
    saveToFile();
    return poppedValue;
}

// Peek at the top value of the stack
int LinkedListStack2::peek() {
    if (isEmpty()) {
        return -1;
    }
    return top -> value;
}

// Save the stack to a file
void LinkedListStack2::saveToFile() {
    ofstream file(filename);
    if (file.is_open()) {
        Node2* current = top;
        while (current) {
            file << current -> value << endl;
            current = current -> next;
        }
        file.close();
    }
}

// Load the stack from a file
void LinkedListStack2::loadFromFile() {
    ifstream file(filename);
    string line;
    int lineCount = 0;
    if (file.is_open()) {
        int value;
        while (lineCount < 6 && getline(file, line)) {
            value = stoi(line);
            push(value);
            lineCount += 1;
        }
        file.close();
    }
}