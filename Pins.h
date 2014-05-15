// Pin Definitions:
//
// -----------------------------------------------------



#define AXIS1_DIRECTION_BIT PORTA_V.F0

#define AXIS1_STEP_BIT PORTA_V.F2

#define AXIS1_ENABLE_BIT PORTA_V.F1


#define AXIS2_DIRECTION_BIT PORTE_V.F0

#define AXIS2_STEP_BIT PORTE_V.F2

#define AXIS2_ENABLE_BIT PORTE_V.F1


#define AXIS3_DIRECTION_BIT PORTC.F0

#define AXIS3_STEP_BIT PORTC.F2

#define AXIS3_ENABLE_BIT PORTC.F1


#define CTS PORTC.F5

#define SWITCH1 PORTD.F0

#define SWITCH2 PORTD.F1

unsigned short PORTA_V;

unsigned short PORTE_V;


void WriteVirtualPorts()
{
     PORTA = PORTA_V;

     PORTE = PORTE_V;
}