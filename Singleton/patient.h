#pragma once

class Patient
{
private:
	static int numberPatient;
protected:
	std::string firstName;
	std::string lastName;
	int age;
	double cholesterol;
	double bloodPressure;
public:
	Patient(int = 0,std::string = "", std::string = "", double = 0, double = 0);
	Patient(const Patient&);
	Patient& operator=(const Patient&);
	virtual ~Patient();

	virtual std::string get_type() = 0;
	virtual void readData(std::istream&);
	virtual void writeData(std::ostream&);
	virtual std::string getCardiovascularRisk() = 0;

	static int getNumberPatient();
	
};
int Patient::numberPatient = 0;

Patient::Patient(int age, std::string firstName, std::string lastName, double cholesterol, double bloodPressure)
{
	this->numberPatient++;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->cholesterol = cholesterol;
	this->bloodPressure = bloodPressure;
}
Patient::Patient(const Patient& P)
{
	this->numberPatient++;
	this->firstName = P.firstName;
	this->lastName = P.lastName;
	this->age = P.age;
	this->cholesterol = P.cholesterol;
	this->bloodPressure = P.bloodPressure;
}
Patient& Patient::operator=(const Patient &P)
{
	if(this != &P)
	{
		this->firstName = P.firstName;
		this->lastName = P.lastName;
		this->age = P.age;
		this->cholesterol = P.cholesterol;
		this->bloodPressure = P.bloodPressure;
	}
	return *this;
}

Patient::~Patient()
{
	this->numberPatient--;
	this->firstName = "";
	this->lastName = "";
	this->age = 0;
	this->cholesterol = 0;
	this->bloodPressure = 0;
}

void Patient::readData(std::istream& in)
{
	std::cout << "Enter your first name.\n";
	in >> firstName;
	std::cout << "Enter your last name.\n";
	in >> lastName;
	std::cout << "Enter the value of cholesterol.\n";
	in >> cholesterol;
	std::cout << "Enter the value of blood pressure.\n";
	in >> bloodPressure;
}

void Patient::writeData(std::ostream& out)
{
	out << firstName << " " << lastName << ": Cardiovascular risk: " << getCardiovascularRisk() << "; ";
	out << "Cholesterol: " << cholesterol << " mg/dl; Blood pressure: " << bloodPressure;
}

int Patient::getNumberPatient()
{
	return numberPatient;
}