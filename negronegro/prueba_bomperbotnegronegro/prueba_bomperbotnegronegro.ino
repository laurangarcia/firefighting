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

// Pines del sensor ultrasónico (frontal)
const int trigPin = 12;
const int echoPin = 11;

// Variables para la distancia
long duracion;
int distancia;



void setup() {
  // Iniciamos la comunicación serial
  Serial.begin(9600);

   // Configuración de pines del sensor ultrasonico 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  


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
  analogWrite(enA, 140);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 140);
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
  analogWrite(enA, 140);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 140);
}

// Función para girar a la derecha
void girarDerecha() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 140);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 140);
}

// Función para girar a la derecha
void girarIzquierda() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 140);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 140);
}

int medirDistancia() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH);
  int distancia = duracion * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  return distancia;
}



void loop() {

  // variable para medir la distancia sel sensor ultrasonico
  distancia = medirDistancia();


  // Leemos el valor del sensor
  sensorValue1 = analogRead(sensorPin1);
  Serial.println("valor analogico"+String(sensorValue1));

  sensorValue2 = analogRead(sensorPin2);
  Serial.println("valor analogico"+String(sensorValue2));


  

  // Determinamos si el primer sensor es negro o blanco
  if (sensorValue1 < 400 && sensorValue2 < 400) { 
    if(distancia >=80){// Ajusta este umbral según tu sensor dice si los sensores de linea son negros y hay no hay obtaculo en mas de 80 cm avance
    avanzar();
    Serial.println("Ambos negros");
  }else{
    reversa();
    delay(700);
    girarIzquierda();
  }
  }

 


else if (sensorValue1 > 400 && sensorValue2 > 400) {
  if (distancia <=20){
    detener();
    Serial.println("Ambos blancos y hay un obstaculo en menos o igual a 30 cm");
    
  } else{
    reversa();
    delay(700);
    girarIzquierda();
    Serial.println("Ambos blancos");
  }
  // Ajusta este umbral según tu sensor 
    // Determinamos si el segundo sensor es negro o blanco
    
  
  }

}