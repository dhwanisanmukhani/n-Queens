#include "state.h"
#include "brain.h"
#include <iostream>
using namespace std;


State Brain::Hill_Climb(State initial){
	State current = initial;
	State next;
	int iterations=0;
	while(iterations<100){
		iterations++;
		next = get_high_suc(current);
		if(next.hval <= current.hval){
			current = next;
			continue;
		}
		else
			return current;
	}
	return current;
}

State Brain::Random_Restart(int n){
	State sol(n), tmp(n);
	for(int i=0;i<100;i++){
		tmp.make_random(); 
		tmp = Hill_Climb(tmp);
		if(tmp.hval < sol.hval){
			sol = tmp;
		}
		if(sol.hval==0){
			cout<<i<<endl;
			break;
		}
	}
	sol.print();
	sol.heuristics();
	cout<<sol.hval<<endl;
	return sol;
}

State Brain::get_high_suc(State current){
	State ret = current;
	auto& v = current.v;
	int hval = current.hval;
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(v[i]==j)
				continue;
			int row = v[i];
			v[i]=j;
			current.heuristics();
			if(current.hval < hval){
				hval = current.hval;
				ret = current;
			}
			v[i]=row;
		}
	}
	return ret;
	// int place, h, htemp, diff = 1e9, index, index_val;
	// for(int i=0;i<current.size;i++){
	// 	place = current.v[i];
	// 	h = current.get_heuristics(i);
	// 	for(int j=0;j<current.size;j++){
	// 		if(j == place)
	// 			continue;
	// 		current.v[i] = j;
	// 		htemp = current.get_heuristics(i);
	// 		cout<<htemp<< " " <<diff << " " <<h<<endl;
	// 		if(htemp < h){
	// 			if(diff > h-htemp){
	// 				diff = h-htemp;
	// 				index = i;
	// 				index_val = j;
	// 			} 
	// 		}
	// 		//current.print();
	// 	}
	// 	current.v[i] = place;
	// }
	// current.v[index] = index_val;
	// current.hval -= diff;
	// current.print();
//	return current;
}