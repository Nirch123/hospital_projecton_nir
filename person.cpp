#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "person.h"

Person::Person(const char* name, const int id,const Date& birthdate, const eGender gender) : id(id), birthdate(birthdate)
{
	this->gender = gender;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Person::Person(const char* name, Date& birthdate) : birthdate(birthdate)
{
	id = 0;
	gender = eGender::MALE;
}

Person::~Person()
{
	delete[] name;
	cout << "\nDEBUG: in Person::~Person()";
}

const char* Person::getName() const { return name; }

const int Person::getId() const { return id; }

const int Person::getGender() const { return gender; }