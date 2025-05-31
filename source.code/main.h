//
// Created by Luka Hofmann on 21.04.25.
//
#ifndef MAIN_H
#define MAIN_H

#include <Adafruit_NeoPixel.h>
//pins
Adafruit_NeoPixel pixels(60, 3, NEO_GRB + NEO_KHZ800);
int piezo = 2;
int potiR = 4; //ESP32 4
int potiG = 5; //ESP32 5
int potiB = 6; //ESP32 6
int button = 11;

//millis
unsigned long previousMillis = 0;
const long interval = 100;

//variablen
int stay_on = 0;
int animation = 0;
int r = 60;
int l = 0;
int lever = 0;
int old = 1;
void setup () {
    pixels.begin ();
    pinMode(button, INPUT_PULLUP);
    pinMode(potiR, INPUT);
    pinMode(potiG, INPUT);
    pinMode(potiB, INPUT);
  Serial.begin(9600);
}
void loop () {
        int red = analogRead(potiR)/15;
        int green = analogRead(potiG)/15;
        int blue = analogRead(potiB)/15;
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
  switch (lever) {
    case 0:
      for (int i = 0; i < 60; i++) {
            pixels.setPixelColor(i, pixels.Color(0, 0, 255));
      }
      pixels.show();
      break;
    case 1:
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
            if (analogRead(piezo) > 200 && stay_on == 1){
               for (int i = 0; i < 60; i++) {
                   pixels.setPixelColor(i, pixels.Color(red, green, blue));
               }
               pixels.show();
            }
            else if (analogRead(piezo) < 200 && stay_on == 1){
                pixels.clear();
                pixels.show();
            }
      	    else if (analogRead(piezo) > 200 && stay_on == 0){
                for (int i = 0; i < 60; i++) {
                    pixels.setPixelColor(i, pixels.Color(red, green, blue));
                }
      	        stay_on = 1;
                pixels.show();
            }
        }
        break;
    case 2:
      for (int i = 0; i < 60; i++) {
      pixels.clear ();
      pixels.show();
     break;
      }
  }
}
#endif //MAIN_H