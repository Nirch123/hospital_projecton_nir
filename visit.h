#ifndef __VISIT_H
#define __VISIT_H

#include <iostream>
using namespace std;

#include "date.h"
#include "check.h"
#include "surgery.h"
class Department;
class Patient;
class Doctor;
class Nurse;

class Visit
{
public:
	enum eVisit {CHECK, SURGERY};
	Visit(Patient* patient, Date& date, Department* department,
		const char* checkName, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	Visit(Patient* patient, Date& date, Department* department,
		bool isFast, int opRoom ,Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	~Visit();
	const char* getPatientDepartment() const;
	const char* getPatientVisitPurpose() const;
	const Date& getDateOfArrival() const;
	Doctor* getPatientDoctor() const;
	Nurse* getPatientNurse() const;
	bool setPatientDepartment(Department* department);
	bool setNurse(Nurse* nurse);
	bool setDoctor(Doctor* doctor);

protected:
	Date DOA; //Date Of Arrival
	Department* department;
	Patient* patient;
	Doctor* doctor;
	Nurse* nurse;
	Check* check;
	Surgery* surgery;
	eVisit visitType;
private:
	Visit(Visit& other);

};

#endif