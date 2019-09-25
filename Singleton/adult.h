#pragma once
#include "patient.h"

class Adult: public Patient
{
private:
	bool isSmoker;
	std::string sedentariness;
public:
	Adult(int = 0, std::string = "", std::string = "", double = 0, double = 0, bool = 0, std::string = "");
	Adult(const Adult&);
	Adult& operator=(const Adult&);
	~Adult();

	virtual std::string get_type();
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
	std::string getCardiovascularRisk();
};

Adult::Adult(int age, std::string firstName, std::string lastName, double cholesterol, double bloodPressure, bool isSmoker, std::string sedentariness): Patient(age, firstName, lastName, cholesterol, bloodPressure)
{
	this->isSmoker = isSmoker;
	this->sedentariness = sedentariness;
}

Adult::Adult(const Adult &A):Patient(A)
{
	this->isSmoker = A.isSmoker;
	this->sedentariness = A.sedentariness;
}

Adult& Adult::operator=(const Adult &A)
{
	if(this != &A)
	{
		this->isSmoker = isSmoker;
		this->sedentariness = sedentariness;
	}
	return *this;
}

Adult::~Adult()
{
	this->isSmoker = 0;
	this->sedentariness = "";
}

std::string Adult::get_type()
{
	return "Adult";
}

void Adult::readData(std::istream& in)
{
	Patient::readData(in);
	std::cout << "Enter 1 if you are smoker or 0 otherwise.\n";
	in >> isSmoker;
	std::cout << "Enter your level of sedentariness(low, medium or high):\n";
	in >> sedentariness;
}

void Adult::writeData(std::ostream &out)
{
	Patient::writeData(out);
	out << "\nLevel of sedentariness: " << sedentariness;
	out << "; Smoker: ";
	if(isSmoker)
	{
		out << "Yes";
	}
	else
	{
		out << "No";
	}

}


std::string Adult::getCardiovascularRisk()
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
	if(isSmoker)
	{
		contor++;
	}
	if(sedentariness == "low")
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