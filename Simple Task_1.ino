#include "FreeRTOS_ARM.h"
/* Demo includes. */
#include "basic_io_arm.h"

/* Used as a loop counter to create a very crude delay. */
#define mainDELAY_LOOP_COUNT   ( 0xfffff )

/* The task functions. */
void vTask1( void *pvParameters );
void vTask2( void *pvParameters );

//-----------------------------------------------------------/

void setup( void )
{
  Serial.begin(9600);
  /* Create one of the two tasks. */
  xTaskCreate(  vTask1,   /* Pointer to the function that implements the task. */
    "Task 1", /* Text name for the task.  This is to facilitate debugging only. */
    200,    /* Stack depth - most small microcontrollers will use much less stack than this. */
    NULL,   /* We are not using the task parameter. */
    1,      /* This task will run at priority 1. */
    NULL );   /* We are not using the task handle. */

  /* Create the other task in exactly the same way. */
  xTaskCreate( vTask2, "Task 2", 200, NULL, 1, NULL );

  /* Start the scheduler so our tasks start executing. */
  vTaskStartScheduler();

  /* If all is well we will never reach here as the scheduler will now be
  running.  If we do reach here then it is likely that there was insufficient
  heap available for the idle task to be created. */
  for( ;; );
//  return 0;
}
//-----------------------------------------------------------/

void vTask1( void *pvParameters )
{
const char *pcTaskName = "Task 1 is running\r\n";
volatile unsigned long ul;

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName );

    /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
      /* This loop is just a very crude delay implementation.  There is
      nothing to do in here.  Later exercises will replace this crude
      loop with a proper delay/sleep function. */
    }
  }
}
//-----------------------------------------------------------/

void vTask2( void *pvParameters )
{
const char *pcTaskName = "Task 2 is running\r\n";
volatile unsigned long ul;

  /* As per most tasks, this task is implemented in an infinite loop. */
  for( ;; )
  {
    /* Print out the name of this task. */
    vPrintString( pcTaskName );

    /* Delay for a period. */
    for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
    {
      /* This loop is just a very crude delay implementation.  There is
      nothing to do in here.  Later exercises will replace this crude
      loop with a proper delay/sleep function. */
    }
  }
}
void loop() {}
