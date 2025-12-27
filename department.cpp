#pragma warning (disable: 4996)
#include "department.h"
#include <iostream>
using namespace std;


Department::Department(const char* name) 
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name); 
	physicalWorkers = 0;
	logicalWorkers = 1;
	workerarr = new Worker * [logicalWorkers];
}

Department::Department(const Department& other) : physicalWorkers(other.physicalWorkers) , 
logicalWorkers(other.logicalWorkers)
{
	this->name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	for (int i = 0; i < physicalWorkers; i++)
		other.workerarr[i] = workerarr[i];
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

	if (workerarr[logicalWorkers] != nullptr) // check if department worker array is full and expand if nesscery
	{
		Worker** temp = new Worker * [logicalWorkers * 2];
		for (int i = 0; i < physicalWorkers; i++)
			temp[i] = workerarr[i];
		delete[] workerarr;
		workerarr = temp;
	}

	workerarr[physicalWorkers] = worker;
	worker->setWorkerDepartment(this); // make sure worker acknowledges it's new department
	physicalWorkers++;
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
				workerarr[j] = workerarr[j + 1];
			while (j < physicalWorkers);
			return true; // worker was found and removed from department
		}
		return false; // worker was not found
}

const char* Department::getName() const { return name; }

const int Department::getWorkersAmount() const { return physicalWorkers; }

const Department::eWorkerType Department::getWorkerType(Worker* worker) const { return workertype; }

ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name;
	return os;
}
