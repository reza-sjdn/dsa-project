// List class-template definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h" // ListNode class definition


template<typename NODETYPE>
class List {
public:
   // constructor
   List() {firstPtr = nullptr; lastPtr = nullptr;}


   // destructor
   ~List() {
      if (!isEmpty()) { // List is not empty
         ListNode<NODETYPE>* currentPtr{firstPtr};
         ListNode<NODETYPE>* tempPtr{nullptr};

         while (currentPtr != nullptr) { // delete remaining nodes
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;  
            delete tempPtr;
         } 
      } 
   } 


   // insert node at front of list
   void pushFront(const NODETYPE& value) {
      ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

      if (isEmpty()) { // List is empty
         firstPtr = lastPtr = newPtr; // new list has only one node
      } 
      else { // List is not empty
         newPtr->nextPtr = firstPtr; // point new node to old 1st node
         firstPtr = newPtr; // aim firstPtr at new node
      } 
   } 


   // insert node at back of list
   void pushBack(const NODETYPE& value) {
      ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

      if (isEmpty()) { // List is empty
         firstPtr = lastPtr = newPtr; // new list has only one node
      } 
      else { // List is not empty
         lastPtr->nextPtr = newPtr; // update previous last node
         lastPtr = newPtr; // new last node
      } 
   } 


   // insert node anywhere in the list
   void insert(ListNode<NODETYPE>* pos, const NODETYPE& value) {
      ListNode<NODETYPE>* newPtr{getNewNode(value)}; // new node

      if ((pos == firstPtr) || isEmpty()) pushFront(value);
      else {
         newPtr->nextPtr = pos;

         ListNode<NODETYPE>* currentPtr{firstPtr};
         while (currentPtr->nextPtr != pos) {
            currentPtr = currentPtr->nextPtr;
         } // get the address of one node before pos

         currentPtr->nextPtr = newPtr;
      }
   }


   // delete node from front of list and return the status
   bool popFront(NODETYPE& value) {
      if (isEmpty()) { // List is empty
         return false; // delete unsuccessful
      } 
      else {
         ListNode<NODETYPE>* tempPtr{firstPtr}; // hold item to delete

         if (firstPtr == lastPtr) {
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
         } 
         else {
            firstPtr = firstPtr->nextPtr; // point to previous 2nd node
         } 

         value = tempPtr->data; // return data being removed
         delete tempPtr; // reclaim previous front node
         return true; // delete successful
      } 
   } 


   // delete node from back of list
   bool popBack(NODETYPE& value) {
      if (isEmpty()) { // List is empty
         return false; // delete unsuccessful
      } 
      else {
         ListNode<NODETYPE>* tempPtr{lastPtr}; // hold item to delete

         if (firstPtr == lastPtr) { // List has one element
            firstPtr = lastPtr = nullptr; // no nodes remain after removal
         }
         else {
            ListNode<NODETYPE>* currentPtr{firstPtr};

            // locate second-to-last element            
            while (currentPtr->nextPtr != lastPtr) {   
               currentPtr = currentPtr->nextPtr; // move to next node
            }

            lastPtr = currentPtr; // remove last node
            currentPtr->nextPtr = nullptr; // this is now the last node
         } 

         value = tempPtr->data; // return value from old last node
         delete tempPtr; // reclaim former last node
         return true; // delete successful
      } 
   } 


   // delete node anywhere in the list
   bool remove(ListNode<NODETYPE>* pos, NODETYPE& value) {
      if (pos == firstPtr) return popFront(value); // pos pointing to first node
      else if (pos == lastPtr) return popBack(value); // pos pointing to last node
      else {
         if (isEmpty()) return false; // no node
         else {
            ListNode<NODETYPE>* currentPtr{firstPtr};

            // go forward untill one node before pos
            while (currentPtr->nextPtr != pos) currentPtr = currentPtr->nextPtr;
            currentPtr->nextPtr = pos->nextPtr;
            value = pos->data;
            delete pos;
            return true;
         }
      }

   }


   // search for a specific node
   ListNode<NODETYPE>* search(const NODETYPE& key) const {
      ListNode<NODETYPE>* currentPtr{firstPtr};
      
      do {
         if (currentPtr->data == key) return currentPtr;
         currentPtr = currentPtr->nextPtr;
      }
      while (currentPtr);

      return nullptr;
   }


   // is List empty?
   bool isEmpty() const {
      return firstPtr == nullptr; 
   } 


   // display contents of List
   void print() const {
      if (isEmpty()) { // List is empty
         std::cout << "The list is empty\n\n";
         return;
      } 

      ListNode<NODETYPE>* currentPtr{firstPtr};

      while (currentPtr) { // get element data
         std::cout << currentPtr->data << '\n';
         currentPtr = currentPtr->nextPtr;
      } 

      std::cout << "\n\n";
   } 



   // get functions
   ListNode<NODETYPE>* getFirstPtr() const {return firstPtr;}
   ListNode<NODETYPE>* getLastPtr() const {return lastPtr;}


private:
   ListNode<NODETYPE>* firstPtr; // pointer to first node
   ListNode<NODETYPE>* lastPtr; // pointer to last node  

   // utility function to allocate new node
   ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
      return new ListNode<NODETYPE>{value};
   } 
}; 

#endif