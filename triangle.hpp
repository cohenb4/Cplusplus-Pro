#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape2d.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
class Triangle : public Shape2D
{
protected:
    vector<double> vside; //creates vector for sides

public:
    static int ntriangle; //number of triangle objects
    static double area; //cumulative triangle area
    static double perimeter; //cumulative triangle perimeter

    Triangle(const double &s0, const double &s1, const double &s2)
    {
        vside.resize(3); //sets vector side
        vside[0] = s0; //sets location 0 as side 0
        vside[1] = s1; //sets location 1 as side 1
        vside[2] = s2; //sets location 2 as side 2
        ++ntriangle; //static variable for number of triangles is incremented during construction
        area += this->calcArea(); //adds area to total areas
        perimeter += this->calcPerimeter(); //adds perimeter to total perimeter
    }

    double calcArea() override
    {
        double s = ((vside[0] + vside[1] + vside[2]) / 2.0); //Heron's formula
        return sqrt(s * (s - vside[0]) * (s - vside[1]) * (s - vside[2]));
    }

    double calcPerimeter() override
    {
        return  (vside[0] + vside[1] + vside[2]); //calculates perimeter
    }

    double getNoTri()
    {
        return ntriangle;
    }

    void setSide1(const double side1)
    {
        vside[0] = side1; //sets side 1 to side 1
    }

    void setSide2(const double side2)
    {
        vside[1] = side2; //sets side 2 to side 2
    }
    void setSide3(const double side3)
    {
        vside[2] = side3; //sets side 3 to side 3
    }

    void print(ofstream &outf) const override
    {
        outf << "triangle" << " " << vside[0] << " " << vside[1] << " " << vside[2] << endl;
    }

    ~Triangle() override{
        --ntriangle; //removes from total number of triangles
        area -= this->calcArea(); //removes area from total area
        perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
    }; //destructor - removes from total count and total area and perimeter

};

/*Triangle::~Triangle(){
    --ntriangle; //removes from total number of triangles
    area -= this->calcArea(); //removes area from total area
    perimeter -= this->calcPerimeter(); //removes perimeter from total perimeter
}; //destructor - removes from total count and total area and perimeter*/

int Triangle::ntriangle = 0;
double Triangle::area = 0;
double Triangle::perimeter = 0;

#endif // TRIANGLE_HPP
