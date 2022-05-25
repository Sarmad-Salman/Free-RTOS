#include "FreeRTOS_ARM.h"
#include "basic_io_arm.h"

TaskHandle_t xTask2Handle = NULL;

void setup( void )
{
  Serial.begin(9600);
  
  xTaskCreate( vTask1, "Task 1", 1000, NULL, 2, NULL );
  xTaskCreate( vTask2, "Task 2", 1000, NULL, 1, &xTask2Handle );
  vTaskStartScheduler();
}

void vTask1( void *pvParameters )
{
  UBaseType_t uxPriority;
  uxPriority = uxTaskPriorityGet( NULL );
  for( ;; )
  {
    vPrintString( "Task 1 is running\r\n" );
    vPrintString( "About to raise the Task 2 priority\r\n" );
    vTaskPrioritySet( xTask2Handle, ( uxPriority + 1 ) );
  }
}

void vTask2( void *pvParameters )
{
  UBaseType_t uxPriority;
  uxPriority = uxTaskPriorityGet( NULL );
  for( ;; )
  {
    vPrintString( "Task 2 is running\r\n" );
    vPrintString( "About to lower the Task 2 priority\r\n" );
    vTaskPrioritySet( NULL, ( uxPriority - 2 ) );
  }
}

void loop() 
{
}
