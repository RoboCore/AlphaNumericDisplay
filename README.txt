
	RoboCore Alphanumeric Display Library
		(v1.1 - 01/03/2012)

  Arduino library to control a string of AlphaNumeric Display Drivers
    (tested with Arduino 0022 and 1.0.1)

  Released under the Beerware license
  Written by François




 Use with RoboCore's Alphanumeric Display/Driver:
 - http://www.robocore.net/modules.php?name=GR_LojaVirtual&prod=338 (driver)
 - http://www.robocore.net/modules.php?name=GR_LojaVirtual&prod=452 (display)



-----------------------------------------
#include <AlphaNumericDisplay.h>


AlphaNumericDisplay class

   Constructors, given the LE pin, OE pin, number of displays, and if inverted
	AlphaNumericDisplay(const byte LE, const byte OE, const byte displays);
	AlphaNumericDisplay(const byte LE, const byte OE, const byte displays, boolean inverted);

	void On(void);				turn on the displays
	void Off(void);				turn off the displays
	void Invert(boolean display_last);	invert the displays
	boolean isInverted(void)		check if displays are inverted
	void Scroll(char * string, int time);	scroll a text
	void Clear(void);			clear the displays
	void Print(char toPrint);		print a char
	void Print(char* toPrint);		print a string
	void SendData(unsigned int data);	send data to the display
	void SetLEpin(byte state); 		set the LE pin HIGH or LOW




