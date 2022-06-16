// System ähnlich wie beim Wecker, nur mehr Werte für die Zeit und Zeit wird geändert, statt Setzen eines Weckers
void einstellenDerZeit() {
  switch (uhre) {

    case 0:
      if (oben == true) {
        bestatigt = true;
        setzenDerZeit();

      }
      break;
    case 1: // jahr
      lcd.clear();
      lcd.print("Jahr: ");
      lcd.print(jahr);



      if (rechts == true) {
        jahr++;
      }
      if (links == true) {
        jahr--;
      }
      if (oben == true) {
        bestatigt = true;
      }
      setzenDerZeit();
      

      break;


    case 2: // monat
      lcd.clear();
      lcd.print("Monat: ");
      lcd.print(monat);
      if (rechts == true) {
        monat++;
      }
      if (links == true) {
        monat--;
      }
      if ( monat > 12) {
        monat = 1;
      }
      if ( monat < 1) {
        monat = 12;
      }
      if (oben == true) {
        bestatigt = true;
      }
      setzenDerZeit();
      // getTime();
      break;

    case 3:
      lcd.clear();
      lcd.print("Tag: ");
      lcd.print(tag);
      if (rechts == true) {
        tag++;
      }
      if (links == true) {
        tag--;
      }

      if (monat == 3) {
        monate = 0;
      }
      if (monat == 1) {
        monate = 0;
      }
      if (monat == 5) {
        monate = 0;
      }
      if (monat == 7) {
        monate = 0;
      }
      if (monat == 8) {
        monate = 0;
      }
      if (monat == 10) {
        monate = 0;
      }
      if (monat == 12) {
        monate = 0;
      }

      if (monat == 2) {
        monate = 1;
      }
      if (monat == 4) {
        monate = 2;
      }
      if (monat == 6) {
        monate = 2;
      }
      if (monat == 9) {
        monate = 2;
      }
      if (monat == 11) {
        monate = 2;
      }
      switch (monate) {
        case 0:
          if ( tag > 31) {
            tag = 1;
          }
          if ( tag < 1) {
            tag = 31;
          }
          break;
        case 1:
          if ( tag > 28) {
            tag = 1;
          }
          if ( tag < 1) {
            tag = 28;
          }
          break;

        case 2:
          if ( tag > 30) {
            tag = 1;
          }
          if (tag < 1) {
            tag = 30;
          }
          break;

      }

      if (oben == true) {
        bestatigt = true;
      }
      setzenDerZeit();
      break;



    case 4: // stunde
      lcd.clear();
      lcd.print("Stunde: ");
      lcd.print(stunde);


      if (rechts == true) {
        stunde++;
      }
      if (links == true) {
        stunde--;
      }
      if (stunde > 23) {
        stunde = 0;
      }
      if (stunde < 0) {
        stunde = 23;
      }
      if (oben == true) {
        bestatigt = true;
      }
      setzenDerZeit();
      // getTime();

      break;

    case 5: // minute
      lcd.clear();
      lcd.print("minute: ");
      lcd.print(minute);


      if (rechts == true) {
        minute++;
      }
      if (links == true) {
        minute--;
      }
      if (minute > 59) {
        minute = 0;
      }
      if (minute < 0) {
        minute = 59;
      }
      if (oben == true) {
        bestatigt = true;
      }
      setzenDerZeit();
      //  getTime();

      break;

    case 6: // sekunde
      lcd.clear();
      lcd.print("Sekunde: ");
      lcd.print(sekunde);


      if (rechts == true) {
        sekunde++;
      }
      if (links == true) {
        sekunde--;
      }
      if (sekunde > 59) {
        sekunde = 0;
      }
      if (sekunde < 0) {
        sekunde = 59;
      }
      if (oben == true) {
        bestatigt = true;
      }
      setzenDerZeit();
      // getTime();

      break;

    case 7:
      lcd.clear();
      lcd.print("Zeit eingestellt");
      delay(500);
      uhre = 0;
      unten = true;
      anzeigenAufLcd();

  }
}
void setzenDerZeit() {
  DateTime now =  rtc.now();
  if (bestatigt == true) {
    switch (uhre) {
      case 0:
        bestatigt = false;
        break;
       case 6:
        positionZeitzoneStellen = 1;
        timezone = 0;
        // mit den Werten von einstellenDerZeit wird die Zeit geändert
        rtc.adjust(DateTime(jahr , monat, tag, stunde, minute, sekunde));
        break;
    }
    bestatigt = false;
    uhre++;

  }
}
