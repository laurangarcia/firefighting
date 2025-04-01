//motor izquierdo
const int pwma=5;
const int ain2=6;
const int ain1=7;
//activa el controlador
const int stby=0;
//motor derecho
const int bin1=9;
const int bin2=10;
const int pwmb=11;
void setup() {
  pinMode(pwma,OUTPUT);
  pinMode(ain2,OUTPUT);
  pinMode(ain1,OUTPUT);
  pinMode(stby,OUTPUT);
  pinMode(bin1,OUTPUT);
  pinMode(bin2,OUTPUT);
  pinMode(pwmb,OUTPUT);

  //activar el controlador
  digitalWrite(stby,1);
}

void loop() {
  adelante(); //llamo la función
  analogWrite(pwma,255); //Defino su velocidd motor izquierdo
  analogWrite(pwmb,255) ;//Defino su velocidd motor derecho
  delay(5000);
  izquierda();
  analogWrite(pwma,255); //Defino su velocidd motor izquierdo
  analogWrite(pwmb,200); //Defino su velocidd motor derecho
  delay(5000);
  derecha();
  analogWrite(pwma,200); //Defino su velocidd motor izquierdo
  analogWrite(pwmb,255) ;//Defino su velocidd motor derecho
  delay(5000);
  detenido();
  analogWrite(pwma,0); //Defino su velocidd motor izquierdo
  analogWrite(pwmb,0); //Defino su velocidd motor derecho
  delay(5000);
  }

void adelante(){
  digitalWrite(ain2,0);//motor izquierdo
  digitalWrite(ain1,1);
  digitalWrite(bin1,1);//motor derecho
  digitalWrite(bin2,0);
}

void izquierda(){
  digitalWrite(ain2,1);//motor izquierdo atras
  digitalWrite(ain1,0);
  digitalWrite(bin1,1);//motor derecho delnte
  digitalWrite(bin2,0);
}
void derecha(){
  digitalWrite(ain2,0); // motor izquierdo adelante
  digitalWrite(ain1,1);
  digitalWrite(bin1,0); //motor izquierdo atrás
  digitalWrite(bin2,1);
}

void atras(){
  digitalWrite(ain2,1); // motor izquierdo atras
  digitalWrite(ain1,0);
  digitalWrite(bin1,0); //motor izquierdo atras
  digitalWrite(bin2,1);
}
void detenido(){
  digitalWrite(ain2,0); // motor izquierdo detenido
  digitalWrite(ain1,0);
  digitalWrite(bin1,0); //motor izquierdo detenido
  digitalWrite(bin2,0);
}