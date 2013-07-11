#include <SoftwareSerial.h>
#include <SerLCD.h>

// This Arduino sketch demonstrates using my SerLCD library
// Steven Cogswell 

// Make a SoftwareSerial object, and a new SerLCD object, 
// which points at the NewSoftSerial object. 
//
// In this demo the Rx pin of the SerLCD is connected to 
// Arduino digital pin 2 (Tx)  We set the SoftwareSerial 
// Rx to 0 because the SerLCD has no facility to transmit
// back. 
//
SoftwareSerial NSS(0,2);
SerLCD theLCD(NSS); 


void setup()
{
  // Remember to start the NewSoftSerial port before doing things with the SerLCD
  NSS.begin(9600); 
  Serial.begin(9600);
  // This will attempt to initialize the display to blank with the backlight on 
  theLCD.begin();   
}


// Silly looking demo that just loops through features of SerLCD
// 
void loop()
{
 
  // Some text at positions
  theLCD.clear(); 
  theLCD.print("SerLCD Library"); 
  delay(1000); 
  theLCD.setPosition(2,0); 
  theLCD.print("Steven Cogswell"); 
  delay(1000); 
  theLCD.clear(); 
  theLCD.setPosition(1,0); 
  theLCD.print("Compatible with");
  theLCD.setPosition(2,0);
  theLCD.print("Arduino 1.0+");   
  delay(2000);
  theLCD.clear();  
  theLCD.setPosition(1,0); 
  theLCD.print("(C) 2010-2013");
  theLCD.setPosition(2,0); 
  theLCD.print("LGPL 2.1 Licence"); 
  delay(2000); 
  
  // Display on and off
  theLCD.displayOff(); 
  delay(1000);
  theLCD.displayOn();
  delay(1000); 
  
  // Scroll Right and left 
  theLCD.scrollRight(); 
  delay(200); 
  theLCD.scrollRight(); 
  delay(200); 
  theLCD.scrollRight(); 
  delay(200); 
  theLCD.scrollLeft(); 
  delay(200); 
  theLCD.scrollLeft(); 
  delay(200); 
  theLCD.scrollLeft(); 
  delay(200); 
  
  // Show some backlight settings 
  delay(1000); 
  theLCD.clear(); 
  theLCD.print("Backlight"); 
  
  theLCD.setBacklight(128);
  theLCD.setPosition(1,12); 
  theLCD.print(128); 
  delay(1000); 
  
  theLCD.setBacklight(140);
  theLCD.setPosition(1,12); 
  theLCD.print(140); 
  delay(1000); 
  
  theLCD.setBacklight(150);
  theLCD.setPosition(1,12); 
  theLCD.print(150); 
  delay(1000);
  
  theLCD.setBacklight(157);
  theLCD.setPosition(1,12); 
  theLCD.print(157); 
  delay(1000);
  
  // Different Cursor modes
  theLCD.clear(); 
  theLCD.print("Cursor box:"); 
  theLCD.boxCursorOn(); 
  delay(3000); 
  theLCD.cursorRight(); 
  delay(500); 
  theLCD.cursorRight(); 
  delay(500);
  theLCD.cursorRight(); 
  delay(500);
  theLCD.cursorLeft(); 
  delay(500); 
  theLCD.cursorLeft(); 
  delay(500);
  theLCD.cursorLeft(); 
  delay(500);
  theLCD.boxCursorOff(); 
  
  theLCD.clear(); 
  theLCD.print("Underline:"); 
  theLCD.underlineCursorOn(); 
  delay(3000); 
  theLCD.cursorRight(); 
  delay(500); 
  theLCD.cursorRight(); 
  delay(500);
  theLCD.cursorRight(); 
  delay(500);
  theLCD.cursorLeft(); 
  delay(500); 
  theLCD.cursorLeft(); 
  delay(500);
  theLCD.cursorLeft(); 
  delay(500);
  theLCD.underlineCursorOff();  
  
  // Print some integers 
  theLCD.clear(); 
  theLCD.print("Some numbers:");
  for(int i = -10; i<100; i++) 
  {
    theLCD.setPosition(1,13);
    theLCD.print("   ");
    theLCD.setPosition(1,13);
    theLCD.print(i); 
    delay(200); 
  }
  delay(1000);
  
  // Print some floating point numbers, showing the leveraging of Print::print class
  // with no code needing to be written for SerLCD's class. 
  theLCD.clear(); 
  theLCD.print("Floats:"); 
  for (float x=1.2942; x<100; x*=1.0785)
  {
     theLCD.setPosition(1,8); 
     theLCD.print(x,3); 
     delay(200);
  }
  // Print::print style formatting 
  theLCD.setPosition(2,0); 
  theLCD.print(-99.75358,5); 
  delay(2000); 
  
  // Strange looking throbber
  theLCD.clear();
  theLCD.setPosition(1,0); 
  theLCD.print("Strange");
  theLCD.setPosition(2,0);
  theLCD.print("Throbbers"); 
  int j=0; 
  for(int i=0; i<=50; i++) 
  {
     j++; 
     theLCD.setPosition(1,15); 
     if (j==1) {
       theLCD.print(".");
     } else if (j==2) {
       theLCD.print("o");
       theLCD.setPosition(2,15); 
       theLCD.print("-"); 
     } else if (j==3) {
       theLCD.print("O"); 
     } else {
       theLCD.print("o");
       theLCD.setPosition(2,15); 
       theLCD.print("+"); 
       j=0;
     }

     delay(200); 
  }
    
}
