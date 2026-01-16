#pragma warning (disable: 4996)
#include "hospital.h"
#include "worker.h"
#include "doctor.h"
#include "nurse.h"
#include "date.h"
#include "patient.h"
#include "surgeon.h"

int Hospital::idCounter = 100;

Hospital::Hospital(const char* name, const char* rc_name) : researchCenter(rc_name)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	departments = new Department* [1];
	staff = new Worker* [1];
	patients = new Patient* [1];
	logicalDepartments = 1;
	physicalDepartments = 0;
	physicalStaff = 0;
	logicalStaff = 1;
	physicalPatients = 0;
	logicalPatients = 1;
}	

Hospital::~Hospital()
{
	cout << "DEBUG: in ~Hospital()";
	for (int i = 0; i < physicalDepartments; i++)
		delete departments[i]; // pointer only
	delete departments;
	delete[] staff; // check if it deletes all staff! (shows in DEBUG)
	delete[] name;
}

const char* Hospital::getName() const { return name; }

const int Hospital::getDepartmentsCount() const { return physicalDepartments; }

const int Hospital::getStaffAmount() const { return physicalStaff; }

const char* Hospital::getResearchCenterName() const { return researchCenter.getName(); }

bool Hospital::addDepartment(const char* departmentName)
{
	if (physicalDepartments == logicalDepartments) // extension of departments array
	{
		logicalDepartments = logicalDepartments * 2;
		Department** temp = new Department* [logicalDepartments];
		for (int i = 0; i < physicalDepartments; i++)
			temp[i] = departments[i];
		delete[] departments;
		departments = temp;
	}
	departments[physicalDepartments] = new Department(departmentName);
	physicalDepartments++;
	return true;
}

bool Hospital::removeDepartment(const Department& department)
{
	if (&department == nullptr)
		return false;
	for (int i = 0; i < physicalDepartments; i++)
	{
		if (strcmp(department.getName(), departments[i]->getName()) == 0)
		{
			delete departments[i];
			int j = i;
			do
			{
				departments[j] = departments[j+1];
				j++;
			} while (j < physicalDepartments);
			physicalDepartments--;
			return true; // department was found, deleted and others reorganized
		}
	}
	return false; // department was not found
}

ostream& operator<<(ostream& os, const Hospital& hospital)
{
	os << hospital.name;
	return os;
}

const char* Hospital::getDepartmentName(int num) const
{
	return departments[num]->getName();
}

const bool Hospital::doesDepartmentExist(const char* departmentName) const
{
	for (int i = 0; i < physicalDepartments; i++)
	{
		if (strcmp(departmentName, departments[i]->getName()) == 0)
			return true;
	}
	return false;
}


const int Hospital::getDepartmentWorkersCount(const char* departmentName) const
{
	if (doesDepartmentExist(departmentName) == true)
	{
		return getDepartmentByName(departmentName)->getWorkersAmount();
	}
	else
		return -1;
}

const int Hospital::getDepartmentPatientsCount(const char* departmentName) const
{
	if (doesDepartmentExist(departmentName) == true)
	{
		return getDepartmentByName(departmentName)->getPatientsAmount();
	}
	else
		return -1;
}


Department* Hospital::getDepartmentByName(const char* dName) const
{
	for (int i = 0; i < getDepartmentsCount(); i++)
	{
		if (strcmp(departments[i]->getName(), dName) == 0)
			return (departments[i]);
	}
	return nullptr;
}

Department* Hospital::getDepartmentByIndex(const int index) const { return departments[index]; }

bool Hospital::addDoctor(Doctor& doctor)
{
	Doctor* d = new Doctor(doctor);
	d->setWorkerId(idCounter++);
	staff[physicalStaff] = d;
	++physicalStaff;
	if (physicalStaff == logicalStaff) // extension of staff array
	{
		logicalStaff = logicalStaff * 2;
		Worker** temp = new Worker * [logicalStaff];
		for (int i = 0; i < physicalStaff; i++)
			temp[i] = staff[i];
		delete[] staff;
		staff = temp;
	}
	if (doctor.getWorkerDepartment() != nullptr)
		getDepartmentByName((staff[physicalStaff-1])->getWorkerDepartment())->addWorker(staff[physicalStaff-1]);	
	return true;
}


bool Hospital::operator+=(Doctor& doctor)
{
	addDoctor(doctor);
	return true;
}

bool Hospital::addSurgeon(Surgeon& surgeon)
{
	Surgeon* s = new Surgeon(surgeon);
	s->setWorkerId(idCounter++);
	staff[physicalStaff] = s;
	++physicalStaff;
	if (physicalStaff == logicalStaff) // extension of staff array
	{
		logicalStaff = logicalStaff * 2;
		Worker** temp = new Worker * [logicalStaff];
		for (int i = 0; i < physicalStaff; i++)
			temp[i] = staff[i];
		delete[] staff;
		staff = temp;
	}
	if (surgeon.getWorkerDepartment() != nullptr)
		getDepartmentByName((staff[physicalStaff - 1])->getWorkerDepartment())->addWorker(staff[physicalStaff - 1]);
	return true;
}


bool Hospital::operator+=(Surgeon& surgeon)
{
	addSurgeon(surgeon);
	return true;
}

bool Hospital::addNurse(Nurse& nurse)
{
	Nurse* n = new Nurse(nurse);
	n->setWorkerId(idCounter++);
	staff[physicalStaff] = n;
	++physicalStaff;
	if (physicalStaff == logicalStaff) // extension of staff array
	{
		logicalStaff = logicalStaff * 2;
		Worker** temp = new Worker * [logicalStaff];
		for (int i = 0; i < physicalStaff; i++)
			temp[i] = staff[i];
		delete[] staff;
		staff = temp;
	}
	if (nurse.getWorkerDepartment() != nullptr)
		getDepartmentByName((staff[physicalStaff - 1])->getWorkerDepartment())->addWorker(staff[physicalStaff - 1]);
	return true;
}

bool Hospital::operator+=(Nurse& nurse)
{
	addNurse(nurse);
	return true;
}

bool Hospital::addPatient(const char* name, int id, const Date& birthdate, Person::eGender gender, const char* visitpurpose,
	const Date& dateofarrival, Department* department, Doctor* doctor, Nurse* nurse)
{
	Patient* p = new Patient(name, id, birthdate, gender, visitpurpose, dateofarrival, department, doctor, nurse);
	patients[physicalPatients] = p;
	++physicalPatients;
	if (physicalPatients == logicalPatients) // extension of patients array
	{
		logicalPatients = logicalPatients * 2;
		Patient** temp = new Patient * [logicalPatients];
		for (int i = 0; i < physicalPatients; i++)
			temp[i] = patients[i];
		delete[] patients;
		patients = temp;
	}
	department->addPatient(p);
	return true;
}

Date& Hospital::createDate(int day, int month, int year)
{
	Date tempDate(day,month,year);
	return tempDate;
}

Nurse* Hospital::getNurseById(int id)
{
	if (physicalStaff == 0)
		return nullptr;
	for (int i = 0; i < physicalStaff; i++)
	{
		if (staff[i]->getWorkerId() == id)
			return dynamic_cast<Nurse*>(staff[i]);
	}
	/*if (physicalDepartments == 0)
		return nullptr; // no departments yet
	for (int i = 0; i < physicalDepartments; i++)
	{
		for (int j = 0; j < departments[i]->physicalWorkers; j++)
		{
			if (id == (departments[i]->workerarr[j]->getWorkerId()))
				return dynamic_cast<Nurse*>(departments[i]->workerarr[j]); // nurse found
		}
	}*/
	return nullptr; // nurse not found
}

Doctor* Hospital::getDoctorById(int id)
{
	if (physicalStaff == 0)
		return nullptr;
	for (int i = 0; i < physicalStaff; i++)
	{
		if (staff[i]->getWorkerId() == id)
			return dynamic_cast<Doctor*>(staff[i]);
	}
	/*if (physicalDepartments == 0)
		return nullptr; // no departments yet
	for (int i = 0; i < physicalDepartments; i++)
	{
		for (int j = 0; j < departments[i]->physicalWorkers; j++)
		{
			if (id == (departments[i]->workerarr[j]->getWorkerId()))
				return dynamic_cast<Doctor*>(departments[i]->workerarr[j]); // doctor found
		}
	}*/
	return nullptr; // doctor not found
}

Patient* Hospital::getPatientById(int id)
{
	if (physicalDepartments == 0)
		return nullptr; // no departments yet
	for (int i = 0; i < physicalDepartments; i++)
	{
		for (int j = 0; j < departments[i]->physicalPatients; j++)
		{
			if (id == (departments[i]->patientArr[j]->getId()))
				return departments[i]->patientArr[j]; // patient found
		}
	}
	return nullptr; // patient not found
}

bool Hospital::updatePatientInformation(Patient* p, Department* department, Doctor* doctor, Nurse* nurse)
{
	p->setPatientDepartment(department);
	p->setDoctor(doctor);
	p->setNurse(nurse);
	return true;
}

const char* Hospital::getPatientNameById(int id)
{
	for (int i = 0; i < physicalPatients; i++)
	{
		if (patients[i]->getId() == id)
			return patients[i]->getName();
	}
	return "Patient ID was not found";
	/*Patient* temp = getPatientById(id);
	if (temp != nullptr)
		return temp->getName();
	else
		return "ERROR";*/
}

Researchcenter* Hospital::getResearchCenter()
{
	return &researchCenter; 
}
