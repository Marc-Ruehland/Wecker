// In dieser Methode erfolgt die Ausgabe auf das LCD
void anzeigenAufLcd() {
  // Überprüfung ob Alarm momentan nicht auslöst, wenn Auslösung erfolgt wird die restliche Anzeige gesperrt
  if (anzeigeFunktion == true) {
    // Zu Beginn aktiv, wodurch das Hauptmenü angezeigt wird, auch auf andere booleans des Menüs anwendbar   
    if (menu == true) {
      // Nach der jeweiligen Position wird die entsprechende Funktion ausgeführt
      if (rechts == true) {
        position++;
      }
      else if (links == true) {
        position--;
      }
      // Falls die Wert der Integer-Variabeln eine bestimmten Wert überschreitet oder unterschreitet wird dieser zum niedrigsten bzw. höchsten Wert gesetzt, Prinzip wird wiederholt angewendet
      if (position < 0) {
        position = 2;
      }
      if (position > 2) {
        position = 0;
      }
      // Falls eine Auswahl erfolgt, indem der Joystick nach oben bewegt wird, wird "menu" gesperrt und die Sperre von "unterMenu" aufgehoben
      if (oben == true) {
        unterMenu = true;
        menu = false;
      }
      //Hauptmenü
      switch (position) {
        case 0: //Uhrzeit
          lcd.clear();
          lcd.print("Uhrzeit");
          break;

        case 1: //Wecker
          lcd.clear();
          lcd.print("Wecker");
          break;

        case 2: //Einstellungen
          lcd.clear();
          lcd.print("Einstellungen");
          break;
      }

    }
    
    //In "unterMenu" wird zu der Auswahl die jeweilige Methode aufgerufen
    if (unterMenu == true) {
     //Falls zurückgekehrt wird, indem der Joystick nach unten bewegt wird, wird "unterMenu" gesperrt und die Sperre von "menu" aufgehoben
     if (unten == true) {
        unterMenu = false;
        postionWeckerStellen = 0;
        bestatigtW = false;
        menu = true;
      }
      switch (position) {
        case 0:
          lcd.clear();
          anzeigenDerUhrzeit();
          break;


        case 1:
          lcd.clear();
          unterMenu = false;
          weckermenu = true;
          oben = false;

          break;

        case 2:
          lcd.clear();
          unterMenu = false;
          einstellungsmenu
          = true;
          oben = false;
          break;
      }
    }
    // Einstellungmenü 
    if (einstellungsmenu == true) {
      if (rechts == true) {
        positionE++;
      }
      else if (links == true) {
        positionE--;
      }

      if (positionE < 0) {
        positionE = 2;
      }
      if (positionE > 2) {
        positionE = 0;
      }
      if (unten == true) {
        menu = true;
        einstellungsmenu = false;
        //  positionE = 3;
      }
      if (oben == true) {
        einstellungspunkt = true;
        einstellungsmenu = false;
      }
      switch (positionE) {

        case 0:
          //Einstellen der Uhrzeit
          lcd.clear();
          lcd.print("Zeitzonen");
          break;


        case 1:
          lcd.clear();
          lcd.print("Uhrzeit aendern");
          break;


        case 2:
          lcd.clear();
          lcd.print("Darkmode");
          break;

      }
    }
    //Einstellungspunkte wenn eine Einstellung ausgewählt wurde, wie die jeweilige Methode für diese hier aufgerufen
    if (einstellungspunkt == true) {
      if (unten == true) {
        einstellungsmenu = true;
        einstellungspunkt = false;
        uhre = 0;
        bestatigtW = false;

      }

      switch (positionE) {
        case 0:
          einstellenDerZeitzone();
          break;


        case 1:
          lcd.clear();
          einstellenDerZeit();
          break;


        case 2:
          lcd.clear();
          aendernDerHintergrundbeleuchtung();
          break;

      }
    }
     // Weckermenü
    if (weckermenu == true) {
      if (rechts == true) {
        positionW++;
      }
      else if (links == true) {
        positionW--;
      }

      if (positionW < 0) {
        positionW = 1;
      }
      if (positionW > 1) {
        positionW = 0;
      }
      if (unten == true) {
        menu = true;
        weckermenu = false;
        
      }
      if (oben == true) {
        weckerpunkt = true;
        weckermenu = false;
      }
      switch (positionW) {

        case 0:
          //Einstellen der Uhrzeit
          lcd.clear();
          lcd.print("Wecker stellen");
          break;


        case 1:
          lcd.clear();
          lcd.print("Wecker aus");
          break;

      }
    }
    //Weckerpunkte wenn eine Weckereinstellung ausgewählt wurde, wie die jeweilige Methode für diese hier aufgerufen
    if (weckerpunkt == true) {
      if (unten == true) {
        weckermenu = true;
        postionWeckerStellen = 0;
        weckerpunkt = false;
        bestatigtW = false;

      }

      switch (positionW) {
        case 0:
          stellenDesWeckers();
          break;


        case 1:
          lcd.clear();
          deaktivierenDesWeckers();
          break;

      }
    }  
  }
}
