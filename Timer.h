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
#define halfSecond 8000000
#define Second 16000000

#define TIMER0   TIMER0_BASE
#define TIMER1   TIMER1_BASE
#define TIMER2   TIMER2_BASE
#define TIMER3   TIMER3_BASE

#define TIMERA  TIMER_A
#define TIMERB  TIMER_B
#define TIMERBOTH  TIMER_BOTH

#define TIMER_A_TIMEOUT  TIMER_TIMA_TIMEOUT        // Timer A timeout interrupt
#define TIMER_B_TIMEOUT  TIMER_TIMB_TIMEOUT        // Timer B timeout interrupt

#define FPTIMER  TIMER_CFG_PERIODIC                // periodic full timer
#define FOTIMER  TIMER_CFG_ONE_SHOT                // one shot full timer

#define HTIMER   TIMER_CFG_SPLIT_PAIR              // two half width timer
#define AOTIMER  TIMER_CFG_A_ONE_SHOT              // half width (A) one shot timer
#define APTIMER  TIMER_CFG_A_PERIODIC              // half width (A) periodic timer

#define BOTIMER  TIMER_CFG_B_ONE_SHOT              // half width (B) one shot timer
#define BPTIMER  TIMER_CFG_B_PERIODIC              // half width (B) periodic timer

void Timer_Init(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32Config, bool bStall, uint32_t ui32Value, uint32_t ui32IntFlags, void (*timerHandler)(void));
void TimerClearFlag(uint32_t ui32Base, uint32_t ui32Timer, uint32_t ui32IntFlags);
