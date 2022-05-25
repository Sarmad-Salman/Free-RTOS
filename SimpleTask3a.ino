#include "FreeRTOS_ARM.h"
#include "basic_io_arm.h"

volatile uint32_t ulIdleCycleCount = 0UL;

static const char *pcTextForTask1 = "Task 1 is running\r\n";
static const char *pcTextForTask2 = "Task 2 is running\r\n";

void setup( void )
{
  Serial.begin(9600);
  
  xTaskCreate( vTaskFunction, "Task 2", 1000, (void*)pcTextForTask2, 2, NULL );
  xTaskCreate( vTaskFunction, "Task 1", 1000, (void*)pcTextForTask1, 2, NULL );
  vTaskStartScheduler();
}

extern "C"
{
  void vApplicationIdleHook( void )
  {
    ulIdleCycleCount++;
  }
}

void vTaskFunction( void *pvParameters )
{
  char *pcTaskName;
  const TickType_t xDelay250ms = pdMS_TO_TICKS( 250 );
  pcTaskName = ( char * ) pvParameters;
  for( ;; )
  {
    vPrintStringAndNumber( pcTaskName, ulIdleCycleCount );
    vTaskDelay( xDelay250ms );
  }
}

void loop() 
{
}
