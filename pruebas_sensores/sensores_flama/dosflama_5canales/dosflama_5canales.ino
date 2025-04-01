// Pines para el primer sensor de flama de 5 canales (Sensor 1)
int Sensor1Pin1 = 2;    
int Sensor1Pin2 = 3;    
int Sensor1Pin3 = 4;    
int Sensor1Pin4 = 5;    
int Sensor1Pin5 = 6;    

// Pines para el segundo sensor de flama de 5 canales (Sensor 2)
int Sensor2Pin1 = 7;    
int Sensor2Pin2 = 8;    
int Sensor2Pin3 = 9;    
int Sensor2Pin4 = 10;   
int Sensor2Pin5 = 11;   

int AvisoPin = 13;      // Para avisar cuando se ha detectado fuego (LED o buzzer)

void setup() {
   Serial.begin(9600);

   // Configurar los pines del primer sensor de flama como entradas
   pinMode(Sensor1Pin1, INPUT);
   pinMode(Sensor1Pin2, INPUT);
   pinMode(Sensor1Pin3, INPUT);
   pinMode(Sensor1Pin4, INPUT);
   pinMode(Sensor1Pin5, INPUT);
   
   // Configurar los pines del segundo sensor de flama como entradas
   pinMode(Sensor2Pin1, INPUT);
   pinMode(Sensor2Pin2, INPUT);
   pinMode(Sensor2Pin3, INPUT);
   pinMode(Sensor2Pin4, INPUT);
   pinMode(Sensor2Pin5, INPUT);

   // Pin de aviso
   pinMode(AvisoPin, OUTPUT);
}

void loop() {
   int detectado = 0;  // Variable para saber si algún sensor detectó fuego

   // Leer sensores del primer sensor de flama (Sensor 1)
   int Pin1_S1 = digitalRead(Sensor1Pin1);
   int Pin2_S1 = digitalRead(Sensor1Pin2);
   int Pin3_S1 = digitalRead(Sensor1Pin3);
   int Pin4_S1 = digitalRead(Sensor1Pin4);
   int Pin5_S1 = digitalRead(Sensor1Pin5);
   
   // Leer sensores del segundo sensor de flama (Sensor 2)
   int Pin1_S2 = digitalRead(Sensor2Pin1);
   int Pin2_S2 = digitalRead(Sensor2Pin2);
   int Pin3_S2 = digitalRead(Sensor2Pin3);
   int Pin4_S2 = digitalRead(Sensor2Pin4);
   int Pin5_S2 = digitalRead(Sensor2Pin5);

   // Verificar las detecciones de ambos sensores

   // Sensor 1 detección
   if (Pin1_S1 == HIGH) {
      Serial.println("Detección a la izquierda (Sensor 1, Canal 1)");
      detectado = 1;
   }
   if (Pin2_S1 == HIGH) {
      Serial.println("Detección a la izquierda (Sensor 1, Canal 2)");
      detectado = 1;
   }
   if (Pin3_S1 == HIGH) {
      Serial.println("Detección de frente (Sensor 1, Canal 3)");
      detectado = 1;
   }
   if (Pin4_S1 == HIGH) {
      Serial.println("Detección a la derecha (Sensor 1, Canal 4)");
      detectado = 1;
   }
   if (Pin5_S1 == HIGH) {
      Serial.println("Detección a la derecha (Sensor 1, Canal 5)");
      detectado = 1;
   }

   // Sensor 2 detección
   if (Pin1_S2 == HIGH) {
      Serial.println("Detección a la izquierda (Sensor 2, Canal 1)");
      detectado = 1;
   }
   if (Pin2_S2 == HIGH) {
      Serial.println("Detección a la izquierda (Sensor 2, Canal 2)");
      detectado = 1;
   }
   if (Pin3_S2 == HIGH) {
      Serial.println("Detección de frente (Sensor 2, Canal 3)");
      detectado = 1;
   }
   if (Pin4_S2 == HIGH) {
      Serial.println("Detección a la derecha (Sensor 2, Canal 4)");
      detectado = 1;
   }
   if (Pin5_S2 == HIGH) {
      Serial.println("Detección a la derecha (Sensor 2, Canal 5)");
      detectado = 1;
   }

   // Si se detecta fuego en cualquier sensor, activar el aviso (LED o buzzer)
   if (detectado > 0) {
      digitalWrite(AvisoPin, HIGH);  // Activar aviso
      delay(1000);  // Mantener el aviso encendido por 1 segundo
      digitalWrite(AvisoPin, LOW);   // Apagar aviso
   }

   delay(500);  // Espera de 500ms antes de volver a leer los sensores
}
