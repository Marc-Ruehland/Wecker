// Methode wird aufgerufen wenn Interrupt pin ein Signal erhält, wenn dies zutrifft wird die Variable "alarm" wahr gesetzt
void aktivierenDesAlarms () {
  alarm = true;
}
// Methode um Parameter für Wecker aufzurufen
void stellenDesWeckers() {
   
  
  switch (postionWeckerStellen) {
    case 0: //Umgehung Doppelerkennung der Position des Joysticks
      if (oben == true) {
        bestatigtW = true;
        aendernDerPostionWeckerstellen();

      }
      break;



   


    case 1: // Stunde

      lcd.clear();
      lcd.print("Stunde: ");
      lcd.print(stundeW);


      if (rechts == true) {
        stundeW++;
      }
      if (links == true) {
        stundeW--;
      }
      if (stundeW > 23) {
        stundeW = 0;
      }
      if (stundeW < 0) {
        stundeW = 23;
      }
      ueberpreufeJoystick();
      if (oben == true) {
        bestatigtW = true;
        aendernDerPostionWeckerstellen();

      }
      break;




    case 2: // Minute
      lcd.clear();
      lcd.print("Minute: ");
      lcd.print(minuteW);


      if (rechts == true) {
        minuteW++;
      }
      if (links == true) {
        minuteW--;
      }
      if (minuteW > 59) {
        minuteW = 0;
      }
      if (minuteW < 0) {
        minuteW = 59;
      }
      ueberpreufeJoystick();
      if (oben == true) {
        bestatigtW = true;
      }
      aendernDerPostionWeckerstellen();
      break;

    case 3:
      setzenDesAlarms();
      break;
  }
}
// in dieser Methode wird positionWeckerStellen um 1 erhöht wodurch der nächste Schritt in "stellenDesWeckers" erreicht wird
void aendernDerPostionWeckerstellen() {
  if (bestatigtW == true) {
    postionWeckerStellen++;
    bestatigtW = false;
  }
}

// In dieser Methode wird mit den Werten von "stellenDesWeckers"
void setzenDesAlarms() {
  lcd.clear();
  //Variable Alarmtime
  DateTime alarmTime (2022, 1, 6, stundeW, minuteW, 0);
  rtc.setAlarm1(alarmTime + (-timezone), DS3231_A1_Hour); 
  lcd.print("Wecker gestellt");
  weckerStatus = true;
  delay(500);
  postionWeckerStellen = 0;
  unten = true;
  anzeigenAufLcd();

}

void ueberpruefeAlarm() {
  if (rtc.alarmFired(1)) {
    if (unten == true) {

      rtc.clearAlarm(1);
      lcd.clear();
      lcd.print("Alarm aus");
      alarm = false;
      anzeigeFunktion = true;
    }
  }
  // Überprüfen  ob Alarm aktiv und Alarmausgabe
  if (alarm == true) {
    tone(BUZZER, 2000);
    delay(100);
    noTone(BUZZER);
    delay(100);
    lcd.clear();
    lcd.print("Alarm! Alarm!");
    anzeigeFunktion =  false;


  }
}

void deaktivierenDesWeckers(){
 rtc.disableAlarm(1);
 lcd.print("Wecker");
  lcd.setCursor(0, 1);
  lcd.print("ausgeschaltet");
  weckerStatus = false;
  delay(250);
  unten = true;
  anzeigenAufLcd(); 
  
 }
