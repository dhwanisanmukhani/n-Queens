#ifndef STATE_H
#define STATE_H
#include <vector>
using namespace std;

class State{
public:
	vector<int> v;
	int hval;
	State(int n=0);
	void make_random();
	void print();
	void heuristics();
	// int get_heuristics(int k);
};

#endif