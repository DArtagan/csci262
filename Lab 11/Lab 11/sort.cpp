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

	template <typename ForwardIterator>
		void selection_sort_v2(ForwardIterator start, ForwardIterator end) {
			int size = end - size;
			if(size <= 0) return;
		
			for(int i = 0; i<size; i++) {
				int smallest = i;
				for(int j = i+1; j < size; j++) {
					if(data[j] < data[smallest]) smallest = j;
				}
				iter_swap(data[i], data[smallest]);
			}
		}

	template <typename Item, typename SizeType>
	void insertion_sort(Item data[], SizeType size) {
		if(size <= 0) return;

		for(int i=1; i<size; ++i) {
			for(int j(i); j>=0 && data[j] > data[i]; --j) {
				if(data[j-1] > data[j]) {
					swap(data[j], data[j-1]);
				}
			}
		}
	}

	template <typename Item, typename SizeType>
	void merge_sort(Item data[], SizeType n) {
		SizeType n1, n2;

		if(n > 1) {
			n1 = n/2;
			n2 = n - n1;

			merge_sort(data, n1);
			merge_sort((data + n1), n2);

			merge(data, n1, n2);
		}
	}

	template <typename Item, typename SizeType>
	void heap_sort(Item data[], SizeType size) {
		make_heap(data, data+size);
		sort_heap(data, data+size);
	}

	template <typename RandomAccessIterator>
		void heap_sort_v2(RandomAccessIterator start, RandomAccessIterator end) {
			make_heap(start, end);
			sort_heap(start, end);
		}

	template <typename Item, typename SizeType>
	void merge(Item data[], SizeType n1, SizeType n2) {
		Item *temp;
		SizeType copied(0), copied1(0), copied2(0), i;

		temp = new Item[n1+n2];

		while((copied1 < n1) && (copied2 < n2)) {
			if(data[copied1]<(data+n1)[copied2]) temp[copied++] = data[copied1++];
			else temp[copied++] = (data+n1)[copied2++];
		}

		while(copied1 < n1) temp[copied++] = data[copied1++];
		while(copied2 < n2) temp[copied++] = (data+n1)[copied2++];
		
		for(i = 0; i<n1+n2; ++i) data[i] = temp[i];

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
}