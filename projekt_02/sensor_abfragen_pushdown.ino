
int ledPin = 13;    // LED-Pin 13
int tasterPin = 8;  // Taster-Pin 8
int tasterStatus;   // Tasterstatus
  
void setup() {
  pinMode(ledPin, OUTPUT);    // LED-PIn als Ausgang
  pinMode(tasterPin, INPUT);  // Taster-Pin als Eingang
}


void loop() {
  tasterStatus = digitalRead(tasterPin);
  if (tasterStatus == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
