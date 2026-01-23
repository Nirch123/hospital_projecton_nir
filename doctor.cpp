#pragma warning (disable: 4996)
#include "doctor.h"
#include "department.h"
#include "worker.h"


Doctor::Doctor(const char* name, const int id, const Date& birthdate, const char* expertise, 
	eGender gender, Department* department) : Worker(name, id, birthdate, gender, department)
{
	this->expertise = new char[strlen(expertise) + 1];
	strcpy(this->expertise,expertise);
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::Doctor(Doctor& other) : Worker(other)
{
	expertise = new char[strlen(other.expertise) + 1];
	strcpy(expertise, other.expertise);
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::~Doctor() 
{
	cout << "\nDEBUG: in ~Doctor()";
	delete[] expertise;
}

void Doctor::setDoctorExpertise(const char* new_expertise) { strcpy(expertise, new_expertise); }

const char* Doctor::getDoctorExpertise() const { return expertise; }

ostream& operator<<(ostream& os, const Doctor& doctor)
{
	if (&(doctor) == nullptr)
		os << "Doctor not assigned";
	else
		os << "Dr." << doctor.getName();
	return os;
}


void Doctor::WorkerTypeOs(ostream& os) const
{
	os << "\n\tTitle: Doctor\n\tExpertise: " << expertise;

}

