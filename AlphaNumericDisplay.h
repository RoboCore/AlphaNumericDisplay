/*
  AlphaNumeric_Driver.h - Arduino library to control a string of AlphaNumeric Display Driver
  30/10/12 at Robocore
  License: Beerware
*/

#ifndef AlphaNumericDisplay_H
#define AlphaNumericDisplay_H

//#include <inttypes.h>

#include <SPI.h>


// Bit position relating display pin to driver output pin
//		SEG
  //LOW byte
  #define M_SEG   0
  #define N_SEG	  1
  #define D1_SEG  2
  #define E_SEG	  3
  #define G1_SEG  4
  #define F_SEG	  5
  #define H_SEG	  6
  #define A1_SEG  7
  
  //HIGH byte
  #define J_SEG   8
  #define K_SEG	  9
  #define A2_SEG  10
  #define B_SEG	  11
  #define G2_SEG  12
  #define C_SEG	  13
  #define L_SEG	  14
  #define D2_SEG  15


#define ALL_SEG 0xFFFF

#define A_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<G1_SEG) + (1<<G2_SEG)
#define B_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) //='8'
#define C_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define D_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<H_SEG) + (1<<N_SEG)
#define E_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define F_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG)
#define G_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<C_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define H_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<G1_SEG) + (1<<G2_SEG)
#define I_CHAR (1<<A1_SEG) + (1<<A2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<J_SEG) + (1<<M_SEG)
#define J_CHAR (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<D1_SEG) + (1<<J_SEG) + (1<<M_SEG)
#define K_CHAR (1<<J_SEG) + (1<<M_SEG) + (1<<K_SEG) + (1<<L_SEG)
#define L_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define M_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<H_SEG) + (1<<K_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define N_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<H_SEG) + (1<<L_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define O_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define P_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<G1_SEG) + (1<<G2_SEG)
#define Q_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<L_SEG)
#define R_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<L_SEG)
#define S_CHAR (1<<F_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<C_SEG) //='5'
#define T_CHAR (1<<A1_SEG) + (1<<A2_SEG) + (1<<J_SEG) + (1<<M_SEG)
#define U_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define V_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<N_SEG) + (1<<K_SEG)
#define W_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<N_SEG) + (1<<L_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define X_CHAR (1<<H_SEG) + (1<<K_SEG) + (1<<N_SEG) + (1<<L_SEG)
#define Y_CHAR (1<<H_SEG) + (1<<K_SEG) + (1<<M_SEG)
#define Z_CHAR (1<<A1_SEG) + (1<<A2_SEG) + (1<<K_SEG) + (1<<N_SEG) + (1<<D1_SEG) + (1<<D2_SEG)

#define ONE_CHAR (1<<J_SEG) + (1<<M_SEG)
#define TWO_CHAR (1<<E_SEG) + (1<<B_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define THREE_CHAR (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define FOUR_CHAR (1<<F_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define FIVE_CHAR (1<<F_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<C_SEG) //='S'
#define SIX_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<C_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define SEVEN_CHAR (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG)
#define EIGHT_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) //='B'
#define NINE_CHAR (1<<F_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
#define ZERO_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<C_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<K_SEG) + (1<<N_SEG)

#define EXCLAMATION_CHAR (1<<F_SEG) + (1<<E_SEG) //='1' ???
#define DOLLAR_CHAR (1<<F_SEG) + (1<<C_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<J_SEG) + (1<<M_SEG)
//#define ATSIGN (1<<D2_SEG) + (1<<D1_SEG) + (1<<E_SEG) + (1<<F_SEG) + (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<G2_SEG) + (1<<J_SEG) //?????????
//#define PERCENT_CHAR (1<<F_SEG) + (1<<A1_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<J_SEG) + (1<<M_SEG) + (1<<D2_SEG) + (1<<C_SEG) + (1<<N_SEG) + (1<<K_SEG)
//#define CARROT (1<<K_SEG)+(1<<N_SEG)+(1<<A2_SEG)+(1<<B_SEG)
#define AMPERSAND_CHAR (1<<J_SEG)+ (1<<N_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG) + (1<<L_SEG)
#define ASTERISK_CHAR (1<<H_SEG) + (1<<J_SEG) + (1<<K_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<N_SEG) + (1<<M_SEG) + (1<<L_SEG)
#define LPAREN_CHAR (1<<F_SEG) + (1<<E_SEG) + (1<<A1_SEG) + (1<<D1_SEG)
#define RPAREN_CHAR (1<<B_SEG) + (1<<C_SEG) + (1<<D2_SEG) + (1<<A2_SEG)
#define MINUS_CHAR (1<<G1_SEG) + (1<<G2_SEG)
#define UNDERSCORE_CHAR (1<<D1_SEG) + (1<<D2_SEG)
#define PLUSYSIGN_CHAR (1<<J_SEG) + (1<<G1_SEG) + (1<<G2_SEG) + (1<<M_SEG)
#define EQUALS_CHAR (1<<G1_SEG) + (1<<G2_SEG) + (1<<D1_SEG) + (1<<D2_SEG)
//#define PERIOD (1<<G1_SEG)+(1<<M_SEG)+(1<<D1_SEG)+(1<<E_SEG)
#define COLON_CHAR (1<<J_SEG) + (1<<M_SEG)
#define SEMICOLON_CHAR (1<<J_SEG) + (1<<N_SEG)
#define LARROW_CHAR (1<<K_SEG) + (1<<L_SEG)
#define RARROW_CHAR (1<<H_SEG) + (1<<N_SEG)
#define COMMA_CHAR (1<<N_SEG)
#define FSLASH_CHAR (1<<N_SEG) + (1<<K_SEG)
#define BSLASH_CHAR (1<<H_SEG) + (1<<L_SEG)
#define SINGLEQUOTE_CHAR (1<<K_SEG)
#define DOUBLEQUOTE_CHAR (1<<F_SEG) + (1<<J_SEG)
#define LBRACKET_CHAR (1<<A2_SEG) + (1<<J_SEG) + (1<<M_SEG) + (1<<D2_SEG)
#define RBRACKET_CHAR (1<<A1_SEG) + (1<<J_SEG) + (1<<M_SEG) + (1<<D1_SEG)
#define LCURLY_CHAR (1<<A1_SEG) + (1<<J_SEG) + (1<<M_SEG) + (1<<D1_SEG) + (1<<G2_SEG)
#define RCURLY_CHAR (1<<A2_SEG) + (1<<J_SEG) + (1<<M_SEG) + (1<<D2_SEG) + (1<<G1_SEG)
#define PIPE_CHAR (1<<J_SEG) + (1<<M_SEG)
//#define TILDE (1<<E_SEG)+(1<<G1_SEG)+(1<<G2_SEG)+(1<<B_SEG)
#define APOSTROPHE_CHAR (1<<H_SEG)
#define QUESTIONMARK_CHAR (1<<A1_SEG) + (1<<A2_SEG) + (1<<B_SEG) + (1<<M_SEG) + (1<<G2_SEG)
//#define POUNDSIGN 0xFFFF


//********************** CLASS **********************

#define STRING_MAX_LENGTH 100

class AlphaNumericDisplay
{
private:
	byte _SDIpin;
	byte _CLKpin;
	byte _LEpin;
	byte _OEpin;
	byte _DisplayAmount;
        boolean _Inverted;
        unsigned int _LastDataSent;
        char _LastStringSent[STRING_MAX_LENGTH];
	
        int TextLength(char* text);
	unsigned int DataToDisplay(char character);
	
public:
	AlphaNumericDisplay(const byte SDI, const byte CLK, const byte LE, const byte OE, const byte displays);
	AlphaNumericDisplay(const byte SDI, const byte CLK, const byte LE, const byte OE, const byte displays, boolean inverted);
	
	void On(void);
	void Off(void);
        void Invert(boolean display_last);
	void Scroll(char * string, int time);
	void Clear(void);
	void Print(char toPrint);
        void Print(char* toPrint);
	void SendData(unsigned int data);
};

#endif	//AlphaNumericDisplay_H
