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
	Hospital(const char* name, const char* rc_name);
	virtual ~Hospital();
	const char* getName() const;
	const char* getDepartmentName(int num) const;
	const int getDepartmentsCount() const;
	const int getDepartmentWorkersCount(const char* departmentName) const;
	const int getDepartmentPatientsCount(const char* departmentName) const;
	const int getStaffAmount() const;
	const bool doesDepartmentExist(const char* departmentName) const;
	const char* getResearchCenterName() const;
	Department* getDepartmentByName(const char* dName) const;
	Department* getDepartmentByIndex(const int index) const;
	Nurse* getNurseById(int id);
	Doctor* getDoctorById(int id);
	Patient* getPatientById(int id);
	const char* getPatientNameById(int id);
	bool addDepartment(const char* departmentName);
	bool removeDepartment(const Department& department);
	bool addDoctor(Doctor& doctor);
	bool operator+=(Doctor& doctor);
	bool addSurgeon(Surgeon& surgeon);
	bool operator+=(Surgeon& surgeon);
	bool addNurse(Nurse& nurse);
	bool operator+=(Nurse& nurse);
	bool addPatient(const char* name, int id, const Date& birthdate, Person::eGender gender,
		const Date& dateofarrival, Department* department, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	Date& createDate(int day, int month, int year);
	//bool printPatientsInDepartment(Department& department);
	friend ostream& operator<<(ostream& os, const Hospital& hospital);
	bool updatePatientInformation(Patient* p,  Department* department = nullptr, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	Researchcenter* getResearchCenter();

private:
	char* name;
	int logicalDepartments,physicalDepartments, logicalStaff, physicalStaff, logicalPatients, physicalPatients;
	Department** departments;
	Worker** staff;
	Patient** patients;
	Researchcenter researchCenter;
	Hospital(Hospital& other);
	Date* date;
	static int idCounter;
};

#endif
