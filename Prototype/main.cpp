#include<iostream>
#include<vector>
#include "prototype.h"

class Factory
{
private:
	static Room* prototypes[2];
public:
	static Room* getRoom(int);
};
Room* Factory::prototypes[] = {new Restaurant, new ConferenceRoom};

Room* Factory::getRoom(int choice)
{
	return prototypes[choice]->clone();
}


int main()
{
	std::vector<Room*> rooms;

	while(true)
	{
		int choice;
		std::cin >> choice;
		if(choice != 1 || choice != 2)
		{
			break;
		}
		rooms.push_back(Factory::getRoom(choice));
	}
}