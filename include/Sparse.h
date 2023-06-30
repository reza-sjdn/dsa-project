// Class Sparse handles big matirces that has lots of empty elements
#ifndef SPARSE_H
#define SPARSE_H

#include "List.h"
#include "ListNode.h"
#include "Element.h"

class Sparse {

public:
    // constructor and destructor
    Sparse(int rows, int cols);

    // set and get functions
    void setRows(int rows);
    int getRows() const;
    void setCols(int cols);
    int getCols() const;
    int getTerms() const;


    // show the terms
    void print() const; 

    // search by row and column
    ListNode<Element<int>>* search(int row, int col) const;

    // add element into sparse list in the right place(sorted order)
    void addElement(int row, int col, int value);

    // modify an existing element of node
    void modify(ListNode<Element<int>>* node, int value);

    // transpose this sparse list
    Sparse* transpose() const;

    // add two sparse lists together and store the result in the argument sparse
    void add(Sparse& sp) const;


private:
    List<Element<int>> list; // list of integer elements

    // the header of the sparse list
    int rows; // total rows
    int cols; // total columns

    // total terms: starting value of terms is 0
    // and after each addElement(), it increments.
    int terms = 0; 
};

#endif