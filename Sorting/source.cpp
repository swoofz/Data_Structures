//  Sorting
//  Created by Jordan Hall on 9/26/19.

#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "LinkedList.hpp"
#include "LinkedList.cpp"

void TestDataTime(std::string);
void TestData(int[], int);

int main(int argc, const char * argv[]) {

    TestDataTime("num10.dat");
//    TestDataTime("num100.dat");
//    TestDataTime("num1000.dat");
//    TestDataTime("num10000.dat");
//    TestDataTime("num100000.dat");
//    TestDataTime("num1000000.dat");
    
    return 0;
}

// Displays list sorted
void DisplaySortedList(LinkedList<int> *list) {
        if(list->Size() < 100) {
        std::cout << "Inital List: ";
        list->Display();
        list->QuickSort();
        std::cout << "Sorted List: ";
        list->Display();
            std::cout << std::endl;
    }
}

// Showing how long it takes
void TestDataTime(std::string filename) {
    int data;
    LinkedList<int> *list = new LinkedList<int>();
    std::ifstream file;
    file.open(filename);
    if(file.is_open()) {
        
        while(!file.eof()) {
            file >> data;
            list->Insert(data);
        }
        
    } else {
        std::cout << "Something went wrong." << std::endl;
    }
    

    file.close();
    clock_t time;

    time = clock();
    list->QuickSort();
    time = clock() - time;
    
    std::cout << "Time took: " << time << std::endl;
    
//    DisplaySortedList(list);
    
//    list->Clear();
//    delete list;
}

// Creates a list
void TestData(int dataArray[], int size) {
    LinkedList<int> *list = new LinkedList<int>();
    for(int i=0;i<size;i++) {
        list->Insert(dataArray[i]);
    }
    
    DisplaySortedList(list);
    
    list->Clear();
    delete list;
}
