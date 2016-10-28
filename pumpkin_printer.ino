/*
 Wells Fargo Account Generator Pumpkin
 Dave Latham
*/
#include <SoftwareSerial.h>
SoftwareSerial Thermal(2, 3);
int heatTime = 80;
int heatInterval = 255;
char printDensity = 15; 
char printBreakTime = 15;
int zero = 0;
void setup() 
{
 Serial.begin(57600); // for debug info to serial monitor
 pinMode(8,INPUT_PULLUP);
 pinMode(13, OUTPUT);
 pinMode(9, OUTPUT);
 Thermal.begin(115200); // to write to our new printer
 initPrinter();
}
void initPrinter()
{
 //Modify the print speed and heat
 Thermal.write(27);
 Thermal.write(55);
 Thermal.write(7); //Default 64 dots = 8*('7'+1)
 Thermal.write(heatTime); //Default 80 or 800us
 Thermal.write(heatInterval); //Default 2 or 20us
 //Modify the print density and timeout
 Thermal.write(18);
 Thermal.write(35);
 int printSetting = (printDensity<<4) | printBreakTime;
 Thermal.write(printSetting); //Combination of printDensity and printBreakTime
 Serial.println();
 Serial.println("Printer ready"); 
}
void loop()
{
 int sensorVal = digitalRead(8);
 if (sensorVal == HIGH) {
    digitalWrite(13, LOW);
    digitalWrite(9, LOW);
  } else {
    digitalWrite(13, HIGH);
    digitalWrite(9, HIGH);
    Serial.println();
 Serial.println("Triggered"); 
 Thermal.write(29); 
 Thermal.write(33);
 Thermal.write(zero);
 Thermal.println("WELLS FARGO ACCOUNT CREATOR");
 Thermal.write(10); //Sends the LF to the printer, advances the paper
// back to normal
 Thermal.write(29); 
 Thermal.write(33);
 Thermal.write(zero);
 Thermal.println(" New account generated for: ");
 Thermal.write(29); 
 Thermal.write(33);
 Thermal.write(1);
 Thermal.println(" JANE DOE "); 
 Thermal.write(10);
 Thermal.write(10);
 Thermal.write(29); 
 Thermal.write(33);
 Thermal.write(zero);
 Thermal.println(" ACCT #: 761726127863");
 Thermal.write(10);
 Thermal.write(10);
 Thermal.write(27);
 Thermal.write(45); 
 Thermal.write(1);
 Thermal.println("We appreciate your business that");
 Thermal.println("you don't know about!"); 
 Thermal.write(10);
 Thermal.write(10);
 Thermal.write(27);
 Thermal.write(45); 
 Thermal.write(zero);
 delay(3000);
  }
 
}
