int ledPinBlink = 13;  // Rote Blink-LED-Pin 13
int ledPinTaster = 10;  // Gelbe Taster-LED-Pin 10
int tasterPin = 8;      // Taster-Pin 8
int tasterStatus;       // Variable zur Aufnahme des Tasterstatus
int interval = 2000;    // Intervalzeit (2 Sekunden)
unsigned long prev;     // Zeit-Variable
int ledStatus = LOW;    // Statusvariable für die Blink-LED
int prevTasterStatus = LOW;       // Statusvariable für den Taster
int zaehler = -1;  // Zählervariable

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

  // Falls aktueller Stasterwert ungleich vorherigem Tasterwert
  if (tasterStatus != prevTasterStatus) {
    // Wurde der Taster gedrückt?
    if (tasterStatus == HIGH) {
      // Zähler um EINS erhöhen
      zaehler++;
    }
  }
  
  prevTasterStatus = tasterStatus; // spreichern des aktuellen Tastenwertes

  // jeder 1.,3.,5. etc. Tastendruck bringt die LED zum Leuchten
  // jeder 2.,4.,6. etc. Tastendruck läßt die LED ausgehen
  if (zaehler % 2 == 0) {
    digitalWrite(ledPinTaster, HIGH);
  } else {
    digitalWrite(ledPinTaster, LOW);
  }
}
