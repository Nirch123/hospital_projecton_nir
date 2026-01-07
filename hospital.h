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
	virtual ~Hospital();
	const char* getName() const;
	const char* getDepartmentName(int num) const;
	const int getDepartmentsCount() const;
	const char* getResearchCenterName() const;
	Department* getDepartmentByName(const char* dName) const;
	Department* getDepartmentByIndex(const int index) const;
	Nurse* getNurseById(int id);
	Doctor* getDoctorById(int id);
	Patient* getPatientById(int id);
	const char* getPatientNameById(int id);
	bool addDepartment(Department& department);
	bool removeDepartment(const Department& department);
	bool addDoctor(const char* name, const int id, Date& birthdate,
		const char* expertise, Person::eGender gender, Department* department = nullptr);
	bool addNurse(const char* name, const int id, 
		const Date& birthdate, Person::eGender gender, Department* department = nullptr, int YoE = 0);
	bool addPatient(const char* name, int id, const Date& birthdate, Person::eGender gender, const char* visitpurpose,
		const Date& dateofarrival, Department* department = nullptr, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	Date& createDate(int day, int month, int year);
	bool printDepartments();
	bool printWorkersInDepartment(Department& department);
	bool printPatientsInDepartment(Department& department);
	friend ostream& operator<<(ostream& os, const Hospital& hospital);
	bool updatePatientInformation(Patient* p,  Department* department = nullptr, Doctor* doctor = nullptr, Nurse* nurse = nullptr);

private:
	char* name;
	int logicalDepartments,physicalDepartments;
	Department** departments;
	Researchcenter& researchCenter;
	Hospital(Hospital& other);
	Date* date;
};

#endif
