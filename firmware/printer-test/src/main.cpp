/*------------------------------------------------------------------------
  Example sketch for Adafruit Thermal Printer library for Arduino.
  Demonstrates a few text styles & layouts, bitmap printing, etc.

  IMPORTANT: DECLARATIONS DIFFER FROM PRIOR VERSIONS OF THIS LIBRARY.
  This is to support newer & more board types, especially ones that don't
  support SoftwareSerial (e.g. Arduino Due).  You can pass any Stream
  (e.g. Serial1) to the printer constructor.  See notes below.
  ------------------------------------------------------------------------*/

  #include <Arduino.h>
  #include "Adafruit_Thermal.h"
  #include "adalogo.h"
  #include "adaqrcode.h"
  #include <AP33772S.h>
  
  // Here's the new syntax when using SoftwareSerial (e.g. Arduino Uno) ----
  // If using hardware serial instead, comment out or remove these lines:

  AP33772S usbpd;
  HardwareSerial printerSerial(1);
  Adafruit_Thermal printer(&printerSerial);     // Pass addr to printer constructor
  // Then see setup() function regarding serial & printer begin() calls.
  
  // Here's the syntax for hardware serial (e.g. Arduino Due) --------------
  // Un-comment the following line if using hardware serial:
  
  //Adafruit_Thermal printer(&Serial1);      // Or Serial2, Serial3, etc.
  
  // -----------------------------------------------------------------------
  
  void setup() {

    // put your setup code here, to run once:
    Wire.begin();

    Serial.begin(115200);
    delay(1000); //Ensure everything got enough time to bootup
    usbpd.begin();

    // This line is for compatibility with the Adafruit IotP project pack,
    // which uses pin 7 as a spare grounding point.  You only need this if
    // wired up the same way (w/3-pin header into pins 5/6/7):
    pinMode(7, OUTPUT); digitalWrite(7, LOW);
  
    // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
    printerSerial.begin(9600, SERIAL_8N1, 10, 7);
    //Serial1.begin(19200); // Use this instead if using hardware serial
    printer.begin();        // Init printer (same regardless of serial type)
  }
  
  void loop() {
    usbpd.setOutput(1);
    if(usbpd.getAVSIndex() > 0)
    {
      for(int i = 15000; i <= 30000; i=i+1000)
        {
          usbpd.setAVSPDO(usbpd.getAVSIndex(), i, 3000);
          delay(600);
        }
    }
  }