#pragma once
#include "shape.h"
#include<cmath>

class Triangle: public Shape 
{
private:
	double side1;
	double side2;
	double side3;
public:
	Triangle(std::string = "", double = 0, double = 0, double = 0);
	Triangle(const Triangle &C);
	Triangle& operator=(const Triangle &C);
	~Triangle();

	virtual std::string getType();
	virtual double getPerimeter();
	virtual double getArea();
	virtual void readData(std::istream &in);
	virtual void writeData(std::ostream &out);
};


Triangle::Triangle(std::string color, double side1, double side2, double side3) : Shape(color), side1(side1), side2(side2), side3(side3){}

Triangle::Triangle(const Triangle &C): Shape(C), side1(C.side1), side2(C.side2), side3(C.side3){}

Triangle& Triangle::operator=(const Triangle& C)
{
	if(this != &C)
	{
		Shape::operator=(C);
		this->side1 = C.side1;
		this->side2 = C.side2;
		this->side3 = C.side3;
	}
	return *this;
}

Triangle::~Triangle()
{
	this->side1 = this->side2 = this->side3 = 0;
}

std::string Triangle::getType()
{
	return "Triangle";
}

double Triangle::getPerimeter()
{
	return side1 + side2 + side3;
}

double Triangle::getArea()
{
	return sqrt(getPerimeter()/2 * (getPerimeter()/2 - side1) * (getPerimeter()/2 - side2) * (getPerimeter()/2 - side3));
}

void Triangle::readData(std::istream &in)
{
	Shape::readData(in);
	std::cout << "Enter the side no. 1 of the triangle.\n";
	in >> side1;
	std::cout << "Enter the side no. 2 of the triangle.\n";
	in >> side2;
	std::cout << "Enter the side no. 3 of the triangle.\n";
	in >> side3;
}

void Triangle::writeData(std::ostream &out)
{
	Shape::writeData(out);
	out << "\nThe side no.1 of the triangle is " << side1;
	out << "\nThe side no.2 of the triangle is " << side2;
	out << "\nThe side no.3 of the triangle is " << side3;
}