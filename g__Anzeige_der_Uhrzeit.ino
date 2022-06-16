void anzeigenDerUhrzeit() {
  //Zeit die "now" zugeordnet wird ist die der RTC plus der Zeitzone
  DateTime now = rtc.now() + timezone;
  //0 wird hinzugefügt,da sonst wenn Stunde kleiner 10, nichts ansprechendes  Layout der Uhr 
  if ( now.hour() < 10) {
    lcd.print("0");
  }
  //Stunde wird auf LCD angezeigt
  lcd.print(now.hour(), DEC);
  lcd.print(':');
   //0 wird hinzugefügt,da sonst wenn Stunde kleiner 10, nichts ansprechendes  Layout der Uhr 
  if ( now.minute() < 10) {
    lcd.print("0");
  }
  //Minute wird auf LCD angezeigt
  lcd.print(now.minute(), DEC);
  lcd.print(' ');
  //Wochentag wird auf LCD angezeigt
  lcd.print(wochentage[now.dayOfTheWeek()]);
  lcd.setCursor(0, 1);
  // Temperatur der RTC wird auf LCD angezeigt
  lcd.print(rtc.getTemperature());
  lcd.print(" C");
  // Überprüfung ob Wecker gestellt ist, wenn ja wird ein "W" angezeigt auf der LCD
  if (weckerStatus == true) {
  lcd.print("      W");

  }
}
