/*
Josh Mencsik
27 February 2020
Implementation of the college.h file
college is a class that stores course information in a linked list
*/

#include<iostream>
#include"college.h"

using namespace std;

College::College () {
    name = "";
    head = NULL;    
    //when the add function is called, check for null case and add from there
}

College::College(const College& other) {
    name = other.name;

    if(other.head == NULL) {
        head = NULL;
    }
    else {
        head = new node(other.head -> data(), other.head -> link());
        node* tmp = head -> link();
        node* cursor = other.head -> link();
        while (cursor != NULL) {
            tmp = new node(cursor -> data(), cursor -> link());
            tmp = tmp -> link();
            cursor = cursor -> link();
        }
        tmp = NULL;
    }
}

College::~College() {
    node* cursor;
    cursor = head;
    while (cursor != NULL) {
        cursor = head -> link();
        delete head;
        head = cursor;
    }
    cout << "Destruction" << endl;
}

College College::operator =(const College& other) {
    if (other.head == head) 
        return;

    node* otherCur = other.head;
    node* cursor = head;

    while (otherCur != NULL) {
        cursor -> set_data(otherCur -> data());
        cursor = cursor -> link();
        otherCur = otherCur -> link();
        }
    cursor = NULL;
}

void College::display (ostream& outs) const {
    node* cursor = head;

    outs << name << ": " << endl;
    //make sure you check for an empty list
    if (head == NULL) {
        outs << "Empty list" << endl;
    }
    else {
        //the loop to output the contents of the list
        while (cursor != NULL) {
            outs << cursor -> data();
            if (cursor -> link() != NULL) {
                outs << endl;
            }
            cursor = cursor -> link();
        }
    }
}

