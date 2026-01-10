#pragma warning (disable: 4996)
#include "researcher.h"
#include "department.h"

Researcher::Researcher(const char* name, const int id, const Date& birthdate, eGender gender, bool isDoctor)
	: Worker(name, id, birthdate, gender, nullptr), isDoctor(isDoctor)
{
	physicalArticles = 0;
	logicalArticles = 2;
	articles = new Article * [logicalArticles];
}

Researcher::Researcher(const Researcher& other)
	: Worker((Worker&)other), isDoctor(other.isDoctor)
{
	this->logicalArticles = other.logicalArticles;
	this->physicalArticles = other.physicalArticles;


	this->articles = new Article * [this->logicalArticles];

	for (int i = 0; i < this->physicalArticles; i++)
	{
		this->articles[i] = new Article(*other.articles[i]);
	}
}

Researcher::~Researcher()
{
	for (int i = 0; i < physicalArticles; i++)
		delete articles[i];
	delete[] articles;
}

bool Researcher::addArticle(const Article& article)
{
	if (physicalArticles == logicalArticles)
	{
		logicalArticles *= 2;
		Article** temp = new Article * [logicalArticles];
		for (int i = 0; i < physicalArticles; i++)
			temp[i] = articles[i];
		delete[] articles;
		articles = temp;
	}
	articles[physicalArticles++] = new Article(article);
	return true;
}

bool Researcher::getIsDoctor() const { return isDoctor; }

int Researcher::getNumOfArticles() const { return physicalArticles; }

ostream& operator<<(ostream& os, const Researcher& researcher)
{
	os << "\n\tResearcher Info:";
	os << "\n\tName: " << researcher.getName();    
	os << "\n\tID: " << researcher.getWorkerId();   
	os << "\n\tIs Doctor: " << (researcher.isDoctor ? "Yes" : "No");
	os << "\n\tArticles count: " << researcher.physicalArticles;
	if (researcher.physicalArticles > 0)
	{
		os << "\n\tArticles List:";
		for (int i = 0; i < researcher.physicalArticles; i++)
			os << "\n\t\t" << *researcher.articles[i];
	}
	return os;
}

void Researcher::researcherOs(ostream& os) const
{
	os << "\n\tTitle: Researcher";
}

bool Researcher::operator>(const Researcher& other) const
{
	return this->getNumOfArticles() > other.getNumOfArticles();
}


