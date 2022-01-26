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

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
#define PORTE 4
#define PORTF 5

#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7


#define LOGIC_HIGH 1
#define LOGIC_LOW  0


#define IN   0
#define OUT  1
#define ODR  1
#define NODR 0

void DIO_init(uint8 port,uint8 pin,uint8 dir, uint8 isFloating);
void DIO_WritePin(uint8 port,uint8 pin, uint8 bitValue);
void DIO_WritePort(uint8 port,uint8 bitValue);
uint8 DIO_ReadPin(uint8 port, uint8 pin);
uint8 DIO_ReadPort(uint8 port);
void DIO_INT_init(uint8 port, uint32_t ui32IntFlags, uint32_t ui32Pin, void (*GPIO_handler)(void), uint32_t ui32IntType);
void DIO_INT_clear(uint8 port, uint32_t ui32IntFlags);