//  Binary_Search_Tree
//  Created by Jordan Hall on 9/20/19.

#include <iostream>
#include "BinarySearchTree.h"
#include "TestingBinaryTrees.hpp"


int main(int argc, const char * argv[]) {
    
    std::cout << "-----TESTING INSERT-----" << std::endl;
    TestingInsert();
    
    std::cout << "\n-----TESTING INSERT OF SAME DATA-----" << std::endl;
    TestingInsertSameData();
    
    std::cout << "\n-----TESTING DELETING DATA-----" << std::endl;
    TestingDelete();
    
    std::cout << "\n-----TESTING IF CAN FIND MAX DATA VALUE-----" << std::endl;
    TestingFindMax();
    
    std::cout << "\n-----TESTING TRAVERSE-----" << std::endl;
    TestingTraverse();
    
    return 0;
}
