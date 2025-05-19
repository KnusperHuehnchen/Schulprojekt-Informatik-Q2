//
// Created by Luka Hofmann on 21.04.25.
//
#ifndef MAIN_H
#define MAIN_H

#include <Adafruit_NeoPixel.h>
//pins
Adafruit_NeoPixel pixels(30, 3, NEO_GRB + NEO_KHZ800);
int button = 2;
int potiR = A0;
int potiG = A1;
int potiB = A2;

//millis
unsigned long previousMillis = 0; //überprüfen !!!
const long interval = 100; //überprüfen !!!

//variablen
int stay_on = 0;
int animation = 0;
int r = 30;
int l = 0;

void setup () {
    pixels.begin ();
    pinMode(button, INPUT_PULLUP);
    pinMode(potiR, INPUT);
    pinMode(potiG, INPUT);
    pinMode(potiB, INPUT);
}
void loop () {
    int red = analogRead(potiR)/4;
    int green = analogRead(potiG)/4;
    int blue = analogRead(potiB)/4;
    if (animation == 0) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            if (r >= 15) {
                pixels.setPixelColor(r, pixels.Color(red, green ,blue));
                r--;
            }
            if (l < 15) {
                pixels.setPixelColor(l, pixels.Color(red, green ,blue));
                l++;
            }
            pixels.show();
            if (r== 14 && l == 15) {
                animation = 1;
            }
        }
    }
    else {
        if (stay_on == 0) {
            if (analogRead(button) > 200){
                stay_on = 1;
            }
        }
        else {
            if (analogRead(button) > 200) {
                for (int i = 0; i < 30; i++) {
                    pixels.setPixelColor(i, pixels.Color(red, green, blue));
                }
                pixels.show();
            }
            else {
                pixels.clear();
                pixels.show();
            }
        }
    }
}
#endif //MAIN_H