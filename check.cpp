#pragma warning (disable: 4996)

#include "check.h"

#include <iostream>
using namespace std;

Check::Check(const char* checkName)
{
	this->checkName = new char[strlen(checkName) + 1];
	strcpy(this->checkName, checkName);
}
Check::~Check()
{
	delete[] checkName;
}
const char* Check::getCheckType() const { return checkName; }

bool Check::setCheckType(const char* checkName)
{
	strcpy(this->checkName, checkName);
	return true;
}
