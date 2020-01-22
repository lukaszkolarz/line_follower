#include "MKL05Z4.h"

#ifndef INIT_H
#define INIT_H

#define leftForward 1		//PTB
#define rightForward 3
#define leftReverse 2
#define rightReverse 4

#define leftPWM 7				//PTB
#define rightPWM 6

#define leftSensor 12		//PTA
#define rightSensor 7

#define redLED 8				//PTB
#define greenLED 9
#define blueLED 10

#define RED_MASK (1 << redLED)
#define GREEN_MASK (1 << greenLED);
#define BLUE_MASK (1 << blueLED);

#define leftForward_MASK (1 << leftForward)
#define rightForward_MASK (1 << rightForward)
#define leftReverse_MASK (1 << leftReverse)
#define rightReverse_MASK (1 << rightReverse)

#define leftSensor_MASK (1 << leftSensor)
#define rightSensor_MASK (1 << rightSensor)

void initPorts(void);
void initLED(void);
void initPWM(void);
void initSensors(void);


#endif //INIT_H
