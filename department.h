#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <iostream>
using namespace std;

#include "worker.h"

class Department
{
	public:
		enum eWorkerType {DOCTOR, NURSE, OTHER};
		Department(const char *name);
		Department(const Department& other);
		~Department();
		bool addWorker(Worker* worker);
		bool removeWorker(Worker* worker);
		const char* getName() const;
		const int getWorkersAmount() const;
		const eWorkerType getWorkerType(Worker* worker) const;
		friend ostream& operator<<(ostream& os, const Department& department);
		friend class Hospital;
		
	private:
		char *name;
		int physicalWorkers, logicalWorkers;
		Worker** workerarr;
		eWorkerType workertype;
};
#endif