#ifndef __RESEARCHCENTER_H
#define __RESEARCHCENTER_H

using namespace std;
#include <iostream>
#include "researcher.h" 

class Researchcenter
{
public:
	Researchcenter(const char* name);
	~Researchcenter();

	const char* getName() const;

	bool addResearcher(Researcher* r);

	bool addArticleToResearcher(int researcherId, const Article& article);

	const Researcher* getResearcherById(int id) const;

	void printAllResearchers() const;

	friend ostream& operator<<(ostream& os, const Researchcenter& researchcenter);

	bool HaveMoreArticle(const Researcher& r1, const Researcher& r2);

	Researchcenter& operator+=(const Researcher& researcher);

private:
	char* name;

	Researcher** allResearchers;
	int physicalResearchers;
	int logicalResearchers;
};

#endif