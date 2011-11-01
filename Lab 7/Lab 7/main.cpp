#include <cstdlib>
#include <iostream>
#include <stack>
#include "queenSolver.h"
using namespace std;

int main() {
	// Initialization and Declarations
	int n(0);
	stack<queen> queenStack;

	while(n < 1) {
		cin >> n;
	}
	queenStack = queenSolver(n);

	cout << endl;
	if(queenStack.empty()) {
		cout << "FAIL" << endl;
	} else {
		cout << "Queens at:" << endl;
		while(!queenStack.empty()) {
			cout << "{" << queenStack.top().row << "," << queenStack.top().col << "}" << endl;
			queenStack.pop();
		}
	}
	// Pause
	system("PAUSE");

	// Exit Program
	return 0;
}