#pragma warning (disable: 4996)
#include "department.h"
#include "patient.h"
#include <iostream>
using namespace std;


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

Department::Department(const Department& other) : physicalWorkers(other.physicalWorkers) , 
logicalWorkers(other.logicalWorkers), physicalPatients(other.physicalPatients), logicalPatients(other.logicalPatients)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	for (int i = 0; i < physicalWorkers; i++)
		other.workerarr[i] = workerarr[i];
	for (int i = 0; i < physicalPatients; i++)
		other.patientArr[i] = patientArr[i];
}

Department::~Department() 
{
	if (name != nullptr)
		delete[] name; 
}

bool Department::addWorker(Worker* worker)
{
	for (int i = 0; i < physicalWorkers; i++)  // check if worker id is in department already
		if (worker->getId() == workerarr[i]->getId())
			return false;

	if (workerarr[logicalWorkers-1] != nullptr) // check if department worker array is full and expand if nesscery
	{
		logicalWorkers = logicalWorkers * 2;
		Worker** temp = new Worker * [logicalWorkers];
		for (int i = 0; i < physicalWorkers; i++)
			temp[i] = workerarr[i];
		delete[] workerarr;
		workerarr = temp;
	}

	workerarr[physicalWorkers] = worker;
	if (worker->getWorkerDepartment() != workerarr[physicalWorkers]->getWorkerDepartment())
		worker->setWorkerDepartment(this); // make sure worker acknowledges it's new department
	physicalWorkers++;
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
	if (patient->getPatientDepartment() != patientArr[physicalPatients]->getPatientDepartment())
		patient->setPatientDepartment(this); 
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

const char* Department::getName() const { return name; }

const int Department::getWorkersAmount() const { return physicalWorkers; }

//const Department::eWorkerType Department::getWorkerType(Worker* worker) const { return workertype; }

const Worker& Department::getWorkerByIndex(int index) const { return *workerarr[index]; }


ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name;
	return os;
}
