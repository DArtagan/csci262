#include "recursion.h"

using namespace std;

int gcd(int x, int y) {
	if((x % y) == 0) {
		return y;
	} else {
		gcd(y, (x % y));
	}
}
