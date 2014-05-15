## Omega

### Overview

This is an embedded C firmware for a multi-axis stepper motor controller based on PIC16F877. The firmware sets up a command-prompt serial interface on a PIC device and can drive up to three M325 stepper motor drivers (http://www.leadshine.com/UploadFile/Down/M325d.pdf) (or any equivalent PWM-based drivers).

A main feature of the firmware is support for asynchronous operation. The controller uses the PIC16F877 Timer device and interrupt service routines to implement a form of "pseudo multi-threading". This allows precise PWM control and serial communication to take place simultaneously.

Refer to the documentation for details about the protocol, circuit connections and controller operation specifics.

The code is written in MikroC Embedded C for PIC (http://www.mikroe.com/mikroc/pic/) which is an excellent compiler and IDE for PIC-based project development.

### Circuit Diagram

![Screenshot](https://raw.github.com/gtarawneh/omega/master/diagrams/circuit.png "Circuit")

### Protocol on HyperTerminal

![Screenshot](https://raw.github.com/gtarawneh/omega/master/diagrams/protocol.png "Protocol")

### LCD Display


![Screenshot](https://raw.github.com/gtarawneh/omega/master/diagrams/lcd1.png "LCD 1")
![Screenshot](https://raw.github.com/gtarawneh/omega/master/diagrams/lcd2.png "LCD 2")