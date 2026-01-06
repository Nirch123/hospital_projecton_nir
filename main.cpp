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


// main function headers
void AddDepartmentFunc(Hospital& h);
void RemoveDepartmentFunc(Hospital &h);
void AddDoctorFunc(Hospital& h);
void AddNurseFunc(Hospital &h);
void InsertPatientVisitFunc(Hospital &h);
void ShowDeparmentInfoFunc(Hospital &h);



void main()
{
	char input1[20], input2[20];
	int select = 0;
	cout << "Welcome to the hospital administration system\n";
	cout << "Please enter hospital name: ";
	cin >> input1;
	cout << "Please enter research center name: ";
	cin >> input2;
	Researchcenter rc(input2);
	Hospital h(input1, rc);
	do
	{
		cout << "\nPlease select an option by entering corresponding number:" <<
			"\n(1)\tAdd department" <<
			"\n(2)\tRemove department" <<
			"\n(3)\tAdd nurse" <<
			"\n(4)\tAdd doctor" <<
			"\n(5)\tInsert patient visit" <<
			"\n(6)\tAdd a researcher" <<
			"\n(7)\tAdd a research paper" <<
			"\n(8)\tShow department information (workers/patients)" <<
			"\n(9)\tShow all medical staff" <<
			"\n(10)\tSearch patient by ID" <<
			"\n(11)\tExit" <<
			"\nUser Input: ";
		cin >> select;
		switch (select)
		{
		case 1:
			AddDepartmentFunc(h);
			break;
		case 2:
			if (h.getDepartmentsCount() != 0)
				RemoveDepartmentFunc(h);
			else
				cout << "\nERROR: There are no departments!\n";
			break;
		case 3:
			if (h.getDepartmentsCount() != 0)
				AddNurseFunc(h);
			else
				cout << "\nERROR: Please create a department first!\n";
			break;
		case 4:
			if (h.getDepartmentsCount() != 0)
				AddDoctorFunc(h);
			else
				cout << "\nERROR: Please create a department first!\n";
			break;
		case 5:
			InsertPatientVisitFunc(h);
			break;
		case 6:
			//AddResearcherFunc();
			break;
		case 7:
			//AddPaperFunc();
			break;
		case 8:
			ShowDeparmentInfoFunc(h);
			break;
		case 9:
			//ShowMedicalStaffFunc();
			break;
		case 10:
			//SearchPatientIDFunc();
			break;
		case 11:
			break;
		default:
			cout << "\nInvalid input, try again\n";
			break;
		}
	} while (select != 11);
}

void AddDepartmentFunc(Hospital &h)
{
	char input[20];
	cout << "\nInsert department name: ";
	cin >> input;
	Department temp(input);
	if (h.addDepartment(temp) == true)
		cout << "\nDepartment " << input << " was added succesfully\n";
	else
		cout << "\nfailed to add department\n";
}

void RemoveDepartmentFunc(Hospital& h)
{
	char input[20];
	bool flag;
	cout << "\nInsert department name to remove: ";
	cin >> input;
	flag = h.removeDepartment(*h.getDepartmentByName(input));
	if (flag == true)
		cout << "\nDepartment " << input << " removed succesfully\n";
	else
		cout << "\nDepartment not found, departments unchanged\n";
}

void AddDoctorFunc(Hospital& h)
{
	char name[20], expertise[20], department[20];
	int id, day, month, year, genderInt;
	Person::eGender gender;
	cout << "\nInput doctor information:";
	cout << "\nName: ";
	cin >> name;
	cout << "\nId: ";
	cin >> id;
	cout << "Gender: (0) Male (1) Female (2) Other: ";
	cin >> genderInt;
	switch (genderInt)
	{
	case 0:
		gender = Person::MALE;
		break;
	case 1:
		gender = Person::FEMALE;
		break;
	default:
		gender = Person::OTHER;
		break;
	}
	cout << "\nDay of birth: ";
	cin >> day;
	cout << "\nMonth of birth: ";
	cin >> month;
	cout << "\nYear of birth: ";
	cin >> year;
	cout << "\nDepartment: ";
	cin >> department;
	cout << "\nExpertise: ";
	cin >> expertise;
	h.addDoctor(name, id, h.createDate(day,month,year), expertise, gender, h.getDepartmentByName(department));
} 

void AddNurseFunc(Hospital& h)
{
	char name[20], department[20];
	int id, day, month, year, genderInt, YoE;
	Person::eGender gender;
	cout << "\nInput nurse information:";
	cout << "\nName: ";
	cin >> name;
	cout << "\nId: ";
	cin >> id;
	cout << "Gender: (0) Male (1) Female (2) Other: ";
	cin >> genderInt;
	switch (genderInt)
	{
	case 0:
		gender = Person::MALE;
		break;
	case 1:
		gender = Person::FEMALE;
		break;
	default:
		gender = Person::OTHER;
		break;
	}
	cout << "\nDay of birth: ";
	cin >> day;
	cout << "\nMonth of birth: ";
	cin >> month;
	cout << "\nYear of birth: ";
	cin >> year;
	cout << "\nDepartment: ";
	cin >> department;
	cout << "\nYears of experience: ";
	cin >> YoE;
	h.addNurse(name, id, h.createDate(day, month, year), gender, h.getDepartmentByName(department), YoE);
}

void InsertPatientVisitFunc(Hospital& h)
{
	cout << "\nPatient visit system: TBD";
}

void ShowDeparmentInfoFunc(Hospital& h)
{
	int intput;
	char input[20];
	cout << "\nInsert department name: ";
	cin >> input;
	if (h.getDepartmentByName(input) != nullptr)
	{
		cout << "\nPlease select:\n(1)\tPrint all workers (doctors/nurses)\n(2)\tPrint all patients\nUser input: ";
		cin >> intput;
		switch (intput)
		{
		case 1:
			h.printWorkersInDepartment(*h.getDepartmentByName(input));
			break;
		case 2:
			//h.printPatientsInDepartment(*h.getDepartmentByName(input));
			break;
		default:
			cout << "\nWrong input please try again.";
			break;
		}
	}
	else
		cout << "\nERROR: No such department exists!\n";
}


//  ############################# hardcoded hospital testbench ####################################
/*
#include "department.h"
#include "worker.h"
#include "date.h"
#include "nurse.h"
#include "doctor.h"
#include "patient.h"

void main ()
{
	Researchcenter researchCenter("Zubi");
	Hospital hospital("Sheeba",researchCenter);
	cout << "Hospital name is: " << hospital;
	cout << "\nHospital Reasearch Center is: " << hospital.getResearchCenterName();
	Department a("Emergency"), b("Kids"), c("Teeth"), d("Clincs");
	hospital.addDepartment(a);
	hospital.addDepartment(b);
	hospital.addDepartment(c);
	hospital.addDepartment(d);
	hospital.printDepartments();
	hospital.removeDepartment(b);
	hospital.printDepartments();
	Date date;
	Worker w1("Nir", 1000 , date , Person::MALE, &b);
	Nurse n1("Liora", 1001, date, Person::FEMALE, &b, 3);
	Nurse n2("Mike", 1002, date, Person::MALE, &b, 5);
	Nurse n3("Abi", 1003, date, Person::OTHER, &b);
	Doctor d1("zubi",10005,date,"heart",Person::MALE,&a);
	Patient p1("dubi",10007,date,Person::OTHER,"heart stroke",date,&a,&d1);
	hospital.printWorkersInDepartment(b);
	hospital.printWorkersInDepartment(a);
	b.removeWorker(&n2);
	hospital.printWorkersInDepartment(b);
}
*/