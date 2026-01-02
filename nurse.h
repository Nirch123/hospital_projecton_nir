#ifndef __NURSE_H
#define __NURSE_H

#include <iostream>
using namespace std;

class Date;
#include "department.h"
#include "worker.h"

class Nurse : public Worker
{
public:
	Nurse(const char* name, const int id, const Date& birthdate, eGender gender, Department *department = nullptr , int YoE = 0);
	~Nurse();
	bool setNurseYears(int YoE);
	const int getNurseYears() const;
	friend ostream& operator<<(ostream& os, const Nurse& nurse);
	virtual void nurseOs(ostream& os) const override; // polymorphisem - p.54

private:
	int YoE; // Years of Experience
};


#endif