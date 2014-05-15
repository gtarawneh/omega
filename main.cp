#line 1 "D:/My Projects/Stepper Motor Controller/Micrcontroller Driver/main.c"
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/pins.h"
#line 34 "d:/my projects/stepper motor controller/micrcontroller driver/pins.h"
unsigned short PORTA_V;

unsigned short PORTE_V;


void WriteVirtualPorts()
{
 PORTA = PORTA_V;

 PORTE = PORTE_V;
}
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/vars.h"




unsigned short trace_axis = 0;

unsigned short trace_flag = 0;

unsigned long trace_skip = 100;

unsigned long trace_counter = 0;

unsigned short comm_test = 0;

unsigned short task_running = 0;

unsigned short task_done_msg = 0;

unsigned short lcd_screen = 1;

unsigned long d1;

unsigned long d2;

unsigned long d3;

unsigned long k;

unsigned long dur;

unsigned long sum;

unsigned long axis1_counter = 0;

unsigned long axis2_counter = 0;

unsigned long axis3_counter = 0;

unsigned long axis1_steps_counter = 0;

unsigned long axis2_steps_counter = 0;

unsigned long axis3_steps_counter = 0;

unsigned long axis1_steps = 0;

unsigned long axis2_steps = 0;

unsigned long axis3_steps = 0;

unsigned long axis1_period_start = 5;

unsigned long axis2_period_start = 5;

unsigned long axis3_period_start = 5;

unsigned long axis1_period_end = 5;

unsigned long axis2_period_end;

unsigned long axis3_period_end = 5;

unsigned long axis1_period_current = 0;

unsigned long axis2_period_current = 0;

unsigned long axis3_period_current = 0;

unsigned long axis1_period_warmup = 50;

unsigned long axis2_period_warmup = 50;

unsigned long axis3_period_warmup = 50;

unsigned long axis1_warmup_counter;

unsigned long axis2_warmup_counter;

unsigned long axis3_warmup_counter;

short axis1_bind_switch1 = 0;

short axis1_bind_switch2 = 0;

short axis2_bind_switch1 = 0;

short axis2_bind_switch2 = 0;

short axis3_bind_switch1 = 0;

short axis3_bind_switch2 = 0;

short switch1_closed = 0;

short switch2_closed = 0;

char b[32] absolute 0x20;

char temp[16] absolute 0x40;

char lcd1[16] absolute 0x50;

char lcd2[16] absolute 0x60;

int b_i=0;

int t;

int j;

unsigned short i;

short PR2_setting = 15;
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/strings.h"




const char lcd1_default[] = "Ready";
const char lcd2_default[] = " ";

const char banner1[] = "###########################################\n";
const char banner2[] = "#                                         #\n";
const char banner3[] = "#   Multi-Axis Stepper Motor Controller   #\n";
const char banner4[] = "#                                         #\n";
const char banner5[] = "###########################################\n";

const char msg1[] = "OK\n";
const char msg2[] = "Aborted\n";
const char msg3[] = "Undefined command\n";
const char msg4[] = "No task running\n";
const char msg5[] = "Task completed\n";

const char cmd1[] = "axis1 +\n";
const char cmd2[] = "axis1 -\n";
const char cmd3[] = "axis1 on\n";
const char cmd4[] = "axis1 off\n";
const char cmd5[] = "axis1 steps \n";
const char cmd6[] = "axis1 period \n";

const char cmd7[] = "axis2 +\n";
const char cmd8[] = "axis2 -\n";
const char cmd9[] = "axis2 on\n";
const char cmd10[] = "axis2 off\n";
const char cmd11[] = "axis2 steps \n";
const char cmd12[] = "axis2 period \n";

const char cmd13[] = "axis3 +\n";
const char cmd14[] = "axis3 -\n";
const char cmd15[] = "axis3 on\n";
const char cmd16[] = "axis3 off\n";
const char cmd17[] = "axis3 steps \n";
const char cmd18[] = "axis3 period \n";

const char cmd19[] = "go\n";

const char cmd20[] = "version\n";

const char cmd21[] = "stop\n";

const char cmd23[] = "screen 1\n";
const char cmd24[] = "screen 2\n";

const char cmd25[] = "ping\n";
const char cmd26[] = "communication test\n";

const char cmd27[] = "axis1 steps switch1\n";
const char cmd28[] = "axis1 steps switch2\n";

const char cmd29[] = "axis2 steps switch1\n";
const char cmd30[] = "axis2 steps switch2\n";

const char cmd31[] = "axis3 steps switch1\n";
const char cmd32[] = "axis3 steps switch2\n";

const char cmd33[] = "lcd1 \n";
const char cmd34[] = "lcd2 \n";

const char cmd35[] = "axis1 period start \n";
const char cmd36[] = "axis1 period end \n";
const char cmd37[] = "axis1 period warmup \n";

const char cmd38[] = "axis2 period start \n";
const char cmd39[] = "axis2 period end \n";
const char cmd40[] = "axis2 period warmup \n";

const char cmd41[] = "axis3 period start \n";
const char cmd42[] = "axis3 period end \n";
const char cmd43[] = "axis3 period warmup \n";

const char cmd44[] = "trace axis1\n";
const char cmd45[] = "trace axis2\n";
const char cmd46[] = "trace axis3\n";
const char cmd47[] = "trace off\n";
const char cmd48[] = "trace skip \n";

const char cmdxx[] = "pr2 \n";

const char newline[] = "\n";
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/functions.h"
void strcp_c(char *str1, const char *cstr2)
{


 unsigned short i = 0;

 do
 {
 str1[i] = cstr2[i];
 }
 while (str1[i++]);
}

short strcmp_c(char *str1, const char *str2)
{


 short i = 0;

 for (;(i==0) || (str2[i-1]!='\n');i++)
 {
 if (str1[i] != str2[i]) return 0;
 }

 return 1;
}

short str_starts_with(char *str1, const char *str2)
{


 short i = 0;

 for (;(i==0) || (str2[i]!='\n');i++)
 {
 if (str1[i] != str2[i]) return 0;
 }

 return 1;
}

void SendLine(char *l)
{


 int t;

 for (t=0; l[t]!= '\n'; t++) Usart_Write(l[t]);

 Usart_Write(13);

 Usart_Write(10);
}


void SendConstLine( const char *l)
{


 int t;

 for (t=0; l[t]!= '\n'; t++) Usart_Write(l[t]);

 Usart_Write(13);

 Usart_Write(10);
}


short ValidChar(char i)
{


 if (i>31 && i<127) return 1;

 return 0;
}

unsigned long max_long(unsigned long a, unsigned long b, unsigned long c)
{
 if (a>b)
 {
 if (a>c) return a; else return c;
 }
 else
 {
 if (b>c) return b; else return c;
 }
}

unsigned long Extract_Numeric_Argument(const int start)
{
 sum = 0;

 for (j=start; j<b_i; j++)
 {
 sum = sum * 10 + (b[j] - 48);
 }

 return sum;

}
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/lcd.h"
void ProgramCustomChars()
{

 Lcd8_Cmd (64);



 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00001110);
 Lcd8_Chr_Cp(0b00010101);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000000);



 Lcd8_Chr_Cp(0b00000000);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00000100);
 Lcd8_Chr_Cp(0b00010101);
 Lcd8_Chr_Cp(0b00001110);
 Lcd8_Chr_Cp(0b00000100);



 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00010001);
 Lcd8_Chr_Cp(0b00010001);
 Lcd8_Chr_Cp(0b00010001);
 Lcd8_Chr_Cp(0b00010001);
 Lcd8_Chr_Cp(0b00010001);
 Lcd8_Chr_Cp(0b00010001);
 Lcd8_Chr_Cp(0b00011111);



 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);
 Lcd8_Chr_Cp(0b00011111);

 Lcd8_Cmd(Lcd_Return_Home);
}

void Intialize_LCD()
{
 Lcd8_Init(&PORTD, &PORTB);

 Lcd8_Cmd(LCD_CURSOR_OFF);

 ProgramCustomChars();

 strcp_c(lcd1, lcd1_default);

 strcp_c(lcd2, lcd2_default);


}

void DisplayScreen1()
{
 Lcd8_Cmd(LCD_CLEAR);

 strcpy(temp, lcd1);

 Lcd8_Out(1, 1, temp);

 strcpy(temp, lcd2);

 Lcd8_Out(2, 1, temp);

 lcd_screen = 1;
}

void DisplayScreen2()
{
 Lcd8_Cmd(LCD_CLEAR);

 Lcd8_Chr(1,3,'1');

 Lcd8_Chr(1,8,'2');

 Lcd8_Chr(1,13,'3');

 LCD8_Chr(2, 2, ( PORTA_V.F1 ) ? 3 : 2);

 LCD8_Chr(2, 4, ( PORTA_V.F0 ) ? 1 : 0);

 LCD8_Chr(2, 7, ( PORTE_V.F1 ) ? 3 : 2);

 LCD8_Chr(2, 9, ( PORTE_V.F0 ) ? 1 : 0);

 LCD8_Chr(2, 12, ( PORTC.F1 ) ? 3 : 2);

 LCD8_Chr(2, 14, ( PORTC.F0 ) ? 1 : 0);

 lcd_screen = 2;
}
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/go.h"




void ProcessStop()
{
 T2CON.TMR2ON = 0;
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

 if ( PORTD.F0 ) switch1_closed = 1;

 if ( PORTD.F1 ) switch2_closed = 1;

 axis1_counter++;

 axis2_counter++;

 axis3_counter++;

 axis1_warmup_counter++;

 axis2_warmup_counter++;

 axis3_warmup_counter++;



 if (! PORTA_V.F1 ) axis1_job_over = 1;

 if (!axis1_bind_switch1 && !axis1_bind_switch2 && !axis1_steps) axis1_job_over = 1;

 if (!axis1_bind_switch1 && !axis1_bind_switch2 && axis1_steps_counter >= axis1_steps) axis1_job_over = 1;

 if (axis1_bind_switch1 && switch1_closed == 1) axis1_job_over = 1;

 if (axis1_bind_switch2 && switch2_closed == 1) axis1_job_over = 1;



 if (! PORTE_V.F1 ) axis2_job_over = 1;

 if (!axis2_bind_switch1 && !axis2_bind_switch2 && !axis2_steps) axis2_job_over = 1;

 if (!axis2_bind_switch1 && !axis2_bind_switch2 && axis2_steps_counter >= axis2_steps) axis2_job_over = 1;

 if (axis2_bind_switch1 && switch1_closed == 1) axis2_job_over = 1;

 if (axis2_bind_switch2 && switch2_closed == 1) axis2_job_over = 1;



 if (! PORTC.F1 ) axis3_job_over = 1;

 if (!axis3_bind_switch1 && !axis3_bind_switch2 && !axis3_steps) axis3_job_over = 1;

 if (!axis3_bind_switch1 && !axis3_bind_switch2 && axis3_steps_counter >= axis3_steps) axis3_job_over = 1;

 if (axis3_bind_switch1 && switch1_closed == 1) axis3_job_over = 1;

 if (axis3_bind_switch2 && switch2_closed == 1) axis3_job_over = 1;



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



 if (axis1_counter>=axis1_period_current)
 {
 axis1_counter = 0;

 axis1_steps_counter++;

 if (!axis1_job_over || (!axis1_steps &&  PORTA_V.F1 ))
 {
  PORTA_V.F2  = ~  PORTA_V.F2 ; WriteVirtualPorts();
  PORTA_V.F2  = ~  PORTA_V.F2 ; WriteVirtualPorts();

 if (trace_axis == 1) Trace();
 }
 }

 if (axis2_counter>=axis2_period_current)
 {
 axis2_counter = 0;

 axis2_steps_counter++;

 if (!axis2_job_over || (!axis2_steps &&  PORTE_V.F1 ))
 {
  PORTE_V.F2  = ~ PORTE_V.F2 ; WriteVirtualPorts();
  PORTE_V.F2  = ~ PORTE_V.F2 ; WriteVirtualPorts();

 if (trace_axis == 2) Trace();
 }
 }

 if (axis3_counter>=axis3_period_current)
 {
 axis3_counter = 0;

 axis3_steps_counter++;

 if (!axis3_job_over || (!axis3_steps &&  PORTC.F1 ))
 {
  PORTC.F2  = ~ PORTC.F2 ; WriteVirtualPorts();
  PORTC.F2  = ~ PORTC.F2 ; WriteVirtualPorts();

 if (trace_axis == 3) Trace();
 }
 }



 if (axis1_job_over && axis2_job_over && axis3_job_over)
 {
 ProcessStop();

 task_done_msg = 1;

 task_running = 0;
 }

 PIR1.TMR2IF = 0;
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

 INTCON.PEIE =1;

 INTCON.GIE = 1;

 PIE1.TMR2IE = 1;

 T2CON = 0b01001001;



 PR2 = PR2_setting;

 trace_flag = 0;

 trace_counter = 0;

 task_running = 1;

 T2CON.TMR2ON = 1;

}
#line 1 "d:/my projects/stepper motor controller/micrcontroller driver/commands.h"








short ProcessACC()
{




 if ( strcmp_c(b,cmd3) )
 {

  PORTA_V.F1  = 1;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd4) )
 {
  PORTA_V.F1  = 0;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd1) )
 {
  PORTA_V.F0  = 0;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd2) )
 {
  PORTA_V.F0  = 1;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd27) )
 {
 axis1_steps = 1;

 axis1_bind_switch1 = 1;

 axis1_bind_switch2 = 0;

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd28) )
 {
 axis1_steps = 1;

 axis1_bind_switch1 = 0;

 axis1_bind_switch2 = 1;

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd5) )
 {
 axis1_steps = Extract_Numeric_Argument(12);

 axis1_bind_switch1 = 0;

 axis1_bind_switch2 = 0;

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd35) )
 {

 axis1_period_current = axis1_period_start = Extract_Numeric_Argument(19);

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd36) )
 {

 axis1_period_end = Extract_Numeric_Argument(17);

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd37) )
 {

 axis1_period_warmup = Extract_Numeric_Argument(20);

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd6) )
 {

 axis1_period_end = axis1_period_start = Extract_Numeric_Argument(13);

 SendConstLine(msg1);

 return 1;

 }



 if ( strcmp_c(b,cmd9) )
 {

  PORTE_V.F1  = 1;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd10) )
 {
  PORTE_V.F1  =0;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd7) )
 {
  PORTE_V.F0  = 0;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd8) )
 {
  PORTE_V.F0  = 1;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd29) )
 {
 axis2_steps = 1;

 axis2_bind_switch1 = 1;

 axis2_bind_switch2 = 0;

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd30) )
 {
 axis2_steps = 1;

 axis2_bind_switch1 = 0;

 axis2_bind_switch2 = 1;

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd11) )
 {
 axis2_steps = Extract_Numeric_Argument(12);

 axis2_bind_switch1 = 0;

 axis2_bind_switch2 = 0;

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd38) )
 {

 axis2_period_start = Extract_Numeric_Argument(19);

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd39) )
 {
 axis2_period_end = Extract_Numeric_Argument(17);

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd40) )
 {
 axis2_period_warmup = Extract_Numeric_Argument(20);

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd12) )
 {
 axis2_period_current = axis2_period_end = axis2_period_start = Extract_Numeric_Argument(13);

 SendConstLine(msg1);

 return 1;

 }



 if ( strcmp_c(b,cmd15) )
 {

  PORTC.F1  = 1;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd16) )
 {
  PORTC.F1  = 0;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd13) )
 {
  PORTC.F0  = 0;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd14) )
 {
  PORTC.F0  = 1;

 WriteVirtualPorts();

 if (lcd_screen == 2) DisplayScreen2();

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd31) )
 {
 axis3_steps = 1;

 axis3_bind_switch1 = 1;

 axis3_bind_switch2 = 0;

 SendConstLine(msg1);

 return 1;
 }

 if ( strcmp_c(b,cmd32) )
 {
 axis3_steps = 1;

 axis3_bind_switch1 = 0;

 axis3_bind_switch2 = 1;

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd17) )
 {
 axis3_steps = Extract_Numeric_Argument(12);

 axis3_bind_switch1 = 0;

 axis3_bind_switch2 = 0;

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd41) )
 {
 axis3_period_current = axis3_period_start = axis3_period_end = Extract_Numeric_Argument(19);

 SendConstLine(msg1);

 return 1;
 }

 if ( str_starts_with(b,cmd42) )
 {

 axis3_period_end= Extract_Numeric_Argument(17);

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd43) )
 {

 axis3_period_warmup = Extract_Numeric_Argument(20);

 SendConstLine(msg1);

 return 1;

 }

 if ( str_starts_with(b,cmd18) )
 {
 axis3_period_end = axis3_period_start = Extract_Numeric_Argument(13);

 SendConstLine(msg1);

 return 1;
 }

 return 0;
}

void ProcessCommand()
{


 if (ProcessACC()) return;



 if ( strcmp_c(b,cmd20) )
 {
 SendConstLine( "2.0\n" );

 return;
 }

 if ( strcmp_c(b,cmd19) )
 {
 ProcessGo();

 SendConstLine(msg1);

 return;
 }

 if ( strcmp_c(b,cmd21) )
 {
 ProcessStop();

 SendConstLine(msg1);

 return;
 }

 if ( strcmp_c(b,cmd23) )
 {
 DisplayScreen1();

 SendConstLine(msg1);

 return;
 }

 if ( strcmp_c(b,cmd24) )
 {
 DisplayScreen2();

 SendConstLine(msg1);

 return;
 }

 if ( strcmp_c(b,cmd25) )
 {
 SendConstLine(msg1);

 return;
 }

 if ( strcmp_c(b,cmd26) )
 {
 if (comm_test > 1)
 {
 comm_test = 0;

 SendConstLine(msg3);
 }
 else
 {
 comm_test++;

 SendConstLine(msg1);
 }

 return;
 }

 if ( str_starts_with(b,cmd33) )
 {
 for (t=5; b[t] != '\n' && (t-5)<16; t++)
 {
 lcd1[t-5] = b[t];
 }

 lcd1[t-5] = 0;

 if (lcd_screen == 1) DisplayScreen1();

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmd34) )
 {
 for (t=5; b[t] != '\n' && (t-5)<16; t++)
 {
 lcd2[t-5] = b[t];
 }

 lcd2[t-5] = 0;

 if (lcd_screen == 1) DisplayScreen1();

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmd44) )
 {
 trace_axis = 1;

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmd45) )
 {
 trace_axis = 2;

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmd46) )
 {
 trace_axis = 3;

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmd47) )
 {
 trace_axis = 0;

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmd48) )
 {
 trace_skip = Extract_Numeric_Argument(11);

 SendConstLine(msg1);

 return;
 }

 if ( str_starts_with(b,cmdxx) )
 {
 PR2_setting = Extract_Numeric_Argument(4);

 SendConstLine(msg1);

 return;
 }

 SendConstLine(msg3);
}
#line 25 "D:/My Projects/Stepper Motor Controller/Micrcontroller Driver/main.c"
void IntializeController();

void Prompt();

void main()
{

 delay_ms(250);

 IntializeController();

 while (1)
 {
 if (Usart_Data_Ready())
 {
 i = Usart_Read();

 Usart_Write(i);

 if (ValidChar(i))
 {
 b[b_i] = i;

 if (b_i<31) b_i++;
 }

 if (i==13)
 {
 b[b_i] = '\n';

 Usart_Write(10);

 ProcessCommand();

 b_i=0;

 Prompt();
 }

  PORTC.F5  = ~ PORTC.F5 ;
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
 Usart_Write( '@' );

 trace_flag = 0;
 }
 }
}

void IntializeController()
{
 TRISB = 0;

 TRISD = 3;

 TRISA = 0;

 TRISE = 0;

 TRISC = 0;

  PORTA_V.F1  = 0;

  PORTE_V.F1  = 0;

  PORTC.F1  = 0;

  PORTA_V.F0  = 0;

  PORTE_V.F0  = 0;

  PORTC.F0  = 0;

  PORTA_V.F2  = 1;

  PORTE_V.F2  = 1;

  PORTC.F2  = 1;

 WriteVirtualPorts();

 delay_ms(50);

 Intialize_LCD();

 DisplayScreen1();

 Usart_Init( 250000 );

  PORTC.F5  = 0;



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
