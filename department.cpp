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
	workerarr = new Worker * [logicalWorkers] {nullptr};
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

const char* Department::getName() const { return name; }

const int Department::getWorkersAmount() const { return physicalWorkers; }

//const Department::eWorkerType Department::getWorkerType(Worker* worker) const { return workertype; }

const Worker& Department::getWorkerByIndex(int index) const { return *workerarr[index]; }


ostream& operator<<(ostream& os, const Department& department)
{
	os << department.name;
	return os;
}
