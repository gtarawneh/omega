// Variable Declarations:
//
// -----------------------------------------------------

unsigned short trace_axis = 0;           // Axis Tracing Configuration

unsigned short trace_flag = 0;           // Axis Tracing Flag

unsigned long trace_skip = 100;          // Trace Skip

unsigned long trace_counter = 0;         // Trace Skip Counter

unsigned short comm_test = 0;            // Communication Test

unsigned short task_running = 0;         // Task Running Flag

unsigned short task_done_msg = 0;        // Task Over Message Flag

unsigned short lcd_screen = 1;           // LCD Screen Mode (either 1 or 2)

unsigned long d1;                        // Duration of stepping for Axis 1 in time units

unsigned long d2;                        // Duration of stepping for Axis 2 in time units

unsigned long d3;                        // Duration of stepping for Axis 3 in time units

unsigned long k;                         // Go command loop counter

unsigned long dur;                       // Duration of stepping in time units for the Go command loop

unsigned long sum;                       // Used in extracting numerical arguments for commands

unsigned long axis1_counter = 0;         // Loop Counter for Axis 1

unsigned long axis2_counter = 0;         // Loop Counter for Axis 2

unsigned long axis3_counter = 0;         // Loop Counter for Axis 3

unsigned long axis1_steps_counter = 0;   // Steps Counter for Axis 1

unsigned long axis2_steps_counter = 0;   // Steps Counter for Axis 2

unsigned long axis3_steps_counter = 0;   // Steps Counter for Axis 3

unsigned long axis1_steps = 0;           // Number of Steps for Axis 1 (Maximum of 4294967296)

unsigned long axis2_steps = 0;           // Number of Steps for Axis 2 (Maximum of 4294967296)

unsigned long axis3_steps = 0;           // Number of Steps for Axis 3 (Maximum of 4294967296)

unsigned long axis1_period_start = 5;    // Starting period of Axis 1

unsigned long axis2_period_start = 5;    // Starting period of Axis 2

unsigned long axis3_period_start = 5;    // Starting period of Axis 3

unsigned long axis1_period_end = 5;      // Ending period of Axis 1

unsigned long axis2_period_end;          // Ending period of Axis 2

unsigned long axis3_period_end = 5;      // Ending period of Axis 3

unsigned long axis1_period_current = 0;  // Instantaneous period of Axis 1

unsigned long axis2_period_current = 0;  // Instantaneous period of Axis 2

unsigned long axis3_period_current = 0;  // Instantaneous period of Axis 3

unsigned long axis1_period_warmup = 50;  // Number of steps to move before period change for Axis 1

unsigned long axis2_period_warmup = 50;  // Number of steps to move before period change for Axis 2

unsigned long axis3_period_warmup = 50;  // Number of steps to move before period change for Axis 3

unsigned long axis1_warmup_counter;      // Time duration seperating period changes for Axis 1

unsigned long axis2_warmup_counter;      // Time duration seperating period changes for Axis 2

unsigned long axis3_warmup_counter;      // Time duration seperating period changes for Axis 3

short axis1_bind_switch1 = 0;            // Defines whether or not motion of Axis 1 is halted by closing switch1

short axis1_bind_switch2 = 0;            // Defines whether or not motion of Axis 1 is halted by closing switch2

short axis2_bind_switch1 = 0;            // Defines whether or not motion of Axis 2 is halted by closing switch1

short axis2_bind_switch2 = 0;            // Defines whether or not motion of Axis 2 is halted by closing switch2

short axis3_bind_switch1 = 0;            // Defines whether or not motion of Axis 3 is halted by closing switch1

short axis3_bind_switch2 = 0;            // Defines whether or not motion of Axis 3 is halted by closing switch2

short switch1_closed = 0;                // Indicates whether or not switch1 was closed during the current motion job

short switch2_closed = 0;                // Indicates whether or not switch2 was closed during the current motion job

char b[32] absolute 0x20;                // Command Buffer

char temp[16] absolute 0x40;             // Temporary Buffer

char lcd1[16] absolute 0x50;             // LCD Screen 1 first line

char lcd2[16] absolute 0x60;             // LCD Screen 1 second line

int b_i=0;                               // Command Buffer Index

int t;                                   // General Purpose

int j;                                   // General Purpose

unsigned short i;                        // Received USART Character

short PR2_setting = 15;                 // Timer2 Counter Scaler