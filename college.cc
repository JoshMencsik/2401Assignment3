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
    head = NULL;
    if(other.head == NULL) {
        head = NULL;
    }
    else {
        node* cursor = other.head;
        while (cursor != NULL) {
            add(cursor -> data());
            cursor = cursor -> link();
        }
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
    //cout << "Destruction" << endl;
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
        //check for duplicates
        if (item.get_course_number() == head -> data().get_course_number()) {
            head -> set_data(item);
        }
            //need a case for when you want to put the couse at the begining
        else if (item.get_course_number() < head -> data().get_course_number()) {
            //make a new node and set its link to the old first, then name 
            //it head to make it first
            tmp = new node(item, head);
            head = tmp;
        }
        else {
            cursor = cursor -> link();
            while (cursor != NULL) {
                if (item.get_course_number() == cursor -> data().get_course_number()) {
                    cursor -> set_data(item);
                    return;
                }
                else if (item.get_course_number() < cursor -> data().get_course_number()) {
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
    node* cursor = head;
    node* prev = head;

    if(head == NULL) //empty list
        return;
    else if(head -> data().get_course_number() == courseName) { //first item
        cursor = head -> link();
        delete head;
        head = cursor;
        return;
    }
    else {
        cursor = head -> link();
        while (cursor != NULL) {
            if (cursor -> link() == NULL && cursor -> data().get_course_number() == courseName) {
                delete cursor;
                prev -> set_link(NULL);
                return;
            }
            else if (cursor -> data().get_course_number() == courseName) {
                prev -> set_link(cursor -> link());
                delete cursor;
                return;
            }
            cursor = cursor -> link();
            prev = prev -> link();
        }
    }
}

double College::hours() const {
    double sum = 0;
    for (node* cursor = head; cursor != NULL; cursor = cursor -> link()) {
        sum += cursor -> data().get_hours();
    }
    
    return sum;
}

int College::gpa() const {
    //take each grade and mult by hours, add all together 
    //then divide by total hours()
    double sum = 0;

    for (node* cursor = head; cursor != NULL; cursor = cursor -> link()) {
        sum += (cursor -> data().get_number_grade() * cursor -> data().get_hours());
    }

    return sum/hours();
}

void College::load(std::istream& ins) {
    course tmp;
    node* cursor;
    if (ins.peek() == '\n') 
        ins.ignore();

    getline(ins, name);
    while (ins.peek() == '\n') 
        ins.ignore();

    ins >> tmp;
    head = new node(tmp);
    cursor = head;
    while (ins >> tmp) {
        cursor -> set_link(new node(tmp));
        cursor = cursor -> link();
    }
    cursor -> set_link(NULL);
}

void College::save(std::ostream& outs) const {
    outs << name << endl;
    for (node* cursor = head; cursor != NULL; cursor = cursor -> link()) {
        outs << cursor -> data();
    }
}

