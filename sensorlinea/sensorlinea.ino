// Definimos los pines de los sensores de línea
const int sensorPin1 = A0;  // Sensor de línea izquierdo
const int sensorPin2 = A1;  // Sensor de línea derecho

int sensorValue1 = 0;  // Variable para guardar la lectura del sensor izquierdo
int sensorValue2 = 0;  // Variable para guardar la lectura del sensor derecho

void setup() {
  // Iniciamos la comunicación serial para ver los resultados
  Serial.begin(9600);
  Serial.println("Iniciando prueba de sensores de línea...");
}

void loop() {
  // Leer los valores de los sensores de línea
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);

  // Imprimir los valores en el Monitor Serial
  Serial.print("Sensor Izquierdo: ");
  Serial.print(sensorValue1);
  Serial.print(" - ");
  Serial.println((sensorValue1 < 400) ? "Negro" : "Blanco");

  Serial.print("Sensor Derecho: ");
  Serial.print(sensorValue2);
  Serial.print(" - ");
  Serial.println((sensorValue2 < 400) ? "Negro" : "Blanco");

  // Pequeña pausa para evitar saturación del monitor
  delay(500);
}
