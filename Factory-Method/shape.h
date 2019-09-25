#pragma once


class Shape
{
private:
	static int numberShape;
protected:
	std::string color;
public:
	Shape(std::string = "");
	Shape(const Shape &S);
	Shape& operator=(const Shape &S);
	virtual ~Shape();

	virtual std::string getType() = 0;
	virtual double getPerimeter() = 0;
	virtual double getArea() = 0;
	virtual void readData(std::istream &in);
	virtual void writeData(std::ostream &out);
	static int getNumberShape();

};
int Shape::numberShape = 0;

Shape::Shape(std::string color_p) : color(color_p)
 {this->numberShape++;}

Shape::Shape(const Shape &S) : color(S.color) {this->numberShape++;}

Shape& Shape::operator=(const Shape &S)
{
	if(this != &S)
	{
		this->color = S.color;
	}
	return *this;
}

Shape::~Shape() {this->color = ""; this->numberShape--;}

void Shape::readData(std::istream &in)
{
	std::cout << "Enter the color of the shape.\n";
	in >> color;
}

void Shape::writeData(std::ostream &out)
{
	out << "The color of the shape is " << color;
}

int Shape::getNumberShape()
{
	return numberShape;
}