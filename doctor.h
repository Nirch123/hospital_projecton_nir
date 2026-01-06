#ifndef __DOCTOR_H
#define __DOCTOR_H

#include <iostream>
using namespace std;

#include "worker.h"
class Department;


class Doctor : public Worker
{
	public:
		Doctor(const char* name, const int id, Date& birthdate, const char* expertise,
			eGender gender, Department* department = nullptr);
		~Doctor();
		void setDoctorExpertise(const char* expertise);
		const char* getDoctorExpertise() const;
		friend ostream& operator<<(ostream& os, const Doctor& doctor);
		virtual void doctorOs(ostream& os) const;

	private:
		char* expertise;
};

#endif