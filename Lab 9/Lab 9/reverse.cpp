#include "recursion.h"

string reverse(string a, unsigned int lowerBound, unsigned int upBound) {
	if(lowerBound >= upBound) {
		return a;
	} else {
		return a[upBound] + reverse(a, lowerBound+1, upBound-1) + a[lowerBound];
	}
}
`  