
/*
    Exemplo de uso da biblioteca AlphaNumericDisplay
            ( RoboCore - http://www.RoboCore.net )
    
    Escrito por François
            
    O exemplo a seguir utiliza 2 displays (pode-se usar a
        quantidade desejada, desde que definida em
        NUMBER_OF_DISPLAYS).
    Neste exemplos, o usuário envia um caractere para o
        Arduino pela serial para executar um comando.
        Dentre os comandos, pode-se Ligar ou Desligar
        os displays, imprimir um caractere, imprimir
        uma string, rolar um texto e inverter
        o texto impresso.
    
    
    Esta biblioteca usa a comunicação SPI para enviar
      os caracteres para o driver. Para mais informações,
      consulte a referência no site do Arduino
      ( http://arduino.cc/en/Reference/SPI )
  
    Conectar os pinos da seguinte maneira:
        Driver    Arduino
        SDI ..... MOSI (ex: 11 no UNO, 51 no Mega 2560)
        CLK ..... SCK (ex: 13 no UNO, 52 no Mega 2560)
        LE ...... 7 (definido pelo usuário)
        OE ...... 6 (definido pelo usuário)
        VCC ..... VIN
        GND ..... GND
*/


#include <SPI.h>
#include <AlphaNumericDisplay.h>

#define NUMBER_OF_DISPLAYS 2 //quantidade de displays usados em série

const byte LEpin = 7; //definição do pino LE
const byte OEpin = 6; //definição do pino OE

char data;

//criar a classe passando os pinos LE, OE e a quantidade de displays
AlphaNumericDisplay Display(LEpin, OEpin, NUMBER_OF_DISPLAYS);

//-----------------------------------------------------------------------

void setup(){
  Display.On(); //liga os displays
  Serial.begin(9600); //inicializa a serial para receber os comandos
  Serial.println("--- start ---");
}

//-----------------------------------------------------------------------

void loop(){
  if(Serial.available()) //espera um comando do usuário
  {
    data = Serial.read(); //lê o caractere enviado pelo usuário
    Serial.println(data); //escreve no Monitor Serial o caractere enviado
    
    //determina qual comando executar em função do caractere enviado
    //    (possíveis caracteres: . % # ^ ~ i z)
    //    (outros caracteres serão impressos no display)
    if(data == '.')
      Display.Clear(); //limpa os displays
    else if(data == '%')
      Display.Scroll("Teste", 500); //rola o texto "Teste"
    else if(data == '#')
      Display.Scroll("abcdefghijklmnopqrstuvwxyz1234567890", 500); //rola o texto
    else if(data == '^')
      Display.Off(); //desliga os displays
    else if(data == '~')
      Display.On(); //liga os displays
    else if(data == 'i')
      Display.Invert(false); //inverte os displays
    else if(data == 'z')
      Display.Print("GAF"); //imprime a string "GAF"
    else
      Display.Print(data); //imprime o caractere
  }
}


