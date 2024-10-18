#include <VarSpeedServo.h>

#define servoBase   3
#define servoAltura 4
#define servoAngulo 5
#define servoGarra  6

#define potBase    A0
#define potAltura  A1
#define potAngulo  A2
#define potGarra   A3

#define botao_trava     8
#define botao_destrava


VarSpeedServo base;
VarSpeedServo altura;
VarSpeedServo angulo;
VarSpeedServo garra;


int leitura_Base;
int valor_Base;
int leitura_altura;
int valor_altura;
int leitura_angulo;
int valor_angulo;
int leitura_garra;
int valor_garra;


int estado_trava, estado_destrava;
int anterior_trava = HIGH;
int anterior_destrava = HIGH;
boolean travado = false;

void setup(){
  pinMode(botao_trava, INPUT_PULLUP);
  pinMode(botao_destrava, INPUT_PULLUP);


  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
    

  base.attach(servoBase);
  altura.attach(servoAltura);
  angulo.attach(servoAngulo);
  garra.attach(servoGarra); 
}


void loop() {
 
  if (!travado) {
    leitura_Base = analogRead(potBase);
    valor_Base = map(leitura_Base, 0, 1023, 0, 180);
    base.slowmove(valor_Base, 30);
                          
  
    leitura_altura = analogRead(potAltura);
    valor_altura = map(leitura_altura, 0, 1023, 180, 0);
    altura.slowmove(valor_altura, 40);
    
    leitura_angulo = analogRead(potAngulo);
    valor_angulo = map(leitura_angulo, 0, 1023, 180, 0);
    angulo.slowmove(valor_angulo,40);
    
    leitura_garra = analogRead(potGarra);             
    valor_garra = map(leitura_garra, 0, 1023, 0, 50); 
    garra.slowmove(valor_garra, 40); 
  }

 
  estado_trava = digitalRead(botao_trava); 
  if (estado_trava != anterior_trava) {
     travado = true;
     digitalWrite(13, HIGH); 
  }
  anterior_trava = estado_trava;


  estado_destrava = digitalRead(botao_destrava); 
  if (estado_destrava != anterior_destrava) {
     travado = false;
     digitalWrite(13, LOW); 
  }
  estado_destrava = anterior_destrava;

}