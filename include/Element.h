// Class template Element as a container for storing data
#ifndef ELEMENT_H
#define ELEMENT_H

#include <iostream>
#include <iomanip>

class Sparse; // forward declaration

template<typename T>
class Element {
    friend class Sparse; // Sparse needs to access this class

    // overloading << operator
    friend std::ostream& operator<<(std::ostream& output, const Element& el) {
        output << std::right << std::setw(5) << el.row;
        output << std::setw(5) << el.col;
        output << std::setw(5) << el.value;
        return output;
    }

    
public:
    // overloading == operator
    bool operator==(const Element<T>& el) const {
        if (this->row == el.row && this->col == el.col && this->value == el.value) {
            return true;
        }
        return false;
    }

    // constructor
    Element (int row, int col, T value) {
        this->row = row;
        this->col = col;
        this->value = value;
    }

    // set and get member functions
    void setValue(const T& value) {this->value = value;}
    T getValue() {return value;}

private: 
    int row;
    int col;
    T value;
};

#endif