#ifndef AUTO_H_
#define AUTO_H_
// Create all the port definitions in one place for easy trouble shooting
#include "API.h"

bool AUTO_SKILL_RUN = false;
// Get the autonomous mode switch status
void getAutoMode();

// Competition mode autonomous wrapper function
void autonomous_comp();

// SKILL challenge autonomous mode wrapper function
void autonomous_skill();

#endif // AUTO_H_
