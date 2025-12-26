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

// main function headers
void printDepartments(Hospital& hospital);



void main()
{
	// temp change
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
}

// common functions (for now)
void printDepartments(Hospital &hospital)
{
	cout << "\n" << "Hospital departments are : " << "\n";
	for (int i = 0; i < hospital.getDepartmentsCount(); i++)
		cout << "(" << i << ") " << hospital.getDepartmentName(i) << "\n";
}