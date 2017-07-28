//
//  Header.h
//  Program #3 Linked Lists
//
//  Created by Llendel Reyes.
//  Copyright © 2017 Llendel Reyes. All rights reserved.


#include <iostream>
using namespace std;

#ifndef LinkedList
#define LinkedList

typedef int ListElement;

class List
{
public:
    List();
    
    
    List(const List & originalList);
    
    ~List();
    
    const List & operator= (const List & rightSide);
    
    bool empty() const;
    
    void push(const ListElement & numvalue);
    
    void display(ostream & out) const;
    
    ListElement top() const;
    
    void pop();
    
    ListElement Length();
    
    ListElement GetNth(ListElement myIndex);
    
    ListElement Split();
    
private:
    class Node
    
    {
        
    public:
        
        ListElement listData;
        
        Node * next;
        
        Node(ListElement numvalue, Node * linker = 0)
        
        : listData(numvalue), next(linker)
        {}
    };
    
    typedef Node * NodePointer;
    
    NodePointer myTop;
};
#endif
