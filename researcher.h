#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "worker.h"
#include "article.h"

class Researcher : public Worker
{
public:
	Researcher(const char* name, const int id, const Date& birthdate, eGender gender, bool isDoctor);
	Researcher(const Researcher& other);
	virtual ~Researcher();

	bool addArticle(const Article& article);
	bool getIsDoctor() const;
	int getNumOfArticles() const;

	friend ostream& operator<<(ostream& os, const Researcher& researcher);
	virtual void researcherOs(ostream& os) const;
	bool operator>(const Researcher& other) const;

private:
	bool isDoctor;
	Article** articles;
	int logicalArticles;
	int physicalArticles;
};

#endif