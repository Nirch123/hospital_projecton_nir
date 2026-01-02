#ifndef __WORKER_H
#define __WORKER_H

#include "person.h"
class Department;

class Worker : public Person
{
public:
	enum eWorkerType { DOCTOR, NURSE, OTHER }; // should classification be under department? or under worker?
	Worker(const char* name, const int id, const Date& birthdate, eGender gender, Department* department = nullptr);
	virtual ~Worker();
	const int getWorkerId() const;
	const char* getWorkerDepartment() const;
	const eWorkerType getWorkerType() const;
	bool setWorkerType(eWorkerType type);
	bool setWorkerDepartment(Department* new_department);
	friend ostream& operator<<(ostream& os, const Worker& worker);
	virtual void nurseOs(ostream& os) const {} // polymorphisem - p.54


protected:

	int workerId;
	Department* department;
	eWorkerType workertype;


private:
	static int idCounter;
	Worker(Worker& other);
};


#endif