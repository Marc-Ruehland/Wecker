// Überprüfen der Position des Joysticks  und dementsprechendes  verändern der entsprechenden Variable
void ueberpreufeJoystick() {
  //Variabeln für X und Y werden dem Wert der jeweiligen Postion des Joysticks zugeordnet
  int xAchse = (analogRead(XPIN));
  int yAchse = (analogRead(YPIN));
  //nach oben
  if (xAchse > 900) {
    oben = true;
    unten = false;
    rechts = false;
    links = false;
    return;
  }

  //nach unten, falls ein Grenzwert  überschritten wird und Abbruch der Methode, falls dies zutrifft
  else if (xAchse < 100) {
    oben = false;
    unten = true;
    rechts = false;
    links = false;
    return;
  }
  //nach rechts, falls ein Grenzwert  überschritten wird und Abbruch der Methode, falls dies zutrifft
  else if (yAchse > 900) {
    oben = false;
    unten = false;
    rechts = true;
    links = false;
    return;
  }
  // nach links, falls ein Grenzwert  überschritten wird und Abbruch der Methode, falls dies zutrifft
  else if (yAchse < 100) {
    oben = false;
    unten = false;
    rechts = false;
    links = true;
    return;
  }
  // falls kein Grenzwert für eine Richtung überschritten wird, wird alles Falsch gesetzt und abgebrochen
  else {
    oben = false;
    unten = false;
    rechts = false;
    links = false;
    return;
  }
}
