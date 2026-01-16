#ifndef __SURGERY_H
#define __SURGERY_H

class Surgery
{
public:
	Surgery(bool isFast, int opRoom);
	const bool getIsFast() const;
	const int getOpRoom() const;
 
private:
	Surgery(Surgery& other);
	bool isFast;
	int opRoom;
};

#endif