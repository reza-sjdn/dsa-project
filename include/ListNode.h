// ListNode class-template definition.
#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List required to announce that class 
// List exists so it can be used in the friend declaration at line 12
template<typename NODETYPE> class List;                         

template<typename NODETYPE>
class ListNode {
   friend class List<NODETYPE>; // make List a friend

public:
   explicit ListNode(const NODETYPE& info) // constructor
      : data{info}, nextPtr{nullptr} {}

   // set and get functions
   void setData(const NODETYPE& data) {this->data = data;}
   NODETYPE getData() const {return data;} 

   // return a pointer to data field 
   NODETYPE* dataAddress() {return &data;}

   // return a pointer to next node
   ListNode<NODETYPE>* getNextPtr() const {return nextPtr;}

private:
   NODETYPE data; // data
   ListNode<NODETYPE>* nextPtr; // next node in list
}; 

#endif
