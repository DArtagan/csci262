#include <cstdlib>
#include <iostream>
#include "recursion.h"

using namespace std;

int main() {
	int h(0);

	while(h != 4) {
		while(h != 1 && h != 2 && h != 3 && h != 4) {
			cout << "1.) Run GCD" << endl << "2.) Run sumover" << endl << "3.) Run string reversal" << endl << "4.) Exit" << endl << endl << "Type the number for the corresponding option:" << endl;
			cin >> h;
		}
		switch (h) {
			case 1: {
				unsigned int a, b;
				cout << "Two positive integers for which you want to find the greatest common denominator for:" << endl;
				cin >> a >> b;
				cout << "GCD = " << CS262::gcd(a, b) << endl << endl;
				break;
			}
			case 2: {
				unsigned int n;
				cout << "Positive nteger you want to run sumover using:" << endl;
				cin >> n;
				cout << "Result: " << CS262::sumover(n) << endl << endl;
				break;
			}
			case 3: {
				unsigned int lowerBound, upBound;
				string aString = "";
				cout << "The string is the entire alphabet \"abcdefghijklmnopqrstuvwxyz\"" << endl;
				aString = "abcdefghijklmnopqrstuvwxyz";
				cout << "Type an integer representing the first bound in the string, where you want to start from:" << endl;
				cin >> lowerBound;
				cout << "Type an integer representing the last bound in the string, where you want to end at:" << endl;
				cin >> upBound;
				cout << "Reversed String: " << CS262::reverse(aString, lowerBound, upBound) << endl << endl;
				break;
			}
			case 4: {
				exit;
			}
		}
		if(h != 4) h = 0;
	}

	return 0;
}