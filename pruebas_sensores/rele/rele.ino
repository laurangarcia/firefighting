
int relayPin = 3;

void setup() {
  pinMode (relayPin, OUTPUT) ;

}
void loop () {

  digitalWrite(relayPin, LOW);
  delay (8000);
  digitalWrite(relayPin, HIGH);
  delay(2000);

}