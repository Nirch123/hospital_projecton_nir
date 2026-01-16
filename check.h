#ifndef __CHECK_H
#define __CHECK_H

class Check
{
public:
	Check(const char* checkName);
	~Check();
	const char* getCheckType() const;
	bool setCheckType(const char* checkName);
private:
	Check(Check& other);
	char* checkName;
};

#endif
