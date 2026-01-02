#ifndef __PERSON_H
#define __PERSON_H

class Date; //change to include date class if nesscery

class Person
{
public:
	enum eGender { MALE, FEMALE, OTHER };
	Person(const char* name, const int id,const Date& birthdate, const eGender gender);
	Person(const char* name, Date& birthdate);
	virtual ~Person();
	const char* getName() const;
	const int getId() const;
	const int getGender() const;

protected:
	char* name;
	int id;
	const Date& birthdate;
	eGender gender;

private:
	Person(Person& other);
};


#endif