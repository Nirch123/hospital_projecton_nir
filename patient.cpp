#pragma warning (disable: 4996)

#include "patient.h"
#include "department.h"
#include "doctor.h"
#include "nurse.h"
#include "date.h"
#include "visit.h"

int Patient::PatientIdCounter = 1000;

Patient::Patient(const char* name, int id, const Date& birthdate, eGender gender, const Date& dateofarrival, Department* department,
	Doctor* doctor, Nurse* nurse)
	: Person(name, id, birthdate, gender), PatientId(PatientIdCounter++)
{
	physicalVisits = 0;
	logicalVisits = 1;
	visits = new Visit * [logicalVisits];
}

bool Patient::CreateCheckVisit(const Patient* patient, Date& date, Department* department,
	const char* checkName, Doctor* doctor, Nurse* nurse)
{
	if (visits[logicalVisits - 1] != nullptr) // visits array expansion if full
	{
		logicalVisits *= 2;
		Visit** temp = new Visit * [logicalVisits];
		for (int i = 0; i < physicalVisits; i++)
			temp[i] = visits[i];
		delete[] visits;
		visits = temp;
	}
	visits[physicalVisits] = new Visit(this, date, department, checkName, doctor, nurse);
	return true;
}

bool Patient::CreateSurgeryVisit(const Patient* patient, Date& date, Department* department,
	bool isFast, int opRoom, Doctor* doctor, Nurse* nurse)
{
	if (visits[logicalVisits - 1] != nullptr) // visits array expansion if full
	{
		logicalVisits *= 2;
		Visit** temp = new Visit * [logicalVisits];
		for (int i = 0; i < physicalVisits; i++)
			temp[i] = visits[i];
		delete[] visits;
		visits = temp;
	}
	visits[physicalVisits] = new Visit(this, date, department, isFast, opRoom, doctor, nurse);
	return true;
}

Patient::~Patient() 
{
	cout << "\nDEBUG: in ~Patient()";
	delete[] visits;
}

const int Patient::getPatientId() const { return PatientId; }

const char* Patient::getPatientDepartment() const { return visits[physicalVisits]->getPatientDepartment(); }

Doctor* Patient::getPatientDoctor() const { return visits[physicalVisits]->getPatientDoctor(); }

Nurse* Patient::getPatientNurse() const { return visits[physicalVisits]->getPatientNurse(); }

const char* Patient::getPatientVisitPurpose() const { return visits[physicalVisits]->getPatientVisitPurpose(); }

const Date& Patient::getDateOfArrival() const { return visits[physicalVisits]->getDateOfArrival(); }

bool Patient::setPatientDepartment(Department* new_department)
{
	visits[physicalVisits]->setPatientDepartment(new_department);
	if (new_department->doesPatientExist(this) == false)
		new_department->addPatient(this);
	//if (visits[physicalVisits]->getPatientDepartment() != nullptr)
		//visits[physicalVisits]->getPatientDepartment().addPatient(this);
	return true;
}

bool Patient::setNurse(Nurse* new_nurse)
{
	visits[physicalVisits]->setNurse(new_nurse);
	return true;
}
bool Patient::setDoctor(Doctor* new_doctor)
{
	visits[physicalVisits]->setDoctor(new_doctor);
	return true;
}

ostream& operator<<(ostream& os, const Patient& patient) // by refrence
{
	os << "\tId: " << patient.getId() <<
		"\n\tName: " << patient.getName() <<
		"\n\tGender: " << patient.getGender() <<
		"\n\tDOB: " << patient.birthdate <<
		"\n\tPatient Id : " << patient.getPatientId() <<
		"\n\tDepartment: " << patient.getPatientDepartment() <<
		"\n\tDOA: " << patient.getDateOfArrival() <<
		"\n\tVisit reason: " << patient.getPatientVisitPurpose() <<
		"\n\tAssigned Doctor: " << *patient.getPatientDoctor() <<
		"\n\tAssigned Nurse: " << *patient.getPatientNurse();
	return os;
}

ostream& operator<<(ostream& os, const Patient* patient) // by pointer (for singular patient printing)
{
	os << "\tId: " << patient->getId() <<
		"\n\tName: " << patient->getName() <<
		"\n\tGender: " << patient->getGender() <<
		"\n\tDOB: " << patient->birthdate <<
		"\n\tPatient Id : " << patient->getPatientId() <<
		"\n\tDepartment: " << patient->getPatientDepartment() <<
		"\n\tDOA: " << patient->getDateOfArrival() <<
		"\n\tVisit reason: " << patient->getPatientVisitPurpose() <<
		"\n\tAssigned Doctor: " << *patient->getPatientDoctor() <<
		"\n\tAssigned Nurse: " << *patient->getPatientNurse();
	return os;
}


void Patient::patientOs(ostream& os)
{
	os << "\nDate of arrival: " << getDateOfArrival() <<
		"\nVisit purpose: " << getPatientVisitPurpose() <<
		"\nDepartment: " << getPatientDepartment();
}
