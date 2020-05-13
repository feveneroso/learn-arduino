#include <TimerOne.h>


const byte interruptPin = 3; //usa interrupção do pino 3 
unsigned int hourmeter;      //acumula o tempo da função countTime

void setup() {

  Serial.begin(9600);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), startHourmeter, FALLING);
  Serial.println("Setup iniciado");
  
}

void loop() {

    if( digitalRead(interruptPin) ){
      stopHourmeter ();
    }
/*
  for (int i = 100; i > 0; i --){
    if( digitalRead(interruptPin) ){
      stopHourmeter ();
    }
    Serial.print("For executando >>> ");
    Serial.println(i);
    delay(500);
  }
*/
}

void startHourmeter (){
  Timer1.initialize(1000000);       //TIMER IRA EXECUTAR A CADA 1 SEGUNDO (PARAMETRO EM MICROSEGUNDOS)
  Timer1.attachInterrupt(countTime);
  Serial.println("Timer iniciado");
}

void stopHourmeter (){
  Timer1.stop();
  //Serial.println("Timer pausado");
}

void countTime() {

     static byte countSecond;
     countSecond++;
     //Serial.print("Contagem de segundos = "); // mostra no monitor o o valor do contador de segundos
     Serial.println(countSecond);
     if (countSecond > 59){
      hourmeter++;
      countSecond = 0;
      Serial.print("Horimetro (em minutos) = "); // mostra no monitor o o valor do horimetro em minutos
      Serial.println(hourmeter);
     }     
}

//teste ok 13/05/2020 15:25>
