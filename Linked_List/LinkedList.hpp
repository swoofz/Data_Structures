#ifndef LinkedList_hpp
#define LinkedList_hpp

template<typename Type>
class LinkedList {
private:
    struct Node {
        Type data;                      // Data that is contained
        Node *nextNode;                 // Pointer to next data in the list
        Node *prevNode;                 // Pointer to the data that was before in the list
    };

    int size;                           // Size of the list
    Node *head;                         // First value in the list
    Node *tail;                         // Last value in the list

public:
    LinkedList();                       // Contructor, Set up a new list ready to use
    Node* Find(Type key);               // Find Node by key
    void Insert(Type newData);          // Create a new Node and Add to the back of the list
    void Delete(Type key);              // Delete Node from list
    Type Minimun();                     // Find Minimun Value
    Type Maximun();                     // Find Maximun Value
    int Size();                         // Size of the linked List
    void Display();                     // Display all of the Linked List's values
    void Clear();                       // Clear all value in the list
    ~LinkedList();                      // Decontructor, clean up any data not already deleted
};

#endif /* LinkedList_hpp */
