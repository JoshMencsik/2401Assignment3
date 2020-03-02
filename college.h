/*
Josh Mencsik
27 February 2020
The header file for the contain class of courses
Will hold a bunch of college courses in a linked list in a predefined order
*/
#include<iostream>
#include "course.h"
#include "node.h"

#ifndef COLLEGE_H
#define COLLEGE_H

class College {
    public:
        College();

        College(const College& other); 
        ~College();
        College operator =(const College& other);

        void display(std::ostream& outs) const;

        void set_name(string n) {n = name;}

    private:
        string name;
        node* head;
};




#endif