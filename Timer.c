#include "Timer.h"

/* function that initialize timer
it takes base timer, timer(a, b or both), configuration, bstall, value of ticks, flags, handler
*/
void Timer_Init(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Config, bool bStall, uint32_t ui32Value, uint32_t ui32IntFlags, void (*timerHandler)(void))
{		
	switch(ui32Base){
	case TIMER0:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
		while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0)){}
		if(ui32Timer == TIMERA){
			TimerDisable(TIMER0, TIMERA);
                        TimerLoadSet(TIMER0, TIMERA, ui32Value - 1);
			TimerConfigure(TIMER0, ui32Config);
                        TimerIntClear(TIMER0, TIMER_TIMA_TIMEOUT);
			TimerControlStall(TIMER0, TIMERA, bStall);
			//IntPrioritySet(INT_TIMER0A,0x20);
			TimerIntEnable(TIMER0, ui32IntFlags);
			TimerIntRegister(TIMER0, TIMERA, timerHandler);
			TimerEnable(TIMER0, TIMERA);
		}
		else if(ui32Timer == TIMERB){
			TimerDisable(TIMER0, TIMERB);
			TimerLoadSet(TIMER0, TIMERB, ui32Value - 1);
                        TimerConfigure(TIMER0, ui32Config);
                        TimerIntClear(TIMER0, TIMER_TIMB_TIMEOUT);
			TimerControlStall(TIMER0, TIMERB, bStall);
			//IntPrioritySet(INT_TIMER0A,0x20);
			TimerIntEnable(TIMER0, ui32IntFlags);
			TimerIntRegister(TIMER0, TIMERB, timerHandler);
			TimerEnable(TIMER0, TIMERB);
		}
		else if(ui32Timer == TIMERBOTH){
			TimerDisable(TIMER0, TIMERBOTH);
			TimerLoadSet(TIMER0, TIMERA, ui32Value - 1);
			TimerConfigure(TIMER0, ui32Config);
                        TimerIntClear(TIMER0, TIMER_TIMA_TIMEOUT);
			TimerControlStall(TIMER0, TIMERBOTH, bStall);
			//IntPrioritySet(INT_TIMER0A,0x20);
			TimerIntEnable(TIMER0, ui32IntFlags);
			TimerIntRegister(TIMER0, TIMERBOTH, timerHandler);
			TimerEnable(TIMER0, TIMERBOTH);
		}
		break;

	case TIMER1:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
		while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1)){}
		if(ui32Timer == TIMERA){
			TimerDisable(TIMER1, TIMERA);
			TimerLoadSet(TIMER1, TIMERA, ui32Value - 1);
                        TimerConfigure(TIMER1, ui32Config);
                        TimerIntClear(TIMER1, TIMER_TIMA_TIMEOUT);
			TimerControlStall(TIMER1, TIMERA, bStall);
			//IntPrioritySet(INT_TIMER0A,0x20);
			TimerIntEnable(TIMER1, ui32IntFlags);
			TimerIntRegister(TIMER1, TIMERA, timerHandler);
			TimerEnable(TIMER1, TIMERA);
		}
		else if(ui32Timer == TIMERB){
			TimerDisable(TIMER1, TIMERB);
			TimerLoadSet(TIMER1, TIMERB, ui32Value - 1);
                        TimerConfigure(TIMER1, ui32Config);
                        TimerIntClear(TIMER1, TIMER_TIMB_TIMEOUT);
			TimerControlStall(TIMER1, TIMERB, bStall);
			//IntPrioritySet(INT_TIMER0A,0x20);
                        TimerIntEnable(TIMER1, ui32IntFlags);
			TimerIntRegister(TIMER1, TIMERB, timerHandler);
			TimerEnable(TIMER1, TIMERB);
		}
		else if(ui32Timer == TIMERBOTH){
			TimerDisable(TIMER1, TIMERBOTH);
			TimerLoadSet(TIMER1, TIMERA, ui32Value - 1);
                        TimerConfigure(TIMER1, ui32Config);
                        TimerIntClear(TIMER1, TIMER_TIMA_TIMEOUT);
			TimerControlStall(TIMER1, TIMERBOTH, bStall);
			//IntPrioritySet(INT_TIMER0A,0x20);
			TimerIntEnable(TIMER1, ui32IntFlags);
			TimerIntRegister(TIMER1, TIMERBOTH, timerHandler);
			TimerEnable(TIMER1, TIMERBOTH);
		}
		break;

	case TIMER2:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
		while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER2)){}
		if(ui32Timer == TIMERA){
			TimerDisable(TIMER2, TIMERA);
			TimerConfigure(TIMER2, ui32Config);
			TimerControlStall(TIMER2, TIMERA, bStall);
			TimerLoadSet(TIMER2, TIMERA, ui32Value - 1);
			TimerIntEnable(TIMER2, ui32IntFlags);
			TimerIntRegister(TIMER2, TIMERA, timerHandler);
			TimerEnable(TIMER2, TIMERA);
		}
		else if(ui32Timer == TIMERB){
			TimerDisable(TIMER2, TIMERB);
			TimerConfigure(TIMER2, ui32Config);
			TimerControlStall(TIMER2, TIMERB, bStall);
			TimerLoadSet(TIMER2, TIMERB, ui32Value - 1);
			TimerIntEnable(TIMER2, ui32IntFlags);
			TimerIntRegister(TIMER2, TIMERB, timerHandler);
			TimerEnable(TIMER2, TIMERB);
		}
		else if(ui32Timer == TIMERBOTH){
			TimerDisable(TIMER2, TIMERBOTH);
			TimerConfigure(TIMER2, ui32Config);
			TimerControlStall(TIMER2, TIMERBOTH, bStall);
			TimerLoadSet(TIMER2, TIMERA, ui32Value - 1);
			TimerIntEnable(TIMER2, ui32IntFlags);
			TimerIntRegister(TIMER2, TIMERBOTH, timerHandler);
			TimerEnable(TIMER2, TIMERBOTH);
		}
		break;

	case TIMER3:
		SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);
		while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER3)){}
		if(ui32Timer == TIMERA){
			TimerDisable(TIMER3, TIMERA);
			TimerConfigure(TIMER3, ui32Config);
			TimerControlStall(TIMER3, TIMERA, bStall);
			TimerLoadSet(TIMER3, TIMERA, ui32Value - 1);
			TimerIntEnable(TIMER3, ui32IntFlags);
			TimerIntRegister(TIMER3, TIMERA, timerHandler);
			TimerEnable(TIMER3, TIMERA);
		}
		else if(ui32Timer == TIMERB){
			TimerDisable(TIMER3, TIMERB);
			TimerConfigure(TIMER3, ui32Config);
			TimerControlStall(TIMER3, TIMERB, bStall);
			TimerLoadSet(TIMER3, TIMERB, ui32Value - 1);
			TimerIntEnable(TIMER3, ui32IntFlags);
			TimerIntRegister(TIMER3, TIMERB, timerHandler);
			TimerEnable(TIMER3, TIMERB);
		}
		else if(ui32Timer == TIMERBOTH){
			TimerDisable(TIMER3, TIMERBOTH);
			TimerConfigure(TIMER3, ui32Config);
			TimerControlStall(TIMER3, TIMERBOTH, bStall);
			TimerLoadSet(TIMER3, TIMERA, ui32Value - 1);
			TimerIntEnable(TIMER3, ui32IntFlags);
			TimerIntRegister(TIMER3, TIMERBOTH, timerHandler);
			TimerEnable(TIMER3, TIMERBOTH);
		}
		break;
	}
}

/* function that clear flag after interrupt
it takes base timer, timer and flag as parameter
*/
void TimerClearFlag(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32IntFlags){
	switch(ui32Base){
	case TIMER0:
		if(ui32Timer == TIMERA) TimerIntClear(TIMER0, TIMER_TIMA_TIMEOUT);
		else if(ui32Timer == TIMERB) TimerIntClear(TIMER0, TIMER_TIMB_TIMEOUT);
		else if(ui32Timer == TIMERBOTH) TimerIntClear(TIMER0, TIMER_TIMA_TIMEOUT);
		break;

	case TIMER1:
		if(ui32Timer == TIMERA) TimerIntClear(TIMER1, TIMER_TIMA_TIMEOUT);
		else if(ui32Timer == TIMERB) TimerIntClear(TIMER1, TIMER_TIMB_TIMEOUT);
		else if(ui32Timer == TIMERBOTH) TimerIntClear(TIMER1, TIMER_TIMA_TIMEOUT);
		break;

	case TIMER2:
		if(ui32Timer == TIMERA) TimerIntClear(TIMER2, TIMER_TIMA_TIMEOUT);
		else if(ui32Timer == TIMERB) TimerIntClear(TIMER2, TIMER_TIMB_TIMEOUT);
		else if(ui32Timer == TIMERBOTH) TimerIntClear(TIMER2, TIMER_TIMA_TIMEOUT);
		break;

	case TIMER3:
		if(ui32Timer == TIMERA) TimerIntClear(TIMER3, TIMER_TIMA_TIMEOUT);
		else if(ui32Timer == TIMERB) TimerIntClear(TIMER3, TIMER_TIMB_TIMEOUT);
		else if(ui32Timer == TIMERBOTH) TimerIntClear(TIMER3, TIMER_TIMA_TIMEOUT);
		break;
	}
}
