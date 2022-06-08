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

// QUICKSORT
template<typename Type>
void LinkedList<Type>::QuickSort() {
    // Size of two or less you can just compare value face to face
    if(size <= 2)
        Sort();
    else {
        // Create less than pivot and greater then pivot lists
        LinkedList<Type> *less = new LinkedList<Type>();
        LinkedList<Type> *greater = new LinkedList<Type>();
        int pivot = ChoosePivot()->data;
        Node *current = head;
        
        // Go through list and add data to less or greater list
        for(int i=0;i<size;i++) {
            if(current->data < pivot)
                less->Insert(current->data);
            else
                greater->Insert(current->data);
            current = current->nextNode;
        }

        // Bring the lists together
        Concatenate(less, pivot, greater);
    }
}

// CONCATENATE
template<typename Type>
void LinkedList<Type>::Concatenate(LinkedList<Type> *less, Type pivot, LinkedList<Type> *greater) {
    // Clear old data before adding in new
    Clear();
    less->QuickSort();
    greater->QuickSort();
    Node* current = less->head;
    // Add Lower data
    for(int i=0;i<less->Size();i++) {
        Insert(current->data);
        current = current->nextNode;
    }
    
    // Add back pivot
    Insert(pivot);
    current = greater->head;
    
    // Add greater data
    for(int j=0;j<greater->Size();j++) {
        Insert(current->data);
        current = current->nextNode;
    }
}

// CHOOSEPIVOT
template<typename Type>
typename LinkedList<Type>::Node* LinkedList<Type>::ChoosePivot() {
    // Choose the middle of the list as the pivot
    Node* current = head;
    int half = size / 2;
    for(int i=0; i<half;i++) {
        current = current->nextNode;
    }
    Delete(current->data);
    return current;
}

// SORT
template<typename Type>
void LinkedList<Type>::Sort() {
    // Size of 1 or less just return
    if(size < 2)
        return;
    // Swap data
    if(head->data > tail->data) {
        Type oldHead = head->data;
        head->data = tail->data;
        tail->data = oldHead;
    }
}

// DECONTRUCTOR
template<typename Type>
LinkedList<Type>::~LinkedList() {
    Clear();
}
