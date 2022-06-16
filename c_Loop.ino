// konstant wiederholende Loop, mit Aufruf der einzelnen Methoden
void loop() {
  // Überprüfung ob Alarm des Weckers an ist
  ueberpruefeAlarm();
  // Überprüfung Position des Joysticks, um aktuelle Eingabe zu bekommen
  ueberpreufeJoystick();
  // Aufruf des Menüs um aktuelle Ausgabe zu bekommen
  anzeigenAufLcd();
  // Verzögerung um zu hohe Wiederholunsgrate auf LCD zu vermeiden, was zu Flackern wird
  delay(250);

}
