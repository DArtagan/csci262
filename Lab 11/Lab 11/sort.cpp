#include "windows.h"

namespace CS262 {
	template <typename Item, typename SizeType>
	void selection_sort(Item data[], SizeType size) {
		if(size <= 0) return;
		
		for(int i = 0, i < size, i++) {
			int smallest = i;
			for(int j = i+1, j < size, j++) {
				if(data[j] < data[smallest]) smallest = j;
			}
			swap(data[i], data[smallest]);
		}
	}

	template <typename Item, typename SizeType>
	void insertion_sort(Item data[], SizeType size) {

	}

	template <typename Item, typename SizeType>
	void merge_sort(Item data[], SizeType size) {

	}

	template <typename Item, typename SizeType>
	void heap_sort(Item data[], SizeType size) {

	}

	double get_milliseconds() {
		LARGE_INTEGER time;
		QueryPerformanceCounter(&time);
		return time.QuadPart / 1000.0;
	}

	template <typename Item, typename SizeType, typename Function>
	double timer(void Function(Item&, const SizeType&)) {
		// record the start time
		double start_time = get_milliseconds();
  
		// call the function you want to time here
		Function(Item&, const SizeType&);

		// the total elapsed time, in milliseconds
		double elapsed_time = get_milliseconds() - start_time;
	}
}