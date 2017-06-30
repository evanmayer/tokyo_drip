# tokyo_drip
making drip coffee ('kyoto', 'yama', 'dutch' style) with arduino!

This program makes use of the Adafruit Motor Shield v2.3, an Adafruit
12V DC motor peristaltic pump, and an Arduino Uno Rev3 to make an adjustable-dose
timed dripper.

The brew column was an Aeropress filled with ground coffee, with a filter on top and bottom.
This has been done a couple of different ways, usually with a solenoid valve:
https://blog.arduino.cc/2016/05/06/brew-some-iced-coffee-with-an-arduino-controlled-tower/
http://blog.seattletechnicalbooks.com/adas-coffee-hacking-kyoto-cold-drip/.
These are plenty precise, although I think this pump can be just as precise, and possibly quieter.
The price of the Adafruit peristaltic pump is comparable to the price of the solenoid valve used in the second link.

This code uses the Adafruit Motor Shield v2 libraries:
https://cdn-learn.adafruit.com/downloads/pdf/adafruit-motor-shield-v2-for-arduino.pdf
to drive the 12V DC motor, and a SimpleTimer library to time the drips
https://playground.arduino.cc/Code/SimpleTimer.

Before running, you should have installed both of the necessary libraries (.cpp, .h files) into your "Arduino/libraries" directory,
and restarted your development environment.

License info at the end of the source code.

Authored 30 June, 2017
Evan Mayer 
