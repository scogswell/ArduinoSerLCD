Arduino SerLCD Library by Steven Cogswell

I wrote this, originally posted with instructions on http://awtfy.com/2010/11/08/yet-another-sparkfun-serlcd-library-for-arduino/  

Here's the original top of the serlcd.h, which has information. 

/******************************************************************************* 
SerLCD - A library to use Sparkfun's SerLCD v2.5 backpack devices with the Arduino
Copyright (C) 2010-2013 Steven Cogswell

http://www.sparkfun.com/commerce/product_info.php?products_id=258
http://www.sparkfun.com/commerce/product_info.php?products_id=9395
http://www.sparkfun.com/datasheets/LCD/SerLCD_V2_5.PDF

Version History:
20130711A:

- Compatibility with the Arduino 1.0+ library specifications.  
- Changes to support Arduino IDE 1.0 (tested with IDE 1.0.5):
	- NewSoftSerial now part of Arduino Core as SoftwareSerial
	- print(value, BYTE) deprecated, replaced with write(value); 
	- size_t types for virtual write() function. 
	
Due to the Arduino IDE 1.0 changes, this may not work on older versions of the 
Arduino IDE.  Your mileage may vary.  

I have only tested this with the 5v 2x16 display.  Your mileage may vary.  
I tested the 20130711A version with an Arduino UNO r2.   

Originally this library required NewSoftSerial, available from http://arduiniana.org, 
which lets you run Serial Port style communications on pins other than the hardware pins.
As of version 20130711A NewSoftSerial is replaced with the Arduino Core SoftwareSerial

As usual, I wrote this for myself, and it works for me.  It may not work for you, in 
which case I sympathize.  

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

	
***********************************************************************************/