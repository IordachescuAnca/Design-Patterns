#pragma once
#include "shape.h"

class Square: public Shape 
{
private:
	double length;
public:
	Square(std::string = "", double = 0);
	Square(const Square &C);
	Square& operator=(const Square &C);
	~Square();

	virtual std::string getType();
	virtual double getPerimeter();
	virtual double getArea();
	virtual void readData(std::istream &in);
	virtual void writeData(std::ostream &out);
};


Square::Square(std::string color, double length_p) : Shape(color), length(length_p){}

Square::Square(const Square &C): Shape(C), length(C.length){}

Square& Square::operator=(const Square& C)
{
	if(this != &C)
	{
		Shape::operator=(C);
		this->length = C.length;
	}
	return *this;
}

Square::~Square()
{
	this->length = 0;
}

std::string Square::getType()
{
	return "Square";
}

double Square::getPerimeter()
{
	return 4 * length;
}

double Square::getArea()
{
	return length * length;
}

void Square::readData(std::istream &in)
{
	Shape::readData(in);
	std::cout << "Enter the length of the square.\n";
	in >> length;
}

void Square::writeData(std::ostream &out)
{
	Shape::writeData(out);
	out << "\nThe length of the square is " << length;
}