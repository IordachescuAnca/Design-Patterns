#pragma once
#include "shape.h"
#include<cmath>

class Circle: public Shape 
{
private:
	double radius;
	const double PI = atan(1.0)*4;
public:
	Circle(std::string = "", double = 0);
	Circle(const Circle &C);
	Circle& operator=(const Circle &C);
	~Circle();

	virtual std::string getType();
	virtual double getPerimeter();
	virtual double getArea();
	virtual void readData(std::istream &in);
	virtual void writeData(std::ostream &out);
};


Circle::Circle(std::string color, double radius_p) : Shape(color), radius(radius_p){}

Circle::Circle(const Circle &C): Shape(C), radius(C.radius){}

Circle& Circle::operator=(const Circle& C)
{
	if(this != &C)
	{
		Shape::operator=(C);
		this->radius = C.radius;
	}
	return *this;
}

Circle::~Circle()
{
	this->radius = 0;
}

std::string Circle::getType()
{
	return "Circle";
}

double Circle::getPerimeter()
{
	return 2 * PI * radius;
}

double Circle::getArea()
{
	return PI * radius * radius;
}

void Circle::readData(std::istream &in)
{
	Shape::readData(in);
	std::cout << "Enter the radius of the circle.\n";
	in >> radius;
}

void Circle::writeData(std::ostream &out)
{
	Shape::writeData(out);
	out << "\nThe radius of the circle is " << radius;
}