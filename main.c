// Multi-Axis Stepper Motor Controller Firmware
//
// -----------------------------------------------------

#define FIRMWARE_VERSION "2.0\n"

#define BAUD_RATE 250000

#define TRACE_CHAR '@'

#include "Pins.h"

#include "Vars.h"

#include "Strings.h"

#include "Functions.h"

#include "LCD.h"

#include "Go.h"

#include "Commands.h"

void IntializeController();

void Prompt();

void main()
{

     delay_ms(250); // 250ms delay before startup ...

    IntializeController();

	   while (1)
	   {
		       if (Usart_Data_Ready())
		       {
                  i = Usart_Read();

                  Usart_Write(i);              // Echo character back to sender

                  if (ValidChar(i))            // If received character is valid, append to array
                  {
                     b[b_i] = i;

                     if (b_i<31) b_i++;
                  }

                  if (i==13)                   // Check if Enter is received
                  {
                     b[b_i] = '\n';            // Append "New Line" character to command buffer

                     Usart_Write(10);          // Send "Carriage Return" character

                     ProcessCommand();         // Process received command

                     b_i=0;                    // Reset buffer index

                     Prompt();
                  }

                  CTS = ~CTS; // Toggle CTS
		      }
		      
          if (task_done_msg)
          {
             SendConstLine(newline);

             SendConstLine(msg5);
             
             Prompt();

             task_done_msg = 0;
          }
          
          if (trace_flag)
          {
             Usart_Write(TRACE_CHAR);
             
             trace_flag = 0;
          }
	    }
}

void IntializeController()
{
     TRISB = 0;                            // LCD Data Port

	   TRISD = 3;                            // LCD Control Port + Switch Bits

	   TRISA = 0;                            // Output Port (Axis 1)

	   TRISE = 0;                            // Output Port (Axis 2)

	   TRISC = 0;                            // Output Port (Axis 3) + Serial Communication Bits

     AXIS1_ENABLE_BIT = 0; // Disable axis 1

     AXIS2_ENABLE_BIT = 0; // Disable axis 2

     AXIS3_ENABLE_BIT = 0; // Disable axis 3

     AXIS1_DIRECTION_BIT = 0; // Set direction of axis 1 to forward

     AXIS2_DIRECTION_BIT = 0; // Set direction of axis 2 to forward

     AXIS3_DIRECTION_BIT = 0; // Set direction of axis 3 to forward

     AXIS1_STEP_BIT = 1; // Initialize axis 1 step output to 1

     AXIS2_STEP_BIT = 1; // Initialize axis 2 step output to 1

     AXIS3_STEP_BIT = 1; // Initialize axis 3 step output to 1
     
     WriteVirtualPorts();

  	 delay_ms(50);

     Intialize_LCD();
     
     DisplayScreen1();
     
	   Usart_Init(BAUD_RATE);

     CTS = 0;
     
     // Display device welcome banner:
     
     SendConstLine(newline);
     
     SendConstLine(newline);
     
     SendConstLine(Banner1);
     
     SendConstLine(Banner2);
     
     SendConstLine(Banner3);
     
     SendConstLine(Banner4);
     
     SendConstLine(Banner5);
     
     SendConstLine(newline);
     
     Prompt();
}

void Prompt()
{
     Usart_Write('>');

     Usart_Write('>');
}
