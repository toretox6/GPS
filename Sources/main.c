/* ###################################################################
**     Filename    : main.c
**     Project     : DataLogger
**     Processor   : MK64FN1M0VLL12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2018-10-23, 19:57, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "stdio.h"
#include "Cpu.h"
#include "Events.h"
#include "FAT1.h"
#include "SD1.h"
#include "SS1.h"
#include "CD1.h"
#include "UTIL1.h"
#include "PPS.h"
#include "ExtIntLdd1.h"
#include "GPS.h"
#include "ASerialLdd2.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "LEDR.h"
#include "LEDpin1.h"
#include "BitIoLdd1.h"
#include "LEDG.h"
#include "LEDpin2.h"
#include "BitIoLdd2.h"
#include "UTIL2.h"
#include "FRTOS1.h"
#include "KSDK1.h"
#include "TmDt1.h"
#include "WAIT1.h"
#include "TMOUT1.h"
#include "MCUC1.h"
#include "CS1.h"
#include "SM1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "GI2C1.h"
#include "CI2C1.h"
#include "FX1.h"
#include "PORT_PDD.h"

/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
#include "FRTOS1.h"
#include <queue.h>
#include "KSDK1.h"
#include "task.h"
#include "Application.h"


const static byte longitud = 1000;
const static byte tamano   = 1;
static FAT1_FATFS fileSystemObject;
static FIL file;

char cadena[128];

static xQueueHandle caracteres;

static void Err(void) {
  for(;;){}
}

void StorageOn(){
/* Deteccion de la tarjeta SD: PTE6 con pull-down! */
 PORT_PDD_SetPinPullSelect(PORTE_BASE_PTR, 6, PORT_PDD_PULL_DOWN);
 PORT_PDD_SetPinPullEnable(PORTE_BASE_PTR, 6, PORT_PDD_PULL_ENABLE);

 FAT1_Init();
 if (FAT1_mount(&fileSystemObject, "0", 1) != FR_OK) /* Comprueba el archivo del sistema */
	 Err();
}

void EscribeSD(char *cadena){
	  UINT bandwidth;
	  char ch[1];
	  int i;

	  /* Abrir fichero */
	  if (FAT1_open(&file, "./log_gps.txt", FA_OPEN_ALWAYS|FA_WRITE)!=FR_OK) {
	    Err();
	  }
	  /* Nos posicionamos en el final del archivo */
	  if (FAT1_lseek(&file, f_size(&file)) != FR_OK || file.fptr != f_size(&file)) {
	    Err();
	  }

	  /* Se escribe la cadena en la microSD */
	  if (FAT1_write(&file, cadena, UTIL1_strlen(cadena), &bandwidth)!=FR_OK) {
		  (void)FAT1_close(&file);
		  Err();
	  }

	  /* Cerrar el fichero */
	  (void)FAT1_close(&file);
}

static void Acce(void) {
	word x;
	for(;;) {
		  FX1_Enable(); /* Activa el acelerometro */
			x = FX1_GetX();
	}
}

static void Imprime (void) {
	char ch;
	int i;

	StorageOn();
	for(;;) {
		LEDR_Neg(); LEDG_Off();//led rojo
		if(FRTOS1_xQueueReceive(caracteres, &ch ,10000) == pdTRUE){
			if (ch !='\n'){
				cadena[i++] = ch;
				cadena[i]=0;
			}else{
				cadena[i++] = '\n';
				if ((i>4 && cadena[3]=='R')){
				/* Se ha recibido un dato. Se escribe por el puerto serie */
				for(int j = 0; j < i; j++)
					while(AS1_SendChar(cadena[j]) != ERR_OK) {}
				EscribeSD(cadena);
				}
				i=0;
			}
		}
	}
}

static void CharGPS(void) {
	byte err;
	char ch;
	GPS_ClearRxBuf(); //limpiamos el buffer del gps
	for(;;) {
		LEDR_Off(); LEDG_Neg(); //led verde
	do {err = GPS_RecvChar(&ch);
	   } while((err != ERR_OK));

	FRTOS1_xQueueSendToBack(caracteres, &ch , (portTickType) 0xFFFFFFFF);
	}
}



/* User includes (#include below this line is not maintained by Processor Expert) */
//#include "Application.h"
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
 	caracteres=FRTOS1_xQueueCreate(longitud,tamano);
	//int16_t x,y,z;
	uint8_t ack;

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/


  /* Write your code here */


  if (xTaskCreate(
  	   CharGPS, /* funci�n de la tarea*/
  	  "gps", /* nombre de la tarea para el kernel */
  	  configMINIMAL_STACK_SIZE, /* tama�o pila asociada a la tarea */
  	  (void*)NULL, /*puntero a los par�metros iniciales de la tarea */
  	  5,/* prioridad de la tarea, cuanto m�s bajo es el n�mero menor es la prioridad */
  	  NULL /* manejo de la tarea, NULL si ni se va a crear o destruir */
    ) != pdPASS) { /* devuelve pdPASS si se ha creado la tarea */
  	  for(;;){} /* error! Probablemente sin memoria */
  	  }

    if (xTaskCreate(
    	   Imprime, /* funci�n de la tarea*/
    	  "print", /* nombre de la tarea para el kernel */
    	  configMINIMAL_STACK_SIZE, /* tama�o pila asociada a la tarea */
    	  (void*)NULL, /*puntero a los par�metros iniciales de la tarea */
    	  6,/* prioridad de la tarea, cuanto m�s bajo es el n�mero menor es la prioridad */
    	  NULL /* manejo de la tarea, NULL si ni se va a crear o destruir */
      ) != pdPASS) { /* devuelve pdPASS si se ha creado la tarea */
    	  for(;;){} /* error! Probablemente sin memoria */
    	  }

    if (xTaskCreate(
      	   Acce, /* funci�n de la tarea*/
      	  "Acc", /* nombre de la tarea para el kernel */
      	  configMINIMAL_STACK_SIZE, /* tama�o pila asociada a la tarea */
      	  (void*)NULL, /*puntero a los par�metros iniciales de la tarea */
      	 1,/* prioridad de la tarea, cuanto m�s bajo es el n�mero menor es la prioridad */
      	  NULL /* manejo de la tarea, NULL si ni se va a crear o destruir */
        ) != pdPASS) { /* devuelve pdPASS si se ha creado la tarea */
      	  for(;;){} /* error! Probablemente sin memoria */
      	  }

  /* For example: for(;;) { } */
  //APP_Run();
  FRTOS1_vTaskStartScheduler();


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
