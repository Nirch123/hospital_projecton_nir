#include "nurse.h"

Nurse::Nurse(const char* name, const int id, const Date& birthdate, eGender gender, Department* department, int YoE) : Worker(name, id, birthdate, gender, department)
{
	this->YoE = YoE;
	Worker::setWorkerType(Worker::eWorkerType::NURSE);
}

Nurse::~Nurse() 
{
	cout << "\nDEBUG: in Nurse::~Nurse()";
}

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
	os << "Worker Id: " << nurse.getWorkerId() << "\nName: " << nurse.getName()
		<< "\nGender: " << nurse.getGender() << "\nDepartment: " << nurse.department->getName()
		<< "\nYoE: " << nurse.YoE;
	return os;
}

void Nurse::nurseOs(ostream& os) const
{
	os << "\n\tTitle: Nurse" << "\n\tYoE : " << this->YoE;
}

const int Nurse::getNurseYears() const
{
	return YoE;
}