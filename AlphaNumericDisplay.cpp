
/*
	RoboCore Alpha Numeric Display Library
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

*/

#include "AlphaNumericDisplay.h"


// PUBLIC ---------------------------------------------------------------------------------------------------------------


// Constructor initializes the pins and clears the displays
AlphaNumericDisplay::AlphaNumericDisplay(const byte LE, const byte OE, const byte displays){
  //SPI pins are automatically set
  _LEpin = LE;
  _OEpin = OE;
  _DisplayAmount = displays;
  _Inverted = false;
  _LastDataSent = ' ';
  _LastStringSent[0] = '\0';
  
  pinMode(_LEpin, OUTPUT);
  pinMode(_OEpin, OUTPUT);

  digitalWrite(_LEpin, HIGH);
  digitalWrite(_OEpin, LOW);
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV4);

  Clear();
}

//-----------------------------------------------------------------------------------------------------------------------

// Constructor initializes the pins and clears the displays
AlphaNumericDisplay::AlphaNumericDisplay(const byte LE, const byte OE, const byte displays, boolean inverted){
  //SPI pins are automatically set
  _LEpin = LE;
  _OEpin = OE;
  _DisplayAmount = displays;
  _Inverted = inverted;
  _LastDataSent = ' ';
  _LastStringSent[0] = '\0';
  
  pinMode(_LEpin, OUTPUT);
  pinMode(_OEpin, OUTPUT);
  
  digitalWrite(_LEpin, HIGH);
  digitalWrite(_OEpin, LOW);
  
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV4);
  
  Clear();
}

//-----------------------------------------------------------------------------------------------------------------------

// Destructor
AlphaNumericDisplay::~AlphaNumericDisplay(void){
  SPI.end();
}

//-----------------------------------------------------------------------------------------------------------------------

// Turns the displays on, of the are off
void AlphaNumericDisplay::On(void){
  digitalWrite(_OEpin, LOW);
}

//-----------------------------------------------------------------------------------------------------------------------

// Turns the displays off, if they are on
// When turned back on, the previously displayed data will still be there
void AlphaNumericDisplay::Off(void){
  digitalWrite(_OEpin, HIGH);
}

//-----------------------------------------------------------------------------------------------------------------------

//Inverts the display and displays the last CHAR/STRING if wanted
void AlphaNumericDisplay::Invert(boolean display_last){
  Clear();
  _Inverted = !_Inverted;
  if(display_last){
    if(_DisplayAmount == 1)
      Print(_LastDataSent);
    else
      Print(_LastStringSent);
  }
}

//-----------------------------------------------------------------------------------------------------------------------

//Get if inverted
boolean AlphaNumericDisplay::isInverted(void){
  return _Inverted;
}

//-----------------------------------------------------------------------------------------------------------------------

//Scrolls the message through the display
void AlphaNumericDisplay::Scroll(char * string, int time){
  Clear();
  
  if(_Inverted){
    for(int i = 0 ; i < TextLength(string) ; i++){
      SendData(DataToDisplay(string[i]));
      if(_DisplayAmount > 1){ //must offset when inverting
        if(i == 0)
          SendData(DataToDisplay(' '));
        else
          SendData(DataToDisplay(string[i-1]));
      }
      delay(time);
    }
  } else {
    for(int i = 0 ; i < TextLength(string) ; i++){
      SendData(DataToDisplay(string[i]));
      delay(time);
    }
  }
}

//-----------------------------------------------------------------------------------------------------------------------

//Clears the display
void AlphaNumericDisplay::Clear(void){
  for (int i = 0; i < _DisplayAmount; i++)
    SendData(0);
}

//-----------------------------------------------------------------------------------------------------------------------

//Prints a CHAR to the display
void AlphaNumericDisplay::Print(char toPrint){
  unsigned int data = DataToDisplay(toPrint);
  SendData(data);
}

//-----------------------------------------------------------------------------------------------------------------------

//Prints a STRING to the display
void AlphaNumericDisplay::Print(char* toPrint){
  Clear();
  int i;
  if(_Inverted){
    i = TextLength(toPrint) - 1; //0 based index
    if(i > (_DisplayAmount - 1))
      i = _DisplayAmount - 1;
    while(i >= 0){
      SendData(DataToDisplay(toPrint[i]));
      i--;
    }
  } else {
    i = 0;
    while((toPrint[i] != '\0') && (i < _DisplayAmount)){ //NULL
      SendData(DataToDisplay(toPrint[i]));
      i++;
    }
  }
  
  i = 0;
  while((toPrint[i] != '\0') && (i < STRING_MAX_LENGTH)){ //NULL
    _LastStringSent[i] = toPrint[i]; //store last value
    i++;
  }
  _LastStringSent[i] = '\0'; //use end of string NULL
}

//-----------------------------------------------------------------------------------------------------------------------

//Sends the data to the display
void AlphaNumericDisplay::SendData(unsigned int data){
  if(_Inverted){
    SPI.transfer((data & 0xFF00) >> 8); //HIGH part
    SPI.transfer(data & 0x00FF);        //LOW part
  } else {
    SPI.transfer(data & 0x00FF);        //HIGH part
    SPI.transfer((data & 0xFF00) >> 8); //LOW part
  }
  _LastDataSent = data; //do it here instead of 'Print(char toPrint)'
}

//-----------------------------------------------------------------------------------------------------------------------

//Set the LE pin (HIGH or LOW)
void AlphaNumericDisplay::SetLEpin(byte state){
  if(state == HIGH)
    digitalWrite(_LEpin, HIGH);
  else
    digitalWrite(_LEpin, LOW);
}

// PRIVATE --------------------------------------------------------------------------------------------------------------


//Gets the length of a string
int AlphaNumericDisplay::TextLength(char* text){
  int i = 0;
  while(text[i] != '\0') //NULL
    i++;
  return i;
}

//-----------------------------------------------------------------------------------------------------------------------

//Converts a CHAR to the Displayed LEDs
unsigned int AlphaNumericDisplay::DataToDisplay(char character)
{
	switch (character)
	{
		case '0':
		case 0:
			return ZERO_CHAR;
			break;
		case '1':
		case 1:
			return ONE_CHAR;
			break;
		case '2':
		case 2:
			return TWO_CHAR;
			break;
		case '3':
		case 3:
			return THREE_CHAR;
			break;
		case '4':  
		case 4:
			return FOUR_CHAR;
			break;
		case '5':
		case 5:
			return FIVE_CHAR;
			break;
		case '6':
		case 6:
			return SIX_CHAR;
			break;
		case '7':
		case 7:
			return SEVEN_CHAR;
			break;
		case '8':
		case 8:
			return EIGHT_CHAR;
			break;
		case '9':
		case 9:
			return NINE_CHAR;
			break;
		case 'A':
		case 'a':
		case 10:  
			return A_CHAR;
			break;
		case 'B':
		case 'b':
		case 11:
		  return B_CHAR;
			break;
		case 'C':
		case 'c':
		case 12:
			return C_CHAR;
			break;
		case 'D':
		case 'd':
		case 13:
			return D_CHAR;
			break;
		case 'E':
		case 'e':
		case 14:
			return E_CHAR;
			break;
		case 'F':
		case 'f':
		case 15:
			return F_CHAR;
			break;
		case 'G':
		case 'g':
			return G_CHAR;
			break;
		case 'H':
		case 'h':
			return H_CHAR;
			break;
		case 'I':
		case 'i':
			return I_CHAR;
			break;
		case 'J':
		case 'j':
			return J_CHAR;
			break;
		case 'K':
		case 'k':
			return K_CHAR;
			break;
		case 'L':
		case 'l':
			return L_CHAR;
			break;
		case 'M':
		case 'm':
			return M_CHAR;
			break;
		case 'N':
		case 'n':
			return N_CHAR;
			break;
		case 'O':
		case 'o':
			return O_CHAR;
			break;
		case 'P':
		case 'p':
			return P_CHAR;
			break;
		case 'Q':
		case 'q':
			return Q_CHAR;
			break;
		case 'R':
		case 'r':
			return R_CHAR;
			break;
		case 'S':
		case 's':
			return S_CHAR;
			break;
		case 'T':
		case 't':
			return T_CHAR;
			break;
		case 'U':
		case 'u':
			return U_CHAR;
			break;
		case 'V':
		case 'v':
			return V_CHAR;
			break;
		case 'W':
		case 'w':
			return W_CHAR;
			break;
		case 'X':
		case 'x':
			return X_CHAR;
			break;
		case 'Y':
		case 'y':
			return Y_CHAR;
			break;
		case 'Z':
		case 'z':
			return Z_CHAR;
			break;
		case ' ':
			return 0;
			break;
		case '!':
			return EXCLAMATION_CHAR;
			break;
		case '#':
			return (unsigned int) 0xFFFF;
			break;
		case '$':
			return DOLLAR_CHAR;
			break;
//		case '%':
//			return PERCENT;
//			break;
//		case '^':
//			return CARROT;
//			break;
		case '&':
			return AMPERSAND_CHAR;
			break;
		case '*':
			return ASTERISK_CHAR;
			break;
		case '(':
			return LPAREN_CHAR;
			break;
		case ')':
			return RPAREN_CHAR;
			break;
		case '-':
			return MINUS_CHAR;
			break;
		case '_':
			return UNDERSCORE_CHAR;
			break;
		case '+':
			return PLUSYSIGN_CHAR;
			break;
		case '=':
			return EQUALS_CHAR;
			break;
		case '>':
			return RARROW_CHAR;
			break;
		case '<':
			return LARROW_CHAR;
			break;
		case ',':
			return COMMA_CHAR;
			break;
		case '/':
			return FSLASH_CHAR;
			break;
		case '\\':
			return BSLASH_CHAR;
			break;
		case '\'':
			return SINGLEQUOTE_CHAR;
			break;
		case '"':
			return DOUBLEQUOTE_CHAR;
			break;
		case 0X5B:
			return LBRACKET_CHAR;
			break;
		case 0X5D:
			return RBRACKET_CHAR;
			break;
		case 0X7D:
			return LCURLY_CHAR;
			break;
		case 0X7B:
			return RCURLY_CHAR;
			break;
		case '|':
			return PIPE_CHAR;
			break;
//		case '~':
//			return TILDE;
//			break;
		case '`':
			return APOSTROPHE_CHAR;
			break;
//		case '@':
//			return ATSIGN;
//			break;
		case '?':
			return QUESTIONMARK_CHAR;
			break;
		case ':':
			return COLON_CHAR;
			break;
		case ';':
			return SEMICOLON_CHAR;
			break;
//		case '.':
//			return PERIOD;
//			break;
		}

	return 0;	// Return
}

//-----------------------------------------------------------------------------------------------------------------------






