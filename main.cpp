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
	//Person p("nir",date);
	Person p("nir", 1, date, Person::eGender::MALE);
	Worker w("nir", 1 , date , Person::eGender::MALE);
}

// common functions (for now)
void printDepartments(Hospital &hospital)
{
	cout << "\n" << "Hospital departments are : " << "\n";
	for (int i = 0; i < hospital.getDepartmentsCount(); i++)
		cout << "(" << i << ") " << hospital.getDepartmentName(i) << "\n";
}