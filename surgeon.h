#ifndef __SURGEON_H
#define __SURGEON_H

#include <iostream>
using namespace std;

#include "doctor.h"


class Surgeon : public Doctor
{
	public:
		Surgeon(const char* name, const int id, const Date& birthdate, const char* expertise,
			eGender gender, Department* department = nullptr, int NumOfSurgeries=0);
		Surgeon(Surgeon& other);
		virtual ~Surgeon();
		void setSurgeonNumOfSurgeries(int NumOfSurgeries);
		const int getSurgeonNumOfSurgeries() const;
		virtual void WorkerTypeOs(ostream& os) const;

		

	private:
		int NumOfSurgeries;
};





#endif