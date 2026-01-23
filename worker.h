#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>
using namespace std;

#include "person.h"
class Department;
class Doctor;


class Worker : public Person
{
public:
	enum eWorkerType { DOCTOR, NURSE, OTHER }; // should classification be under department? or under worker?
	Worker(const char* name, const int id, const Date& birthdate, eGender gender, Department* department = nullptr);
	Worker(Worker& other);
	Worker(Doctor& other);
	virtual ~Worker();
	const int getWorkerId() const;
	const char* getWorkerDepartment() const;
	const eWorkerType getWorkerType() const;
	bool setWorkerId(int workerId);
	bool setWorkerType(eWorkerType type);
	bool setWorkerDepartment(Department* new_department);
	friend ostream& operator<<(ostream& os, const Worker& worker);
	virtual void WorkerTypeOs(ostream& os) const {}



protected:
	int workerId;
	Department* department;
	eWorkerType workertype;


//private:
	//static int idCounter;
};


#endif