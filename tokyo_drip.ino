/* This program makes use of the Adafruit Motor Shield v2.3, an Adafruit
 * 12V DC motor peristaltic pump, and an Arduino Uno Rev3 to make an adjustable-dose
 * timed dripper.
 * 
 * This code uses the Adafruit Motor Shield v2 libraries:
 * https://cdn-learn.adafruit.com/downloads/pdf/adafruit-motor-shield-v2-for-arduino.pdf
 * to drive the 12V DC motor, and a SimpleTimer library to time the drips
 * https://playground.arduino.cc/Code/SimpleTimer.
 * 
 * License info after the code.
 * 
 * Authored 30 June, 2017
 * Evan Mayer
 */

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <SimpleTimer.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

// Initialize a timer object to time the drips
SimpleTimer timer;

// a function to be executed periodically, 1500ms apart, called by setInterval
void drip() {
  // time in milliseconds to run motor; adjusts water vol per "drip" cycle.
  int mtr_time = 300;
  digitalWrite(LED_BUILTIN, HIGH); // LED on while dripping
  Serial.print("Uptime (s): ");
  Serial.println(millis() / 1000); // time in sec since beginning monitor
  // Run the motor forward for mtr_time to make a few small drips
  myMotor->run(FORWARD);
  myMotor->setSpeed(50); // crude ramp up
  myMotor->setSpeed(100);
  delay(mtr_time); 
  myMotor->run(RELEASE);
  digitalWrite(LED_BUILTIN, LOW); // LED off when dripping done
}

void setup() {
  // time in milliseconds between drips
  int drip_wait = 1500;
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // set up Serial comms at 9600 bps
  Serial.println("Adafruit Motorshield v2 - \"Kyoto\" Aeropress Drip test!");
  // initialize motor frequency with 800Hz. Max 1600Hz for this shield.
  AFMS.begin(800);
  timer.setInterval(drip_wait, drip); // call drip function on a timer
}

void loop() {
  // run the timer object initialized in setup
  timer.run();
}

/* Adafruit License Information
 *  
 *  Software License Agreement (BSD License)
 *
 * Copyright (c) 2012, Adafruit Industries.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

 
/* SimpleTimer License Information 
 *  
 * SimpleTimer - A timer library for Arduino.
 * Author: mromani@ottotecnica.com
 * Copyright (c) 2010 OTTOTECNICA Italy
 *
 * This library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser
 * General Public License as published by the Free Software
 * Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will
 * be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser
 * General Public License along with this library; if not,
 * write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */
 
 /* The GNU LGPL 2.1+ License Text can be found at
  *  https://www.gnu.org/licenses/old-licenses/lgpl-2.1.en.html
  */
