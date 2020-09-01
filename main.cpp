#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include "shape2d.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"

using namespace std;

const int &nshapes = 2000; //number of lines in Shape.txt file

int main()
{
    string shapestr; //declares shapestr
    int icounter = 0; //loop counter
    double radius; //delcares radius
    double side1, side2, side3; //delclares sides
    double width, length; //delares width and length

    ifstream infile;
    infile.open("C:\\Users\\Gus\\Documents\\qt\\finalproject\\Shapes.txt"); //opens "Shape.txt" (2001 lines) for reading

    ofstream outfile;
    outfile.open("C:\\Users\\Gus\\Documents\\qt\\finalproject\\ShapesOut.txt"); //opens "ShapesOut.txt" for writing

    vector<Shape2D *> vptr_shape(nshapes, nullptr); //size 2000

    while(1)
    {
        infile >> shapestr; //reads a string
        if(shapestr == "circle") //checks if circle
        {
            infile >> radius; //reads radius
            vptr_shape[icounter] = new Circle(radius); //constructs circle
            vptr_shape[icounter]->calcArea(); //calls calcArea()
            vptr_shape[icounter]->calcPerimeter(); //calls calcPerimter()
        }

        else if(shapestr == "triangle") //checks for triangle
        {
            infile >> side1; //reads side1
            infile >> side2; //reads side2
            infile >> side3; //reads side3
            vptr_shape[icounter] = new Triangle(side1, side2, side3); //constructs Triangle
            vptr_shape[icounter]->calcArea(); //cals calcArea()
            vptr_shape[icounter]->calcPerimeter();
        }

        else if(shapestr == "rectangle")
        {
            infile >> width;
            infile >> length;
            vptr_shape[icounter] = new Rectangle(width, length);
            vptr_shape[icounter]->calcArea();
            vptr_shape[icounter]->calcPerimeter();
        }

        else if (shapestr == "EOF")
        {
            break; //terminating condition
        }

        else
        {
            cout << "Error: UNRECOGNIZED SHAPE, Line no." << icounter + 1 << endl;
            return 1; //return with code '1'
        }

        outfile << *vptr_shape[icounter]; //derefernces pointer
        ++icounter; //increments loop counter
    }

    cout << "Number of Circles = " << Circle::ncircle << ", Total Circle Area = " << Circle::area << ", Total Circle Perimeter = " << Circle::perimeter << endl;
    cout << "Number of Triangles = " << Triangle::ntriangle << ", Total Triangle Area = " << Triangle::area << ", Total Triangle Perimeter = " << Triangle::perimeter << endl;
    cout << "Number of Rectangles = " << Rectangle::nrectangle << ", Total Rectangle Area = " << Rectangle::area << ", Total Rectangle Perimeter = " << Rectangle::perimeter << endl;

    infile.close();
    outfile.close();
    return 0;
}
