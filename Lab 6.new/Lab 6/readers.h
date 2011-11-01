#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "car.h"
#include "LinkedList.h"
using namespace std;

namespace CS262 {
	LinkedList<car> carReader();
	LinkedList<tile> trackReader();
}