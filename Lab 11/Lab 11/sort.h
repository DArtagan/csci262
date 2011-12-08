#include <algorithm>
#include "windows.h"

namespace CS262 {
	template <typename Item, typename SizeType>
	void selection_sort(Item data[], const SizeType size);

	template <typename Item, typename SizeType>
	void insertion_sort(Item data[], const SizeType size);

	template <typename Item, typename SizeType>
	void merge_sort(Item data[], const SizeType size);

	template <typename Item, typename SizeType>
	void heap_sort(Item data[], const SizeType size);

	double get_milliseconds();

	template <typename Item, typename SizeType, typename Function>
	double timer(void Function(Item&, const SizeType&));
}

#include "sort.cpp"