#include<iostream>
#include "shape.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"


class MyShape
{
private:
	Shape *pShape;
public:
	MyShape(std::string choice)
	{
		if(choice == "triangle")
		{
			pShape = new Triangle();
		}
		else if(choice == "square")
		{
			pShape = new Square();
		}
		else if(choice == "circle")
		{
			pShape = new Circle();
		}
	}
	~MyShape()
	{
		if(pShape)
		{
			delete pShape;
			pShape = NULL;
		}
	}
	void readData(std::istream &in)
	{
		pShape->readData(in);
	}
	void writeData(std::ostream &out)
	{
		pShape->writeData(out);
	}
	Shape* getShape()
	{
		return pShape;
	}
};


int main()
{
	std::cout << "Enter the shape: circle, square or triangle.\n";
	std::string choice;
	std::cin >> choice;
	MyShape *pShape = new MyShape(choice);
	pShape->readData(std::cin);
	pShape->writeData(std::cout);
	return 0;
}