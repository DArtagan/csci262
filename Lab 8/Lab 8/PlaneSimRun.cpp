#include "PlaneSimRun.h"
using namespace std;

int RunPlaneSim(int landTime, int takeoffTime, int MaxAirTime, int arrivalInterval, int departInterval, int TotalTime){
	queue<Plane> landings, takingoffs;
	Plane soars;
	int tarmack(0), Departures, Arrivals, Crashes, Waitingfortakeoff, Waitingforland;
	double AverageTakeWait, AverageLandWait;
	ofstream text("log.txt");
	text << "Begin Simulation" << endl;
	if (!text) { cout << "Failed to open log.txt" << endl; exit(1);}
	for (int i = 0; i < TotalTime; i++){
		if (!(i%arrivalInterval)){
			landings.push(soars);
			text << i << " Plane enters queue to land." << endl;
		}
		if (!(i%departInterval)){
			takingoffs.push(soars);
			text << i << " Plane enters queue to takeoff." << endl;
		}
		if (!tarmack && !landings.empty()) {
			Arrivals++;
			AverageLandWait = AverageLandWait*(Arrivals-1)/Arrivals + landings.front().getWait()/Arrivals;
			landings.pop();
			tarmack = landTime;
			text << i << " Plane starts to land." << endl;
		} else if (!tarmack && !takingoffs.empty()) {
			Departures++;
			AverageTakeWait = AverageTakeWait*(Departures-1)/Departures + takingoffs.front().getWait()/Departures;
			landings.pop();
			tarmack = takeoffTime;
			text << i << " Plane starts to takeoff." << endl;
		}
		landings = incrementPlanes(landings, Crashes, MaxAirTime, text, i);
		takingoffs = incrementPlanes(takingoffs, Crashes, 1000000000, text, i);
	}
	Waitingforland =landings.size();
	Waitingfortakeoff = takingoffs.size();
	text << "End Simulation" << endl;
	text.close();
	return 0;
}

queue<Plane> incrementPlanes(queue<Plane> ps, int& Crashes, const int& MaxAirTime, ofstream& text, int i) {
	queue<Plane> newqp;
	while (!ps.empty()) {
		ps.front()++;
		if (ps.front().getWait() >= MaxAirTime) {
			Crashes++;
			text << i << " A plane has crashed." << endl;
			ps.pop();
		} else {
			newqp.push(ps.front());
			ps.pop();
		}
	}
	return newqp;
}