#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include <iostream>
using namespace std;

#include "department.h";
#include "researchcenter.h"
#include "person.h"
class Date;

class Hospital
{
public:
	Hospital(const char* name, Researchcenter& rc);
	~Hospital();
	const char* getName() const;
	const char* getDepartmentName(int num) const;
	const int getDepartmentsCount() const;
	const char* getResearchCenterName() const;
	Department* getDepartmentByName(const char* dName) const;
	bool addDepartment(Department& department);
	bool removeDepartment(const Department& department);
	bool addDoctor(const char* name, const int id, Date& birthdate,
		const char* expertise, Person::eGender gender, Department* department = nullptr);
	bool addNurse(const char* name, const int id, 
		const Date& birthdate, Person::eGender gender, Department* department = nullptr, int YoE = 0);
	Date& createDate(int day, int month, int year);
	bool printDepartments();
	bool printWorkersInDepartment(Department& department);
	friend ostream& operator<<(ostream& os, const Hospital& hospital);

private:
	char* name;
	int logicalDepartments,physicalDepartments;
	Department** departments;
	Researchcenter& researchCenter;
	Hospital(Hospital& other);
	Date* date;
};

#endif
