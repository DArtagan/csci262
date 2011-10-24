// Master tile class
#pragma once
#include "car.h"

namespace CS262 {
	class tile{
	public:
		tile(): tile_num(0), tileType("straight") {};
		tile(int num, std::string str) : tile_num(num), tileType(str){};
		int get_tile_num() {return tile_num;}
		std::string get_type() {return tileType;}
		void set_num(int n) {tile_num = n;}

		virtual void change_acc(car&);
		virtual void check_topspeed(car& c);

	protected:
		int tile_num;
		std::string tileType;
		int max_speed_allowed;
		double acc_multi;

	};
}
