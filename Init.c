#include "MKL05Z4.h"
#include "Init.h"

void initPorts(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTB_MASK;
	PORTB->PCR[leftForward] = PORT_PCR_MUX(1);
	PORTB->PCR[rightForward] = PORT_PCR_MUX(1);
	PORTB->PCR[leftReverse] = PORT_PCR_MUX(1);
	PORTB->PCR[rightReverse] = PORT_PCR_MUX(1);
	
	PORTB->PCR[leftPWM] = PORT_PCR_MUX(2);
	PORTB->PCR[rightPWM] = PORT_PCR_MUX(2);
	
	PTB->PDDR |= (leftForward_MASK | rightForward_MASK | leftReverse_MASK | rightReverse_MASK);
	PTB->PCOR |= (leftForward_MASK | rightForward_MASK | leftReverse_MASK | rightReverse_MASK);
	
	return;
}

void initSensors(void){
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	PORTA->PCR[leftSensor] |= PORT_PCR_MUX(1);
	PORTA->PCR[rightSensor] |= PORT_PCR_MUX(1);
	PORTA->PCR[leftSensor] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;		//pullup enable
	PORTA->PCR[rightSensor] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

	PORTA->PCR[leftSensor] |= PORT_PCR_IRQC(0x08);
	PORTA->PCR[rightSensor] |=	PORT_PCR_IRQC(0x08);
	
	PTA->PDDR &= ~leftSensor_MASK;
	PTA->PDDR &= ~rightSensor_MASK;
	
	NVIC_ClearPendingIRQ(PORTA_IRQn);
	NVIC_EnableIRQ(PORTA_IRQn);
	NVIC_SetPriority(PORTA_IRQn, 1);
	
	return;
}

void initLED(void){	
	PORTB->PCR[redLED] = PORT_PCR_MUX(1);
	PORTB->PCR[greenLED] = PORT_PCR_MUX(1);
	PORTB->PCR[blueLED] = PORT_PCR_MUX(1);
	
	PTB->PDDR |= RED_MASK;
	PTB->PDDR |= GREEN_MASK;
	PTB->PDDR |= BLUE_MASK;
	
	PTB->PSOR |= RED_MASK;
	PTB->PSOR |= GREEN_MASK;
	PTB->PSOR |= BLUE_MASK;
	return;
}

void initPWM()
	{
	SIM->SCGC6 |= SIM_SCGC6_TPM0_MASK;			
	SIM->SOPT2 |= SIM_SOPT2_TPMSRC(1);			
	
	TPM0->SC &= ~TPM_SC_CPWMS_MASK;
	TPM0->SC |= TPM_SC_PS(7);							
	TPM0->MOD = 0xFFF;		
	TPM0->CONTROLS[3].CnSC = TPM_CnSC_MSB_MASK|TPM_CnSC_ELSB_MASK;
	TPM0->CONTROLS[3].CnV = 0x0000;
	TPM0->CONTROLS[2].CnSC = TPM_CnSC_MSB_MASK|TPM_CnSC_ELSB_MASK;
	TPM0->CONTROLS[2].CnV = 0x0000;
	TPM0->SC |= TPM_SC_CMOD(1);
}


