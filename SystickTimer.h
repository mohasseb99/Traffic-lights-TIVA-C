#include <stdio.h>
#include "stdint.h"
#include "stdbool.h"
#include "types.h"
#include "Macros.h"
#include "tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"


#define quarterSecond 4000000
#define halfSecond    8000000
#define Second        16000000


void SYSTICK_DelayPollingMS(uint32_t period);
void SYSTICK_DelayIntMS(uint32_t period, void (*SystickHandler)(void) );