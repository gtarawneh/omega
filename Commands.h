// Process Command Function:
//
// -----------------------------------------------------

#define IsCommand(A) strcmp_c(b,A)            // Define IsCommand macro

#define CommandStarts(A) str_starts_with(b,A) // Define CommandStarts

short ProcessACC()
{
     // Axis Configuration Commands
     
     // Axis 1 Commands:

     if (IsCommand(cmd3)) // Check if input is "axis1 on"
     {

        AXIS1_ENABLE_BIT = 1;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd4)) // Check if input is "axis1 off"
     {
        AXIS1_ENABLE_BIT = 0;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd1)) // Check if input is "axis1 +"
     {
        AXIS1_DIRECTION_BIT = 0;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd2)) // Check if input is "axis1 -"
     {
        AXIS1_DIRECTION_BIT = 1;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd27)) // Check if input is "axis1 steps switch1"
     {
        axis1_steps = 1;

        axis1_bind_switch1 = 1;

        axis1_bind_switch2 = 0;

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd28)) // Check if input is "axis1 steps switch2"
     {
        axis1_steps = 1;

        axis1_bind_switch1 = 0;

        axis1_bind_switch2 = 1;

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (CommandStarts(cmd5)) // Check if input is "axis1 steps x", where x is a number
     {
         axis1_steps = Extract_Numeric_Argument(12);

         axis1_bind_switch1 = 0;

         axis1_bind_switch2 = 0;

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd35)) // Check if input is "axis1 period start x", where x is a number
     {

         axis1_period_current = axis1_period_start = Extract_Numeric_Argument(19);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd36)) // Check if input is "axis1 period end x", where x is a number
     {

         axis1_period_end = Extract_Numeric_Argument(17);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd37)) // Check if input is "axis1 period warmup x", where x is a number
     {

         axis1_period_warmup = Extract_Numeric_Argument(20);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd6)) // Check if input is "axis1 period x", where x is a number
     {

         axis1_period_end = axis1_period_start = Extract_Numeric_Argument(13);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     // Axis 2 Commands:

     if (IsCommand(cmd9)) // Check if input is "axis2 on"
     {

        AXIS2_ENABLE_BIT = 1;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd10)) // Check if input is "axis2 off"
     {
        AXIS2_ENABLE_BIT =0;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd7)) // Check if input is "axis2 +"
     {
        AXIS2_DIRECTION_BIT = 0;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd8)) // Check if input is "axis2 -"
     {
        AXIS2_DIRECTION_BIT = 1;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd29)) // Check if input is "axis2 steps switch1"
     {
        axis2_steps = 1;

        axis2_bind_switch1 = 1;

        axis2_bind_switch2 = 0;

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd30)) // Check if input is "axis2 steps switch2"
     {
        axis2_steps = 1;

        axis2_bind_switch1 = 0;

        axis2_bind_switch2 = 1;

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (CommandStarts(cmd11)) // Check if input is "axis2 steps x", where x is a number
     {
         axis2_steps = Extract_Numeric_Argument(12);

         axis2_bind_switch1 = 0;

         axis2_bind_switch2 = 0;

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd38)) // Check if input is "axis2 period start x", where x is a number
     {

         axis2_period_start = Extract_Numeric_Argument(19);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd39)) // Check if input is "axis2 period end x", where x is a number
     {
         axis2_period_end = Extract_Numeric_Argument(17);

         SendConstLine(msg1); // Send "OK"

         return 1;
      }

     if (CommandStarts(cmd40)) // Check if input is "axis2 period warmup x", where x is a number
     {
         axis2_period_warmup = Extract_Numeric_Argument(20);

         SendConstLine(msg1); // Send "OK"

         return 1;
      }

     if (CommandStarts(cmd12)) // Check if input is "axis2 period x", where x is a number
     {
         axis2_period_current = axis2_period_end = axis2_period_start = Extract_Numeric_Argument(13);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

      // Axis 3 Commands:

     if (IsCommand(cmd15)) // Check if input is "axis3 on"
     {

        AXIS3_ENABLE_BIT = 1;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd16)) // Check if input is "axis3 off"
     {
        AXIS3_ENABLE_BIT = 0;

        WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd13)) // Check if input is "axis3 +"
     {
         AXIS3_DIRECTION_BIT = 0;

         WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd14)) // Check if input is "axis3 -"
     {
         AXIS3_DIRECTION_BIT = 1;

         WriteVirtualPorts();

        if (lcd_screen == 2) DisplayScreen2(); // Update if screen 2 is displayed

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd31)) // Check if input is "axis3 steps switch1"
     {
        axis3_steps = 1;

        axis3_bind_switch1 = 1;

        axis3_bind_switch2 = 0;

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (IsCommand(cmd32)) // Check if input is "axis3 steps switch2"
     {
        axis3_steps = 1;

        axis3_bind_switch1 = 0;

        axis3_bind_switch2 = 1;

        SendConstLine(msg1); // Send "OK"

        return 1;
     }

     if (CommandStarts(cmd17)) // Check if input is "axis3 steps x", where x is a number
     {
         axis3_steps = Extract_Numeric_Argument(12);

         axis3_bind_switch1 = 0;

         axis3_bind_switch2 = 0;

         SendConstLine(msg1); // Send "OK"

         return 1;
      }

     if (CommandStarts(cmd41)) // Check if input is "axis3 period start x", where x is a number
     {
         axis3_period_current = axis3_period_start = axis3_period_end = Extract_Numeric_Argument(19);

         SendConstLine(msg1); // Send "OK"

         return 1;
      }

     if (CommandStarts(cmd42)) // Check if input is "axis3 period end x", where x is a number
     {

         axis3_period_end= Extract_Numeric_Argument(17);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd43)) // Check if input is "axis3 period warmup x", where x is a number
     {

         axis3_period_warmup = Extract_Numeric_Argument(20);

         SendConstLine(msg1); // Send "OK"

         return 1;

      }

     if (CommandStarts(cmd18)) // Check if input is "axis3 period x", where x is a number
     {
         axis3_period_end = axis3_period_start = Extract_Numeric_Argument(13);

         SendConstLine(msg1); // Send "OK"

         return 1;
     }
     
     return 0;
}
     
void ProcessCommand()
{
     // Axis Configuration Commands
     
     if (ProcessACC()) return;

     // General Commands

     if (IsCommand(cmd20))
     {
        SendConstLine(FIRMWARE_VERSION);
        
        return;
     }

      if (IsCommand(cmd19)) // Check if input is "go"
      {
         ProcessGo();

         SendConstLine(msg1); // Send "OK"
         
         return;
      }
      
      if (IsCommand(cmd21)) // Check if input is "stop"
      {
          ProcessStop();
     
          SendConstLine(msg1); //Send "OK"
          
          return;
      }
      
      if (IsCommand(cmd23)) // Check if input is "screen 1"
      {
         DisplayScreen1();
         
         SendConstLine(msg1); //Send "OK"
         
         return;
      }

      if (IsCommand(cmd24)) // Check if input is "screen 2"
      {
         DisplayScreen2();
         
         SendConstLine(msg1); //Send "OK"
         
         return;
      }
      
      if (IsCommand(cmd25)) // Check if input is "ping"
      {
         SendConstLine(msg1); // Send "OK"
      
         return;
      }
      
      if (IsCommand(cmd26)) // Check if input is "communication test"
      {
          if (comm_test > 1)
          {
                comm_test = 0;
                
                SendConstLine(msg3); // Send "Undefined Command"
          }
          else
          {
               comm_test++;

               SendConstLine(msg1); //Send "OK"
          }
          
          return;
      }
      
     if (CommandStarts(cmd33)) // Check if input is "lcd1 x", where x is a string
     {
         for (t=5; b[t] != '\n' && (t-5)<16; t++)
         {
             lcd1[t-5] = b[t];
         }
         
         lcd1[t-5] = 0;

         if (lcd_screen == 1) DisplayScreen1();

         SendConstLine(msg1); // Send "OK"

         return;
      }

     if (CommandStarts(cmd34)) // Check if input is "lcd2 x", where x is a string
     {
         for (t=5; b[t] != '\n' && (t-5)<16; t++)
         {
             lcd2[t-5] = b[t];
         }
         
         lcd2[t-5] = 0;

         if (lcd_screen == 1) DisplayScreen1();

         SendConstLine(msg1); // Send "OK"

         return;
      }
      
      if (CommandStarts(cmd44)) // Check if input is "trace axis1"
      {
         trace_axis = 1;

         SendConstLine(msg1); // Send "OK"
         
         return;
      }

      if (CommandStarts(cmd45)) // Check if input is "trace axis2"
      {
         trace_axis = 2;

         SendConstLine(msg1); // Send "OK"

         return;
      }
      
      if (CommandStarts(cmd46)) // Check if input is "trace axis3"
      {
         trace_axis = 3;

         SendConstLine(msg1); // Send "OK"

         return;
      }
      
      if (CommandStarts(cmd47)) // Check if input is "trace off"
      {
         trace_axis = 0;

         SendConstLine(msg1); // Send "OK"

         return;
      }
      
      if (CommandStarts(cmd48)) // Check if input is "trace skip x", where x is a number
      {
         trace_skip = Extract_Numeric_Argument(11);
         
         SendConstLine(msg1); // Send "OK"

         return;
      }
      
      if (CommandStarts(cmdxx)) // Check if input is "pr2 x", where x is a number
      {
         PR2_setting = Extract_Numeric_Argument(4);

         SendConstLine(msg1); // Send "OK"

         return;
       }

      SendConstLine(msg3); // Send "Undefined Command"
}