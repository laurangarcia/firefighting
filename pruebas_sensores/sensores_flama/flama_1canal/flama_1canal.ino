const int llama= 3;
const int Beep = 11;
const int led =13;
int valor =1;
void setup()
{    Serial.begin(9600);
    pinMode(Beep, OUTPUT);
    pinMode(led, OUTPUT);
    pinMode(llama, INPUT);

}
void loop()
{
    valor = analogRead(llama);
    Serial.println(valor);
    if (valor == 0) 
    {
       analogWrite(Beep, HIGH);
       analogWrite(led, HIGH);
    }
    else
    {
        
      analogWrite(Beep, LOW);
            analogWrite(led, LOW);

    }
    delay(50);
}
