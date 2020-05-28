#include <SoftwareSerial.h> 
 
const int pinoRX = 2; //PINO 2 (RX)
const int pinoTX = 3; //PINO 3 (TX)
const int pino1 = 12; //LIGA LAMPADA 1
const int pino2 = 11; //LIGA LAMPADA 2
int dadoBluetooth = 0; //VARIAVEL DO BLUETOOTH
 
SoftwareSerial bluetooth(pinoRX, pinoTX);
//O PINO 2 É O RX E O PINO 3 É O TX
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  bluetooth.begin(9600); //INICIALIZA A SERIAL DO BLUETOOTH
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  bluetooth.print("$"); //IMPRIME O CARACTERE
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
  pinMode(pino1, OUTPUT); //DEFINE O PINO COMO SAÍDA 1
  pinMode(pino2, OUTPUT); //DEFINE O PINO COMO SAÍDA 2
}
 
void loop(){
  
  if(bluetooth.available()){ 
       dadoBluetooth = bluetooth.read(); 
 
    if(dadoBluetooth == '1'){ //SE O VALOR RECEBIDO FOR IGUAL A 1, FAZ
      Serial.println("L1 LIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(pino1, HIGH); //LIGA O LED
    }
    if(dadoBluetooth == '0'){ //SE O VALOR RECEBIDO FOR IGUAL A 0, FAZ
      Serial.println("L1 DESLIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(pino1, LOW); //DESLIGA O LED
    }

       if(dadoBluetooth == '2'){ //SE O VALOR RECEBIDO FOR IGUAL A 2, FAZ
      Serial.println("L2 LIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(pino2, HIGH); //LIGA O LED
    }
    if(dadoBluetooth == '3'){ //SE O VALOR RECEBIDO FOR IGUAL A 3, FAZ
      Serial.println("L2 DESLIGADO"); //IMPRIME O TEXTO NA SERIAL
      digitalWrite(pino2, LOW); //DESLIGA O LED
    }
    
 }
}
