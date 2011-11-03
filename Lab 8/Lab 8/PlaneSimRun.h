#pragma once
#include <cstdlib>
#include <queue>
#include <random>
#include <fstream>
#include <iostream>
#include "Plane.h"
using namespace std;

namespace CS262 {
	void RunPlaneSim(double values[], int landTime, int takeoffTime, int MaxAirTime, int arrivalInterval, int departInterval, int TotalTime);
	queue<Plane> incrementPlanes(queue<Plane>, int& Crashes, const int& MaxAirTime, ofstream&, int i);
}