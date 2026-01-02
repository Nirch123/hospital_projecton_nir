#include <iostream>
using namespace std;

#include "patient.h"
#include "department.h"
#include "doctor.h"
#include "nurse.h"

int Patient::PatientIdCounter = 1000;

Patient::Patient(const char* name,  int id, const Date& birthdate, eGender gender, Department* department, Doctor* doctor, Nurse* nurse,const Date& date,const char* visitpurpose)
	: Person(name, id, birthdate, gender), PatientId(PatientIdCounter++), MyDoctor(doctor), MyNurse(nurse), dateofarrival(date)
{
	setPatientDepartment(department);
	//strcpy
}

Patient::~Patient() {}

const int Patient::getPatientId() const { return PatientId; }

const char* Patient::getPatientDepartment() const { return department->getName(); }

Doctor* Patient::getPatientDoctor() const { return this->MyDoctor; }

Nurse* Patient::getPatientNurse() const { return this->MyNurse; }

const char* Patient::getPatientVisitPurpose() const { return this->VisitPurpose; }

bool Patient::setPatientDepartment(Department* new_department)
{
	department = new_department;
	if (department != nullptr)
		department->addPatient(this);
	return true;
}

ostream& operator<<(ostream& os, const Patient& patient)
{
	os << "Patient Id: " << patient.getPatientId() << " Name: " << patient.getName()
		<< " Gender: " << patient.getGender() << " Department: " << patient.department->getName();
	return os;
}
