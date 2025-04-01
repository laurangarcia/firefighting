//---------------------------------------------------------
//Pines para sensor de linea 
//---------------------------------------------------------
const int sensorIzquierdo = A0; // Cambia A0 por el pin que estés usando
const int sensorDerecho = A1;

int sensorValueIzq = 0;
int sensorValueDer = 0;


//---------------------------------------------------------
//Pines para puente H L298N 
//---------------------------------------------------------
     
// Pines del L298N para el motor izquierdo
const int enA = 9;
const int in1 = 7;
const int in2 = 8;

// Pines del L298N para el motor derecho
const int enB = 10;
const int in3 = 5;
const int in4 = 6;
const int relePin = 2; // Pin para el módulo relé

//---------------------------------------------------------
//Pines del sensor ultrasonico 
//---------------------------------------------------------
const int trigPin = 11;  // Nuevo pin para el Trigger
const int echoPin = 12;  // Nuevo pin para el Echo
long duration;
int distance;
unsigned long intervaloMedicion = 50; // Tiempo entre mediciones en milisegundos
unsigned long tiempoAnterior = 0;     // Almacenará el tiempo de la última medición

void avanzar() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 250);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 250);
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
  analogWrite(enA, 200);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

// Función para girar a la derecha
void girarDerecha() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 200);
}

// Función para girar a la derecha
void girarIzquierda() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 200);
}

void distancia(){
  // Envía un pulso de 10µs al pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo que tarda en recibir el pulso en el pin Echo
  duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en cm (velocidad del sonido: 343 m/s)
  distance = duration * 0.034 / 2;

  // Muestra la distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
}

void setup() {
  // Iniciamos la comunicación serial
  Serial.begin(9600);

  //Definición de entradas y salidas   

  pinMode(sensorIzquierdo, INPUT);//Sensores de linea 
  pinMode(sensorDerecho, INPUT);

  pinMode(enA, OUTPUT);//motor izquierdo 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);//motor derecho 
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(trigPin, OUTPUT);    // Sensor ultrasonico 
  pinMode(echoPin, INPUT);     // 
}

void loop() {

  // lectura de los sensores de linea 
  sensorValueIzq = analogRead(sensorIzquierdo);
  Serial.println("valor sensor izquierdo"+String(sensorValueIzq));

  sensorValueDer = analogRead(sensorDerecho);
  Serial.println("valor sensor derecho"+String(sensorValueDer));

  //Lectura del sensor ultrasonico usando millis()
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervaloMedicion) {
    tiempoAnterior = tiempoActual; // Actualiza el tiempo de la última medición
    distancia();
  }

  // Si amabos sensores leen negro avanza 
  if (sensorValueIzq < 400 && sensorValueDer < 400) { // Ajusta este umbral según tu sensor
    avanzar();
    Serial.println("Ambos negros");
  }

  // Si el sensor izquierdo lee blanco retorcede y gira a la derecha
  else if (sensorValueIzq > 400 && sensorValueDer < 400) { // Ajusta este umbral según tu sensor
    reversa();
    delay(700);
    girarDerecha();
    delay(400);
    Serial.println("Blanco Negro");
  }
  // Si el sensor derecho lee blanco retorcede y gira a la izquierda
  else if (sensorValueIzq < 400 && sensorValueDer > 400) { // Ajusta este umbral según tu sensor
    detener();
    digitalWrite(relePin,HIGH);
    delay(4000);
    reversa();
    delay(700);
    girarIzquierda();
    delay(400);
    Serial.println("Negro Blanco");
  }

  // Si ambos sensores leen nergo retorcede y gira
  else if (sensorValueIzq > 400 && sensorValueDer > 400) { // Ajusta este umbral según tu sensor
    reversa();
    delay(700);
    girarIzquierda();
    delay(400);
    Serial.println("Ambos blancos");
  }
}