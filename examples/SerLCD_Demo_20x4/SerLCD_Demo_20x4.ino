#include <SoftwareSerial.h>
#include <SerLCD.h>

// This Arduino sketch demonstrates using my SerLCD library
// Steven Cogswell.  This demo is specifically for a 20x4 
// Sparkfun SerLCD.  https://www.sparkfun.com/products/9568

// Make a SoftwareSerial object, and a new SerLCD object, 
// which points at the NewSoftSerial object. 
//
// In this demo the Rx pin of the SerLCD is connected to 
// Arduino digital pin 2 (Tx)  We set the SoftwareSerial 
// Rx to 0 because the SerLCD has no facility to transmit
// back. 
//
SoftwareSerial NSS(3,2);
SerLCD theLCD(NSS,20,4); 


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
  theLCD.print("SerLCD Library(20x4)"); 
  delay(1000); 
  theLCD.setPosition(2,0); 
  theLCD.print("Steven Cogswell"); 
  delay(1000); 
  theLCD.setPosition(4,0); 
  theLCD.print("http://awtfy.com"); 
  delay(2000);
  theLCD.clear();  
  theLCD.setPosition(1,0); 
  theLCD.print("(C) 2010-2013");
  theLCD.setPosition(2,0); 
  theLCD.print("LGPL 2.1 Licence"); 
  theLCD.setPosition(3,0); 
  theLCD.print("Compatible With");
  theLCD.setPosition(4,0); 
  theLCD.print("Arduino 1.0+");
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
  theLCD.setPosition(3,0);
  theLCD.print("These Extra Lines");
  theLCD.setPosition(4,0);
  theLCD.print("are useful"); 
  theLCD.setPosition(1,0); 
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
  theLCD.setPosition(3,0);
  theLCD.print("Monty Python and");
  theLCD.setPosition(4,0);
  theLCD.print("the Holy Grail"); 
  theLCD.setPosition(1,0); 
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
  for(int i = -20; i<=100; i++) 
  {
    theLCD.setPosition(1,14);
    theLCD.print("   ");
    theLCD.setPosition(1,14);
    theLCD.print(i); 
    delay(30); 
  }
  delay(1000);

  
  // Print some floating point numbers, showing the leveraging of Print::print class
  // with no code needing to be written for SerLCD's class. 
  theLCD.clear(); 
  theLCD.print("Floating point:"); 
  for (float x=1.2942; x<100; x*=1.0785)
  {
     theLCD.setPosition(2,0); 
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
     if (j==1) {
       theLCD.setPosition(1,15); 
       theLCD.print(".");
     } else if (j==2) {
       theLCD.setPosition(1,15); 
       theLCD.print("o");
       theLCD.setPosition(2,15); 
       theLCD.print("+"); 
     } else if (j==3) {
       theLCD.setPosition(1,15); 
       theLCD.print("O"); 
     } else {
       theLCD.setPosition(1,15); 
       theLCD.print("o");
       theLCD.setPosition(2,15); 
       theLCD.print("-"); 
       j=0;
     }

     delay(200); 
  }
  
  // We're done
  theLCD.clear();
  theLCD.print("Demo Over"); 
  delay(1000); 
  theLCD.setPosition(2,0);
  theLCD.print("That's it");
  delay(1000); 
  theLCD.setPosition(3,0); 
  theLCD.print("We're done here");
  delay(5000); 
  theLCD.setPosition(4,0);
  theLCD.print("Go Home Already"); 
  delay(5000); 
  
  // Shibe
  theLCD.clear(); 
  theLCD.setPosition(1,5); 
  theLCD.print("wow"); 
  theLCD.setPosition(3,1); 
  theLCD.print("such lcd"); 
  theLCD.setPosition(2,6);
  theLCD.print("yes backlited"); 
  theLCD.setPosition(4,15); 
  theLCD.print("wow"); 
  delay(5000); 
}
