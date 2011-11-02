#pragma once
class Plane
{
public:
	Plane() : waitingTime(0) {}
	int getWait(){return waitingTime;}
	void setWait(int w){waitingTime =w;}

private:
	int waitingTime;

};

