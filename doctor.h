#ifndef __DOCTOR_H
#define __DOCTOR_H

#include "department.h"
#include "worker.h"

class Doctor : public Worker
{
	public:
		Doctor(const char* name, const int id, Date& birthdate, eGender gender, Department* department = nullptr, const std::string& expertise);
		~Doctor();
		void setDoctorExpertise(const std::string& expertise);
		const std::string& getDoctorExpertise() const;
		friend ostream& operator<<(ostream& os, const Doctor& doctor);
		//add poly os 

	private:
		std::string expertise;
	
};

#endif