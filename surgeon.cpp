#pragma warning (disable: 4996)
#include "surgeon.h"
#include "doctor.h"

Surgeon::Surgeon(const char* name, const int id, const Date& birthdate, const char* expertise,
	eGender gender, Department* department, int NumOfSurgeries) : Doctor(name, id, birthdate, expertise, gender, department)
{

}

Surgeon::Surgeon(Surgeon& other) : Doctor(other)
{

}

Surgeon::~Surgeon()
{
	cout << "\nDEBUG: in ~Surgeon()";
}

void Surgeon::setSurgeonNumOfSurgeries(const int new_numofsurgeries) { NumOfSurgeries = new_numofsurgeries; }

const int Surgeon::getSurgeonNumOfSurgeries() const { return NumOfSurgeries; }

ostream& operator<<(ostream& os, const Surgeon& surgeon)
{
	if (&(surgeon) == nullptr)
		os << "Surgeon not assigned";
	return os;
}

void Surgeon::surgeonOs(ostream& os) const
{
	os << "\n\tTitle: Surgeon\n\tNumber of Surgeries: " << NumOfSurgeries;

}
