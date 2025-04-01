// Pines del L298N para el motor izquierdo
const int enA = 9;  // PWM para el motor izquierdo (ENA)
const int in1 = 7;  // Dirección 1 motor izquierdo (IN1)
const int in2 = 8;  // Dirección 2 motor izquierdo (IN2)

// Pines del L298N para el motor derecho
const int enB = 10; // PWM para el motor derecho (ENB)
const int in3 = 5;  // Dirección 1 motor derecho (IN3)
const int in4 = 6;  // Dirección 2 motor derecho (IN4)

void setup() {
  // Configurar los pines como salida
                          
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Iniciar comunicación serial (opcional)
  Serial.begin(9600);
  Serial.println("Iniciando prueba de dos motores...");
}

void loop() {
  avanzar();        // Ambos motores avanzan
  delay(8000);      // Avance durante 8 segundos

  detener();        // Detener ambos motores
  delay(4000);      // Pausa de 1 segundo

  retroceder();     // Ambos motores retroceden
  delay(8000);      // Retroceso durante 8 segundos

  detener();        // Detener nuevamente
  delay(4000);      // Pausa antes de repetir
}

// Función para avanzar ambos motores (IN1/IN3 = HIGH, IN2/IN4 = LOW)
void avanzar() {
  Serial.println("Avanzando...");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 180);  // Velocidad máxima motor izquierdo

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 180);  // Velocidad máxima motor derecho
}

// Función para retroceder ambos motores (IN1/IN3 = LOW, IN2/IN4 = HIGH)
void retroceder() {
  Serial.println("Retrocediendo...");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 180);  // Velocidad máxima motor izquierdo

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 180);  // Velocidad máxima motor derecho
}

// Función para detener ambos motores (todos los pines LOW)
void detener() {
  Serial.println("Deteniendo...");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  analogWrite(enA, 0);  // Apagar PWM motor izquierdo

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enB, 0);  // Apagar PWM motor derecho
}
