#pragma once
#include "patient.h"
#include "child.h"
#include "adult.h"
#include<vector>

class Hospital //SINGLETON
{
private:
	static Hospital* init;
	std::string nameDoctor;
	std::vector<Patient*> patients;
	double price;
	Hospital() {}
	Hospital& operator=(const Hospital& H) {return *this;}
	Hospital(const Hospital& H) {}
public:
	static Hospital* getInit(std::string, double);
	void menu();
	void addPatient(Patient*);
	void displayAllPatients();
	void displayPriceConsultation(Patient *);
};
Hospital* Hospital::init = nullptr;

Hospital* Hospital::getInit(std::string nameDoctor, double price)
{
	if(init == nullptr)
	{
		init = new Hospital();
		init->nameDoctor = nameDoctor;
		init->price = price;
	}
	return init;
}

void Hospital::menu()
{
	std::cout << "Menu:\n";
	std::cout << "1.Add a patient.\n";
	std::cout << "2.Display all patients.\n";
	std::cout << "3.Display the price of a consulatation.\n";
	std::cout << "4.Exit.\n";
}

void Hospital::addPatient(Patient *P)
{
	patients.push_back(P);
}

void Hospital::displayAllPatients()
{
	std::cout << "Children:\n";
	for(unsigned int i = 0; i < patients.size(); ++i)
	{
		if(patients[i]->get_type() == "Children")
		{
			patients[i]->writeData(std::cout);
		}
	}

	std::cout << "Adults:\n";
	for(unsigned int i = 0; i < patients.size(); ++i)
	{
		if(patients[i]->get_type() == "Adult")
		{
			patients[i]->writeData(std::cout);
		}
	}
}

void Hospital::displayPriceConsultation(Patient *P)
{
	int newPrice = price;
	if(P->get_type() == "Adult")
	{
		newPrice *= 1.25;
	}

	if(P->getCardiovascularRisk() == "Low")
	{
		newPrice *= 1.5;
	}
	else
	{
		newPrice *= 2.5;
	}

	std::cout << "Price: " << newPrice;
}