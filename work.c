#include "MKL05Z4.h"
#include "work.h"
#include "Init.h"

void driveForward(void){
	PTB->PCOR |= (leftReverse_MASK | rightReverse_MASK);
	PTB->PSOR |= (leftForward_MASK | rightForward_MASK);
	TPM0->CONTROLS[3].CnV = 0xFFF;
	TPM0->CONTROLS[2].CnV = 0xFFF;
	
	PTB->PSOR |= BLUE_MASK;
	PTB->PSOR |= RED_MASK;
}

void driveReverse(void){
	PTB->PCOR |= (leftForward_MASK | rightForward_MASK);
	PTB->PSOR |= (leftReverse_MASK | rightReverse_MASK);
	TPM0->CONTROLS[3].CnV = 0xFF0;
	TPM0->CONTROLS[2].CnV = 0xFF0;

	
}

void turnLeft(void){
	PTB->PCOR |= RED_MASK;

	PTB->PCOR |= (leftForward_MASK | rightReverse_MASK);
	PTB->PSOR |= (rightForward_MASK | leftReverse_MASK);
	TPM0->CONTROLS[3].CnV = 0xDF0;
	TPM0->CONTROLS[2].CnV = 0xDF0;
}

void turnRight(void){
	PTB->PCOR |= BLUE_MASK;
	
	PTB->PCOR |= (rightForward_MASK | leftReverse_MASK);
	PTB->PSOR |= (leftForward_MASK  | rightReverse_MASK);
	TPM0->CONTROLS[3].CnV = 0xDF0;
	TPM0->CONTROLS[2].CnV = 0xDF0;

}

void delay(uint32_t value_ms){
	uint32_t x, delay;
	
	for(x=0; x<value_ms; x++){
		for(delay=0; delay < 100000; delay++){};
	}
	
	return;
}
