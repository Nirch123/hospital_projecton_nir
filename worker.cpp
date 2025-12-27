#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "worker.h"

int Worker::idCounter = 100;

Worker::Worker(const char* name, const int id, Date& birthdate, eGender gender, Department* department) : Person(name, id, birthdate, gender), workerId(++idCounter)
{
	setWorkerDepartment(department);
}

Worker::~Worker()
{}

const int Worker::getWorkerId() const { return workerId; }

const char* Worker::getWorkerDepartment() const { return department->getName(); }

bool Worker::setWorkerDepartment(Department* new_department)
{
	department = new_department;
	department->addWorker(this);
	return true;
}
