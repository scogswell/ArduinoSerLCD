/******************************************************************************* 
SerLCD - A library to use Sparkfun's SerLCD v2.5 backpack devices with the Arduino
Copyright (C) 2010 Steven Cogswell

Version 20101108A.   

See SerLCD.h for version history. 

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

#include "WProgram.h"
#include "NewSoftSerial.h"
#include "SerLCD.h"

// Constructor, to which you pass a previously generated NewSoftSerial  Object 
// e.g. - 
//   NewSoftSerial NSS(0,2);   // Note that SerLCD only has Rx and no Tx, so only really need a Tx from Arduino
//   SerLCD theLCD(NSS); 
// This will default to 16 columns, 2 row LCD.  Use the other constructor for more options. 
SerLCD::SerLCD(NewSoftSerial &_SerTX)
{
	SerTX = &_SerTX; 
	columns=16;
	rows=2;
}

// Constructor, to which you pass a previously generated NewSoftSerial  Object 
// and the rows and columns of your LCD 
// e.g. - 
//   NewSoftSerial NSS(0,2);
//   SerLCD theLCD(NSS,16,2); 
SerLCD::SerLCD(NewSoftSerial &_SerTX, int _columns, int _rows)
{
	SerTX = &_SerTX; 
	columns=_columns;
	rows=_rows; 
}


// Does some (perhaps not so) helpful init of the SerLCD.   
void SerLCD::begin()
{
	displayOn(); 
	clear(); 
	setBacklight(157); 
}

// Clears the SerLCD display.   
void SerLCD::clear() 
{
	SerTX->print(SERLCD_COMMAND,BYTE); // commmand 
    SerTX->print(0x01,BYTE);   // Clear LCD
}

// Uses the virutal "write" of the Print::print class to pass all "print" statements
// through to the Print::print class.  This gets the bonus of less compiled code and 
// all the flexibility of the existing Print::print class without having to implement 
// any of it yourself. 
void SerLCD::write(uint8_t byte)
{
	SerTX->print(byte); 
}

// Sets the position of the cursor on the SerLCD.   Sparkfun uses absolute positions
// but this accepts as row/column position
void SerLCD::setPosition(int row, int col) 
{
	int pos; 
	// For 16-character displays
	if (columns==16) {
		if (row==1) {
			pos=col;
		} else if (row==2) {
			pos=col+64; 
		} else if (row==3) {
			pos=col+16; 
		} else if (row==4) {
			pos=col+80;
		}
	} else if (columns==20) {
		if (row==1) {
			pos=col;
		} else if (row==2) {
			pos=col+64; 
		} else if (row==3) {
			pos=col+20; 
		} else if (row==4) {
			pos=col+84;
		}
	}
		
	pos=pos+128;   // Cursor move command
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(pos,BYTE); 
}

// Move the cursor one space to the right 
void SerLCD::cursorRight()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x14,BYTE); 
}

// Move the cursor one space to the left 
void SerLCD::cursorLeft()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x10,BYTE); 
}

// Scroll the entire display one position to the right 
void SerLCD::scrollRight()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x1C,BYTE);
}

// Scroll the entire display one position to the left 
void SerLCD::scrollLeft()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x18,BYTE);
}

// Turn off the display.  Does not affect backlight setting. 
void SerLCD::displayOff() 
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x08,BYTE);
}

// Turn display on.  Does not affect backlight setting. 
void SerLCD::displayOn() 
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x0C,BYTE);
}

// Turns on the "underline"  (" _ ") style cursor 
void SerLCD::underlineCursorOn()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x0E,BYTE);
}

// Turns off the underline cursor.  Technically turns off the box cursor since it's the same command 
void SerLCD::underlineCursorOff()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x0C,BYTE);
}

// Turns on the "Box" style cursor
void SerLCD::boxCursorOn()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x0D,BYTE);
}

// Turns off the box cursor.  Technically turns off the underline cursor since it's the same command 
void SerLCD::boxCursorOff()
{
	SerTX->print(SERLCD_COMMAND,BYTE); 
	SerTX->print(0x0C,BYTE);
}

// Set the backlight intensity level.  According to the Sparkfun 2.5 document, acceptable values 
// are 128 (off) to 157 (full on).  
void SerLCD::setBacklight(int value) 
{
	// Enforce values to 128-157 range, as values outside do different things. 
	if (value >157)
	{
		value=157;
	}
	if (value <128) 
	{
		value=128;
	}

	SerTX->print(SERLCD_BACKLIGHT_COMMAND,BYTE); 
	delay(SERLCD_BACKLIGHT_COMMAND_DELAY_MS); // A brief delay, or it seems the SerLCD will hang up. 
	SerTX->print(value,BYTE);
	delay(SERLCD_BACKLIGHT_COMMAND_DELAY_MS); // A brief delay, or it seems the SerLCD will hang up. 
}