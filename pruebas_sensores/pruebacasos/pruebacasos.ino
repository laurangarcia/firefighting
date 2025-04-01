//definir los pines TRIg y ECHO 
const int trigPin = 11;
const int echoPin = 10;
const int trigPin = 8;
const int echoPin = 9;

long duration_Ad;
int distance_Ad;
long duration_AT;
int distance_AT;
void setup() {
  Serial.begin(9600);
  pinMode(trigDEL,OUTPUT);
  pinMode(trigATR,OUTPUT);
  pinMode(echoDEL,INPUT);
  pinMode(echoATR,INPUT);

 

}

void loop() {
  atras();
  adelante();



void atras(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Enviamos un pulso de 10 microsegundos en el pin Trig
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Convertimos la duración a distancia (en cm)
  distance = duration * 0.034 / 2;
  if(TR)
}

}
