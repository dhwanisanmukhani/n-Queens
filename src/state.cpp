#include "state.h"
#include <vector>
#include <iostream> 
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

State::State(int n){
	v.resize(n);
	for(int i=0;i<n;i++) v[i]=i;
	hval = (n*(n-1))/2;
}

void State::make_random(){
	random_shuffle(v.begin(), v.end());
	heuristics();
}

void State::print(){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(j == v[i])
				cout << "*|";
			else
				cout << ".|";
		}
		cout << endl;
	}
}

void State::heuristics(){
	int h = 0;
	for(int i=0;i<v.size();i++){
		for(int j=i+1;j<v.size();j++){
			if(v[j] == v[i] || j-i == abs(v[j]-v[i]))
				h++;
		}
	}
	hval = h;
}

// int State::get_heuristics(int k){
// 	int count=0;
// 	for(int i=0;i<v.size();i++){
// 		if(i==k)
// 			continue;
// 		if(v[i] == v[k])
// 			count++;
// 		if(i-k == v[k]-v[i] || k-i == v[k]-v[i])
// 			count++;
// 	}
// 	return count;
// }