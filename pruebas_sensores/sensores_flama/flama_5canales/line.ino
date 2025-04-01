int SensorPin1 = 2;    // Para el sensor D1, UTILIZAMOS LAS SEÑALES DIGITALES DEL SENSOR 
int SensorPin2 = 3;    // Para el sensor D2, UTILIZAMOS LAS SEÑALES DIGITALES DEL SENSOR 
int SensorPin3 = 4;    // Para el sensor D3, UTILIZAMOS LAS SEÑALES DIGITALES DEL SENSOR 
int SensorPin4 = 5;    // Para el sensor D4, UTILIZAMOS LAS SEÑALES DIGITALES DEL SENSOR 
int SensorPin5 = 6;    // Para el sensor D5, UTILIZAMOS LAS SEÑALES DIGITALES DEL SENSOR  
int AvisoPin = 7;      // Para avisar cuando se ha detectado fuego

void setup()
{
   Serial.begin(9600);
   //*** DECLARAMOS LOS PINES QUE VAMOS A UTILIZAR PARA RECIBIR LAS SEÑALES DEL SENSOR IR ****
   // EN NUESTRO CASO VAMOS A UTILIZAR LAS SALIDAS DIGITALES DEL SENSOR, SI QUEREMOS AFINAR O HACER DETERMINADAS ACCIONES SEGÚN EL GRADO DE CALOR QUE SE DETECTE
   // ENTONCES TENDREMOS QUE UTILIZAR LAS SALIDAS ANALÓGICAS Y TRATARLAS CON LAS ENTRADAS ANALÓGICAS DEL ARDUINO.
   pinMode(SensorPin1, INPUT);
   pinMode(SensorPin2, INPUT);
   pinMode(SensorPin3, INPUT);
   pinMode(SensorPin4, INPUT);
   pinMode(SensorPin5, INPUT);
   pinMode(AvisoPin, OUTPUT);
}

void loop()
{
   int Pin1 = digitalRead(SensorPin1); // Para recoger la señal del sensor 1
   int Pin2 = digitalRead(SensorPin2); // Para recoger la señal del sensor 2
   int Pin3 = digitalRead(SensorPin3); // Para recoger la señal del sensor 3
   int Pin4 = digitalRead(SensorPin4); // Para recoger la señal del sensor 4
   int Pin5 = digitalRead(SensorPin5); // Para recoger la señal del sensor 5
   int detectado = 0;  // Con esta variable controlamos lo que haremos si se detecta incendio

   // ****** Podriamos utilizar una sentencia lógia OR para controlar todos los pines y simplemente avisar de fuego, pero lo haremos por separado para indicar también donde está el fuego *******
   if (Pin1 == HIGH)  // Primer sensor sería como si usamos un reloj y marcará el fuego entre las 9 y 10
   {
      Serial.println("Detección a la izquierda");     // Esto es opcional si queremos saber que sensor es el que ha detectado fuego
      detectado = 1;                                  // Pasamos la variable de detección a 1 para hacer lo que determinemos
   }
   if (Pin2 == HIGH)  // Segundo sensor sería como si usamos un reloj y marcará el fuego entre 10 y 11
   {
      Serial.println("Detección a la izquierda");     // Esto es opcional si queremos saber que sensor es el que ha detectado fuego
      detectado = 2;                                  // Pasamos la variable de detección a 1 para hacer lo que determinemos
   }
   if (Pin3 == HIGH)  // Tercer sensor sería como si usamos un reloj y marcará el fuego entre 11 y 12
   {
      Serial.println("Detección de frente");          // Esto es opcional si queremos saber que sensor es el que ha detectado fuego
      detectado = 3;                                  // Pasamos la variable de detección a 1 para hacer lo que determinemos
   }
   if (Pin4 == HIGH)  // Curato sensor sería como si usamos un reloj y marcará el fuego entre 12 y 1
   {
      Serial.println("Detección a la derecha");       // Esto es opcional si queremos saber que sensor es el que ha detectado fuego
      detectado = 4;                                  // Pasamos la variable de detección a 1 para hacer lo que determinemos
   }
   if (Pin5 == HIGH)  // Quinto sensor sería como si usamos un reloj y marcará el fuego entre 1 y 2
   {
      Serial.println("Detección a la derecha");       // Esto es opcional si queremos saber que sensor es el que ha detectado fuego
      detectado = 5;                                  // Pasamos la variable de detección a 1 para hacer lo que determinemos
   }
}