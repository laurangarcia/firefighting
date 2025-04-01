// Definimos el pin donde está conectado el sensor
const int sensorPin1 = A0; // Cambia A0 por el pin que estés usando
const int sensorPin2 = A1;
int sensorValue1 = 0;
int sensorValue2 = 0;


// Pines del L298N para el motor izquierdo
const int enA = 9;
const int in1 = 7;
const int in2 = 8;

// Pines del L298N para el motor derecho
const int enB = 10;
const int in3 = 6;
const int in4 = 5;




void setup() {
  // Iniciamos la comunicación serial
  Serial.begin(9600);


    // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void avanzar() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
}

// Función para detener ambos motores
void detener() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

// Función para dar reversa
void reversa() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 150);
}

// Función para girar a la derecha
void girarDerecha(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);
}

// Función para girar a la derecha
void girarIzquierda() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 150);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 150);
}



void loop() {


  // Leemos el valor del sensor
  sensorValue1 = analogRead(sensorPin1);
  Serial.println("valor analogico"+String(sensorValue1));

  sensorValue2 = analogRead(sensorPin2);
  Serial.println("valor analogico"+String(sensorValue2));

  // Determinamos si el primer sensor es negro o blanco
  if (sensorValue1 < 400 && sensorValue2 < 400) { // Ajusta este umbral según tu sensor
    avanzar();
    Serial.println("Ambos negros");
  }

  // Determinamos si el segundo sensor es negro o blanco
  else if (sensorValue1 < 400 && sensorValue2 > 400) { // Ajusta este umbral según tu sensor
    reversa();
    delay(700);
    girarDerecha();
    Serial.println("Negro Blanco");
  }
  // Determinamos si el segundo sensor es negro o blanco
  else if (sensorValue1 > 400 && sensorValue2 < 400) { // Ajusta este umbral según tu sensor
    reversa();
    delay(700);
    girarIzquierda();
    Serial.println("Blanco Negro");
  }

  // Determinamos si el segundo sensor es negro o blanco
  else if (sensorValue1 > 400 && sensorValue2 > 400) { // Ajusta este umbral según tu sensor
    detener();
    delay(700);
    girarIzquierda();
    Serial.println("Ambos blancos");
  
  }

}