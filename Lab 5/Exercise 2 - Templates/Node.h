#pragma once
#include <cstdlib>


namespace CS262 {

	struct Node
	{
		typedef double value_type;

		Node(const value_type& data = value_type(),
			 Node* next = NULL,
			 Node* prev = NULL
		) : data(data), next(next), prev(prev) { }

		value_type data;
		Node* next;
		Node* prev;
	};
}