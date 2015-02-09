/* Sketch written by Padraig Lysandrou May,7, 2014
 * feel free to email me at psl58@cornell.edu
 *
 *This is so that you have a stepper motor at the base (bipolar)
 *This is also that you have two servos controlling the main shoulder
 *It is given that one servo controls the elbow, wrist, and claw
 *
 *
 *
 * This will require an Arduino Mega 2560
 * enjoy the code <3
*/
#include <Stepper.h>
#include <Servo.h> 
#include "definitions.h"

void setup() 
{ 
  Claw.attach(7);  // attaches the servo on pin 9 to the servo object 
  Wrist.attach(6);
  Elbow.attach(5);
  Shoulder1.attach(4);
  Shoulder2.attach(3);
  
  Base.setSpeed(10); //This establishes the speed of the stepper at 10rpm
} 
 
void loop() 
{ 
  servorun(A0, Claw);
  servorun(A1, Wrist);
  servorun(A2, Elbow);
  servorun(A3, Shoulder1);
  servorun(A3, Shoulder2);
  
  Stepval= analogRead(A4);
  Base.step(Stepval-previous);
  previous = Stepval;

} 

void servorun(char analog, Servo servodo)
{
  readl = analogRead(analog);
  newread = map(readl, 0, 1023, 0, 179);
  servodo.write(newread);
  delay(5);

}
