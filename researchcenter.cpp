#pragma warning (disable: 4996)
using namespace std;
#include "researchcenter.h"
#include <iostream>
//Zubi
Researchcenter::Researchcenter(const char* name) : NumOfResearchers(0)
{ 
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name); 
}

Researchcenter::~Researchcenter() { delete[] name; }

const char* Researchcenter::getName() const { return name; }

const int Researchcenter::getNumOfResearchers() const { return NumOfResearchers; }


ostream& operator<<(ostream& os, const Researchcenter& researchcenter)
{
	os << researchcenter.name;

	return os;
}

/*bool Researchcenter::addResearcher(Researcher* r)
{
	AllResearcher[NumOfResearcher++] = r;
	return true;
}*/
