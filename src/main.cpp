// driver program for testing purpose
#include <iostream>
#include "../include/Sparse.h"
using namespace std;

int main() {
    cout << "\n==>> PROJECT OUTPUT SUMMARY <<==\n\n";
    cout << "    ADDING SOME NONZERO ELEMENTS ...\n\n";
    Sparse sp(9, 8);
    sp.addElement(8, 0, 12);
    sp.addElement(6, 7, 23);
    sp.addElement(7, 0, 31);
    sp.addElement(2, 0, 88);
    sp.addElement(1, 2, 3);
    sp.addElement(4, 0, 41);
    sp.addElement(0, 7, 59);
    sp.addElement(1, 7, 62);
    sp.print();
    cout << "    SEARCHING AND MODIFYING ELEMENT WITH ROW 7, COL 0 ...\n\n";
    sp.modify(sp.search(7, 0), 28);
    sp.print();
    cout << "    TRANSPOSING THE LAST SPARSE MATRIX ...\n\n";
    Sparse* tsp = sp.transpose();
    tsp->print();
    cout << "******************************\n\n";
    Sparse a(4, 5);
    a.addElement(0, 0, 4);
    a.addElement(1, 2, 8);
    a.addElement(0, 2, 6);
    a.addElement(2, 0, 5);
    Sparse b(8, 9);
    b.addElement(5, 1, 11);
    b.addElement(6, 7, 23);
    b.addElement(0, 0, 31);
    b.addElement(5, 3, 19);
    b.addElement(7, 0, 41);
    b.addElement(0, 2, 59);
    cout << "    MATRIX A:\n\n";
    a.print();
    cout << "    MATRIX B:\n\n";
    b.print();
    cout << "    SUM OF MATRICES A AND B:\n\n";
    a.add(b);
    b.print();
    cout << "END OF TESTING.\n";
    return 0;
}