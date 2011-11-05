#include "recursion.h"

double sumover(unsigned int n) {
	if(n == 0) {
		return 0;
	} else {
		return sumover(n-1) + 1.0/n;
	}
}
