/*
~~~~~~~~~~~~~ Hospital Projecton ~~~~~~~~~~~~~
				  Submitters:
			  Nir Maman 322698747
			  Tal Ritz 315420422
*/


#pragma warning (disable: 4996)
#include <iostream>
using namespace std;

#include "hospital.h"
#include "department.h"
#include "worker.h"
#include "date.h"
#include "nurse.h"

// main function headers
void printDepartments(Hospital& hospital);



void main()
{
	// hardcoded hospital benchmark
	Researchcenter researchCenter("Zubi");
	Hospital hospital("Sheeba",researchCenter);
	cout << "Hospital name is: " << hospital;
	cout << "\nHospital Reasearch Center is: " << hospital.getResearchCenterName();
	Department a("Emergency"), b("Kids"), c("Teeth"), d("Clincs");
	hospital.addDepartment(a);
	hospital.addDepartment(b);
	hospital.addDepartment(c);
	hospital.addDepartment(d);
	printDepartments(hospital);
	hospital.removeDepartment(b);
	printDepartments(hospital);
	Date date;
	Worker w1("Nir", 1 , date , Person::MALE);
	Nurse n1("Liora", 2, date, Person::FEMALE, &b, 3);
	printNursesInDepartment(b);
}

// common functions (for now)
void printDepartments(Hospital &hospital)
{
	cout << "\nHospital departments are : \n";
	for (int i = 0; i < hospital.getDepartmentsCount(); i++)
		cout << "(" << i << ") " << hospital.getDepartmentName(i) << "\n";
}

void printNursesInDepartment(Department& department)
{
	if (department.getWorkersAmount() == 0)
		cout << "\nThere are no workers in this department\n"
	else
	{
		cout << "\nDepartment " << department << " nurses are : \n";
		for (int i = 0; i < department.getWorkersAmount(); i++)
			if (department.getWorkerType() == Department::NURSE)
			cout << "(" << i << ") " << department.getWorkerType << "\n";
	}
}