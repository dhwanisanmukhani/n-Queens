#ifndef BRAIN_H
#define BRAIN_H
#include "state.h"

class Brain{
public:
	State Hill_Climb(State initial);
	State Random_Restart(int n);
	State get_high_suc(State current);
};

#endif