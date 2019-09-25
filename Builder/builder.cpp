#include "builder.h"

Book::Book(Builder *B)
{
	this->lastNameAuthor = B->lastNameAuthor;
	this->firstInitials = B->firstInitials;
	this->publicationYear = B->publicationYear;
	this->bookTitle = B->bookTitle;
	this->location = B->location;
	this->publisher = B->publisher;
}

Book::Builder::Builder(std::string author, std::string initials, int year, std::string title, std::string location, std::string publisher)
{
	this->lastNameAuthor = author;
	this->firstInitials = initials;
	this->publicationYear = year;
	this->bookTitle = title;
	this->location = location;
	this->publisher = publisher;
}

Book::Builder& Book::Builder::setAuthor(std::string author)
{
	this->lastNameAuthor = author;
	return *this;
}

Book::Builder& Book::Builder::setInitials(std::string initials)
{
	this->firstInitials = initials;
	return *this;
}

Book::Builder& Book::Builder::setYear(int year)
{
	this->publicationYear = year;
	return *this;
}

Book::Builder& Book::Builder::setTitle(std::string title)
{
	this->bookTitle = title;
	return *this;
}

Book::Builder& Book::Builder::setLocation(std::string location)
{
	this->location = location;
	return *this;
}

Book::Builder& Book::Builder::setPublisher(std::string publisher)
{
	this->publisher = publisher;
	return *this;
}

Book* Book::Builder::build()
{
	return new Book(this);
}
