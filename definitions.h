#define STEPS 200  //this defines the steps on your motor

Servo Claw;     //defining the outermost servo, the END EFFECTOR, or the one that picks shit up
Servo Wrist;    //defining the servo that moves the effector up and down
Servo Elbow;    //defining the servo that moves the whole upper half of the arm
Servo Shoulder1; //defining the two servos that receive the same signal, they move the entire body at an angle
Servo Shoulder2;

Stepper Base(STEPS, 8, 9, 10, 11);  /* create an instance of the stepper class, specifying 
                                     * the number of steps of the motor and the pins it's
                                     *attached to
                                     */                 
int previous = 0; //previous value for analog input of stepperpot
int Stepval; 
int readl;
int newread;
