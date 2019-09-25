#include<iostream>
#include "patient.h"
#include "child.h"
#include "adult.h"
#include "singleton.h"

int main()
{
	Hospital *Central = Hospital::getInit("Dr.Evans", 100);

	while(true)
	{
		bool exit = 0;
		Central->menu();
		int choice;
		std::cin >> choice;
		Patient *newPatient;
		switch(choice)
		{
			case 1:
			std::cout << "Enter the age.\n";
			int age;
			std::cin >> age;
			if(age < 18)
			{
				newPatient = new Child(age);
			}
			else
			{
				newPatient = new Adult(age);
			}
			newPatient->readData(std::cin);
			Central->addPatient(newPatient);
			break;
			case 2:
			Central->displayAllPatients();
			break;
			case 3:
			newPatient->readData(std::cin);
			Central->displayPriceConsultation(newPatient);
			break;
			case 4:
			exit = 1;
			break;
			default:
			break;
		}
		if(exit)
		{
			break;
		}
	}
	return 0;
}
