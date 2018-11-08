/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions related to it.
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "portdef.h"
#include "auto.h"

/*
 * Runs the user autonomous code. This function will be started in its own task with the default
 * priority and stack size whenever the robot is enabled via the Field Management System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit. If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

void getAutoMode() {
  if(analogRead(POT_AUTO_SWITCH) > POT_AUTO_SKILL ) {
    AUTO_SKILL_RUN = true;                    // we are running skills autonomous
  } else {
    AUTO_SKILL_RUN = false;                   // standard skills run
  }
}
                               // autonomous
void autonomous_skill() {
  // SKILL autonomous - all autonomous code it goes in this function

}

void autonomous_comp() {
  // COMPETITION 15sec autonomous all code for competition code goes here
  motorSet(LM_F_DRIVE, 100);   // set right wheels
  motorSet(RM_F_DRIVE, -100);  // set left wheels - reversed !
  delay(500);                  // drive for 500ms forward
  motorSet(LM_F_DRIVE, 0);     // stop both wheels
  motorSet(RM_F_DRIVE, 0);
}

void autonomous() {
  // we can run TWO forms of autonomous - competition or skills
  if(AUTO_SKILL_RUN) {
    autonomous_skill();
  } else {
    autonomous_comp();
  } 

}
