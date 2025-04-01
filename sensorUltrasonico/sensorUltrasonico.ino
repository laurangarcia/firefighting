const int trigPin = 11;  // Pin para el Trigger
const int echoPin = 12; // Pin para el Echo

unsigned long intervaloMedicion = 50; // Tiempo entre mediciones en milisegundos
unsigned long tiempoAnterior = 0;     // Almacenará el tiempo de la última medición

void setup() {
  Serial.begin(9600);        // Inicia la comunicación serie
  pinMode(trigPin, OUTPUT);   // Configura el pin Trig como salida
  pinMode(echoPin, INPUT);    // Configura el pin Echo como entrada
}

void loop() {
  // Verifica si ha pasado el intervalo deseado para medir la distancia
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior >= intervaloMedicion) {
    tiempoAnterior = tiempoActual; // Actualiza el tiempo de la última medición

    int distancia = medirDistancia();
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
  }

  // Aquí puedes agregar otras funciones del robot sin detener el código
}

// Función para medir la distancia con el sensor ultrasónico
int medirDistancia() {
  long duracion;
  int distancia;

  // Envía un pulso de 10µs al pin Trig
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo que tarda en recibir el pulso en el pin Echo
  duracion = pulseIn(echoPin, HIGH);

  // Calcula la distancia en cm (velocidad del sonido: 343 m/s)
  distancia = duracion * 0.034 / 2;

  return distancia;
}
