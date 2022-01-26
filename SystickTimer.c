#include "SystickTimer.h"

/* function that use systick timer to count seconds using polling 
it takes time as miliseconds
*/
void SYSTICK_DelayPollingMS(uint32_t period)
{
	SysTickDisable();
	SysTickPeriodSet(period * 16000 - 1);
	SysTickEnable();
	while (Get_Bit(NVIC_ST_CTRL_R, 16) == 0){}
	SysTickDisable();
}

/* function that use systick timer to count seconds using interrupt
it takes time as miliseconds
*/
void SYSTICK_DelayIntMS(uint32_t period, void (*SystickHandler)(void) )
{
	SysTickDisable();
	SysTickPeriodSet(period * 16000 - 1);
	SysTickIntEnable();
	SysTickIntRegister(SystickHandler);
	IntMasterEnable();
	SysTickEnable();
}
