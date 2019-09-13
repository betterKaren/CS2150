// Yu Du, yd2am
// ListItr.cpp
// 09/10/2019

#include <iostream>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
using namespace std;

// Constructor
ListItr::ListItr() {
  current = NULL;
}

// One parameter constructor
ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

// returns true if the iterator pointing the past end position
bool ListItr::isPastEnd() const {
  return current->next == NULL;
}

// returns true if the iterator pointing the past first position
bool ListItr::isPastBeginning() const {
  return current->previous == NULL;
}

// advances the current pointer to the next position in the list
void ListItr::moveForward() {
  if(!isPastEnd()) {
    current = current->next;
  }
}

// move current back to the previous position in the list
void ListItr::moveBackward() {
  if(!isPastBeginning()) {
    current = current->previous;
  }
}

// returns the value of the item in the current position of the list
int ListItr::retrieve() const{
  return current->value;
}
