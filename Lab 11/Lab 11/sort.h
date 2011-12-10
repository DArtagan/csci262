#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"

namespace CS262 {
	template <typename Item, typename SizeType>
		void selection_sort(Item data[], const SizeType size);

	template <typename ForwardIterator>
		void selection_sort_v2(ForwardIterator start, ForwardIterator end);

	template <typename Item, typename SizeType>
		void insertion_sort(Item data[], const SizeType size);

	template <typename Item, typename SizeType>
		void merge_sort(Item data[], const SizeType size);

	template <typename Item, typename SizeType>
		void heap_sort(Item data[], const SizeType size);

	template <typename RandomAccessIterator>
		void heap_sort_v2(RandomAccessIterator start, RandomAccessIterator end);

	template<typename Item, typename SizeType>
		void merge(Item data[], SizeType n1, SizeType n2);

	template <typename Item, typename SizeType>
		Item source(SizeType& size);

	template <typename Item, typename SizeType>
		double timer(void f(int&, const int&), Item& data, const SizeType& size);
}

#include "sort.cpp"