#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "worker.h"
#include "department.h" // ???

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
	if (department != nullptr)
		department->addWorker(this);
	return true;
}

ostream& operator<<(ostream& os, const Worker& worker)
{
	os << "Worker Id: " << worker.getWorkerId() << " Name: " << worker.getName()
		<< " Gender: " << worker.getGender() << " Department: " << worker.department->getName();
	worker.nurseOs(os);
	return os;
}

const Worker::eWorkerType Worker::getWorkerType() const { return workertype; }

bool Worker::setWorkerType(Worker::eWorkerType type = Worker::eWorkerType::OTHER)
{
	this->workertype = type;
	return true;
}



