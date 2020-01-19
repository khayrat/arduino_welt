int ledPinBlink = 13;  // Rote Blink-LED-Pin 13
int ledPinTaster = 10;  // Gelbe Taster-LED-Pin 10
int tasterPin = 8;      // Taster-Pin 8
int tasterStatus;       // Variable zur Aufnahme des Tasterstatus
int interval = 2000;    // Intervalzeit (2 Sekunden)
unsigned long prev;     // Zeit-Variable
int ledStatus = LOW;    // Statusvariable für die Blink-LED


void setup() {
  pinMode(ledPinBlink, OUTPUT);   // Blink-LED-Pin als Ausgang
  pinMode(ledPinTaster, OUTPUT);  // Tast-LED-Pin als Ausgang
  pinMode(tasterPin, INPUT);      // Taster-Pin als Eingang
  prev = millis();                // jetzigen Zeitstempel merken
}

void loop() {
  // Blink-LED über Intervalsteuerung blinken lassen
  if ((millis() - prev) > interval) {
    prev = millis();
    ledStatus = !ledStatus; // Toggeln des LED-Status
    digitalWrite(ledPinBlink, ledStatus);
  }

  // Abfrage des Taster-Status
  tasterStatus = digitalRead(tasterPin);
  if (tasterStatus == HIGH) {
    digitalWrite(ledPinTaster, HIGH);
  } else {
    digitalWrite(ledPinTaster, LOW);
  }
}
