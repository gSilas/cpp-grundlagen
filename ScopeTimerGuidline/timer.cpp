#include "timer.hpp"
#include <iostream>

// TODO: Definition of constructor and destructor of the ScopeTimer.

ScopeTimer::ScopeTimer(int name){
	this->name = name;
	timer = clock();
}

ScopeTimer::~ScopeTimer(){
	timer = clock() - timer;
	std::clog << "Timer: " << name << " Sekunden: " << static_cast<float>(timer) / (CLOCKS_PER_SEC*1000) << std::endl;
}
