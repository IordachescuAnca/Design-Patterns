#pragma once
#include "patient.h"

class Child: public Patient
{
private:
	std::string nameMother;
	std::string nameFather;
	bool precedent;
	double proteinC;
public:
	Child(int = 0, std::string = "", std::string = "", double = 0, double = 0, std::string = "", std::string = "", bool = 0, double = 0);
	Child(const Child&);
	Child& operator=(const Child&);
	~Child();

	virtual std::string get_type();
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
	std::string getCardiovascularRisk();
};

Child::Child(int age, std::string firstName, std::string lastName, double cholesterol, double bloodPressure, std::string nameMother, std::string nameFather, bool precedent, double proteinC): Patient(age, firstName, lastName, cholesterol, bloodPressure)
{
	this->nameMother = nameMother;
	this->nameFather = nameFather;
	this->precedent = precedent;
	this->proteinC = proteinC;
}

Child::Child(const Child &C):Patient(C)
{
	this->nameMother = C.nameMother;
	this->nameFather = C.nameFather;
	this->precedent = C.precedent;
	this->proteinC = C.proteinC;
}

Child& Child::operator=(const Child &C)
{
	if(this != &C)
	{
		Patient::operator=(C);
		this->nameMother = C.nameMother;
		this->nameFather = C.nameFather;
		this->precedent = C.precedent;
		this->proteinC = C.proteinC;
	}
	return *this;
}

Child::~Child()
{
	this->nameMother = "";
	this->nameFather = "";
	this->precedent = 0;
	this->proteinC = 0;
}

std::string Child::get_type()
{
	return "Child";
}

void Child::readData(std::istream &in)
{
	Patient::readData(in);
	std::cout << "Enter your mother's name.\n";
	in >> nameMother;
	std::cout << "Enter your father's name.\n";
	in >> nameFather;
	std::cout << "Enter 1 if one of your parents has a cardiovascular disease or 0 otherwise.\n";
	in >> precedent;
	std::cout << "Enter the Protein C value.\n";
	in >> proteinC;
}
void Child::writeData(std::ostream &out)
{
	Patient::writeData(out);
	out << "\nProtein C: " << proteinC << " mg/dl";
}

std::string Child::getCardiovascularRisk()
{
	int contor = 0;
	if(cholesterol > 240)
	{
		contor++;
	}
	if(bloodPressure > 139 || bloodPressure < 130)
	{
		contor++;
	}
	if(precedent)
	{
		contor++;
	}
	if(proteinC > 0.6)
	{
		contor++;
	}
	switch(contor)
	{
		case 0:
		return "Low";
		break;
		case 1:
		return "Medium";
		break;
		default:
		return "High";
		break;
	}
}

