//
//  LinkedList.cpp
//  Program #3 Linked Lists
//
// Created by Llendel Reyes.
// Copyright © 2017 Llendel Reyes. All rights reserved.

#include <new>
using namespace std;

#include "LinkedList.h"

List::List()
: myTop(0) {}

List::List(const List &original) {
    myTop = 0;
    if (!original.empty()) {
        
        myTop = new List::Node(original.top());
        
        List::NodePointer prevPtr = myTop,
        originalPtr = original.myTop->next;
        
        while (originalPtr != 0) {
            prevPtr->next = new List::Node(originalPtr->listData);
            prevPtr = prevPtr->next;
            originalPtr = originalPtr->next;
        }
    }
}

List::~List() {
    
    List::NodePointer currentPtr = myTop,
    nextPtr;
    while (currentPtr != 0) {
        nextPtr = currentPtr->next;
        delete currentPtr;
        currentPtr = nextPtr;
    }
}

const List &List::operator=(const List &rightSide) {
    if (this != &rightSide) {
        this->~List();
        if (rightSide.empty())
            myTop = 0;
        else {
            
            myTop = new List::Node(rightSide.top());
            
            List::NodePointer prevPtr = myTop,
            rsPtr = rightSide.myTop->next;
            
            while (rsPtr != 0) {
                prevPtr->next = new List::Node(rsPtr->listData);
                prevPtr = prevPtr->next;
                rsPtr = rsPtr->next;
            }
        }
    }
    return *this;
}

bool List::empty() const {
    return (myTop == 0);
}

void List::push(const ListElement &numvalue) {
    myTop = new List::Node(numvalue, myTop);
}

void List::display(ostream &out) const {
    List::NodePointer pointer;
    for (pointer = myTop; pointer != 0; pointer = pointer->next)
        out << pointer->listData << endl;
}

ListElement List::top() const {
    if (!empty())
        return (myTop->listData);
    else {
        cerr << "*** Empty list. ***\n -- Returning Trash --" << endl;
        ListElement *tempV = new (ListElement);
        ListElement trash = *tempV;
        delete tempV;
        return trash;
    }
}

void List::pop() {
    if (!empty()) {
        List::NodePointer pointer = myTop;
        myTop = myTop->next;
        delete pointer;
    } else
        cerr << "*** Empty List. Cannot remove a value. ***" << endl;
}

ListElement List::Length() {
List:
    NodePointer CurrentPtr = myTop;
    int counter = 1;
    
    while (CurrentPtr->next != NULL) {
        counter++;
        CurrentPtr = CurrentPtr->next;
    }
    
    return counter;
}

ListElement List::GetNth(ListElement userIndex) {
    
List:
    NodePointer CurrentPtr = myTop;
    int counter = 0;
    
    while (CurrentPtr->next != NULL) {
        if (counter == userIndex) {
            return CurrentPtr->listData;
        }
        
        counter++;
        CurrentPtr = CurrentPtr->next;
    }
    
    return CurrentPtr->listData;
}

ListElement List::Split() {
    int i;
    
List:
    NodePointer CurrentPtr = myTop, First, Last;
    
    if (Length() < 2) {
        First = myTop;
        Last = NULL;
    }
    
    else {
        int hopCounter = Length() / 2;
        for (i = 0; i < hopCounter; i++) {
            CurrentPtr = CurrentPtr->next;
        }
    }
    
    First = myTop;
    Last = CurrentPtr->next;
    CurrentPtr->next = NULL;
    
    return CurrentPtr->listData;
}
