#pragma warning (disable: 4996)

#include "visit.h"
#include "department.h"

Visit::Visit(Patient* patient, Date& date, Department* department,
	const char* checkName, Doctor* doctor, Nurse* nurse)
	: patient(patient), DOA(date), department(department)
	  ,doctor(doctor), nurse(nurse)
{
	check = new Check(checkName);
	surgery = nullptr;
	visitType = CHECK;
}

Visit::Visit(Patient* patient, Date& date, Department* department,
	bool isFast, int opRoom, Doctor* doctor, Nurse* nurse)
	: patient(patient), DOA(date), department(department)
	, doctor(doctor), nurse(nurse)
{
	surgery = new Surgery(isFast, opRoom);
	check = nullptr;
	visitType = SURGERY;
}

const char* Visit::getPatientDepartment() const { return department->getName(); }

Doctor* Visit::getPatientDoctor() const { return doctor; }

Nurse* Visit::getPatientNurse() const { return nurse; }

const char* Visit::getPatientVisitPurpose() const // for printing
{ 
	if (visitType == CHECK)
		return "Check";
	else
		return "Surgery";
}

const Date& Visit::getDateOfArrival() const { return DOA; }

bool Visit::setPatientDepartment(Department* new_department)
{
	department = new_department;
	if (new_department->doesPatientExist(patient) == false)
		new_department->addPatient(patient);
	//if (department != nullptr)
		//department->addPatient(patient);
	return true;
}

bool Visit::setNurse(Nurse* new_nurse)
{
	nurse = new_nurse;
	return true;
}
bool Visit::setDoctor(Doctor* new_doctor)
{
	doctor = new_doctor;
	return true;
}
