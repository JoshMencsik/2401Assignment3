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

void College::operator =(const College& other) {
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

void College::add(const course& item) {
    node* cursor = head;
    node* prev = head;
    node* tmp;

    if (head == NULL) { //check for the empty list
        head = new node(item, NULL);
    }
    else { //actually go through and find the course's alphabetical spot
            //need a case for when you want to put the couse at the begining
        if (item.get_course_number() < head -> data().get_course_number()) {
            //make a new node and set its link to the old first, then name 
            //it head to make it first
            tmp = new node(item, head);
            head = tmp;
        }
        else {
            cursor = cursor -> link();
            while (cursor != NULL) {
                if (item.get_course_number() < cursor -> data().get_course_number()) {
                    //for when the inserted course is greater
                    prev -> set_link(new node(item, cursor));
                    return;
                }
                cursor = cursor -> link();
                prev = prev -> link();
            }
            //insert cursor at the end of list if the loop never triggered
            prev -> set_link(new node(item, cursor));
        }
    }
}

void College::remove(const std::string courseName) {

}

int College::hours() const {

    return 11;
}

int College::gpa() const {

    return 11;
}

void College::load(std::istream& ins) {

}

void College::save(std::ostream& outs) const {

}

