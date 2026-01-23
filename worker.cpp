#pragma warning (disable: 4996)


#include "worker.h"
#include "department.h"
#include "doctor.h"

//int Worker::idCounter = 100;

Worker::Worker(const char* name, const int id, const Date& birthdate, eGender gender, Department* department) 
	: Person(name, id, birthdate, gender)
{
	if (department != nullptr)
		setWorkerDepartment(department);
}

Worker::Worker(Worker& other)
	: Person(other.name, other.id, other.birthdate, other.gender)
{
	department = other.department;
}

Worker::Worker(Doctor& other) : Person(other)
{
	department = other.department;
}

Worker::~Worker()
{
	cout << "\nDEBUG: in Worker::~Worker()";
}

const int Worker::getWorkerId() const { return workerId; }

const char* Worker::getWorkerDepartment() const { return department->getName(); }

bool Worker::setWorkerDepartment(Department* new_department)
{
	department = new_department;
	if (department != nullptr)
		department->addWorker(this);
	return true;
}

bool Worker::setWorkerId(int workerId)
{
	this->workerId = workerId;
	return true;
}


ostream& operator<<(ostream& os, const Worker& worker)
{
	os << "\tWorker Id: " << worker.getWorkerId() << "\n\tName: " << worker.getName()
		<< "\n\tGender: " << worker.getGender() << "\n\tDepartment: " << worker.department->getName();
	worker.WorkerTypeOs(os);
	return os;
}

const Worker::eWorkerType Worker::getWorkerType() const { return workertype; }

bool Worker::setWorkerType(Worker::eWorkerType type = Worker::eWorkerType::OTHER)
{
	this->workertype = type;
	return true;
}



