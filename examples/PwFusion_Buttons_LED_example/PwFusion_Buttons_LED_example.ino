/***************************************************************************
* File Name: PwFusion_Buttons_LED_example.ino
* Processor/Platform: R3aktor (tested)
* Development Environment: Arduino 2.2.1
*
* Designed for use with Playing With Fusion I2C Buttons
* interface board: IFB-40003
*
* Copyright © 2015-18 Playing With Fusion, Inc.
* SOFTWARE LICENSE AGREEMENT: This code is released under the MIT License.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
* **************************************************************************
* REVISION HISTORY:
* Author		  Date	    Comments
* N. Johnson  2023Aug10 Original Version
*
* Playing With Fusion, Inc. invests time and resources developing open-source
* code. Please support Playing With Fusion and continued open-source
* development by buying products from Playing With Fusion!
* **************************************************************************
* ADDITIONAL NOTES:
* This file contains functions to initialize and run a Playing With Fusion R3aktor in
* order to communicate with the I2C Buttons board. Funcionality is as described below:
*	- Configure R3aktor to receive information from the I2C Buttons board
* - Activate and deactivate select LEDs based on the button being pressed
*	- Broadcast results to COM port
*  Circuit: (see Schematic.png)
*    R3aktor     -->  I2C Buttons
*    Qwiic pins  -->  Qwiic pins
*    R3aktor     -->  LEDS
*    DIO 05      -->  LED 1 in series with 220 ohm resistor
*    DIO 06      -->  LED 2 in series with 220 ohm resistor
*    DIO 09      -->  LED 3 in series with 220 ohm resistor
*    DIO 10      -->  LED 4 in series with 220 ohm resistor
*    DIO 11      -->  LED 5 in series with 220 ohm resistor
***************************************************************************/

// Include the PwFusion I2C Butons library
#include <PwFusion_Buttons.h>

// Define address for the i2c buttons
uint8_t ADR_BTN = 0x05;

// Define pins for the 5 leds
int l1 = 5;
int l2 = 6;
int l3 = 9;
int l4 = 10;
int l5 = 11;



// Create a new button object
Buttons btn;

void setup() {
  Serial.begin(9600);

  // Start the button object and pass in the i2c address
  btn.begin(ADR_BTN);

  // Define the pin mode for each LED
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(l5, OUTPUT);
}

void loop() {

  // Print out the value of the buttons
  Serial.print("Button:  ");
  Serial.println(btn.getBtn());

  
  updateLED(l2, 1);
  updateLED(l4, 2);
  updateLED(l5, 3);
  updateLED(l1, 4);
  updateLED(l3, 5);

}

// Turn all of the LEDs off
void allOff() {
  digitalWrite(l1, LOW);
  digitalWrite(l2, LOW);
  digitalWrite(l3, LOW);
  digitalWrite(l4, LOW);
  digitalWrite(l5, LOW);
}

// Turn on a specific LED
void updateLED(int led, int swnum) {
  // Turn on the given led if the given switch number is active
  if (btn.getBtn() == swnum) {
    digitalWrite(led, HIGH);
  } else {
    allOff();
  }
}
