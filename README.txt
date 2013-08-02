
	RoboCore Alphanumeric Display Library
		(v1.1 - 01/03/2013)

  Arduino library to control a string of AlphaNumeric Display Drivers
    (tested with Arduino 0022 and 1.0.1)

  Copyright 2013 RoboCore (François) ( http://www.RoboCore.net )
  
  ------------------------------------------------------------------------------
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  ------------------------------------------------------------------------------




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




