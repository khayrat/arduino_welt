int ledPinBlink = 13;  // Rote Blink-LED-Pin 13
int ledPinTaster = 10;  // Gelbe Taster-LED-Pin 10
int tasterPin = 8;      // Taster-Pin 8
int tasterStatus;       // Variable zur Aufnahme des Tasterstatus
int interval = 2000;    // Intervalzeit (2 Sekunden)
unsigned long prev;     // Zeit-Variable
int ledStatus = LOW;    // Statusvariable für die Blink-LED
int prevTasterStatus = LOW;       // Statusvariable für den Taster
int ledTasterStatus = LOW;  // Statusvariable für die Taster-LED

void setup() {
  pinMode(ledPinBlink, OUTPUT);   // Blink-LED-Pin als Ausgang
  pinMode(ledPinTaster, OUTPUT);  // Tast-LED-Pin als Ausgang
  pinMode(tasterPin, INPUT);      // Taster-Pin als Eingang
  prev = millis();                // jetzigen Zeitstempel merken

  Serial.begin(9600);
  for (int i = 0; i < 7; i++) {
    Serial.println(i);
  }
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
    // taster pressed
    if (tasterStatus == prevTasterStatus) {
      // still pressing - do nothing
    } else {
      // taster is pressed first time - toggle led
      ledTasterStatus = !ledTasterStatus;
      // mark as pressed
      prevTasterStatus = HIGH;
    }
  } else {
    prevTasterStatus = LOW;
  }
  
  digitalWrite(ledPinTaster, ledTasterStatus);
}
