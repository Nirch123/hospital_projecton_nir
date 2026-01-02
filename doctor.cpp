#include "doctor.h"

Doctor::Doctor(const char* name, const int id, Date& birthdate, eGender gender, Department* department = nullptr, const std::string& expertise)
	: Worker(name, id, birthdate, gender, department)
{
	this->expertise = expertise;
	Worker::setWorkerType(Worker::eWorkerType::DOCTOR);
}

Doctor::~Doctor() {}

void Doctor::setDoctorExpertise(const std::string& new_expertise)
{
	expertise = new_expertise;
}

const std::string& Doctor::getDoctorExpertise() const
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