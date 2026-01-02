#pragma warning (disable: 4996)
#include "doctor.h"

Doctor::Doctor(const char* name, const int id, Date& birthdate, const char* expertise, eGender gender, Department* department)
	: Worker(name, id, birthdate, gender, department)
{
	expertise = new char[strlen(expertise) + 1];
	strcpy(this->expertise,expertise);
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::~Doctor() {}

void Doctor::setDoctorExpertise(const char* new_expertise)
{
	strcpy(expertise,new_expertise);
}

const char* Doctor::getDoctorExpertise() const
{
	return expertise;
}

ostream& operator<<(ostream& os, const Doctor& doctor)
{
	os << "Worker Id: " << doctor.getWorkerId() << " Name: " << doctor.getName()
		<< " Gender: " << doctor.getGender() << " Department: " << doctor.department->getName()
		<< " Expertise: " << doctor.expertise;
	//add poly os 
	return os;
}