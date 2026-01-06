#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <iostream>
using namespace std;

class Person;
class Worker;
class Patient;
class Doctor;
class Nurse;

class Department
{
	public:
		//enum eWorkerType {DOCTOR, NURSE, OTHER}; // should classification be under department? or under worker?
		Department(const char *name);
		Department(const Department& other);
		~Department();
		bool addWorker(Worker* worker);
		bool addPatient(Patient* patient);
		bool removeWorker(Worker* worker);
		bool removePatient(Patient* patient);
		const char* getName() const;
		const int getWorkersAmount() const;
		const int getPatientsAmount() const;
		const Worker& getWorkerByIndex(int index) const;
		const Patient& getPatientByIndex(int index) const;
		//const eWorkerType getWorkerType(Worker* worker) const;
		friend ostream& operator<<(ostream& os, const Department& department);
		friend class Hospital;
		
	private:
		char *name;
		int physicalWorkers, logicalWorkers, physicalPatients, logicalPatients;
		Patient** patientArr;
		Worker** workerarr;
		//eWorkerType workertype;
};
#endif