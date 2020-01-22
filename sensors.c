#include "MKL05Z4.h"
#include "sensors.h"
#include "Init.h"
#include "work.h"

void PORTA_IRQHandler(void){
	
	if (PORTA->PCR[leftSensor] & PORT_PCR_ISF_MASK){
		leftSensor_service();
	}
	else if (PORTA->PCR[rightSensor] & PORT_PCR_ISF_MASK){
		rightSensor_service();
	}
	PORTA->PCR[leftSensor] |= PORT_PCR_ISF_MASK;
	PORTA->PCR[rightSensor] |= PORT_PCR_ISF_MASK;
	
	return;
}

void leftSensor_service(){
	turnRight();
	return;
}

void rightSensor_service(){
	turnLeft();
	return;
}
