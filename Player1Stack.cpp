#include "Player1Stack.h"

// Node constructor
Node::Node(int val) {
    value = val;
    next = nullptr;
}

// LinkedListStack constructor
LinkedListStack1::LinkedListStack1(){
    top = nullptr;
    loadFromFile();
}

// LinkedListStack destructor
LinkedListStack1::~LinkedListStack1() {
    while (!isEmpty()) {
        pop();
    }
}

// Check if the stack is empty
bool LinkedListStack1::isEmpty() {
    return top == nullptr;
}

// Push a value onto the stack
void LinkedListStack1::push(int value) {
    Node* newNode = new Node(value);
    newNode -> next = top;
    top = newNode;
    saveToFile();
}

// Pop a value from the stack
int LinkedListStack1::pop() {
    if (isEmpty()) {return -1;}
    int poppedValue = top -> value;
    Node* temp = top;
    top = top -> next;
    delete temp;
    saveToFile();
    return poppedValue;
}

// Peek at the top value of the stack
int LinkedListStack1::peek() {
    if (isEmpty()) {
        return -1;
    }
    return top -> value;
}

// Save the stack to a file
void LinkedListStack1::saveToFile() {
    ofstream file(filename);
    if (file.is_open()) {
        Node* current = top;
        while (current) {
            file << current -> value << endl;
            current = current -> next;
        }
        file.close();
    }
}

// Load the stack from a file
void LinkedListStack1::loadFromFile() {
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