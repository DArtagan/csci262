#include "queenSolver.h"

stack<queen> queenSolver(int n) {
	// Initializings and Declarations
	stack<queen> queenStack;
	bool success(false);
	queenStack.push(queen(1,1));

	while(!success) {
		if(conflictChecker(queenStack)) {
			while(queenStack.top().col == n) {
				queenStack.pop();
				if(queenStack.empty()) return queenStack;
			}
			queenStack.top().col++;
		} else if(queenStack.size() == n) {
			success = true;
		} else {
			queenStack.push(queen(queenStack.size()+1,1));
		}
	}

	return queenStack;
}

bool conflictChecker(stack<queen> current) { // It's passing as a copy anyways, no need for "test = current", just use queen top = current.top();
	bool conflict(false);
	queen top = current.top();

	while(!current.empty() && conflict != true && current.size() > 1) {
		current.pop();
		if(current.top().col == top.col) conflict = true;
		if(abs(current.top().row - top.row) == abs(current.top().col - top.col)) conflict = true;
	}

	return conflict;
}