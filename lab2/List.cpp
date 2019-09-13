// Yu Du, yd2am
// List.cpp
// 09/09/2019

#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
#include "List.h"
using namespace std;

// Constructor
List::List() {
  head = new ListNode;
  tail = new ListNode;
  count = 0;

  head->next = tail;
  tail->previous = head;
}

// Copy Constructor
List::List(const List& source) {
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
  ListItr iter(source.head->next);
  while(!iter.isPastEnd()) {       // deep copy of the list
    insertAtTail(iter.retrieve());
    iter.moveForward();
  }
}

// Destructor
List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

// Equals operator
List& List::operator=(const List& source) {
  if (this == &source)
    return *this;
  else {
    makeEmpty();
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
    }
  }
  return *this;
}

// true if the list is empty, else false
bool List::isEmpty() const {
  if(count == 0)
    return true;
  else
    return false;
}

// removes all items from a list except dummy head and tail nodes
void List::makeEmpty() {
  ListNode *cur = head->next;
  
  while(cur != tail) {
    ListNode *temp;
    cur->previous->next = cur->next;
    cur->next->previous = cur->previous;

    // delete current listnode and keep iteration
    temp = cur;
    cur = cur->next;
    delete temp;

    count--;
  }
}

// returns an iterator points to the first ListNode (after head ListNode)
ListItr List::first() {
  return ListItr(head->next);
}

// returns an iterator points to the last ListNode (before tail ListNode)
ListItr List::last() {
  return ListItr(tail->previous);
}

// inserts x after current iterator position
void List::insertAfter(int x, ListItr position) {
  ListNode *newNode = new ListNode;
  newNode->value = x;
  // ListItr has current position!
  newNode->previous = position.current;
  newNode->next = position.current->next;

  position.current->next->previous = newNode;
  position.current->next = newNode;

  count++;
}

// insert x before current iterator position
void List::insertBefore(int x, ListItr position) {
  ListNode *newNode = new ListNode;
  newNode->value = x;
  newNode->previous = position.current->previous;
  newNode->next = position.current;
 
  position.current->previous->next = newNode;
  position.current->previous = newNode;

  count++;
}

// insert x at tail of list
void List::insertAtTail(int x) {
  ListNode *newNode = new ListNode;
  newNode->value = x;
  newNode->previous = tail->previous;
  newNode->next = tail;

  tail->previous->next = newNode;
  tail->previous = newNode;

  count++;
}

// remove the first occurence of x
void List::remove(int x) {
  // use ListItr to find the place of x
  ListItr node = find(x);
  node.current->previous->next = node.current->next;
  node.current->next->previous = node.current->previous;
  
  delete node.current;
  count--;
}

// returns an iterator that points to the first occurence of x
ListItr List::find(int x) {
  // start from the first listnode
  ListItr iter = first();

  // while it's not the end of the list
  while(!iter.isPastEnd()) {
    if(iter.current->value == x)
      return iter;
    else
      iter.moveForward();
  }
  // when x is not in the list, return a ListIter object
  // where the current pointer points to the dummy tail node
  return iter;
}

// returns the number of elements in the list
int List::size() const {
  int size;
  ListNode *temp;
  temp = head->next;
  // cout<< "Hi" << endl;
  while(temp != NULL){
    size++;
    temp = temp->next;
  }
  // dummy tail counted
  size = size-2;
  cout << "size = " << size << endl;
  return size;
}

// prints a list either forwards or backwards
void printList(List& theList, bool forward){
  ListItr iter; 
  if(forward) {
    iter = theList.first();
    
    while(!iter.isPastEnd()) {
      cout << "Forward: " << iter.retrieve() << endl;
      iter.moveForward();
    }
  }

  else {
    iter = theList.last();

    while(!iter.isPastBeginning()) {
      cout << "Backward:" << iter.retrieve() << endl;
      iter.moveBackward();
    }
  }
}


