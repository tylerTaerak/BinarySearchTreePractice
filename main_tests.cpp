#include <iostream>
#include <string>
#include "BinarySearchTree.h"


/**
 * @author Tyler Conley
 * 
 * This is a program that I developed to practice C++.  I have learned programming a fair bit before this, so this, along with my Linked List program, is simply to get
 * familiarity with the C++ language.  
 * 
 * This is a simple binary search tree that can have elements added and removed from it, and can calculate the size and height of
 * the tree.  In addition, the tree can be printed in-order, pre-order, post-order, and as a tree, which gives 8 functions in total.
 * 
 * I should note that I did not use 'using namespace std' all throughout the program.  This was a deliberate action, and done to teach myself a little bit more about
 * the standard library as I developed this program.  
 */

int main(){
    
    //Tests for default constructor
    std::cout << "Beginning Tests for Default Constructor" << "\n------------------------------------" << std::endl;

    BinarySearchTree<int> def_bst{};
    std::cout << "Binary search tree initialized" << std::endl;

    std::cout << "Adding 3 Random Numbers between 0 and 99" << std::endl << std::endl;

    int i1, i2, i3;

    def_bst.add(rand() % 100);
    def_bst.add(rand() % 100);
    def_bst.add( i1 = rand() % 100);
    def_bst.add(rand() % 100);
    def_bst.add(rand() % 100);
    def_bst.add(i2 = rand() % 100);
    def_bst.add(i3 = rand() % 100);
    def_bst.add(rand() % 100);
    def_bst.add(rand() % 100);

    std::cout << "All numbers added" << std::endl;

    std::cout << "Printing in-order, pre-order, post-order, and as a tree" << std::endl << "---------------------------------------" << std::endl;

    std::cout << "Printing in-order" << std::endl;
    def_bst.printInOrder();
    
    std::cout << "\n\nPrinting pre-order" << std::endl;
    def_bst.printPreOrder();

    std::cout << "\n\nPrinting post-order" << std::endl;
    def_bst.printPostOrder();

    std::cout << "\n\nPrinting as tree" << std::endl;
    def_bst.printAsTree();

    std::cout << "\nTesting size and height functions" << std::endl;
    std::cout << "Size: " << def_bst.size() << "\tHeight: " << def_bst.height() << std::endl;

    std::cout << "\n\nRemoving three values from tree: " << i1 << ", " << i2 << ", " << i3 << std::endl;
    std::cout << "Removing " << i1 << "...      " << std::boolalpha << def_bst.remove(i1) << std::endl;
    std::cout << "Removing " << i2 << "...      " << std::boolalpha << def_bst.remove(i2) << std::endl;
    std::cout << "Removing " << i3 << "...      " << std::boolalpha << def_bst.remove(i3) << std::endl;
    

    std::cout << "Printing (4 methods) again" <<std::endl;
    std::cout << "Printing in-order" << std::endl;
    def_bst.printInOrder();
    
    std::cout << "\n\nPrinting pre-order" << std::endl;
    def_bst.printPreOrder();

    std::cout << "\n\nPrinting post-order" << std::endl;
    def_bst.printPostOrder();

    std::cout << "\n\nPrinting as tree" << std::endl;
    def_bst.printAsTree();
    

    std::cout << "\nSize: " << def_bst.size() << "\tHeight: " << def_bst.height();

    delete &def_bst;
    std::cout << "Default Constructor Binary Search Tree Successfully Deleted" << std::endl;

    

    //Tests for overloaded constructor

    std::cout << "\n\n\n\n\nBeginning Tests for Overloaded Constructor" << "\n------------------------------------" << std::endl;

    std::vector<int> collection = {6, 3, 8, 91, 4, 15, 16, 10, 12, 14, 26, 39, 42, 31, 44, 55, 63, 70, 21};
    std::cout << "vector initialized" << std::endl;

    BinarySearchTree<int> ov_bst(collection);
    std::cout << "Binary search tree initialized" << std::endl;

    std::cout << "Printing in-order, pre-order, post-order, and as a tree" << std::endl << "---------------------------------------" << std::endl;

    std::cout << "Printing in-order" << std::endl;
    ov_bst.printInOrder();
    
    std::cout << "\n\nPrinting pre-order" << std::endl;
    ov_bst.printPreOrder();

    std::cout << "\n\nPrinting post-order" << std::endl;
    ov_bst.printPostOrder();

    std::cout << "\n\nPrinting as tree" << std::endl;
    ov_bst.printAsTree();

    std::cout << "\nTesting size and height functions" << std::endl;
    std::cout << "Size: " << ov_bst.size() << "\tHeight: " << ov_bst.height() << std::endl;

    std::cout << "\n\nRemoving three values from tree: " << 16 << ", " << 42 << ", " << 55 << std::endl;
    std::cout << std::boolalpha << ov_bst.remove(16) << std::endl;
    std::cout << std::boolalpha << ov_bst.remove(42) << std::endl;
    std::cout << std::boolalpha << ov_bst.remove(55) << std::endl;

    std::cout << "Printing (4 methods) again" <<std::endl;
    std::cout << "Printing in-order" << std::endl;
    ov_bst.printInOrder();
    
    std::cout << "\n\nPrinting pre-order" << std::endl;
    ov_bst.printPreOrder();

    std::cout << "\n\nPrinting post-order" << std::endl;
    ov_bst.printPostOrder();

    std::cout << "\n\nPrinting as tree" << std::endl;
    ov_bst.printAsTree();

    std::cout << "\nSize: " << ov_bst.size() << "\tHeight: " << ov_bst.height() << std::endl;

    delete &ov_bst;

    
    //tests for binary search tree containing floats
    std::cout << "Beginning Tests for BST containing floats" << "\n------------------------------------" << std::endl;

    std::vector<float> fl_collection = {1.01f, 3.74f, 2.12f, 88.54f, 36.3f, 81.0f, 74.123f, 75.65f, 0.012f, 12.13f, 62.31f};

    BinarySearchTree<float> fl_bst(fl_collection);
    std::cout << "Binary search tree initialized" << std::endl;

    std::cout << "Printing in-order, pre-order, post-order, and as a tree" << std::endl << "---------------------------------------" << std::endl;

    std::cout << "Printing in-order" << std::endl;
    fl_bst.printInOrder();
    
    std::cout << "\n\nPrinting pre-order" << std::endl;
    fl_bst.printPreOrder();

    std::cout << "\n\nPrinting post-order" << std::endl;
    fl_bst.printPostOrder();

    std::cout << "\n\nPrinting as tree" << std::endl;
    fl_bst.printAsTree();

    std::cout << "\nTesting size and height functions" << std::endl;
    std::cout << "Size: " << fl_bst.size() << "\nHeight: " << fl_bst.height() << std::endl;

    std::cout << "\nRemoving three values from tree: " << 74.123f << ", " << 36.3f << ", " << 12.13f << std::endl;
    std::cout << std::boolalpha << fl_bst.remove(74.123f) << std::endl;
    std::cout << std::boolalpha << fl_bst.remove(36.3f) << std::endl;
    std::cout << std::boolalpha << fl_bst.remove(12.13f) << std::endl;

    std::cout << "Printing (4 methods) again" <<std::endl;
    std::cout << "Printing in-order" << std::endl;
    fl_bst.printInOrder();
    
    std::cout << "\n\nPrinting pre-order" << std::endl;
    fl_bst.printPreOrder();

    std::cout << "\n\nPrinting post-order" << std::endl;
    fl_bst.printPostOrder();

    std::cout << "\n\nPrinting as tree" << std::endl;
    fl_bst.printAsTree();

    std::cout << "\nSize: " << fl_bst.size() << "\tHeight: " << fl_bst.height() << std::endl;

    delete &fl_bst;
    std::cout << "\nBinary Search Tree containing floats successfully deleted" << std::endl;


    return 0;
}