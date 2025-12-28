#include "nurse.h"

Nurse::Nurse(const char* name, const int id, Date& birthdate, eGender gender, Department* department, int YoE) : Worker(name, id, birthdate, gender, department)
{
	this->YoE = YoE;
	Worker::setWorkerType(Worker::eWorkerType::NURSE);
}

Nurse::~Nurse() {}

bool Nurse::setNurseYears(int YoE)
{
	if (YoE > -1)
	{
		this->YoE = YoE;
		return true;
	}
	else
		return false; // invalid years of experience to be less than 0
}

ostream& operator<<(ostream& os, const Nurse& nurse)
{
	os << "Worker Id: " << nurse.getWorkerId() << " Name: " << nurse.getName()
		<< " Gender: " << nurse.getGender() << " Department: " << nurse.department->getName()
		<< " YoE: " << nurse.YoE;
	return os;
}

void Nurse::nurseOs(ostream& os) const
{
	os << " Title: Nurse YoE: " << this->YoE;
}

const int Nurse::getNurseYears() const
{
	return YoE;
}