#pragma once
#include<vector>

class Room
{
private:
	static int numberRoom;
protected:
	std::string id;
	int capacity;
public:
	Room(std::string = "", int = 0);
	Room(const Room &R);
	virtual ~Room();

	virtual Room* clone() = 0;
	virtual void readData(std::istream &);
	virtual void writeData(std::ostream &);	
};
int Room::numberRoom = 0;


Room::Room(std::string id_p, int capacity_p) : id(id_p), capacity(capacity_p){this->numberRoom++;}

Room::Room(const Room &R) : id(R.id), capacity(R.capacity) {this->numberRoom++;}

Room::~Room(){this->numberRoom--;}

void Room::readData(std::istream& in)
{
	std::cout << "Enter the id of the room.\n";
	in >> id;
	std::cout << "Enter the capacity of the room.\n";
	in >> capacity;
}

void Room::writeData(std::ostream &out)
{
	out << "\nThe id of the room is " << id;
	out << "\nThe capacity of the room is " << capacity;
}


//////
class ConferenceRoom: public Room
{
private:
	bool videoProjector;
public:
	ConferenceRoom(std::string = "", int = 0, bool = 0);
	ConferenceRoom(const ConferenceRoom &R);

	Room* clone();
	void readData(std::istream &);
	void writeData(std::ostream &);	
};

ConferenceRoom::ConferenceRoom(std::string id_p, int capacity_p, bool projector) : Room(id_p, capacity_p), videoProjector(projector) {}

ConferenceRoom::ConferenceRoom(const ConferenceRoom &R) : Room(R) {videoProjector = R.videoProjector;}

Room* ConferenceRoom::clone()
{
	return new ConferenceRoom(*this);
}

void ConferenceRoom::readData(std::istream& in)
{
	Room::readData(in);
	std::cout << "Enter 1 if the conference room has a video projector or 0 otherwise.\n";
	in >> videoProjector;
}

void ConferenceRoom::writeData(std::ostream &out)
{
	Room::writeData(out);
	if(videoProjector)
	{
		out << "\nThe conference room has a video projector.";
	}
	else
	{
		out << "\nThe conference room doesn't have a video projector.";
	}
}


/////
class Restaurant: public Room
{
private:
	std::vector<int> tables;
public:
	Restaurant(std::string = "", int = 0);
	Restaurant(const Restaurant &R);

	Room* clone();
	void readData(std::istream &);
	void writeData(std::ostream &);	
};

Restaurant::Restaurant(std::string id_p, int capacity_p) : Room(id_p, capacity_p) {}

Restaurant::Restaurant(const Restaurant &R) : Room(R) {tables = R.tables;}

Room* Restaurant::clone()
{
	return new Restaurant(*this);
}

void Restaurant::readData(std::istream& in)
{
	Room::readData(in);
	std::cout << "Enter the number of tables.\n";
	int noTables;
	in >> noTables;
	for(int i = 0; i < noTables; ++i)
	{
		int number;
		in >> number;
		tables.push_back(number);
	}
}
void Restaurant::writeData(std::ostream &out)
{
	Room::writeData(out);
	out << "\nThe number of tables is " << tables.size() << "\n";
	for(unsigned int i = 0; i < tables.size(); ++i)
	{
		out << tables[i] << " "; 
	}
}