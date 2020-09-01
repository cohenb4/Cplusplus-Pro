#ifndef SHAPE2D_HPP
#define SHAPE2D_HPP
#include <iostream>
#include <fstream>
using namespace std;

class Shape2D{
public:
    virtual double calcArea() = 0; //virtual function for calculating area
    virtual double calcPerimeter() = 0; //virtual function for calculating perimeter
    virtual void print(ofstream &) const = 0; //virtual function for printing to file
    virtual ~Shape2D() = 0; //virtual destructor
    friend ofstream & operator <<(ofstream &, const Shape2D &); //overloads <<
};

Shape2D::~Shape2D() {}

ofstream & operator <<(ofstream &outf, const Shape2D &s2d){
    s2d.print(outf); //calls print function from derived classes
    return outf;
} //prints to file

#endif // SHAPE2D_HPP
