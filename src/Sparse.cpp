// Class Sparse implementation
#include <iostream>
#include <iomanip>
#include "../include/Sparse.h"
#include "../include/List.h"
#include "../include/ListNode.h"
#include "../include/Element.h"

// some useful constants
#define currentData currentPtr->getData() // frequently used
#define currentNext currentPtr->getNextPtr() // frequently used


using namespace std;

//constructor
Sparse::Sparse(int rows, int cols) {
    // initialize header
    this->rows = rows;
    this->cols = cols;
}


// set and get functions
void Sparse::setRows(int rows) {this->rows = rows;}
int Sparse::getRows() const {return rows;}
void Sparse::setCols(int cols) {this->cols = cols;}
int Sparse::getCols() const {return cols;}
int Sparse::getTerms() const {return terms;}


// show terms
void Sparse::print() const {
    // writing header
    cout << right << setw(5) << rows;
    cout << setw(5) << cols;
    cout << setw(5) << terms << endl;

    // writing main body
    list.print();
}


// search by row and column
ListNode<Element<int>>* Sparse::search(int row, int col) const {
    ListNode<Element<int>>* currentPtr = list.getFirstPtr();
    while (currentPtr) {
        if (currentData.row == row
            && currentData.col == col) {return currentPtr;}

        currentPtr = currentNext;
    }
    return nullptr;
}


// add element into sparse list in the right place(sorted order)
void Sparse::addElement(int row, int col, int value) {
    // check validity
    if (row >= rows || col >= cols) {
        cout << "out of bound element!\n";
        return;
    }

    // if there exists already such an element modify it
    ListNode<Element<int>>* found = search(row, col);
    if (found) { 
        modify(found, value);
        return;
    }

    // increment terms
    ++terms;

    // create an element with specified parts
    Element<int> el(row, col, value);
    // create a node of new created element
    ListNode<Element<int>>* newPtr = new ListNode<Element<int>>(el);

    if (list.isEmpty()) {
        list.pushBack(el);
    }
    else {
        ListNode<Element<int>>* currentPtr = list.getFirstPtr();
        while (currentPtr) {
            // this nested if makes sure that
            // the new node will be added
            // in the right place in the sparse list

            if (row < currentData.row) { // check the rows
                list.insert(currentPtr, el);
                return;
            }

            // if two rows were equal, check the columns
            else if (row == currentData.row) {
                if (col < currentData.col) {
                    list.insert(currentPtr, el);
                    return;
                }
            }

            currentPtr = currentNext; // keep going
        }

        // if the loop terminated, just push back!
        list.pushBack(el);
    }
}


// modify an existing element of node
void Sparse::modify(ListNode<Element<int>>* node, int value) {
    Element<int>* elPtr = node->dataAddress();
    elPtr->setValue(value);
}


// transpose this sparse list
Sparse* Sparse::transpose() const {
    // create a dynamic tMat and set the header
    Sparse* tSparse = new Sparse(getCols(), getRows()); 

    ListNode<Element<int>>* currentPtr;

    // scan for columns
    for (size_t i = 0; i < getCols(); ++i) { 
        currentPtr = list.getFirstPtr(); // resume the global scan

        // global scan
        while (currentPtr) {
            if (currentData.col == i) {
                // create an element with specified parts
                Element<int> el(i, currentData.row, currentData.value);
                tSparse->list.pushBack(el);
            }

            currentPtr = currentNext; // keep going
        }
    }

    return tSparse; // return the address of new created sparse list
}


// add two sparse lists together and store the result in the argument sparse
void Sparse::add(Sparse& sp) const {
    ListNode<Element<int>>* currentPtr = list.getFirstPtr();
    while (currentPtr) {
        // search for common elements
        ListNode<Element<int>>* found = sp.search(currentData.row, currentData.col);

        if (found) { // if it was common element
            int newValue = found->getData().value + currentData.value;
            found->dataAddress()->setValue(newValue);
        }
        else sp.addElement(currentData.row, currentData.col, currentData.value);

        currentPtr = currentNext; // keep going
    }
}
