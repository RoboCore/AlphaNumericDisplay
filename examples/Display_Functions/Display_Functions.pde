
#include <SPI.h>
#include <AlphaNumericDisplay.h>

#define NUMBER_OF_DISPLAYS 2

const byte CLKpin = 13;
const byte SDIpin = 11;
const byte LEpin = 7;
const byte OEpin = 6;

char data;

AlphaNumericDisplay Display(SDIpin, CLKpin, LEpin, OEpin, NUMBER_OF_DISPLAYS);


void setup()
{
  Display.On();
  Serial.begin(57600);
}


void loop()
{
  if(Serial.available())
  {
    data = Serial.read();
    if(data == '.')
      Display.Clear();
    else if(data == '%')
      Display.Scroll("Teste", 1000);
    else if(data == '^')
      Display.Off();
    else if(data == '~')
      Display.On();
    else if(data == 'i')
      Display.Invert(false);
    else if(data == 'z')
      Display.Print("GAF");
    else
      Display.Print(data);
  }
}


