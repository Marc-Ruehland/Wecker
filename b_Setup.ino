// Setup beim ersten Starten
void setup() {
  // Initialisierung von der LCD und des seriellen Monitors
  lcd.begin(16, 2);
  Serial.begin(9600);
#ifndef ESP8266
  while (!Serial); 
#endif
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
  //Für digitale Pins wird festgelegt ob sie als Output oder als Input dienen
  pinMode(HINTERGRUNDBELEUCHTUNG, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(CLOCK_INTERRUPT_PIN, INPUT_PULLUP);
  //Falls der Interrupt Pin ein Signal erhält wird die Funktion "aktivierenDesAlarms" aufgerufen
  attachInterrupt(digitalPinToInterrupt(CLOCK_INTERRUPT_PIN), aktivierenDesAlarms, FALLING);
  digitalWrite(HINTERGRUNDBELEUCHTUNG, HIGH);
  // Falls ein Alarm auftrat, während der Arduino aus war, wird dieser deaktiviert, um Fehler zu vermeiden
  rtc.clearAlarm(1);
  // Um den SQW Pin als Interrurpt zu nutzen muss das Rechtecksignal deaktiviert werden
  rtc.writeSqwPinMode(DS3231_OFF);
}
