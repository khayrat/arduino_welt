int tasterPin = 8;          // Taster-Pin 8
int tasterStatus;           // Variable zur Aufnahme des Tasterstatus
int prevTasterStatus = LOW; // Statusvariable für den Taster
int ledIndex = -1;          // Zählervariable - selektiert den Eintrag im Array 'leds'
int ledPins[] = {13, 10};   // Feld mit LED-Pins
int MAX_LEDS = 2;           // Anzahl der LEDS == Länge(ledPins)
int ledStatus = HIGH;

void setup() {
  for (int i = 0; i < MAX_LEDS; i++) {
      pinMode(ledPins[i], OUTPUT);   // LED-Pin als Ausgang
  }
  pinMode(tasterPin, INPUT);      // Taster-Pin als Eingang
}

void loop() {
  // Abfrage des Taster-Status
  tasterStatus = digitalRead(tasterPin);

  // Falls aktueller Stasterwert ungleich vorherigem Tasterwert
  if (tasterStatus != prevTasterStatus) {
    // Wurde der Taster gedrückt?
    if (tasterStatus == HIGH) {
      // selektiere nächste LED
      ledIndex++;
    }
  }
  
  prevTasterStatus = tasterStatus; // spreichern des aktuellen Tastenwertes

  // nur schreiben, wenn ledIndex auf gültigen Eintrag verweist
  if (ledIndex > -1 && ledIndex < MAX_LEDS) {
    digitalWrite(ledPins[ledIndex], ledStatus);
  }

  // wenn ledIndex das Ende des gültigen Bereichs erreicht
  if (ledIndex == MAX_LEDS-1) {
    ledIndex = -1;          // ledIndex zurücksetzen
    ledStatus = !ledStatus; // led toggeln
  }
}
