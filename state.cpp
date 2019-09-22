//shnmba004
//lab4
//23 September 2018

#include <vector>
#include <map>
#include "state.h"

state::state(std::vector<char> action, std::map<int, int> reward, int value, int state_no, float discount, float prob){
  this->action=action;
  this->reward=reward;
  this->value=value;
  this->state_no=state_no;
  this->discount=discount;
  this->prob=prob;
}

state::state(){
}

state::~state(){
}

void state::set_value(float value){
	this->value = value;
}

void state::set_state_no(int state_no){
	this->state_no = state_no;
}

void state::set_discount(float discount){
	this->discount = discount;
}

void state::set_prob(float prob){
	this->prob = prob;
}

float state::get_discount(){
  return this->discount;
}

float state::get_prob(){
  return this->prob;
}

std::map<int, int> state::get_reward(){
  return this->reward;
}

int state::get_state_no(){
  return this->state_no;
}

float state::get_value(){
  return this->value;
}

std::vector<char> state::get_action(){
  return this->action;
}

void state::to_string(){
  for (size_t i = 0; i < this->action.size(); i++) {
    std::cout << this->action[i] << '\n';
  }
  for (size_t i = 0; i < this->reward.size(); i++) {
    std::cout << this->reward[i] << '\n';
  }
  std::cout << this->value << '\n';
  std::cout << this->state_no << '\n';
  std::cout << this->discount << '\n';
  std::cout << this->prob << '\n';
}
