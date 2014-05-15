//  Go Command:
//
// -----------------------------------------------------

void ProcessStop()
{
      T2CON.TMR2ON = 0; // Disable Timer2
}

void Trace()
{
   trace_counter++;

   if (trace_counter >= trace_skip)
   {
        trace_flag = 1;

        trace_counter = 0;
   }
}

void interrupt()
{
    short axis1_job_over = 0;
    
    short axis2_job_over = 0;
    
    short axis3_job_over = 0;
    
    if (SWITCH1) switch1_closed = 1;
    
    if (SWITCH2) switch2_closed = 1;

    axis1_counter++;

    axis2_counter++;

    axis3_counter++;
    
    axis1_warmup_counter++;

    axis2_warmup_counter++;

    axis3_warmup_counter++;
    
    // Axis 1 Job Termination:

    if (!AXIS1_ENABLE_BIT) axis1_job_over = 1;

    if (!axis1_bind_switch1 && !axis1_bind_switch2 && !axis1_steps) axis1_job_over = 1;

    if (!axis1_bind_switch1 && !axis1_bind_switch2 && axis1_steps_counter >= axis1_steps) axis1_job_over = 1;
    
    if (axis1_bind_switch1 && switch1_closed == 1) axis1_job_over = 1;
    
    if (axis1_bind_switch2 && switch2_closed == 1) axis1_job_over = 1;
    
    // Axis 2 Job Termination:

    if (!AXIS2_ENABLE_BIT) axis2_job_over = 1;

    if (!axis2_bind_switch1 && !axis2_bind_switch2 && !axis2_steps) axis2_job_over = 1;

    if (!axis2_bind_switch1 && !axis2_bind_switch2 && axis2_steps_counter >= axis2_steps) axis2_job_over = 1;

    if (axis2_bind_switch1 && switch1_closed == 1) axis2_job_over = 1;

    if (axis2_bind_switch2 && switch2_closed == 1) axis2_job_over = 1;
    
    // Axis 3 Job Termination:

    if (!AXIS3_ENABLE_BIT) axis3_job_over = 1;

    if (!axis3_bind_switch1 && !axis3_bind_switch2 && !axis3_steps) axis3_job_over = 1;

    if (!axis3_bind_switch1 && !axis3_bind_switch2 && axis3_steps_counter >= axis3_steps) axis3_job_over = 1;

    if (axis3_bind_switch1 && switch1_closed == 1) axis3_job_over = 1;

    if (axis3_bind_switch2 && switch2_closed == 1) axis3_job_over = 1;
    
    // Period Warmup:
    
    if (axis1_warmup_counter >= axis1_period_warmup)
    {
         if (axis1_period_current<axis1_period_end) axis1_period_current++;
         
         if (axis1_period_current>axis1_period_end) axis1_period_current--;

         axis1_warmup_counter = 0;
    }
    
    if (axis2_warmup_counter >= axis2_period_warmup)
    {
         if (axis2_period_current<axis2_period_end) axis2_period_current++;

         if (axis2_period_current>axis2_period_end) axis2_period_current--;

         axis2_warmup_counter = 0;
    }
    
    if (axis3_warmup_counter >= axis3_period_warmup)
    {
         if (axis3_period_current<axis3_period_end) axis3_period_current++;

         if (axis3_period_current>axis3_period_end) axis3_period_current--;

         axis3_warmup_counter = 0;
    }
    
    // Stepping Pulse Generation:

    if (axis1_counter>=axis1_period_current)
    {
          axis1_counter = 0;

          axis1_steps_counter++;
          
          if (!axis1_job_over || (!axis1_steps && AXIS1_ENABLE_BIT))
          {
                 AXIS1_STEP_BIT = ~ AXIS1_STEP_BIT; WriteVirtualPorts();
                 AXIS1_STEP_BIT = ~ AXIS1_STEP_BIT; WriteVirtualPorts();

                 if (trace_axis == 1) Trace();
          }
    }
    
    if (axis2_counter>=axis2_period_current)
    {
          axis2_counter = 0;

          axis2_steps_counter++;
          
          if (!axis2_job_over || (!axis2_steps && AXIS2_ENABLE_BIT))
          {
                 AXIS2_STEP_BIT = ~AXIS2_STEP_BIT; WriteVirtualPorts();
                 AXIS2_STEP_BIT = ~AXIS2_STEP_BIT; WriteVirtualPorts();

                 if (trace_axis == 2) Trace();
          }
    }
    
    if (axis3_counter>=axis3_period_current)
    {
          axis3_counter = 0;

          axis3_steps_counter++;

          if (!axis3_job_over || (!axis3_steps && AXIS3_ENABLE_BIT))
          {
                 AXIS3_STEP_BIT = ~AXIS3_STEP_BIT; WriteVirtualPorts();
                 AXIS3_STEP_BIT = ~AXIS3_STEP_BIT; WriteVirtualPorts();
                 
                 if (trace_axis == 3) Trace();
          }
    }
    
    // Task Completion:

    if (axis1_job_over && axis2_job_over && axis3_job_over)
    {
         ProcessStop();

         task_done_msg = 1; // Signal main thread to output "Task Completed" message

         task_running = 0;
    }

    PIR1.TMR2IF = 0; // Clear Timer2 Interrupt Flag
}

void ProcessGo()
{
     axis1_counter = 0;

     axis2_counter = 0;

     axis3_counter = 0;

     axis1_steps_counter = 0;

     axis2_steps_counter = 0;

     axis3_steps_counter = 0;
     
     axis1_warmup_counter = 0;
     
     axis2_warmup_counter = 0;
     
     axis3_warmup_counter = 0;
     
     switch1_closed = 0;
     
     switch2_closed = 0;
     
     axis1_period_current = axis1_period_start;
     
     axis2_period_current = axis2_period_start;
     
     axis3_period_current = axis3_period_start;

     INTCON.PEIE =1; // Enable Peripheral Interrupts
     
     INTCON.GIE = 1; // Enable General Interrupts
     
     PIE1.TMR2IE = 1; // Enable Timer2 Interrupt
     
     T2CON = 0b01001001; // Timer2 Configuration Word
     
     // Timer 2 Settings: Prescaling = 4, Postscaling =  10; PR2 = 125
     
     PR2 = PR2_setting;
     
     trace_flag = 0;
     
     trace_counter = 0;
     
     task_running = 1;

     T2CON.TMR2ON = 1; // Enable Timer2
     
}

