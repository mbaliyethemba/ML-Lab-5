//shnmba004
//lab4
//23 September 2018

#include <vector>
#include <map>
#include <iostream>

#ifndef STATE_H
#define STATE_H

class state{
	private:
		std::vector<char> action;
		std::map<int, int> reward;
		int state_no;
		float discount, prob, value;
	public:
		state();
		~state();
		state(std::vector<char>, std::map<int, int>, int, int, float, float);
		void set_value(float);
		void set_discount(float);
		void set_prob(float);
		void set_state_no(float);
		float get_discount();
		float get_prob();
		std::map<int, int> get_reward();
		int get_state_no();
		float get_value();
		std::vector<char> get_action();
		void to_string();
	}
