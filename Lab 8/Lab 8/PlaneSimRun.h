#pragma once
#include "Plane.h"
#include <queue>
#include <random>
#include <fstream>
#include <iostream>
#include "stdafx.h"
using namespace std;

int RunPlaneSim(int landTime, int takeoffTime, int MaxAirTime, int arrivalInterval, int departInterval, int TotalTime);
queue<Plane> incrementPlanes(queue<Plane>, int& Crashes, const int& MaxAirTime, ofstream&, int i);
int operator ++(Plane& p){return p.waitingTime++;}