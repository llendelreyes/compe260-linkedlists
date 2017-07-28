//
//  Driver.cpp
//  Program #3 Linked Lists
//
// Created by Llendel Reyes.
// Copyright © 2017 Llendel Reyes. All rights reserved.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

void print(List st)

{ st.display(cout); }

int main() {
    
    List l;
    
    int indexnum, listnum;
    
    cout << "Empty List created?" << endl
    << boolalpha << l.empty() << endl
    << endl;
    
    cout << "How many elements do you want to add to the List: ";
    
    cin >> listnum;
    
    for (int i = 1; i <= listnum; i++)
        
        l.push(10 * i);
    
    cout << "Is list empty? " << endl
    << l.empty() << endl
    << endl;
    
    cout << "List L:"<<endl<<endl;
    
    cout << "**"<<endl;
    print(l);
    cout << "**";
    cout << endl<<endl;
    
    cout << "invalid index or (>0) will terminate function" << endl
    << endl;
    
    while (true) {
        cout << "Enter Index: ";
        
        cin >> indexnum;
        
        if (indexnum >= listnum || indexnum < 0) {
            
            cout << endl
            << indexnum << " is an invalid index. Program will now terminate!" << endl;
            
            break;
        }
        
        else {
            cout << "Index " << indexnum << " contains: " << l.GetNth(indexnum) << endl
            << endl;
        }
    }
    
    cout << endl
    << "Size of List L: " << l.Length() << " values" << endl;
    
    cout << "Post-Split List (via function): " << l.Split() << endl
    << endl;
}
