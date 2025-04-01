const int sensorPin = 2;  // Pin donde está conectado el TCRT5000
const int ledPin = 13;    // LED integrado para indicar detección

void setup() {
  pinMode(sensorPin, INPUT); // Configura el pin del sensor como entrada
  pinMode(ledPin, OUTPUT);   // Configura el pin del LED como salida
  Serial.begin(9600);        // Inicia la comunicación serial para monitorear
}

void loop() {
  int sensorValue = digitalRead(sensorPin); // Lee el estado del sensor

  // Si el sensor detecta una superficie negra (poca reflexión), el valor será LOW
  if (sensorValue == LOW) {
    Serial.println("¡Línea negra detectada!"); // Imprime el mensaje en el Monitor Serial
    digitalWrite(ledPin, HIGH);                // Enciende el LED
  } else {
    Serial.println("Superficie clara detectada."); // Imprime el mensaje en el Monitor Serial
    digitalWrite(ledPin, LOW);                    // Apaga el LED
  }

  delay(200); // Retardo para evitar saturar el Monitor Serial
}
