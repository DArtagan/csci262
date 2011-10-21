#pragma once
#include <cstdlib>


namespace CS262 {
	template <typename Item>
	struct Node
	{
		typedef Item value_type;

		Node(const value_type& data = value_type(),
			 Node<Item>* next = NULL,
			 Node<Item>* prev = NULL
		) : data(data), next(next), prev(prev) { }

		value_type data;
		Node<Item>* next;
		Node<Item>* prev;
	};
}