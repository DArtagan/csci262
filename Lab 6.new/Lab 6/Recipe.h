#pragma once
#include "LinkedList.h"
using namespace std;

namespace CS262 {
	class Recipe : LinkedList<string> {
	public:
		Recipe() : LinkedList<string>(), Dish("No Name"){};
		Recipe(string d) : LinkedList<string>(), Dish(d){};
		string get_Dish(){return Dish;}
		void set_Dish(string d){Dish = d;}

	protected:
		string Dish;
	};
}