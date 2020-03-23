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
        void operator =(const College& other);

        void display(std::ostream& outs) const;

        void set_name(const std::string& n) {name = n;}

        void add(const course& item);

        void remove(const std::string courseName);

        double hours() const;

        void load(std::istream& ins);

        void save(std::ostream& outs) const;
        //unimplemented
        int gpa() const;

    private:
        std::string name;
        node* head;
};



#endif