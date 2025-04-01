// Definición de pines
const int relePin = 2; // Pin para el módulo relé

void setup() {
  // Inicializa la comunicación serial
  Serial.begin(9600);

  // Configura el pin del relé como salida
  pinMode(relePin, OUTPUT);
}

void loop() {
  // Activa el relé
  digitalWrite(relePin, HIGH); // Activa el relé
  Serial.println("Relé activado");
  delay(3000); // Espera 3 segundos

  // Desactiva el relé
  digitalWrite(relePin, LOW); // Desactiva el relé
  Serial.println("Relé desactivado");
  delay(3000); // Espera 3 segundos
}
