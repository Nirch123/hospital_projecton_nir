

#include "nurse.h"
#include "department.h"

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
	if (&(nurse) == nullptr)
		os << "Nurse not assigned";
	else
		os << nurse.getName();
	return os;
}


void Nurse::WorkerTypeOs(ostream& os) const
{
	os << "\n\tTitle: Nurse" << "\n\tYoE : " << this->YoE;
}


const int Nurse::getNurseYears() const { return YoE; }
