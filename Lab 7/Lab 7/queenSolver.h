#include <stack>
#include <iostream>
#include "queen.h"
using namespace std;
using namespace CS262;

stack<queen> queenSolver(int n);
bool conflictChecker(stack<queen> current);