#ifndef __PATIENT_H
#define __PATIENT_H

#include <iostream>
using namespace std;

#include "person.h"
#include "department.h"

class Nurse;
class Doctor;

class Patient : public Person
{
public:
	Patient(const char* name,  int id, const Date& birthdate, eGender gender, const char* visitpurpose, const Date& dateofarrival, Department* department=nullptr,
		Doctor* doctor=nullptr, Nurse* nurse=nullptr);
	~Patient();
	const char* getPatientDepartment() const;
	const char* getPatientVisitPurpose() const;
	Doctor* getPatientDoctor() const;
	Nurse* getPatientNurse() const;
	const int getPatientId() const;
	bool setPatientDepartment(Department* department);
	friend ostream& operator<<(ostream& os, const Patient& patient);
	bool setNurse(Nurse* nurse);
	bool setDoctor(Doctor* doctor);



protected:
	const Date& dateofarrival;
	Department* department;
	Doctor* MyDoctor;
	Nurse* MyNurse;
	char* VisitPurpose;
	int PatientId;


private:
	static int PatientIdCounter;
};

#endif
