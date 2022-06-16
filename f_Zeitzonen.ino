// Aufruf der Methode für Einstellen der Zeitzone
void einstellenDerZeitzone() {
//wenn rechts wahr ist, wird  zur nächsten Zeitzone gewechselt, bei einer Überschreitung der Zeitzonen wird zur ersten Zeitzone gewechselt
  if (rechts == true) {
    positionZeitzoneStellen++;
    if ( positionZeitzoneStellen > 38) {
      positionZeitzoneStellen = 1;
    }
  }
  //wenn links wahr ist, wird  zur nächsten Zeitzone gewechselt, bei einer Unteschreitung der Zeitzonen wird zur letzten Zeitzone gewechselt
  if (links == true) {
    positionZeitzoneStellen--;
    if ( positionZeitzoneStellen < 1) {
      positionZeitzoneStellen = 38;
    }
  }

 // switch-case Anweisung in welcher die Zeitzoneninformationen enthalten sind
  switch (positionZeitzoneStellen) {
    //Erlärung auf alle Zeitzonen anwendbar
    case 1 : //MEZ hier Standardzeit
      // globale variable "timezone" dem Wert für die jeweilige  Zeitzone gegeben
      timezone = 0;
      lcd.clear();
      lcd.print("MEZ");
      //Aufruf der Methode "anzeigenUhrzeitDerZeitzonen", in welcher die Uhreit in Stunde und Minute angezeigt wird.
      anzeigenUhrzeitDerZeitzonen();
      break;


    case 23 : //UTC
      timezone = -3600L;
      lcd.clear();
      lcd.print("UTC ");
      anzeigenUhrzeitDerZeitzonen();
      break;

    case 2 : //LINT
      timezone = 13 * 3600L;
      lcd.clear();
      lcd.print("LINT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 3 : //CHADT
      timezone = 12.75 * 3600L;
      lcd.clear();
      lcd.print("CHADT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 4 ://ANAT
      timezone = 11 * 3600L;
      lcd.clear();
      lcd.print("ANAT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 5 ://AEDT

      timezone = 10 * 3600L;
      lcd.clear();
      lcd.print("AEDT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 6 ://ACDT
      timezone = 9.5 * 3600L;
      lcd.clear();
      lcd.print("ACDT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 7 ://AEST
      timezone = 9 * 3600L;
      lcd.clear();
      lcd.print("AEST");
      anzeigenUhrzeitDerZeitzonen();
      break;

    case 8 ://ACST
      timezone = 8.5 * 3600L;
      lcd.clear();
      lcd.print("ACST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 9 ://JST
      lcd.clear();
      timezone = 8 * 3600L;
      lcd.print("JST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 10: //ACWST
      timezone = 7.75 * 3600L;
      lcd.clear();
      lcd.print("ACWST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 11://CST
      timezone = 7 * 3600L;
      lcd.clear();
      lcd.print("CST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 12 : //WIB
      timezone = 6 * 3600L;
      lcd.clear();
      lcd.print("WIB");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 13 ://MMT
      timezone = 5.5 * 3600L;
      lcd.clear();
      lcd.print("MMT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 14 ://BST
      timezone = 5 * 3600L;
      lcd.clear();
      lcd.print("BST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 15 ://NPT
      timezone = 4.75 * 3600L;
      lcd.clear();
      lcd.print("NPT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 16 ://IST
      timezone = 4.5 * 3600L;
      lcd.clear();
      lcd.print("IST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 17 ://UZT
      timezone = 4 * 3600L;
      lcd.clear();
      lcd.print("UZT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 18 ://AFT
      timezone = 3.5 * 3600L;
      lcd.clear();
      lcd.print("AFT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 19 ://GST
      timezone = 3 + 3600L;
      lcd.clear();
      lcd.print("GST");
      anzeigenUhrzeitDerZeitzonen();
      break;

    case 20 ://IRST
      timezone = 2.5 * 3600L;
      lcd.clear();
      lcd.print("IRST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 21 ://MSK
      timezone = 2 * 3600L;
      lcd.clear();
      lcd.print("MSK");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 22 ://OEZ
      timezone = 3600L;
      lcd.clear();
      lcd.print("OEZ");
      anzeigenUhrzeitDerZeitzonen();
      break;

    case 24 ://GMT/UTC
      timezone = -3600L;
      lcd.clear();
      lcd.print("UTC/GMT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 25 ://CVT
      timezone = 2 * -3600L;
      lcd.clear();
      lcd.print("CVT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 26 ://GST
      timezone = 3 * -3600L;
      lcd.clear();
      lcd.print("GST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 27 ://ART
      timezone = 4 * -3600L;
      lcd.clear();
      lcd.print("ART");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 28 ://NST
      timezone = 4.5 * -3600L;
      lcd.clear();
      lcd.print("NST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 29 ://VET
      timezone = 5 * -3600L;
      lcd.clear();
      lcd.print("VET");
      anzeigenUhrzeitDerZeitzonen();

      break;
    case 30 ://EST
      timezone = 6 * -3600L;
      lcd.clear();
      lcd.print("EST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 31 ://CST
      timezone = 7 * -3600L;
      lcd.clear();
      lcd.print("CST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 32 ://MST
      timezone = 8 * -3600L;
      lcd.clear();
      lcd.print("MST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 33 ://PST
      timezone = 9 * -3600L;
      lcd.clear();
      lcd.print("PST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 34://AKST
      timezone = 10 * -3600L;
      lcd.clear();
      lcd.print("AKST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 35 ://MART
      timezone = 10.5 * -3600L;
      lcd.clear();
      lcd.print("MART");
      anzeigenUhrzeitDerZeitzonen();

      break;
    case 36 ://HST
      timezone = 11 * -3600L;
      lcd.clear();
      lcd.print("HST");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 37 ://NUT
      timezone = 12 * -3600L;
      lcd.clear();
      lcd.print("NUT");
      anzeigenUhrzeitDerZeitzonen();
      break;
    case 38 ://AoE
      timezone = 13 * -3600L;
      lcd.clear();
      lcd.print("AoE");
      anzeigenUhrzeitDerZeitzonen();
      break;
  }
}
//Prinzip gleich wie in Anzeige_der_Uhrzeit
void anzeigenUhrzeitDerZeitzonen() {
  
  DateTime now = rtc.now() + timezone;
  lcd.print(" ");
  if ( now.hour() < 10) {
    lcd.print("0");
  }
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  if ( now.minute() < 10) {
    lcd.print("0");
  }
  lcd.print(now.minute(), DEC);
  lcd.print(' ');

}
