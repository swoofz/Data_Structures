#include <iostream>
#include "LinkedList.hpp"

// CONSTRUCTOR
template<typename Type>
LinkedList<Type>::LinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

// FIND
template<typename Type>
typename LinkedList<Type>::Node* LinkedList<Type>::Find(Type key) {
    Node *currentNode = head;
    // Look throught the list to find the first value that matches the given value
    while(currentNode != NULL && currentNode->data != key) {
        currentNode = currentNode->nextNode;
    }

    return currentNode;
}

// INSERT
template<typename Type>
void LinkedList<Type>::Insert(Type newData) {
    // Create new node
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->nextNode = NULL;
    newNode->prevNode = tail;
    
    if(tail != NULL)
        tail->nextNode = newNode;       // Making the previous tail's next node our new node
    if(size == 0) {
        newNode->prevNode = NULL;
        head = newNode;                 // Setting the first value in the list
    }
    tail = newNode;                     // New node is set to the end of the list
    size++;
}

// DELETE
template<typename Type>
void LinkedList<Type>::Delete(Type key) {
    // Find the node want to remove from list
    Node *delNode = Find(key);
    if(delNode == NULL) {
        std::cout << "Did not find the key you want to delete\n";
        return;
    }

    // Remove
    if(delNode->prevNode != NULL)
        delNode->prevNode->nextNode = delNode->nextNode;
    else
        head = delNode->nextNode;
    if(delNode->nextNode != NULL)
        delNode->nextNode->prevNode = delNode->prevNode;

    
    // Clean up data so can't be accessed anymore
    size--;
//    delNode = NULL;
    delete delNode;
}

// MINIMUN
template<typename Type>
Type LinkedList<Type>::Minimun() {
    Node *currentNode = head;
    Type lowest = head->data;

    // Compare nodes to find the smallest value
    while(currentNode->nextNode != NULL){
        if(lowest > currentNode->nextNode->data){
            lowest = currentNode->nextNode->data;
        }

        currentNode = currentNode->nextNode;
    }

    return lowest;
}

// MAXIMUN
template<typename Type>
Type LinkedList<Type>::Maximun() {
    Node *currentNode = head;
    Type biggest = head->data;

    // Compare nodes to find the biggest value
    while(currentNode->nextNode != nullptr){
        if(biggest < currentNode->nextNode->data){
            biggest = currentNode->nextNode->data;
        }

        currentNode = currentNode->nextNode;
    }

    return biggest;
}

// SIZE
template<typename Type>
int LinkedList<Type>::Size() {
    // Shows how many items are in the list
    return size;
}

// DISPLAY
template<typename Type>
void LinkedList<Type>::Display() {
    Node *currentNode = head;

    // Print the list
    std::cout << "{";
    for(int i=0;i<size;i++){
        std::cout << currentNode->data;
        currentNode = currentNode->nextNode;

        if(i + 1 < size)
            std::cout << ", ";
    }
    std::cout << "}"  << std::endl;
}

// CLEAR
template<typename Type>
void LinkedList<Type>::Clear() {
    // Delete everything on the list
    while(size != 0) {
        Delete(head->data);
    }
}

// DECONTRUCTOR
template<typename Type>
LinkedList<Type>::~LinkedList() {
    Clear();
}
