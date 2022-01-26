#include "DIO.h"
#include "SystickTimer.h"
#include "Timer.h"

char state;
uint8 TF = 0;

void GPIO_Init (void);

void TF1_turn_on_Green(void);
void TF1_turn_on_Yellow (void);
void TF1_turn_on_Red (void);
void TF2_turn_on_Green(void);
void TF2_turn_on_Yellow(void);
void TF2_turn_on_Red(void);

void TF_Timer_init(void (*timerHandler)(void), uint32_t ui32Value);

void PEDS_GPIO_INT_init(void);
void PEDS_F04_handler(void);
void PEDS_Timer_init_2S(void);
void PEDS_Timer_handler_2S(void);
void PEDS_Timer_init_1S(void);
void PEDS_Timer_handler_1S(void);





int main()
{
 GPIO_Init();
 PEDS_GPIO_INT_init();
 TF1_turn_on_Green();
 IntMasterEnable();
 while(1)
  {
    
  }
}

/* function that initalize all pins of all traffic lights and two buttons of pedestrain
   PIN 0, 1, 2 port E for 1st traffic light
   PIN 3 port E, PIN 6 PORT E, PIN 5 PORT E for 2nd traffic light
   PIN 0, 1 PORT D for 1st pedestrain traffic light
   PIN 2, 3 PORT D for 2nd pedestrain traffic light
   order of leds in traffic lights is green, yellow, red
   order of leds in pedestrain traffic lights is green, red
*/
void GPIO_Init(void)
{
  // initialize 2 buttons for pedestrain
  DIO_init(PORTF, PIN0, IN, ODR);
  DIO_init(PORTF, PIN4, IN, ODR);
  
  // initialize leds for traffic lights 
  DIO_init(PORTE, PIN0, OUT, ODR);     // traffic light 1
  DIO_init(PORTE, PIN1, OUT, ODR);     // traffic light 1
  DIO_init(PORTE, PIN2, OUT, ODR);     // traffic light 1
  
  DIO_init(PORTE, PIN3, OUT, ODR);     // traffic light 2
  DIO_init(PORTD, PIN6, OUT, ODR);     // traffic light 2
  DIO_init(PORTE, PIN5, OUT, ODR);     // traffic light 2
  
  DIO_init(PORTD, PIN0, OUT, ODR);     // traffic light pedestrian 1
  DIO_init(PORTD, PIN1, OUT, ODR);     // traffic light pedestrian 1
  
  DIO_init(PORTD, PIN2, OUT, ODR);     // traffic light pedestrian 2
  DIO_init(PORTD, PIN3, OUT, ODR);     // traffic light pedestrian 2
  
  // initalize all leds -> 0
  DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 0);        // traffic light 1

  DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 0);        // traffic light 2

  DIO_WritePin(PORTD, PIN0, 0);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 0);        // traffic light pedestrian 1

  DIO_WritePin(PORTD, PIN2, 0);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 0);        // traffic light pedestrian 2
}

/* first we turned off interrupt of two buttons during writing on leds and turned them on again 
   1st traffic light -> green 
   2nd traffic light -> red
   1st pedestrain traffic light -> red
   2nd pedestrain traffic light -> green
*/
void TF1_turn_on_Green(void)
{
  printf("green 1\n");
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  
  // turn off all leds in traffic light 1
  // green led in traffic light 1 -> 1
  DIO_WritePin(PORTE, PIN0, 1);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 0);        // traffic light 1

  // turn off all leds in traffic light 2
  // red led in traffic light 2 -> 1
  DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 1);        // traffic light 2

  // turn off all leds in pedestrain traffic light 1
  // red led in pedestrain traffic light 1 -> 1
  DIO_WritePin(PORTD, PIN0, 0);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 1);        // traffic light pedestrian 1
  
  // turn off all leds in pedestrain traffic light 2
  // green led in pedestrain traffic light 2 -> 1
  DIO_WritePin(PORTD, PIN2, 1);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 0);        // traffic light pedestrian 2
  
  state = 'g';
  TF = 1;
  TF_Timer_init(TF1_turn_on_Yellow, 5);
  PEDS_GPIO_INT_init();
}

/* first we turned off interrupt of two buttons during writing on leds and turned them on again 
   1st traffic light -> yellow 
   2nd traffic light -> red
   1st pedestrain traffic light -> red
   2nd pedestrain traffic light -> green
*/
void TF1_turn_on_Yellow(void)
{
  printf("yellow 1\n");
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  
  // turn off all leds in traffic light 1
  // yellow led in traffic light 1 -> 1
  DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 1);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 0);        // traffic light 1

  // turn off all leds in traffic light 2
  // red led in traffic light 2 -> 1
  DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 1);        // traffic light 2

  // turn off all leds in pedestrain traffic light 1
  // red led in pedestrain traffic light 1 -> 1
  DIO_WritePin(PORTD, PIN0, 0);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 1);        // traffic light pedestrian 1
  
  // turn off all leds in pedestrain traffic light 2
  // green led in pedestrain traffic light 2 -> 1
  DIO_WritePin(PORTD, PIN2, 1);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 0);        // traffic light pedestrian 2
 
  state = 'y';
  TF = 1;
  TF_Timer_init(TF1_turn_on_Red, 2);
  PEDS_GPIO_INT_init();
}

/* first we turned off interrupt of two buttons during writing on leds and turned them on again 
   turn on red leds in all traffic lights for 1 second
   1st traffic light -> red 
   2nd traffic light -> red
   1st pedestrain traffic light -> red
   2nd pedestrain traffic light -> red
*/
void TF1_turn_on_Red(void)
{
  printf("red 1\n");
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  
  // turn off all leds in traffic light 1
  // red led in traffic light 1 -> 1
  DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 1);        // traffic light 1

  // turn off all leds in traffic light 2
  // red led in traffic light 2 -> 1
  DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 1);        // traffic light 2

  // turn off all leds in pedestrain traffic light 1
  // red led in pedestrain traffic light 1 -> 1
  DIO_WritePin(PORTD, PIN0, 0);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 1);        // traffic light pedestrian 1

  // turn off all leds in pedestrain traffic light 2
  // red led in pedestrain traffic light 2 -> 1
  DIO_WritePin(PORTD, PIN2, 0);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 1);        // traffic light pedestrian 2
 
  state = 'r';
  TF = 1;
  TF_Timer_init(TF2_turn_on_Green, 1);
  PEDS_GPIO_INT_init();
}

/* first we turned off interrupt of two buttons during writing on leds and turned them on again 
   1st traffic light -> red 
   2nd traffic light -> green
   1st pedestrain traffic light -> green
   2nd pedestrain traffic light -> red
*/
void TF2_turn_on_Green(void)
{  
  printf("green 2\n");
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  
  // turn off all leds in traffic light 1
  // red led in traffic light 1 -> 1
  DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 1);        // traffic light 1

  // turn off all leds in traffic light 2
  // green led in traffic light 2 -> 1
  DIO_WritePin(PORTE, PIN3, 1);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 0);        // traffic light 2

  // turn off all leds in pedestrain traffic light 1
  // green led in pedestrain traffic light 1 -> 1
  DIO_WritePin(PORTD, PIN0, 1);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 0);        // traffic light pedestrian 1

  // turn off all leds in pedestrain traffic light 2
  // red led in pedestrain traffic light 2 -> 1
  DIO_WritePin(PORTD, PIN2, 0);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 1);        // traffic light pedestrian 2
 
  state = 'g';
  TF = 2;
  TF_Timer_init(TF2_turn_on_Yellow, 5);
  PEDS_GPIO_INT_init();
}

/* first we turned off interrupt of two buttons during writing on leds and turned them on again 
   1st traffic light -> red 
   2nd traffic light -> yellow
   1st pedestrain traffic light -> green
   2nd pedestrain traffic light -> red
*/
void TF2_turn_on_Yellow(void)
{
  printf("yellow 2\n");
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  
  // turn off all leds in traffic light 1
  // red led in traffic light 1 -> 1
  DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 1);        // traffic light 1

  // turn off all leds in traffic light 2
  // yellow led in traffic light 2 -> 1
  DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 1);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 0);        // traffic light 2

  // turn off all leds in pedestrain traffic light 1
  // green led in pedestrain traffic light 1 -> 1
  DIO_WritePin(PORTD, PIN0, 1);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 0);        // traffic light pedestrian 1

  // turn off all leds in pedestrain traffic light 2
  // red led in pedestrain traffic light 2 -> 1
  DIO_WritePin(PORTD, PIN2, 0);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 1);        // traffic light pedestrian 2
 
  state = 'y';
  TF = 2;
  TF_Timer_init(TF2_turn_on_Red, 2);
  PEDS_GPIO_INT_init();
}

/* first we turned off interrupt of two buttons during writing on leds and turned them on again 
   turn on red leds in all traffic lights for 1 second
   1st traffic light -> red 
   2nd traffic light -> red
   1st pedestrain traffic light -> red
   2nd pedestrain traffic light -> red
*/
void TF2_turn_on_Red(void)
{
  printf("red 2\n");
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  
  // turn off all leds in traffic light 1
  // red led in traffic light 1 -> 1
  DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
  DIO_WritePin(PORTE, PIN2, 1);        // traffic light 1

  // turn off all leds in traffic light 2
  // red led in traffic light 2 -> 1
  DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
  DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
  DIO_WritePin(PORTE, PIN5, 1);        // traffic light 2

  // turn off all leds in pedestrain traffic light 1
  // red led in pedestrain traffic light 1 -> 1
  DIO_WritePin(PORTD, PIN0, 0);        // traffic light pedestrian 1
  DIO_WritePin(PORTD, PIN1, 1);        // traffic light pedestrian 1

  // turn off all leds in pedestrain traffic light 2
  // red led in pedestrain traffic light 2 -> 1
  DIO_WritePin(PORTD, PIN2, 0);        // traffic light pedestrian 2
  DIO_WritePin(PORTD, PIN3, 1);        // traffic light pedestrian 2
 
  state = 'r';
  TF = 2;
  TF_Timer_init(TF1_turn_on_Green, 1);
  PEDS_GPIO_INT_init();
}

/* function that initialize timer for two traffic lights
   it takes handler that will call after ui32value elapsed 
*/
void TF_Timer_init(void (*timerHandler)(void), uint32_t ui32Value)
{
  Timer_Init(TIMER1, TIMERBOTH, FOTIMER, true, ui32Value*16000000, TIMER_A_TIMEOUT, timerHandler);
}

/* function to initialize GPIO F interrupts
   we make button 0 and button 4 interrupt for the same handler
*/
void PEDS_GPIO_INT_init(void)
{
  DIO_INT_init(PORTF, GPIO_INT_PIN_0, GPIO_PIN_0, PEDS_F04_handler, GPIO_LOW_LEVEL);
  DIO_INT_init(PORTF, GPIO_INT_PIN_4, GPIO_PIN_4, PEDS_F04_handler, GPIO_LOW_LEVEL);
}

/* handler of PEDS_GPIO_INT_init() 
   we handled both buttons interrupt for the same handler so if two buttons preesed in same time same handler will be executed for one time (BOUNS)
   we turned off two GPIO F interrupt so if pedestrain press button more than one time that will not handled (BOUNS)\
   we turned off timer 1 's clock so affter 2 seconds the timer will resume its state and resume the remaining time
   (it is not logical that pedestrain press button when traffic light is red and pedestrain traffic light is green) so if button pressed
   we make two traffic lights -> red , two pedestrain traffic lights -> green
   we clear flag of two buttons interrupt
   call function that initialize timer 0 to count 2 seconds for pedestrain
*/ 
void PEDS_F04_handler (void)    // handle pedestrain press, when pressed 2 traffic lights -> red, 2 pedestrain traffic lights -> green, stop clock of timer, save state
{
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_4);
  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_INT_PIN_0);
  SysCtlPeripheralDisable(SYSCTL_PERIPH_TIMER1);
  SYSTICK_DelayPollingMS(30);
  if(DIO_ReadPin(PORTF, PIN0) == 0 || DIO_ReadPin(PORTF, PIN4) == 0)
  {
    printf("ped 0 pressed\n");
    // tf1
    DIO_WritePin(PORTE, PIN0, 0);        // traffic light 1
    DIO_WritePin(PORTE, PIN1, 0);        // traffic light 1
    DIO_WritePin(PORTE, PIN2, 1);        // traffic light 1

    // turn off all leds in traffic light 2
    // red led in traffic light 2 -> 1
    DIO_WritePin(PORTE, PIN3, 0);        // traffic light 2
    DIO_WritePin(PORTD, PIN6, 0);        // traffic light 2
    DIO_WritePin(PORTE, PIN5, 1);        // traffic light 2

    // turn off all leds in pedestrain traffic light 1
    // red led in pedestrain traffic light 1 -> 1
    DIO_WritePin(PORTD, PIN0, 1);        // traffic light pedestrian 1
    DIO_WritePin(PORTD, PIN1, 0);        // traffic light pedestrian 1
  
    // turn off all leds in pedestrain traffic light 2
    // green led in pedestrain traffic light 2 -> 1
    DIO_WritePin(PORTD, PIN2, 1);        // traffic light pedestrian 2
    DIO_WritePin(PORTD, PIN3, 0);        // traffic light pedestrian 2
  }
  while(1)
  {
    if(DIO_ReadPin(PORTF, PIN0) == 1 && DIO_ReadPin(PORTF, PIN4) == 1){
      SYSTICK_DelayPollingMS(30);
      if(DIO_ReadPin(PORTF, PIN0) == 1 && DIO_ReadPin(PORTF, PIN4) == 1) break;
    }	
  }
  DIO_INT_clear(PORTF, GPIO_INT_PIN_0);
  DIO_INT_clear(PORTF, GPIO_INT_PIN_4);
  PEDS_Timer_init_2S();   
}

/* function to initialize timer for 2 seconds for pedestrain to cross street
   it calls Timer_Init() from Timer.c 
   we use timer0 as full width one shot
   Timer_Init() takes timerBase, timer, configuration, bstall, value of ticks, flag and handler which called after 2 seconds
*/
void PEDS_Timer_init_2S()
{ 
  
  Timer_Init(TIMER0, TIMERBOTH, FOTIMER, true, 32000000, TIMER_A_TIMEOUT, PEDS_Timer_handler_2S);
}
/* handler function of PEDS_Timer_init_2S() to return to state before pedestrain press button
   we have two global variables one for state and another for which traffic light pedestrain press button
   if 1st traffic light we turn off red led for 1st traffic light and depending on state we turn on led, if g -> turn on green, if y -> turn on yellow
   for 1st pedestrian traffic light we turn off green led and turn on red led
   same if 2nd traffic light
   when pedestrain press button, we turn off clock of timer 1 to resume counting after 2 seconds (croos pedestrain street)
   we turn on clock for timer 1 after 2 seconds
   clear flag of timer 0
   initialize timer 0 to count for 1 second so we enable GPIO Interrupt  (BOUNS)
*/
void PEDS_Timer_handler_2S (void)   // handler after 2 seconds start clock of 2 tl, return to their state, 2 peds tl -> red, initalize timer to count 1 second then initialize peds gpio interrupt
{ 
  if(TF == 1){
    DIO_WritePin(PORTE, PIN2, 0);        // traffic light 1
    DIO_WritePin(PORTD, PIN0, 0);        // traffic light pedestrian 1
    DIO_WritePin(PORTD, PIN1, 1);        // traffic light pedestrian 1
    if(state == 'y') DIO_WritePin(PORTE, PIN1, 1);        // traffic light 1
    else if (state == 'g') DIO_WritePin(PORTE, PIN3, 1);        // traffic light 1
  }
  else if(TF == 2){
    DIO_WritePin(PORTE, PIN5, 0);        // traffic light 2
    DIO_WritePin(PORTD, PIN2, 0);        // traffic light pedestrian 2
    DIO_WritePin(PORTD, PIN3, 1);        // traffic light pedestrian 2
    if(state == 'y') DIO_WritePin(PORTD, PIN6, 1);        // traffic light 1
    else if (state == 'g') DIO_WritePin(PORTD, PIN2, 1);        // traffic light 1
  }
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
  while (!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1)){}
  TimerClearFlag(TIMER0, TIMERBOTH, TIMER_A_TIMEOUT);
  PEDS_Timer_init_1S();
  printf("time elapsed 2 seconds\n");
}

/* function to initialize timer for 1 second to enable interrupt of GPIOF because we turned it off when pedestrain press button
   it calls Timer_Init() from Timer.c 
   we use timer 0 as full width one shot
   Timer_Init() takes timerBase, timer, configuration, bstall, value of ticks, flag and handler which called after 1 second
*/
void PEDS_Timer_init_1S()
{ 
  Timer_Init(TIMER0, TIMERBOTH, FOTIMER, true, 16000000, TIMER_A_TIMEOUT, PEDS_Timer_handler_1S);
}

/* handler function of PEDS_Timer_init_1S() to return to turn on GPIOF interrupt (BOUNS)
   here we initialize GPIOF interrupts and clear flag of timer 0
*/
void PEDS_Timer_handler_1S (void)  
{ 
  TimerClearFlag(TIMER0, TIMERBOTH, TIMER_A_TIMEOUT);
  PEDS_GPIO_INT_init();
  printf("timer elapsed 1 second GPIO initialized\n");
}





