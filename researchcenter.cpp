#pragma warning (disable: 4996)
using namespace std;
#include "researchcenter.h"
#include <iostream>

Researchcenter::Researchcenter(const char* name)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	logicalResearchers = 2;
	physicalResearchers = 0;
	allResearchers = new Researcher * [logicalResearchers];
}

Researchcenter::~Researchcenter()
{
	cout << "\nDEBUG: in ~Researchcenter()";
	for (int i = 0; i < physicalResearchers; i++)
		delete allResearchers[i];

	delete[] allResearchers;
	delete[] name;
}

const char* Researchcenter::getName() const { return name; }

bool Researchcenter::addResearcher(Researcher* r)
{
	if (physicalResearchers == logicalResearchers)
	{
		logicalResearchers *= 2;
		Researcher** temp = new Researcher * [logicalResearchers];
		for (int i = 0; i < physicalResearchers; i++)
			temp[i] = allResearchers[i];
		delete[] allResearchers;
		allResearchers = temp;
	}

	allResearchers[physicalResearchers++] = r;
	return true;
}

const Researcher* Researchcenter::getResearcherById(int id) const
{
	for (int i = 0; i < physicalResearchers; i++)
	{
	
		if (allResearchers[i]->getId() == id)
			return allResearchers[i];
	}
	return nullptr;
}

bool Researchcenter::addArticleToResearcher(int researcherId, const Article& article)
{
	for (int i = 0; i < physicalResearchers; i++)
	{
		if (allResearchers[i]->getId() == researcherId)
		{
			return allResearchers[i]->addArticle(article);
		}
	}
	return false;
}

void Researchcenter::printAllResearchers() const
{
	if (physicalResearchers == 0)
		cout << "\nNo researchers in center.";
	else
	{
		cout << "\nList of Researchers in " << name << ":";
		for (int i = 0; i < physicalResearchers; i++)
			cout << "\n" << *allResearchers[i];
	}
}

ostream& operator<<(ostream& os, const Researchcenter& researchcenter)
{
	os << "Research Center: " << researchcenter.name
		<< " (Researchers count: " << researchcenter.physicalResearchers << ")";
	return os;
}

bool HaveMoreArticle(const Researcher& r1, const Researcher& r2)
{
	return r1 > r2;
}

Researchcenter& Researchcenter::operator+=(const Researcher& other)
{
	Researcher* newR = new Researcher(other);

	this->addResearcher(newR);

	return *this;
}