//Einbindung der Bibliotheken
#include "RTClib.h"
#include <LiquidCrystal.h>
// Zuweisung Steckplätze
RTC_DS3231 rtc;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
const int XPIN = 0; 
const int YPIN = 1; 
const int BUZZER = 3;
const int HINTERGRUNDBELEUCHTUNG = 5;
#define CLOCK_INTERRUPT_PIN 2

// Variablen Menü
bool anzeigeFunktion = true;
bool menu = true;  
int position = 0;
int positionE = 0;
int positionW = 0;
bool unterMenu = false;
bool einstellungsmenu = false;
bool einstellungspunkt = false;
bool weckermenu = false;
bool weckerpunkt = false;


//Variablen für das Einstellen des Weckers
bool alarm = false;
bool bestatigtW = false; 
int stundeW = 1;
int minuteW = 0;
int postionWeckerStellen = 0;
bool weckerStatus = false;


//Variablen für das Ändern der Zeitzone 
long timezone = 0L;
int positionZeitzoneStellen = 1;

//Variablen für das einstellen der Zeit
bool bestatigt = false;
int jahr = 2020;
int monate = 0;
// Hilfsvariable zur Bestimmung der Monatsdauer
int monat = 1;
int tag = 1;
int stunde = 1;
int minute = 0;
int sekunde = 0;
int uhre = 0;

//Variablen Zeit für Zeitdarstellung 
char wochentage[7][12] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};

//Variablen für Steuerung
bool oben = false;
bool unten = false;
bool rechts = false;
bool links = false;
// Variable für das ändern der Hintegrundbeleuchtung
int hell;
