# Data Structure Project - Implementing Sparse Matrix by Linked-list
## by Seyyed Reza Sajjadian & Shoeib Besharatdeh
------------------------------------------------------------------

Implementing sparse matrix by linked-list has two advantages over arrays:
- No limit 
- Dynamic memory manangement


Sparse class has Linked-list as its underlying data structure
and the linked list has Element objects as its data field.
Element class has made up of 3 data members:
- row
- col
- value


Sparse class has these main member functions:
- addElement
- search
- print
- modify
- transpose
- add 
And the following data members:
- list
- rows
- cols
- terms


## Main Member Functions Overview
## addElement
- Prototype: void addElement(int row, int col, int value);
- Role: add element into sparse list in the right place(sorted order)
- Complexity: O(terms)

## search
- Prototype: ListNode<Element<int>>* search(int row, int col) const;
- Role: search by row and column
- Complexity: O(terms)

## print
- Prototype: void print() const; 
- Role: show the terms
- Complexity: O(terms)

## modify
- Prototype: void modify(ListNode<Element<int>>* node, int value);
- Role: modify an existing element of node
- Complexity: O(1)

## transpose
- Prototype: Sparse* transpose() const;
- Role: transpose this sparse list
- Complexity: O(cols x terms)

## add
- Prototype: void add(Sparse& sp) const;
- Role: add two sparses together and store the result in the second sparse
- Complexity: (this->terms x sp.terms)