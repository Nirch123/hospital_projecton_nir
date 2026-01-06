#pragma warning (disable: 4996)

#include "patient.h"
#include "department.h"
#include "doctor.h"
#include "nurse.h"
#include "date.h"

int Patient::PatientIdCounter = 1000;

Patient::Patient(const char* name, int id, const Date& birthdate, eGender gender, const char* visitpurpose, const Date& dateofarrival, Department* department,
	Doctor* doctor, Nurse* nurse) : Person(name, id, birthdate, gender), PatientId(PatientIdCounter++), MyDoctor(doctor), MyNurse(nurse), dateofarrival(dateofarrival)
{
	setPatientDepartment(department);
	this->VisitPurpose = new char[strlen(visitpurpose) + 1];
	strcpy(this->VisitPurpose, visitpurpose);
}

Patient::~Patient() {}

const int Patient::getPatientId() const { return PatientId; }

const char* Patient::getPatientDepartment() const { return department->getName(); }

Doctor* Patient::getPatientDoctor() const { return this->MyDoctor; }

Nurse* Patient::getPatientNurse() const { return this->MyNurse; }

const char* Patient::getPatientVisitPurpose() const { return this->VisitPurpose; }

const Date& Patient::getDateOfArrival() const { return dateofarrival; }

bool Patient::setPatientDepartment(Department* new_department)
{
	department = new_department;
	if (department != nullptr)
		department->addPatient(this);
	return true;
}

bool Patient::setNurse(Nurse* new_nurse)
{
	MyNurse = new_nurse;
	return true;
}
bool Patient::setDoctor(Doctor* new_doctor)
{
	MyDoctor = new_doctor;
	return true;
}

ostream& operator<<(ostream& os, const Patient& patient)
{
	os << "\tId: " << patient.getId() << "\n\tName: " << patient.getName()
		<< "\n\tGender: " << patient.getGender() << "\n\tDOB: " << patient.birthdate << "\tPatient Id : " << patient.getPatientId()
		<< "\n\tDepartment: " << patient.department->getName() << "\n\tDOA: " << patient.getDateOfArrival()
		<< "\tVisit reason: " << patient.getPatientVisitPurpose() << "\n\tAssigned Doctor: " << patient.getPatientDoctor()
		<< "\n\tAssigned Nurse: " << patient.getPatientNurse();
	return os;
}

void Patient::patientOs(ostream& os)
{
	os << "\nDate of arrival: " << dateofarrival << "\nVisit purpose: " << VisitPurpose << "\nDepartment: " << department;
}
