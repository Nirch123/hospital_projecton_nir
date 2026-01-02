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
#include "doctor.h"
#include "patient.h"

// main function headers
void printDepartments(Hospital& hospital);
void printWorkersInDepartment(Department& department);



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
	Worker w1("Nir", 1000 , date , Person::MALE, &b);
	Nurse n1("Liora", 1001, date, Person::FEMALE, &b, 3);
	Nurse n2("Mike", 1002, date, Person::MALE, &b, 5);
	Nurse n3("Abi", 1003, date, Person::OTHER, &b);
	Doctor d1("zubi", 1004, date, Person::MALE, &d, "heart");
	Patient p1("dubi", 1005, date, Person::FEMALE, &c, &d1, &n1, date, "heart stroke");
	printWorkersInDepartment(b);
	printWorkersInDepartment(a);
	b.removeWorker(&n2);
	printWorkersInDepartment(b);

}

// common functions (for now)
void printDepartments(Hospital &hospital)
{
	cout << "\nHospital departments are : \n";
	for (int i = 0; i < hospital.getDepartmentsCount(); i++)
		cout << "(" << i << ") " << hospital.getDepartmentName(i) << "\n";
}

void printWorkersInDepartment(Department& department)
{
	cout << "\nDepartment " << department << " workers are : \n";
	if (department.getWorkersAmount() == 0)
		cout << "There are no workers in this department\n";
	else
	{
		for (int i = 0; i < department.getWorkersAmount(); i++)
			cout << "(" << i << ") " << department.getWorkerByIndex(i) << "\n\n";
	}
	//add for patients
}