#include "recursion.h"

namespace CS262 {
	string reverse(string a, const unsigned int lowerBound, const unsigned int upBound) {
		if(lowerBound == upBound) {
			return a.substr(lowerBound, 1);
		} else if(lowerBound > upBound){
			return "";
		} else {
			return a[upBound] + reverse(a, lowerBound+1, upBound-1) + a[lowerBound];
		}
	}
}