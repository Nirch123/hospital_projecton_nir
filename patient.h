#ifndef __PATIENT_H
#define __PATIENT_H

#include <iostream>
using namespace std;

#include "person.h"
class Department;
class Nurse;
class Doctor;
class Visit;

class Patient : public Person
{
public:
	Patient(const char* name,  int id, const Date& birthdate, eGender gender, const Date& dateofarrival, Department* department,
		Doctor* doctor=nullptr, Nurse* nurse=nullptr);
	virtual ~Patient();
	const char* getPatientDepartment() const;
	const char* getPatientVisitPurpose() const;
	const Date& getDateOfArrival() const;
	Doctor* getPatientDoctor() const;
	Nurse* getPatientNurse() const;
	const int getPatientId() const;
	bool setPatientDepartment(Department* department);
	friend ostream& operator<<(ostream& os, const Patient& patient);
	friend ostream& operator<<(ostream& os, const Patient* patient);
	bool CreateCheckVisit(const Patient* patient, Date& date, Department* department,
		const char* checkName, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	bool CreateSurgeryVisit(const Patient* patient, Date& date, Department* department,
		bool isFast, int opRoom, Doctor* doctor = nullptr, Nurse* nurse = nullptr);
	virtual void patientOs(ostream& os);
	bool setNurse(Nurse* nurse);
	bool setDoctor(Doctor* doctor);
	friend class Hospital;

protected:
	//const Date dateofarrival;
	//Department* department;
	//Doctor* MyDoctor;
	//Nurse* MyNurse;
	Visit** visits;
	int PatientId, physicalVisits, logicalVisits;


private:
	static int PatientIdCounter;
};

#endif
