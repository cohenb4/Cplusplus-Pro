#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape2d.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Rectangle : public Shape2D{
    public:
        Rectangle(const double &s0, const double &s1); //non-default constructor

        void setSides(const double &s0, const double &s2); //setter for side lengths
        double getSide1();
        double getSide2();

        double calcArea() override; //calculates area of the rectangle
        double calcPerimeter() override; //calculates perimeter of rectangle
        void print(ofstream &) const override; //prints dimensions to file
        ~Rectangle() override{
            --nrectangle; //removes from total number of rectangles
            area -= this->calcArea(); //removes area from total area
            perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
        }; //destructor - removes from total count and total area and perimeter

        static int nrectangle; //total # of rectangles
        static double area; //total area of all rectangles
        static double perimeter; //total perimeter of all rectangles

    protected:
        vector<double> vside; //side lengths of rectangle

};

Rectangle::Rectangle(const double &s0, const double &s1){
    vside.resize(2); //sets vector of side lengths to hold two side lengths
    vside.at(0) = s0;
    vside.at(1) = s1;
    ++nrectangle; //adds to total number of rectangles
    area += this->calcArea(); //adds area to total areas
    perimeter += this->calcPerimeter(); //adds perimeter to total perimeter
}

void Rectangle::setSides(const double &s0, const double &s1){
    area -= this->calcArea(); //removes area from total area
    perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
    vside.at(0) = s0;
    vside.at(1) = s1;
    area += this->calcArea(); //adds area to total areas
    perimeter += this->calcPerimeter(); //adds perimeter to total perimeter
} //setter for side lengths - sets side lengths and updates total area and parameter

double Rectangle::getSide1(){
    return vside.at(0);
} //getter for first side

double Rectangle::getSide2(){
    return vside.at(1);
} //getter for second side

/*Rectangle::~Rectangle(){
    --nrectangle; //removes from total number of rectangles
    area -= this->calcArea(); //removes area from total area
    perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
}; //destructor - removes from total count and total area and perimeter*/

double Rectangle::calcArea(){
    return (vside.at(0) * vside.at(1));
} //returns area of rectangle

double Rectangle::calcPerimeter(){
    return (2 * (vside.at(0) + vside.at(1)));
} //returns perimeter of rectangle

void Rectangle::print(ofstream &outf) const{
    outf << "rectangle " << vside.at(0) << " " << vside.at(1) << endl;
} //prints dimensions to file

int Rectangle::nrectangle = 0;
double Rectangle::area = 0;
double Rectangle::perimeter = 0;

#endif // RECTANGLE_HPP
