#pragma warning (disable: 4996)
#include "hospital.h"
#include "worker.h"
#include "doctor.h"
#include "nurse.h"
#include "date.h"
#include "patient.h"


Hospital::Hospital(const char* name, Researchcenter& rc) : researchCenter(rc)
{
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	departments = new Department* [1];
	logicalDepartments = 1;
	physicalDepartments = 0;
}	

Hospital::~Hospital()
{
	cout << "DEBUG: in ~Hospital()";
	for (int i = 0; i < physicalDepartments; i++)
		delete departments[i]; // pointer only
	delete departments;
	delete[] name;
}

const char* Hospital::getName() const { return name; }

const int Hospital::getDepartmentsCount() const { return physicalDepartments; }

const char* Hospital::getResearchCenterName() const { return researchCenter.getName(); }

bool Hospital::addDepartment(Department& department)
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
	departments[physicalDepartments] = new Department(department);
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

bool Hospital::printDepartments() // printing in "master class" allowed?
{
	cout << "\nHospital departments are : \n";
	for (int i = 0; i < getDepartmentsCount(); i++)
		cout << "(" << i << ") " << getDepartmentName(i) << "\n";
	return true;
}

bool Hospital::printWorkersInDepartment(Department& department)
{
	cout << "\nDepartment " << department << " workers are : \n";
	if (department.getWorkersAmount() == 0)
		cout << "There are no workers in this department\n";
	else
	{
		for (int i = 0; i < department.getWorkersAmount(); i++)
			cout << "(" << i << ") " << department.getWorkerByIndex(i) << "\n\n";
	}
	return true;
}

bool Hospital::printPatientsInDepartment(Department& department)
{
	cout << "\nDepartment " << department << " patients are : \n";
	if (department.getPatientsAmount() == 0)
		cout << "There are no patients in this department\n";
	else
	{
		for (int i = 0; i < department.getPatientsAmount(); i++)
			cout << "(" << i << ") " << department.getPatientByIndex(i) << "\n\n";
	}
	return true;
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

bool Hospital::addDoctor(const char* name, const int id, Date& birthdate,
	const char* expertise, Person::eGender gender, Department* department)
{
	Doctor* d = new Doctor(name,id,birthdate,expertise,gender,department);
	department->addWorker(d);
	return true;
}

bool Hospital::addNurse(const char* name, const int id,
	const Date& birthdate, Person::eGender gender, Department* department, int YoE)
{
	Nurse* n = new Nurse(name, id, birthdate, gender, department, YoE);
	department->addWorker(n);
	return true;
}

bool Hospital::addPatient(const char* name, int id, const Date& birthdate, Person::eGender gender, const char* visitpurpose,
	const Date& dateofarrival, Department* department, Doctor* doctor, Nurse* nurse)
{
	Patient* p = new Patient(name, id, birthdate, gender, visitpurpose, dateofarrival, department, doctor, nurse);
	department->addPatient(p);
	return true;
}

Date& Hospital::createDate(int day, int month, int year)
{
	date = new Date(day,month,year);
	return *date;
}

Nurse* Hospital::getNurseById(int id)
{
	if (physicalDepartments == 0)
		return nullptr; // no departments yet
	for (int i = 0; i < physicalDepartments; i++)
	{
		for (int j = 0; j < departments[i]->physicalWorkers; j++)
		{
			if (id == (departments[i]->workerarr[j]->getWorkerId()))
				return dynamic_cast<Nurse*>(departments[i]->workerarr[j]); // nurse found
		}
	}
	return nullptr; // nurse not found
}

Doctor* Hospital::getDoctorById(int id)
{
	if (physicalDepartments == 0)
		return nullptr; // no departments yet
	for (int i = 0; i < physicalDepartments; i++)
	{
		for (int j = 0; j < departments[i]->physicalWorkers; j++)
		{
			if (id == (departments[i]->workerarr[j]->getWorkerId()))
				return dynamic_cast<Doctor*>(departments[i]->workerarr[j]); // doctor found
		}
	}
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
