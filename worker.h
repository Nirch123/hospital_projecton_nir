#ifndef __WORKER_H
#define __WORKER_H

#include "person.h"
#include "department.h"

class Worker : public Person
{
public:
	Worker(const char* name, const int id, Date& birthdate, eGender gender, Department* department = nullptr);
	~Worker();
	const int getWorkerId() const;
	const char* getWorkerDepartment() const;
	bool setWorkerDepartment(Department* new_department);

protected:

	int workerId;
	Department* department;
private:
	static int idCounter;
	Worker(Worker& other);
};


#endif