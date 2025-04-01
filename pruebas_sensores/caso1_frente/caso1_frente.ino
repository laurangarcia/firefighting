// Pines del sensor ultrasónico (frontal)
const int trigPin = 12;
const int echoPin = 11;

// Pines del L298N para el motor izquierdo
const int enA = 9;
const int in1 = 8;
const int in2 = 7;

// Pines del L298N para el motor derecho
const int enB = 10;
const int in3 = 6;
const int in4 = 5;

// Variables para la distancia
long duracion;
int distancia;

void setup() {
  // Configuración de pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Inicialización de comunicación serial
  Serial.begin(9600);
  Serial.println("Iniciando robot evasor...");
}

void loop() {
  distancia = medirDistancia();  // Medir la distancia del obstáculo al frente

  if (distancia > 30) {
    avanzar();  // Si no hay obstáculos cerca, avanzar
  } else {
    detener();  // Si hay un obstáculo al frente, detenerse
    girarHastaRutaLibre();  // Intentar girar hasta encontrar una ruta libre
  }

  delay(100);  // Pausa breve para estabilidad
}

// Función para medir la distancia con el sensor ultrasónico
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

// Función para avanzar ambos motores
void avanzar() {
  Serial.println("Avanzando...");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 255);  // Velocidad máxima motor izquierdo

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);  // Velocidad máxima motor derecho
}

// Función para detener ambos motores
void detener() {
  Serial.println("Deteniendo...");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);
}

// Función para girar hasta encontrar una ruta libre
void girarHastaRutaLibre() {
  Serial.println("Girando hasta encontrar una ruta libre...");
  
  while (medirDistancia() <= 30) {  // Mientras haya un obstáculo
    girarDerecha();  // Girar a la derecha para evitar el obstáculo
    delay(500);  // Esperar medio segundo antes de medir de nuevo
  }

  detener();  // Detenerse una vez que se encuentre una ruta libre
}

// Función para girar a la derecha
void girarDerecha() {
  Serial.println("Girando a la derecha...");
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 150);  // Velocidad media motor izquierdo

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 150);  // Velocidad media motor derecho
}
