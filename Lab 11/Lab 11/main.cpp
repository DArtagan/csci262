#include <cstdlib>
#include <iostream>
#include "sort.h"
using namespace std;
using namespace CS262;

double get_milliseconds() {
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	return time.QuadPart / 1000.0;
}

void readSeed() {
	/*  Variables  */
	int n;

	/*  Seed Prompt  */
	cout << "What would you like the seed for rand() to be?" << endl;
	cin >> n;
	cout << endl << endl;
	srand(n);
}

int main() {
	char choice = 0;
	double time = 0;
	int* data;
	int size;
	string outFileName;
	
	readSeed();

	while(choice != 'Q') {
		cout << "Enter the number for the algorithm you would like to run (or enter Q to quit):" << endl << "1. Selection Sort" << endl << "2. Insertion Sort" << endl << "3. Merge Sort" << endl << "4. Heap Sort" << endl << "5. STL sort function" << endl;
		cin >> choice;
		double start_time = get_milliseconds();
		switch (choice) {
		case 1:
			// time = timer(selection_sort, data, size);  // I really want it to work, but it just won't
			source(data, size);
			selection_sort(data, size);
			break;
		case 2:
			source(data, size);
			insertion_sort(data, size);
			break;
		case 3: 
			source(data, size);
			merge_sort(data, size);
			break;
		case 4:
			source(data, size);
			heap_sort(data, size);
			break;
		case 5:
			source(data, size);
			sort(data, data+size);
			break;
		}

		cout << endl << "Elapsed Time: " << get_milliseconds() - start_time << endl << endl << endl;

		cout << "Name of the file to store the sorted array in:" << endl;
		cin >> outFileName;

		ofstream outFile(outFileName.c_str());
		if( !outFile ) {
			cout << "Error opening file." << endl;
			system("PAUSE");
			exit(1);
		}
		string test;
		test = size;
		outFile << test << " ";
		for( int i(0); i<size; i++ ) {
			if( !( outFile << data[i] << " " ) ) {
				cout << "The data contains an invalid point.";
				break; // read error
			}
		}
	}

	return 0;
}