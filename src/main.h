//
// Created by Luka Hofmann on 21.04.25.
//
#ifndef MAIN_H
#define MAIN_H

#include <Adafruit_NeoPixel.h>
//pins
Adafruit_NeoPixel pixels(60, 3, NEO_GRB + NEO_KHZ800);
int piezo = 2; //Arduino A5
int potiR = 4; //Arduino A0
int potiG = 5; //Arduino A1
int potiB = 6; //Arduino A2
int button = 11;

//millis
unsigned long previousMillis = 0;
const long interval = 100;

//variablen
int stay_on = 0; // LED mit dem ersten Schlag aus
int animation = 0; //für die Start-Animation
int r = 60; //LED Position
int l = 0; //LED Position
int lever = 0; // Moduswechsel
int old = 1; // Flankenerkennung

void setup () {
  pixels.begin (); //Initialisiert die Hardware-Schnittstelle für die LEDs
  pinMode(button, INPUT_PULLUP);
  pinMode(piezo, INPUT);
  pinMode(potiR, INPUT);
  pinMode(potiG, INPUT);
  pinMode(potiB, INPUT);
  Serial.begin(9600);
}
void loop () {
  int red = analogRead(potiR)/15;
  int green = analogRead(potiG)/15;
  int blue = analogRead(potiB)/15;
  // MODUS WECHSEL
  if (digitalRead(button) == 0 && old == 1 && lever == 0) {
    lever ++;
    animation = 0;
    stay_on = 0;
    r = 60;
    l = 0;
  }
  else if (digitalRead(button) == 0 && old == 1 && lever == 1) {
    lever ++;
  }
  else if (digitalRead(button) == 0 && old == 1 && lever == 2) {
    lever = 0;
  }
  old = digitalRead(button);
  // MODIS
  switch (lever) {
    case 0:
      if (animation == 0) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
          previousMillis = currentMillis;
          if (r >= 30) {
            pixels.setPixelColor(r, pixels.Color(red, green ,blue));
            r--;
          }
          if (l < 30) {
            pixels.setPixelColor(l, pixels.Color(red, green ,blue));
            l++;
          }
          pixels.show();
          if (r== 29 && l == 30) {
            animation = 1;
          }
        }
      }
      else {
        if (analogRead(piezo) < 200 && stay_on == 0){
          for (int i = 0; i < 60; i++) {
            pixels.setPixelColor(i, pixels.Color(red, green, blue));
          }
          pixels.show();
        }
        else if (analogRead(piezo) > 200 && stay_on == 0){
          pixels.clear();
          pixels.show();
          stay_on = 1;
        }
        else if (analogRead(piezo) > 200 && stay_on == 1){
          for (int i = 0; i < 60; i++) {
            pixels.setPixelColor(i, pixels.Color(red, green, blue));
          }
          pixels.show();
        }
        else if (analogRead(piezo) < 200 && stay_on == 1){
          pixels.clear();
          pixels.show();
        }
      }
    break;
    case 1:
      for (int i = 0; i < 60; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
      }
      pixels.show();
      break;
    case 2:
      for (int i = 0; i < 60; i++) {
        pixels.clear ();
        pixels.show();
      }
      break;
  }
  Serial.println(analogRead(piezo));
}
#endif //MAIN_H