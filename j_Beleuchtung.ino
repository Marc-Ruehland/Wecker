 // In dieser Methode wird falls die Hintergrundbeleuchtung an ist diese ausgeschaltet und falls diese aus ist wird diese eingeschaltet
     void aendernDerHintergrundbeleuchtung() {
      if (digitalRead(HINTERGRUNDBELEUCHTUNG) == HIGH) {
    hell = 1;
  }
  if (digitalRead(HINTERGRUNDBELEUCHTUNG) == LOW) {
    hell = 0;
  }
  switch (hell) {
    case 1:
      // Beleuchtung wird ausgeschaltet
      digitalWrite(HINTERGRUNDBELEUCHTUNG, LOW);
      einstellungspunkt = false;
      lcd.print("Beleuchtung aus");
      delay(1000);
      einstellungsmenu = true;

      break;

    case 0:
      // Beleuchtung wird eingeschaltet
      digitalWrite(HINTERGRUNDBELEUCHTUNG, HIGH);
      einstellungspunkt = false;
      lcd.print("Beleuchtung ein");
      delay(1000);
      einstellungsmenu = true;

      break;
  }
}
 
