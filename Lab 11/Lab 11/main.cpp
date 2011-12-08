#include <cstdlib>
#include <iostream>
#include "sort.h"
using namespace std;
using namespace CS262;

int main() {
	char choice = 0;
	double time = 0;
	int data[5];
	int size = 5;

	cout << "Enter the number for the algorithm you would like to run (or enter Q to quit):" << endl << "1. Selection Sort" << endl << "2. Insertion Sort \n" << endl << "3. Merge Sort" << endl << "4. Heap Sort" << endl << "5. STL sort function";
	switch (choice) {
	case 1:
		time = timer(selection_sort(data, size);
		break;
	case 2:

		break;
	case 3: 

		break;
	case 4:

		break;
	case 5:

		break;
	case 'Q':

		break;
	}

	system("PAUSE");
	return 0;
}