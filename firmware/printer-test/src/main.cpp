#include <Arduino.h>
#include <AP33772S.h>

// put function declarations here:
AP33772S usbpd;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();

  Serial.begin(115200);
  delay(1000); //Ensure everything got enough time to bootup
  usbpd.begin();
}

void loop() {
  usbpd.setOutput(1);
  usbpd.setFixPDO(2, 3000);
  delay(2000);
}