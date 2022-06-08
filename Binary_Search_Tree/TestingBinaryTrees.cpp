#include <iostream>
#include "TestingBinaryTrees.hpp"
#include "BinarySearchTree.h"

void TestingInsert()  {
    int arr[10] = {40,32,56,27,54,23,43,34,51,63};
    BinarySearchTree<int> *bst = new BinarySearchTree<int>(arr, 10);
    
    // Display tree
    bst->InorderTraverse();
    std::cout << "All values should be in the tree." <<
    " - 40,32,56,27,54,23,43,34,51,63. : Sorted." << std::endl;
    
    delete bst;
}

void TestingInsertSameData() {
    BinarySearchTree<int> *bst = new BinarySearchTree<int>();
    
    std::cout << "Insert in two 5 data" << std::endl;
    bst->Insert(5);
    bst->Insert(5);
    
    // Display tree
    bst->InorderTraverse();
    std::cout << "Should have got a message that data was already insert. And should not be in the tree" << std::endl;
    
    delete bst;
}

void TestingDelete() {
    int arr[12] = {32,74,15,10,13,23,22,5,6,77,55,45};
    BinarySearchTree<int> *bst = new BinarySearchTree<int>(arr,12);
    std::cout << "Tree inorder look like this:  ";
    bst->InorderTraverse();
    std::cout << std::endl;
    
    // Delete root
    bst->Delete(32);
    
    // Display Tree
    bst->InorderTraverse();
    std::cout << "Should not have 32 anymore.\n\n";
    
    // Detele node with two children nodes that isn't root
    bst->Delete(15);
    bst->InorderTraverse();
    std::cout << "Should not have 15 anymore.\n\n";
    
    // Detele node with one child nodes that isn't root
    bst->Delete(5);
    bst->InorderTraverse();
    std::cout << "Should not have 5 anymore.\n\n";
    
    // Delete node with no child nodes
    bst->Delete(45);
    bst->InorderTraverse();
    std::cout << "Should not have 45 anymore.\n\n";
    
    // Node doesn't exist so delete nothing
    bst->Delete(123);
    bst->InorderTraverse();
    std::cout << "Nothing should have changed.\n\n";
    
}

void  TestingFindMax() {
    int arr[14] = {40,32,56,27,54,23,43,34,51,63,29,14,35,45};
    BinarySearchTree<int> *bst = new BinarySearchTree<int>(arr, 14);
    
    std::cout << "Max should be 63;" << std::endl;
    std::cout << "Running Max: "  << bst->Maximun() << std::endl;
}

void TestingTraverse() {
    int arr[10] = {5,3,6,10,4,1,8,7,2,9};
    BinarySearchTree<int> *bst = new BinarySearchTree<int>(arr, 10);

    
    // inorder
    std::cout << "Display: 5,3,6,10,4,1,8,7,2,9 - inorder" << std::endl;
    bst->InorderTraverse();
    bst->ClearTree();
        
    // New set of number to test
    bst->Insert(10);
    bst->Insert(8);
    bst->Insert(15);
    bst->Insert(19);
    bst->Insert(13);
    bst->Insert(11);
    bst->Insert(14);
    bst->Insert(17);
    bst->Insert(22);
    bst->Insert(9);
    bst->Insert(5);
    bst->Insert(6);
    bst->Insert(3);
    bst->Insert(4);
    
    // inorder
    std::cout << "\nDisplay: 10,8,15,19,13,11,14,17,22,9,5,6,3,4 - inorder" << std::endl;
    bst->InorderTraverse();
    bst->ClearTree();
        
    // New set of number to test
    bst->Insert(100);
    bst->Insert(70);
    bst->Insert(50);
    bst->Insert(60);
    bst->Insert(55);
    bst->Insert(68);
    bst->Insert(65);
    bst->Insert(63);
    bst->Insert(67);
    bst->Insert(66);
    
    // inorder
    std::cout << "\nDisplay: 100,70,50,60,55,68,65,63,67,66 - inorder" << std::endl;
    bst->InorderTraverse();
    bst->ClearTree();
}
