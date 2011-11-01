#pragma once
class Plane
{
public:
	Plane() : waitingTime(0) {}
	int getWait(){return waitingTime;}
	friend int operator ++(Plane&);

private:
	int waitingTime;

};

