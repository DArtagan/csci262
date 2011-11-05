#include "recursion.h"

using namespace std;

namespace CS262 {
	int gcd(const unsigned int x, const unsigned int y) {
		if((x % y) == 0) {
			return y;
		} else {
			gcd(y, (x % y));
		}
	}
}