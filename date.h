#ifndef __DATE_H
#define __DATE_H

class Date
{
public:
	Date();
	Date(int d, int m, int y);
	Date(Date& other);

	void show() const;
	const int getDate() const;
	void setDate(int d,int m,int y);

private:
	int day, month, year;

};

#endif
