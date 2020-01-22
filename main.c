#include "MKL05Z4.h"
#include "Init.h"
#include "sensors.h"
#include "work.h"

int main(){
	initPorts();
	initLED();
	initPWM();
	initSensors();

	while(1){
	driveForward();
	}
}
