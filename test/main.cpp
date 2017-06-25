#include "brain.h"
#include "state.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[]){
	srand(time(NULL));
	Brain AI;
	AI.Random_Restart(atoi(argv[1]));
	return 0;
}