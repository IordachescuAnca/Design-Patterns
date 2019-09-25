
#include<iostream>
#include "builder.h"

int main()
{
	Book *p = Book::Builder().setAuthor("Rogers").setInitials("C. R.").setTitle("On becoming a person").setYear(1961).setPublisher("Houghton Mifflin.").setLocation("Boston").build();
	p->printData(std::cout);
}