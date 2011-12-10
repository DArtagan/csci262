#include "windows.h"

namespace CS262 {
	template <typename Item, typename SizeType>
	void selection_sort(Item data[], SizeType size) {
		if(size <= 0) return;
		
		for(int i = 0; i<size; i++) {
			int smallest = i;
			for(int j = i+1; j < size; j++) {
				if(data[j] < data[smallest]) smallest = j;
			}
			swap(data[i], data[smallest]);
		}
	}

	template <typename Item, typename SizeType>
	void insertion_sort(Item data[], SizeType size) {
		if(size <= 0) return;

		int sorted = 0;
		for(int i=0; i<size; i++) {
			for(int j=i; j>0 || data[j] < data[i]; j--) {
				if(data[j] < data[j-1]) {
					swap(data[j], data[j-1]);
				}
			}
		}

		/*for(int i=0; i<size; i++) {
			for(int j=0; j<i; j++) {
				if(data[i] > data[j]) {
					Item temp = data[i];
					for(int k=j+1; k<size; k++) {
						swap(data[k], data[k-1]);
					}
					data[j] = temp;
				}
			}
		}*/
	}

	template <typename Item, typename SizeType>
	void merge_sort(Item data[], SizeType size) {
		SizeType n1, n2;

		if(size > 1) {
			n1 = size/2;
			n2 = size - n1;

			merge_sort(data, n1);
			merge_sort((data + n1), n2);

			merge(data, n1, n2);
		}
	}

	template <typename Item, typename SizeType>
	void heap_sort(Item data[], SizeType size) {
		make_heap(data, data+size);
		sort_heap(data, data+size);
		pop_heap(data, data+size);
		heap_sort(data, size-1);
		return;
	}

	template <typename Item, typename SizeType>
	void merge(Item data[], SizeType n1, SizeType n2) {
		Item *temp;
		SizeType copied(0), copied1(0), copied2(0);

		temp = new Item[n1+n2];

		while((copied1 < n1) && (copied2 < n2)) {
			if(data[copied1]<(data+n1)[copied2]) {
				temp[copied++] = data[copied1++];
			} else {
				temp[copied++] = (data+n1)[copied2++];
			}
		}

		while(copied1 < n1) temp[copied++] = data[copied1++];
		while(copied2 < n2) temp[copied++] = (data+n1)[copied2++];
		
		for(int i=0; i<n1+n2; ++i) data[i] = temp[i];
		
		delete [] temp;
	}

	template <typename Item, typename SizeType>
	double timer(void f(Item&, const SizeType&), Item data, const SizeType size) {
		// record the start time
		double start_time = get_milliseconds();
  
		// call the function you want to time here
		f(data, size);

		// the total elapsed time, in milliseconds
		double elapsed_time = get_milliseconds() - start_time;
		
		return elapsed_time;
	}

	template <typename Item, typename SizeType>
	void source(Item data[], SizeType& size) {
		char theChoice=0;
		
		while(theChoice != 1 || theChoice != 2) {
			cout << "Select the array of integers to sort:" << endl << "1. Random Array" << endl << "2. Data from file" << endl;
			cin >> theChoice;

			switch (theChoice) {
			case 1:
				cout << "How big of an array do you want:" << endl;
				cin >> size;
				data = new Item[size];
				for(int i=0; i<size; i++) {
					data[i] = rand();
				}
				break;
			case 2:
				string inFileName;
				cout << "Name of the file you want opened:" << endl;
				cin >> inFileName;
				ifstream inFile(inFileName.c_str());
				if( !inFile ) {
					cout << "Error opening file." << endl;
					system("PAUSE");
					exit(1);
				}
				inFile >> size;
				for( int i(0); i<size; i++ ) {
					if( !( inFile >> data[i] ) ) {
						cout << "The data contains an invalid point.";
						break; // read error
					}
				}
				break;
			}
		}
	}
}