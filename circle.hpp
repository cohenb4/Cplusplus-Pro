#ifndef circle_HPP
#define circle_HPP
#include "shape2d.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class Circle : public Shape2D
{

protected:
    double radius; // radius is specific to Circle

public:
    static int ncircle; //number of circle objects
    static double area; //cumulative circle area
    static double perimeter; //cumulative circle perimeter

    Circle(double rad);
    void setRadius(double rad);
    double getRadius();

    double calcArea() override{
     double term = PI*pow(radius,2);
     return term; // return by value
     }

    double calcPerimeter() override
    {
        return 2 * PI * radius;
    }

    double getNoCircle()
    {
        return ncircle;
    }


    void print(ofstream &outf) const override{
     outf << "circle" << " " << radius << endl;
    }

    ~Circle() override{
        --ncircle; //removes from total number of circles
        area -= this->calcArea(); //removes area from total area
        perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
    } //destructor - removes from total count and total area and perimeter
};

Circle::Circle(double rad)
{
    radius = rad;
    ++ncircle;
    area += calcArea();
    perimeter += calcPerimeter();
}

void Circle::setRadius(double rad) {
    radius = rad;
}

double Circle::getRadius() {
    return radius;
}

/*Circle::~Circle(){
    --ncircle; //removes from total number of circles
    area -= this->calcArea(); //removes area from total area
    perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
}; //destructor - removes from total count and total area and perimeter*/

int Circle::ncircle = 0;
double Circle::area = 0;
double Circle::perimeter = 0;

#endif // circle_HPP
