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
#include "doctor.h"
#include "surgeon.h"
#include "nurse.h"
#include "patient.h"
#include "date.h"

// main function headers
void AddDepartmentFunc(Hospital& h);
void RemoveDepartmentFunc(Hospital &h);
void AddDoctorFunc(Hospital& h);
void AddNurseFunc(Hospital &h);
void InsertPatientVisitFunc(Hospital &h);
void ShowDeparmentInfoFunc(Hospital &h);
void ShowMedicalStaffFunc(Hospital& h);
void SearchPatientIDFunc(Hospital& h);
void AddResearcherFunc(Hospital& h, Researchcenter& rc);
void AddPaperFunc(Researchcenter& rc, Hospital& h);
void ShowResearchCenterInfoFunc(Researchcenter& rc);
void HaveMoreArticleFunc(Researchcenter& rc);



// interaction menu system
void main()
{
	char hospital_name[20], research_center_name[20];
	int select = 0;
	cout << "Welcome to the hospital administration system\n";
	cout << "Please enter hospital name: ";
	cin >> hospital_name;
	cout << "Please enter research center name: ";
	cin >> research_center_name;

	Hospital h(hospital_name, research_center_name);

	Researchcenter* rc = h.getResearchCenter();

	//HARDCODED BENCHTEST
	//Hospital h("Ichilov", "Erison");
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
			"\n(11)\tShow all research center staff" <<
			"\n(12)\tCheck which researcher has more articles" <<
			"\n(13)\tExit" <<
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
			AddResearcherFunc(h,*rc);
			break;
		case 7:
			AddPaperFunc(*rc, h);
			break;
		case 8:
			ShowDeparmentInfoFunc(h);
			break;
		case 9:
			ShowMedicalStaffFunc(h);
			break;
		case 10:
			SearchPatientIDFunc(h);
			break;
		case 11:
			ShowResearchCenterInfoFunc(*rc);
			break;
		case 12:
			HaveMoreArticleFunc(*rc);
			break;
		case 13:
			break;
		default:
			cout << "\nInvalid input, try again\n";
			break;
		}
	} while (select != 13);
}

void AddDepartmentFunc(Hospital &h)
{
	
	char departmentName[20];
	cout << "\nInsert department name: ";
	cin >> departmentName;
	Department temp(departmentName);
	if (h.addDepartment(departmentName) == true)
		cout << "\nDepartment " << departmentName << " was added succesfully\n";
	else
		cout << "\nfailed to add department\n";
	

	// HARDCODED BENCHMARK
	//h.addDepartment("children");
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
	int id, day, month, year, genderInt, IsSurgeon, NumOfSurgeries;
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
	cout << "\nIs He/She a Surgeon: (1-Yes) ";
	cin >> IsSurgeon;
	if (IsSurgeon == 1)
	{
		cout << "\n The Number Of Surgeries:  ";
		cin >> NumOfSurgeries;
		Surgeon temp(name, id, h.createDate(day, month, year), expertise, gender, h.getDepartmentByName(department), NumOfSurgeries);
		h += temp;
	}
	else
	{
		Doctor temp(name, id, h.createDate(day, month, year), expertise, gender, h.getDepartmentByName(department));
		h += temp;
	}
	
	// HARDCODED BENCHTEST
	//Date tempD(7, 6, 2000);
	//Doctor temp("Nir", 1234 , tempD, "help", Person::MALE, h.getDepartmentByName("children"));

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
	Nurse temp(name, id, h.createDate(day, month, year), gender, h.getDepartmentByName(department), YoE);

	// HARDCODED BENCHTEST
	//Date tempD(17, 10, 2001);
	//Nurse temp("Liora", 1212, tempD,Person::FEMALE, h.getDepartmentByName("children"));

	h += temp;
}

void InsertPatientVisitFunc(Hospital& h)
{
	char name[20], department[20], checkName[20];
	int id, genderInt, day, month, year, visitD, visitM, visitY,
		docId, nurseId, reason, opRoom;
	bool isFast;
	Person::eGender gender;
	cout << "\nPatient visit system";
	if (h.getDepartmentsCount() == 0)
	{
		cout << "\nERROR: No departments exist!\n";
		return;
	}
	cout << "\nInsert patient ID: ";
	cin >> id;
	if (h.getPatientById(id) == nullptr) // new patient
	{
		cout << "\nNew patient, creating visit card:";
		cout << "\nInput patient information\nName: ";
		cin >> name;
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
		cout << "\nDate of arrival:\nDay: ";
		cin >> visitD;
		cout << "\nMonth: ";
		cin >> visitM;
		cout << "\nYear: ";
		cin >> visitY;
		cout << "\nReason of visit:\n(1) Check\n(2) Surgery";
		cin >> reason;
		if (reason == 1)
		{
			cout << "\nCheck name: ";
			cin >> checkName;
		}
		else
		{
			cout << "\nIs the patient fasting? (1) Yes, (0) No: ";
			cin >> isFast;
			cout << "\nSurgery/Opeartion room number: #";
			cin >> opRoom;
		}
		cout << "\nDepartment: ";
		cin >> department;
		cout << "\nAssigned doctor worker ID: ";
		cin >> docId;
		cout << "\nAssigned nurse worker ID: ";
		cin >> nurseId;
		h.addPatient(name, id, h.createDate(day, month, year), gender, 
			h.createDate(visitD, visitM, visitY), 
			h.getDepartmentByName(department), 
			h.getDoctorById(docId),
			h.getNurseById(nurseId));
		if (reason == 1)
			h.getPatientById(id)->CreateCheckVisit(h.getPatientById(id),
				h.createDate(visitD, visitM, visitY),
				h.getDepartmentByName(department),
				checkName,
				h.getDoctorById(docId),
				h.getNurseById(nurseId));
		else
			h.getPatientById(id)->CreateSurgeryVisit(h.getPatientById(id),
				h.createDate(visitD, visitM, visitY),
				h.getDepartmentByName(department),
				isFast, opRoom,
				h.getDoctorById(docId),
				h.getNurseById(nurseId));
	}
	else // existing patient
	{
		cout << "\nPatient found in system! Update patient information? (Y/N): ";
		cin >> name;
		if (strcmp(name, "Y") == 0)
		{
			cout << "\nDepartment: ";
			cin >> department;
			cout << "\nAssigned doctor worker ID: ";
			cin >> docId;
			cout << "\nAssigned nurse worker ID: ";
			cin >> nurseId;
			h.updatePatientInformation(h.getPatientById(id), h.getDepartmentByName(department), h.getDoctorById(docId), h.getNurseById(nurseId));
		}
		else
		{
			cout << "\nCreating new visit:";
			cout << "\nDate of arrival:\nDay: ";
			cin >> visitD;
			cout << "\nMonth: ";
			cin >> visitM;
			cout << "\nYear: ";
			cin >> visitY;
			cout << "\nReason of visit:\n(1) Check\n(2) Surgery";
			cin >> reason;
			if (reason == 1)
			{
				cout << "\nCheck name: ";
				cin >> checkName;
			}
			else
			{
				cout << "\nIs the patient fasting? (1) Yes, (0) No: ";
				cin >> isFast;
				cout << "\nSurgery/Opeartion room number: #";
				cin >> opRoom;
			}
			cout << "\nDepartment: ";
			cin >> department;
			cout << "\nAssigned doctor worker ID: ";
			cin >> docId;
			cout << "\nAssigned nurse worker ID: ";
			cin >> nurseId;
			if (reason == 1)
				h.getPatientById(id)->CreateCheckVisit(h.getPatientById(id),
					h.createDate(visitD, visitM, visitY),
					h.getDepartmentByName(department),
					checkName,
					h.getDoctorById(docId),
					h.getNurseById(nurseId));
			else
				h.getPatientById(id)->CreateSurgeryVisit(h.getPatientById(id),
					h.createDate(visitD, visitM, visitY),
					h.getDepartmentByName(department),
					isFast, opRoom,
					h.getDoctorById(docId),
					h.getNurseById(nurseId));
		}
	}
	
	//HARDCODED BENCHTEST
	//h.addPatient("Arik", 1010, h.createDate(0, 0, 0), Person::OTHER, "headache", h.createDate(19, 01, 2026));
}

void ShowDeparmentInfoFunc(Hospital& h)
{
	int select;
	char departmentName[20];
	cout << "\nInsert department name: ";
	cin >> departmentName;
	if (h.doesDepartmentExist(departmentName) == true)
	{
		cout << "\nPlease select:\n(1)\tPrint all workers (doctors/nurses)\n(2)\tPrint all patients\nUser input: ";
		cin >> select;
		switch (select)
		{
		case 1:
			if (h.getDepartmentWorkersCount(departmentName) == 0)
			{
				cout << "\nThere are no workers in this department!\n";
			}
			else
			{
				cout << "\nDepartment " << h.getDepartmentByName(departmentName)->getName() << " workers are :\n\n";
				for (int i = 0; i < h.getDepartmentWorkersCount(departmentName); i++)
				{
					cout << (i + 1) << h.getDepartmentByName(departmentName)->getWorkerByIndex(i) << "\n\n";
				}
			}
			break;
		case 2:
			if (h.getDepartmentPatientsCount(departmentName) == 0)
			{
				cout << "\nThere are no patients in this department!\n";
			}
			else
			{
				cout << "\nDepartment " << h.getDepartmentByName(departmentName)->getName() << " patients are : \n";
				for (int i = 0; i < h.getDepartmentPatientsCount(departmentName); i++)
				{
					cout << (i + 1) << h.getDepartmentByName(departmentName)->getPatientByIndex(i) << "\n\n";
				}
			}
			break;
		default:
			cout << "\nWrong input please try again.";
			break;
		}
	}
	else
		cout << "\nERROR: No such department exists!\n";
}

void ShowMedicalStaffFunc(Hospital& h)
{
	if (h.getDepartmentsCount() == 0)
	{
		cout << "\nERROR: please add a department and staff first!\n";
		return;
	}
	for (int i = 0; i < h.getDepartmentsCount(); i++)
	{
		cout << "\nPrinting all medical staff:\nDepartment: " << h.getDepartmentName(i);
		if (h.getDepartmentByIndex(i)->getWorkersAmount() == 0)
			cout << "\nThere are no workers in this department\n";
		else
			cout << "\nWorkers:\n";
			for (int j = 0; j < h.getDepartmentByIndex(i)->getWorkersAmount(); j++)
			{
				cout << (j + 1) << h.getDepartmentByName(h.getDepartmentName(i))->getWorkerByIndex(j) << "\n\n";
			}
	}
	cout << "\n";
}

void SearchPatientIDFunc(Hospital& h)
{
	int id;
	cout << "\nInsert patient ID to search: ";
	cin >> id;
	for (int i = 0; i < h.getDepartmentsCount(); i++)
	{
		if (h.getPatientById(id) != nullptr)
		{
			cout << "\nPatient found in department: " << h.getDepartmentName(i)
				<< "\nPatient name: " << h.getPatientNameById(id) << "\n";
			return;
		}
	}
	cout << "\nPatient was not found!\n";

}

void AddResearcherFunc(Hospital& h, Researchcenter& rc)
{
	char name[20];
	int id, day, month, year, genderInt, isDocInt;
	Person::eGender gender;
	bool isDoctor;

	cout << "\nInput Researcher information:";
	cout << "\nName: "; cin >> name;
	cout << "\nId: "; cin >> id;

	cout << "Gender: (0) Male (1) Female (2) Other: ";
	cin >> genderInt;
	switch (genderInt)
	{
	case 0: gender = Person::MALE; break;
	case 1: gender = Person::FEMALE; break;
	default: gender = Person::OTHER; break;
	}

	cout << "\nDay of birth: "; cin >> day;
	cout << "\nMonth of birth: "; cin >> month;
	cout << "\nYear of birth: "; cin >> year;
	cout << "\nIs this researcher also a doctor? (1 for Yes, 0 for No): ";

	cin >> isDocInt;
	isDoctor = (isDocInt == 1);

	Researcher temp(name, id, h.createDate(day, month, year), gender, isDoctor);

	rc += temp;

	cout << "\nResearcher added successfully!\n";
}

void AddPaperFunc(Researchcenter& rc, Hospital& h)
{
	int id, day, month, year;
	char articleName[50], magazineName[50];

	cout << "\nEnter Researcher ID to add article to: ";
	cin >> id;

	if (rc.getResearcherById(id) == nullptr)
	{
		cout << "\nERROR: Researcher not found inside the Research Center!\n";
		return;
	}

	cout << "\nArticle Name: "; cin >> articleName;
	cout << "\nMagazine Name: "; cin >> magazineName;
	cout << "\nPublication Date (D M Y): ";
	cin >> day >> month >> year;

	Article newArticle(articleName, magazineName, h.createDate(day, month, year));

	if (rc.addArticleToResearcher(id, newArticle))
		cout << "\nArticle added successfully!\n";
	else
		cout << "\nFailed to add article.\n";
}

void ShowResearchCenterInfoFunc(Researchcenter& rc)
{
	
	cout << "\n   Research Center Information System   ";
	
	rc.printAllResearchers();
	
}

void HaveMoreArticleFunc(Researchcenter& rc)
{
	int id1, id2;
	cout << "\nEnter Researcher 1 ID:";
	cin >> id1;
	cout << "\nEnter Researcher 2 ID:";
	cin >> id2;

	const Researcher* r1 = rc.getResearcherById(id1);
	const Researcher* r2 = rc.getResearcherById(id2);

	if (r1 == nullptr || r2 == nullptr)
	{
		cout << "\nERROR: One or both researchers not found!";
		return;
	}

	if (*r1 > *r2)
	{
		cout << "\nResearcher 1 have more articles";
	}
	else if (*r2 > *r1)
	{
		cout << "\nResearcher 2 have more articles";
	}
	else
		cout << "\nThe Researchers have the same amount of articles.";

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