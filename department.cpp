#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "department.h"
//#include "person.h"
#include "worker.h"
#include "patient.h"


Department::Department(const char* name) 
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name); 
	physicalWorkers = 0;
	logicalWorkers = 1;
	workerarr = new Worker * [logicalWorkers] {nullptr};
	physicalPatients = 0;
	logicalPatients = 1;
	patientArr = new Patient * [logicalPatients] {nullptr};
}

Department::~Department() 
{
	cout << "\nDEBUG: in ~Department()";
	if (name != nullptr)
		delete[] name; 
}

bool Department::addWorker(Worker* worker)
{
	for (int i = 0; i < physicalWorkers; i++)  // check if worker id is in department already
		if (worker->getWorkerId() == workerarr[i]->getWorkerId())
			return false;

	if (logicalWorkers == physicalWorkers) // check if department worker array is full and expand if nesscery
	{
		logicalWorkers = logicalWorkers * 2;
		Worker** temp = new Worker * [logicalWorkers];
		for (int i = 0; i < physicalWorkers; i++)
			temp[i] = workerarr[i];
		delete[] workerarr;
		workerarr = temp;
	}

	workerarr[physicalWorkers] = worker;
	if (strcmp(worker->getWorkerDepartment(),workerarr[physicalWorkers]->getWorkerDepartment()) != 0)
		worker->setWorkerDepartment(this); // make sure worker acknowledges it's new department
	if (worker->getWorkerId() != 0) physicalWorkers++; // if workerId = 0 -> it's a temporary created in main only!!!
	return true;
}

bool Department::addPatient(Patient* patient)
{
	for (int i = 0; i < physicalPatients; i++)  
		if (patient->getId() == patientArr[i]->getId())
			return false;

	if (patientArr[logicalPatients - 1] != nullptr) 
	{
		logicalPatients = logicalPatients * 2;
		Patient** temp = new Patient * [logicalPatients];
		for (int i = 0; i < physicalPatients; i++)
			temp[i] = patientArr[i];
		delete[] patientArr;
		patientArr = temp;
	}

	patientArr[physicalPatients] = patient;
	//if (strcmp(patient->getPatientDepartment(),patientArr[physicalPatients]->getPatientDepartment()))
		//patient->setPatientDepartment(this); 
	physicalPatients++;
	return true;
}

bool Department::removeWorker(Worker* worker)
{
	for (int i = 0; i < physicalWorkers; i++)  // check if worker id is in department already
		if (worker->getId() == workerarr[i]->getId())
		{
			workerarr[i]->setWorkerDepartment(nullptr);
			int j = i;
			do
			{
				workerarr[j] = workerarr[j + 1];
				++j;
			}
			while (j < physicalWorkers);
			--physicalWorkers;
			return true; // worker was found and removed from department
		}
		return false; // worker was not found
}

bool Department::removePatient(Patient* patient)
{
	for (int i = 0; i < physicalPatients; i++) 
		if (patient->getId() == patientArr[i]->getId())
		{
			patientArr[i]->setPatientDepartment(nullptr);
			int j = i;
			do
			{
				patientArr[j] = patientArr[j + 1];
				++j;
			} while (j < physicalPatients);
			--physicalPatients;
			return true; 
		}
	return false;
}

const char* Department::getName() const 
{
	if (this == nullptr)
		return "NONE";
	else
		return name; 
}

const int Department::getWorkersAmount() const { return physicalWorkers; }

const int Department::getPatientsAmount() const { return physicalPatients; }

const Worker& Department::getWorkerByIndex(int index) const { return *workerarr[index]; }

const Patient& Department::getPatientByIndex(int index) const { return *patientArr[index]; }

ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name;
	return os;
}

const bool Department::doesPatientExist(const Patient* patient)
{
	for (int i = 0; i < physicalPatients; i++)
		if (patient->getId() == patientArr[i]->getId())
			return true;
	return false;
}

