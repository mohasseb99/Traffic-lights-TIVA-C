#include "DIO.h"

/* function to initialize port and pins needed 
isFloating parametr -> open drain
*/
void DIO_init(uint8 port,uint8 pin,uint8 dir, uint8 isFloating)
{
  switch (port){
  case 0:
    Set_Bit(SYSCTL_RCGCGPIO_R,0);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,0)==0){}
    Set_Bit(GPIO_PORTA_CR_R,pin);
    if(dir==1){
      Set_Bit(GPIO_PORTA_DIR_R,pin);
      if(isFloating) Set_Bit(GPIO_PORTA_ODR_R,pin);
    }
    if(dir==0){
      Clear_Bit(GPIO_PORTA_DIR_R,pin);
      Set_Bit(GPIO_PORTA_PUR_R,pin);
    }
    Set_Bit(GPIO_PORTA_DEN_R,pin);
    break;
    
  case 1:
    Set_Bit(SYSCTL_RCGCGPIO_R,1);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,1)==0){}
    Set_Bit(GPIO_PORTB_CR_R,pin);
    if(dir==1){
    	Set_Bit(GPIO_PORTB_DIR_R,pin);
    	if(isFloating) Set_Bit(GPIO_PORTB_ODR_R,pin);
    }
    if(dir==0){
    	Clear_Bit(GPIO_PORTB_DIR_R,pin);
    	Set_Bit(GPIO_PORTB_PUR_R,pin);
    }
    Set_Bit(GPIO_PORTB_DEN_R,pin);
    break;
    
  case 2:
    Set_Bit(SYSCTL_RCGCGPIO_R,2);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,2)==0){}
    GPIO_PORTC_LOCK_R=0x4C4F434B;
    Set_Bit(GPIO_PORTC_CR_R,pin);
    if(dir==1){
    	Set_Bit(GPIO_PORTC_DIR_R,pin);
    	if(isFloating) Set_Bit(GPIO_PORTC_ODR_R,pin);
    }
    if(dir==0){
    	Clear_Bit(GPIO_PORTC_DIR_R,pin);
    	Set_Bit(GPIO_PORTC_PUR_R,pin);
    }
    Set_Bit(GPIO_PORTC_DEN_R,pin);
    break;
    
  case 3:
    Set_Bit(SYSCTL_RCGCGPIO_R,3);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,3)==0){}
    GPIO_PORTD_LOCK_R=0x4C4F434B;
    Set_Bit(GPIO_PORTD_CR_R,pin);
    if(dir==1){
    	Set_Bit(GPIO_PORTD_DIR_R,pin);
    	if(isFloating) Set_Bit(GPIO_PORTD_ODR_R,pin);
    }
    if(dir==0){
    	Clear_Bit(GPIO_PORTD_DIR_R,pin);
    	Set_Bit(GPIO_PORTD_PUR_R,pin);
    }
    Set_Bit(GPIO_PORTD_DEN_R,pin);
    break;
    
  case 4:
    Set_Bit(SYSCTL_RCGCGPIO_R,4);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,4)==0){}
    Set_Bit(GPIO_PORTE_CR_R,pin);
    if(dir==1){
    	Set_Bit(GPIO_PORTE_DIR_R,pin);
    	if(isFloating) Set_Bit(GPIO_PORTE_ODR_R,pin);
    }
    if(dir==0){
    	Clear_Bit(GPIO_PORTE_DIR_R,pin);
    	Set_Bit(GPIO_PORTE_PUR_R,pin);
    }
    Set_Bit(GPIO_PORTE_DEN_R,pin);
    break;
    
  case 5:
    Set_Bit(SYSCTL_RCGCGPIO_R,5);
    while(Get_Bit(SYSCTL_RCGCGPIO_R,5)==0){}
    GPIO_PORTF_LOCK_R=0x4C4F434B;
    Set_Bit(GPIO_PORTF_CR_R,pin);
    if(dir==1){
    	Set_Bit(GPIO_PORTF_DIR_R,pin);
    	//if(isFloating) Set_Bit(GPIO_PORTF_ODR_R,pin);
    }
    if(dir==0){
    	Clear_Bit(GPIO_PORTF_DIR_R,pin);
    	Set_Bit(GPIO_PORTF_PUR_R,pin);
    }
    Set_Bit(GPIO_PORTF_DEN_R,pin);
    break;
    
  } 
}

/* function that write on pin
it takes port num, pin num and value
*/
void DIO_WritePin(uint8 port,uint8 pin, uint8 bitValue){
	switch(port)
	{
	case PORTA:
		if(bitValue)
		{
			Set_Bit(GPIO_PORTA_DATA_R,pin);
		}
		else{
			Clear_Bit(GPIO_PORTA_DATA_R,pin);
		}
		break;

	case PORTB:
		if(bitValue)
		{
			Set_Bit(GPIO_PORTB_DATA_R,pin);
		}
		else{
			Clear_Bit(GPIO_PORTB_DATA_R,pin);
		}
		break;

	case PORTC:
		if(bitValue)
		{
			Set_Bit(GPIO_PORTC_DATA_R,pin);
		}
		else{
			Clear_Bit(GPIO_PORTC_DATA_R,pin);
		}
		break;

	case PORTD:
		if(bitValue)
		{
			Set_Bit(GPIO_PORTD_DATA_R,pin);
		}
		else{
			Clear_Bit(GPIO_PORTD_DATA_R,pin);
		}
		break;
  
	case PORTE:
		if(bitValue)
		{
			Set_Bit(GPIO_PORTE_DATA_R,pin);
		}
		else{
			Clear_Bit(GPIO_PORTE_DATA_R,pin);
		}
		break;
  
	case PORTF:
		if(bitValue)
		{
			Set_Bit(GPIO_PORTF_DATA_R,pin);
		}
		else{
			Clear_Bit(GPIO_PORTF_DATA_R,pin);
		}
		break;
	}
}

/* function that write on port
it takes port num and value 
*/
void DIO_WritePort(uint8 port,uint8 bitValue){
  switch(port){
  	  case PORTA:
  		  GPIO_PORTA_DATA_R=bitValue;
  		  break;
    
  	  case PORTB:
  		  GPIO_PORTB_DATA_R=bitValue;
  		  break;
    
  	  case PORTC:
  		  GPIO_PORTC_DATA_R=bitValue;
  		  break;
    
  	  case PORTD:
  		  GPIO_PORTD_DATA_R=bitValue;
  		  break;
    
  	  case PORTE:
  		  GPIO_PORTE_DATA_R=bitValue;
  		  break;
    
  	  case PORTF:
    	GPIO_PORTF_DATA_R=bitValue;
    	break;
  }
}


/* function that read specific pin 
it takes port num and pi num
*/
uint8 DIO_ReadPin(uint8 port, uint8 pin){
  uint8 value;
  switch(port){
  	  case PORTA:
  		  value = Get_Bit(GPIO_PORTA_DATA_R, pin);
  		  break;

  	  case PORTB:
  		  value = Get_Bit(GPIO_PORTB_DATA_R, pin);
  		  break;

  	  case PORTC:
  		  value = Get_Bit(GPIO_PORTC_DATA_R, pin);
  		  break;

  	  case PORTD:
  		  value = Get_Bit(GPIO_PORTD_DATA_R, pin);
  		  break;

  	  case PORTE:
  		  value = Get_Bit(GPIO_PORTE_DATA_R, pin);
  		  break;

  	  case PORTF:
  		  value = Get_Bit(GPIO_PORTF_DATA_R, pin);
  		  break;
  }
  return value;
}
  
/* function that read specific port
it takes port num
*/
uint8 DIO_ReadPort(uint8 port){
  uint8 value;
  switch(port){
  	  case PORTA:
  		  value = GPIO_PORTA_DATA_R;
  		  break;

  	  case PORTB:
  		  value = GPIO_PORTB_DATA_R;
  		  break;

  	  case PORTC:
  		  value = GPIO_PORTC_DATA_R;
  		  break;

  	  case PORTD:
  		  value = GPIO_PORTD_DATA_R;
  		  break;

  	  case PORTE:
  		  value = GPIO_PORTE_DATA_R;
  		  break;
    
  	  case PORTF:
  		  value = GPIO_PORTF_DATA_R;
  		  break;
  }
  return value;
}

/* function that initialize interrupt for GPIO
it takes port, flags, pin, handler, type -> high/low lever or failing/rising edge
*/
void DIO_INT_init(uint8 port, uint32_t ui32IntFlags, uint32_t ui32Pin, void (*GPIO_handler)(void), uint32_t ui32IntType)
{
  switch (port){
  case 0:
	  GPIOIntDisable(GPIO_PORTA_BASE, ui32IntFlags);
	  GPIOIntRegisterPin(GPIO_PORTA_BASE, ui32Pin, GPIO_handler);
	  IntRegister(INT_GPIOA, GPIO_handler);
	  GPIOIntTypeSet(GPIO_PORTA_BASE, ui32Pin, ui32IntType);
	  GPIOIntEnable(GPIO_PORTA_BASE, ui32IntFlags);
	  IntEnable(INT_GPIOA);
	  break;

  case 1:
  	  GPIOIntDisable(GPIO_PORTB_BASE, ui32IntFlags);
  	  GPIOIntRegisterPin(GPIO_PORTB_BASE, ui32Pin, GPIO_handler);
  	  IntRegister(INT_GPIOB, GPIO_handler);
  	  GPIOIntTypeSet(GPIO_PORTB_BASE, ui32Pin, ui32IntType);
  	  GPIOIntEnable(GPIO_PORTB_BASE, ui32IntFlags);
  	  IntEnable(INT_GPIOB);
  	  break;

  case 2:
      GPIOIntDisable(GPIO_PORTC_BASE, ui32IntFlags);
      GPIOIntRegisterPin(GPIO_PORTC_BASE, ui32Pin, GPIO_handler);
      IntRegister(INT_GPIOC, GPIO_handler);
      GPIOIntTypeSet(GPIO_PORTC_BASE, ui32Pin, ui32IntType);
      GPIOIntEnable(GPIO_PORTC_BASE, ui32IntFlags);
      IntEnable(INT_GPIOC);
      break;

  case 3:
      GPIOIntDisable(GPIO_PORTD_BASE, ui32IntFlags);
      GPIOIntRegisterPin(GPIO_PORTD_BASE, ui32Pin, GPIO_handler);
      IntRegister(INT_GPIOD, GPIO_handler);
      GPIOIntTypeSet(GPIO_PORTD_BASE, ui32Pin, ui32IntType);
      GPIOIntEnable(GPIO_PORTD_BASE, ui32IntFlags);
      IntEnable(INT_GPIOD);
      break;

  case 4:
      GPIOIntDisable(GPIO_PORTE_BASE, ui32IntFlags);
      GPIOIntRegisterPin(GPIO_PORTE_BASE, ui32Pin, GPIO_handler);
      IntRegister(INT_GPIOE, GPIO_handler);
      GPIOIntTypeSet(GPIO_PORTE_BASE, ui32Pin, ui32IntType);
      GPIOIntEnable(GPIO_PORTE_BASE, ui32IntFlags);
      IntEnable(INT_GPIOE);
      break;

  case 5:
      GPIOIntDisable(GPIO_PORTF_BASE, ui32IntFlags);
      GPIOIntRegisterPin(GPIO_PORTF_BASE, ui32Pin, GPIO_handler);
      IntRegister(INT_GPIOF, GPIO_handler);
      GPIOIntTypeSet(GPIO_PORTF_BASE, ui32Pin, ui32IntType);
      GPIOIntEnable(GPIO_PORTF_BASE, ui32IntFlags);
      IntEnable(INT_GPIOF);
      break;
  }
}

/* function that clear flag of interrupt
it takes port and flag
*/
void DIO_INT_clear(uint8 port, uint32_t ui32IntFlags){
	switch(port){
	case 0:
		GPIOIntClear(GPIO_PORTA_BASE, ui32IntFlags);
		break;

	case 1:
		GPIOIntClear(GPIO_PORTB_BASE, ui32IntFlags);
		break;

	case 2:
		GPIOIntClear(GPIO_PORTC_BASE, ui32IntFlags);
		break;

	case 3:
		GPIOIntClear(GPIO_PORTD_BASE, ui32IntFlags);
		break;

	case 4:
		GPIOIntClear(GPIO_PORTE_BASE, ui32IntFlags);
		break;

	case 5:
		GPIOIntClear(GPIO_PORTF_BASE, ui32IntFlags);
		break;
	}
}
