//shnmba004
//lab4
//23 September 2018

#include "grid.h"
#include <algorithm>    // std::max
#include <fstream>
#include "float.h"

grid::grid(){
	}
	
grid::~grid(){
	}
	
grid::grid(std::vector<std::vector<state>> world){
  this->world = world;
}

void grid::to_string(){
  for (size_t i = 0; i < this->world.size(); i++) {
    for (size_t j = 0; j < this->world[i].size(); j++) {
      std::cout << this->world[i][j].get_value() << " | ";
    }
    std::cout << '\n';
  }
}

bool grid::converge(grid lhs){
  for (size_t column = 0; column < this->world.size(); column++) {
    for (size_t row = 0; row < this->world[column].size(); row++) {
      if (this->world[column][row].get_value()!=lhs.world[column][row].get_value()) {
        return false;
      }
    }
  }
  return true;
}

void grid::fill_grid(){
	grid g, a;
	state s;
	s.set_value(1.0);
	g.world = {{s,s,s},{s,s,s}};
	a.world = g.world;
	int iteration = 0;
	while(this->converge(g) == 0){
		for(size_t col = 0; col < this->world.size(); col++){
			for(size_t row = 0; row < this->world[col].size(); row++){
				state next;
				for(char b: this->world[col][row].get_action()){
					switch(b){
						case 'u':{
							next = this->world[col-1][row];
							this->world[col][row].set_value(std::max(this->world[col][row].get_value(), this->world[col][row].get_reward()[next.get_state_no()] + this->world[col][row].get_discount()*next.get_value()));
						}
						break;
						case 'd':{
							next = this->world[col+1][row];
							this->world[col][row].set_value(std::max(this->world[col][row].get_value(), this->world[col][row].get_reward()[next.get_state_no()] + this->world[col][row].get_discount()*next.get_value()));
						}
						break;
						case 'l':{
							next = this->world[col][row-1];
							this->world[col][row].set_value(std::max(this->world[col][row].get_value(), this->world[col][row].get_reward()[next.get_state_no()] + this->world[col][row].get_discount()*next.get_value()));
						}
						break;
						case 'r':{
							next = this->world[col][row+1];
							this->world[col][row].set_value(std::max(this->world[col][row].get_value(), this->world[col][row].get_reward()[next.get_state_no()] + this->world[col][row].get_discount()*next.get_value()));
						}
						break;
						default:{
						}
						break;
					}
				}
			}
		}
		g.world = a.world;
		a.world = this->world;
		iteration++;
	}
	this->write_optimal(iteration);
}

void grid::write_optimal(int i) {
  std::ofstream ofs ("question1");
  for (size_t column = 0; column < 2; column++) {
    for (size_t row = 0; row < 3; row++) {
      ofs << this->world[column][row].get_value() << " | ";
    }
    ofs << '\n';
  }
  ofs << '\n';
  ofs << "iterations: " << i;
  ofs.close();
}

std::vector<state> grid::optimal_policy(state s){
  std::vector<state> states, optimal_states;
  state next_state;
  optimal_states.push_back(s);
  this->world[0][2].set_value(FLT_MAX);
  for (size_t column = 0; column < this->world.size(); column++) {
    for (size_t row = 0; row < this->world[column].size(); row++) {
      if (s.get_state_no()==this->world[column][row].get_state_no()) {
        while (s.get_state_no()!=3) {
          for(char a: s.get_action()){
            switch (a) {
              case 'u':{
                next_state=this->world[column-1][row];
                states.push_back(next_state);
              }
              break;
              case 'd':{
                next_state=this->world[column+1][row];
                states.push_back(next_state);
              }
              break;
              case 'l':{
                next_state=this->world[column][row-1];
                states.push_back(next_state);
              }
              break;
              case 'r':{
                next_state=this->world[column][row+1];
                states.push_back(next_state);
              }
              break;
              case 'i':{
                next_state=this->world[column][row];
                states.push_back(next_state);
              }
              break;
              default:{
              }
              break;
            }
          }
          s=optimal_state(states);
          optimal_states.push_back(s);
          states.erase(states.begin(), states.end());
          s.to_string();
        }
      }
    }
  }
  return optimal_states;
}

state grid::optimal_state(std::vector<state> v){
	state s;
	for(size_t col = 0; col < v.size(); col++){
		if(v[col].get_value() > s.get_value()){
			s.set_value(v[col].get_value());
			s.set_state_no(v[col].get_state_no());
		}
	}
	return s;
}

void grid::write_optimal_policy(std::vector<state> states){
	std::ofstream ofs("question2");
	for(auto s: states){
		ofs << "s" << s.get_state_no() << "->";
	}
	ofs.close();
}
