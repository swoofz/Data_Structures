// UAT Assignment: Linked List
// By: Jordan Hall
// Date: 9/15/19

#include <iostream>
#include "LinkedList.hpp"
#include "LinkedList.cpp"

bool TestLinkedList();  // Test if anything breaks
bool TestInt();         // Test int linked list
bool TestChar();        // Test Char linked list
int Menu();             // User Menu to interaction with Linked list created

int main(int argc, const char * argv[]) {
    int number;
    int choice = Menu();
    LinkedList<int> *list = new LinkedList<int>();
    
    // User actions
    while(choice != 6) {
        // Test
        if(choice == 1) {
            if(TestLinkedList())
                std::cout << "\nAll Test have passed." << std::endl;
            else
                std::cout << "\nSome Test didn't pass." << std::endl;
        }
        // Insert
        if(choice == 2) {
            std::cout << "Enter a number: ";
            std::cin >> number;
            list->Insert(number);
            std::cout << std::endl;
        }
        // Delete
        if(choice == 3) {
            std::cout << "Your number that you can delete are. - ";
            list->Display();
            std::cout << std::endl;
            std::cout << "Delete a number: ";
            std::cin >> number;
            list->Delete(number);
            std::cout << std::endl;
        }
        // Clear
        if(choice == 4) {
            list->Clear();
            std::cout << std::endl;
        }
        // Display
        if(choice == 5) {
            list->Display();
            std::cout << std::endl;
        }
        
        choice = Menu();
    }
    
    return 0;
}

// User Menu
int Menu() {
    int choice = 0;
    std::cout << "Welcome to my Linked List Program. Please Browse around." << std::endl;
    std::cout << "1. Run already generated test." << std::endl;
    std::cout << "2. Add to whole number List." << std::endl;
    std::cout << "3. Delete from a List." << std::endl;
    std::cout << "4. Clear List." << std::endl;
    std::cout << "5. Display List." << std::endl;
    std::cout << "6. End Program." << std::endl;
    std::cout << "Please enter number: ";
    std::cin >> choice;
    std::cout << std::endl;
    return choice;
}

// Simple Checking List for testing
bool TestLinkedList() {
    bool success = true;
    
    if(!TestInt() || !TestChar())
        success = false;
    
    return success;
}

// Testing int Linked List
bool TestInt() {
    bool success = true;
    LinkedList<int> myList;
    
    // Testing init Size
    if(myList.Size() > 0) {
        std::cout << "When created size got increase and is wrong" << std::endl;
        success = false;
    } else
        std::cout << "Init size is correct." << std::endl;
    
    // Test if can insert into a list
    myList.Insert(5);
    if(myList.Find(5)->data != 5) {
        std::cout << "Data was not entered correctly." << std::endl;
        success = false;
    }
    else
        std::cout << "Data was entered correctly" << std::endl;
    
    // Test the size of list working
    if(myList.Size() != 1) {
        std::cout << "Didn't increase size correctly." << std::endl;
        success = false;
    } else
        std::cout << "Increase size correctly." << std::endl;
    
    // If can delete from list
    myList.Delete(5);
    if(myList.Size() != 0) {
        std::cout << "Size should be zero." << std::endl;
        success = false;
    } else
        std::cout << "Size is correct." << std::endl;
    if(myList.Find(5) != NULL) {
        std::cout << myList.Find(5)->data << std::endl;
        std::cout << "Should not be able to find" << std::endl;
        success = false;
    } else
        std::cout << "No value found, so working correctly." << std::endl;
    
    // Test Max / Min
    myList.Insert(123);
    myList.Insert(12);
    myList.Insert(328);
    myList.Insert(6121);
    myList.Insert(923);
    
    // Max
    if(myList.Maximun() != 6121) {
        std::cout << "Maximun should of been 6121" << std::endl;
        success = false;
    } else
        std::cout << "Correct Maximun" << std::endl;
    // Min
    if(myList.Minimun() != 12) {
        std::cout << "Minimun should of been 12" << std::endl;
        success = false;
    } else
        std::cout << "Correct Minimun" << std::endl;
    
    return success;
}

// Testing Char Linked List
bool TestChar() {
    bool success = true;
    LinkedList<char> myList;
    
    // Testing init Size
    if(myList.Size() > 0) {
        std::cout << "When created size got increase and is wrong" << std::endl;
        success = false;
    } else
        std::cout << "Init size is correct." << std::endl;
    
    // Test if can insert into a list
    myList.Insert('c');
    if(myList.Find('c')->data != 'c') {
        std::cout << "Data was not entered correctly." << std::endl;
        success = false;
    }
    else
        std::cout << "Data was entered correctly" << std::endl;
    
    // Test the size of list working
    if(myList.Size() != 1) {
        std::cout << "Didn't increase size correctly." << std::endl;
        success = false;
    } else
        std::cout << "Increase size correctly." << std::endl;
    
    // If can delete from list
    myList.Delete('c');
    if(myList.Size() != 0) {
        std::cout << "Size should be zero." << std::endl;
        success = false;
    } else
        std::cout << "Size is correct." << std::endl;
    if(myList.Find('c') != NULL) {
        std::cout << myList.Find('c')->data << std::endl;
        std::cout << "Should not be able to find" << std::endl;
        success = false;
    } else
        std::cout << "No value found, so working correctly." << std::endl;
    
    // Test Max / Min
    myList.Insert('g');
    myList.Insert('y');
    myList.Insert('d');
    myList.Insert('a');
    myList.Insert('t');
    
    // Max
    if(myList.Maximun() != 'y') {
        std::cout << "Maximun should of been 'y'" << std::endl;
        success = false;
    } else
        std::cout << "Correct Maximun" << std::endl;
    // Min
    if(myList.Minimun() != 'a') {
        std::cout << "Minimun should of been 'a'" << std::endl;
        success = false;
    } else
        std::cout << "Correct Minimun" << std::endl;
    
    return success;

}
