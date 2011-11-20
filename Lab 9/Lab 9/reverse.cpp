#include "recursion.h"

namespace CS262 {
	string reverse(string a, const unsigned int lowerBound, const unsigned int upBound) {
		if(lowerBound >= upBound) {
			return a;
		} else {
			char temp;
			temp = a[upBound];
			a[upBound] = a[lowerBound];
			a[lowerBound] = temp;
			return reverse(a, lowerBound+1, upBound-1);
		}
	}
}