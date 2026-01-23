#ifndef __NURSE_H
#define __NURSE_H

#include <iostream>
using namespace std;

#include "worker.h"

class Date;
class Department;

class Nurse : public Worker
{
public:
	Nurse(const char* name, const int id, const Date& birthdate, eGender gender, Department *department = nullptr , int YoE = 0);
	virtual ~Nurse();
	bool setNurseYears(int YoE);
	const int getNurseYears() const;
	friend ostream& operator<<(ostream& os, const Nurse& nurse);
	virtual void WorkerTypeOs(ostream& os) const;


private:
	int YoE; // Years of Experience
};


#endif