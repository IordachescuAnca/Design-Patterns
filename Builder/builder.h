#pragma once
#include<string>

class Book
{
private:
	std::string lastNameAuthor;
	std::string firstInitials;
	int publicationYear;
	std::string bookTitle;
	std::string location;
	std::string publisher;
public:

	class Builder
	{
	private:
		std::string lastNameAuthor;
		std::string firstInitials;
		int publicationYear;
		std::string bookTitle;
		std::string location;
		std::string publisher;
	public:
		Builder(std::string = "", std::string = "", int = 0, std::string = "", std::string = "", std::string = "");
		Builder& setAuthor(std::string);
		Builder& setInitials(std::string);
		Builder& setYear(int);
		Builder& setTitle(std::string);
		Builder& setLocation(std::string);
		Builder& setPublisher(std::string);
		Book *build();
		friend class Book;
	};

	Book(Builder *);
	~Book();
};