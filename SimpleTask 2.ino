#include "FreeRTOS_ARM.h"
#include "basic_io_arm.h"
#define mainDELAY_LOOP_COUNT   ( 0xfffff )
static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";
void setup( void )
{  Serial.begin(9600);
  xTaskCreate(  vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 1, NULL );
  xTaskCreate( vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 1, NULL );
  vTaskStartScheduler();
  for( ;; );}
void vTaskFunction( void *pvParameters )
{char *pcTaskName;
volatile uint32_t ul; 
 pcTaskName = ( char * ) pvParameters;
 for( ;; )
 { vPrintString( pcTaskName );
 for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
 { } }}
void loop() {}
