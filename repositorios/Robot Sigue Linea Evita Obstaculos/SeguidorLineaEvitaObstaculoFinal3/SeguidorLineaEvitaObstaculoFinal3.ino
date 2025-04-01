/* 
Programa: Robot Seguidor de Linea - Evita Obstaculos
Autor:  Humberto Higinio
Canal de Youtube: https://www.youtube.com/user/HHSolis
Video Exclusivo para mi canal de Youtube
Todos los Derechos Reservados - 2019
Código de Dominio Público
*/

#include<NewPing.h>

// Se definen conexiones de los motores al Motor Driver
// Se reserva el pin 3 PWM para el Speach de Arduino

// Motor A - Derecho
int ENA = 10;  // ENA connectado al pin digital 10
int IN1 = 4; // connectado al ping digital 4
int IN2 = 5; // connectado al ping digital 5


// Motor B - Izquierdo
int ENB = 9;  // ENB connectado al pin digital 9
int IN3 = 6; // connectado al ping digital 6
int IN4 = 7; // connectado al ping digital 7

// Se definen conexiones de los sensores infrarojos a los puertos Analogicos

int RIGHT = A0; // Sensor Derecho connectado al pin analogico A0
int LEFT = A1;  // Sensor Izquierdo connectado al pin analogico A1

// Se definen conexiones del Sensor HC-SR04 con Arduino

#define TRIG A2 // PIN TRIGGER connectado al pin analogico A2
#define ECHO A3 // PIN ECHO conectado al pin analogico A3
#define MAX_DISTANCE 100 // Define la Maxima Distancia

NewPing sonar(TRIG, ECHO, MAX_DISTANCE); 

void setup() {

// Se inicializan los pines como Entradas o Salidas

pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT); 
pinMode(IN1, OUTPUT); 
pinMode(IN2, OUTPUT); 
pinMode(IN3, OUTPUT); 
pinMode(IN4, OUTPUT); 
pinMode(RIGHT, INPUT); 
pinMode(LEFT, INPUT);  

}

void loop() {
    
delay(70);
int distance = sonar.ping_cm();
if (distance == 0) {
  distance = 30;
}
if(distance <=15) {   // Se define la distancia para detectar un obstaculo y las acciones a tomar
  Stop();
  delay(100);
  turnRight();
  delay(580);
  moveForward();
  delay(450);
  turnLeft();
  delay(550);
  moveForward();
  delay(700);
  turnLeft();
  delay(500);
  moveForward();
  delay(480);
  turnRight();
  delay(500);
 
}
if (analogRead(RIGHT)<=35 && analogRead(LEFT)<=35) {  // en el Centro de la linea negra avanza de Frente  
  analogWrite(ENA, 80);  // Setea la velocidad a 80 en el rango posible de 0~255
  analogWrite(ENB, 80);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}else if (analogRead(RIGHT)<=35 && !analogRead(LEFT)<=35) {  // a la derecha de la linea girar a la Izquierda
  analogWrite(ENA,80);
  analogWrite(ENB, 80);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

}else if (!analogRead(RIGHT)<=35 && analogRead(LEFT)<=35) {  // a la izquierda de la linea girar a la Derecha
  analogWrite(ENA, 80);
  analogWrite(ENB, 80);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}else if (!analogRead(RIGHT)<=35 && !analogRead(LEFT)<=35) {   // ambos en la linea negra se detiene
 
  Stop();
}

}
void Stop() {  // Detiene los motores 
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnRight() {   // Gira a la derecha
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
}

void turnLeft() {    // Gira a la izquierda
  analogWrite(ENA,100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveForward() {    // Avanza de frente
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
