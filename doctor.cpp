#pragma warning (disable: 4996)
#include "doctor.h"
#include "department.h"


Doctor::Doctor(const char* name, const int id, Date& birthdate, const char* expertise, 
	eGender gender, Department* department) : Worker(name, id, birthdate, gender, department)
{
	this->expertise = new char[strlen(expertise) + 1];
	strcpy(this->expertise,expertise);
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::~Doctor() {}

void Doctor::setDoctorExpertise(const char* new_expertise) { strcpy(expertise, new_expertise); }

const char* Doctor::getDoctorExpertise() const { return expertise; }

ostream& operator<<(ostream& os, const Doctor& doctor)
{
	os << "Worker Id: " << doctor.getWorkerId() << " Name: " << doctor.getName()
		<< " Gender: " << doctor.getGender() << " Department: " << doctor.department->getName()
		<< " Expertise: " << doctor.expertise;
	return os;
}

void Doctor::doctorOs(ostream& os) const
{
	os << "\n\tTitle: Doctor\n\tExpertise: " << expertise;
}