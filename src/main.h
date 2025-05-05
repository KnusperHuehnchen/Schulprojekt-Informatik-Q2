//
// Created by Luka Hofmann on 21.04.25.
//
#ifndef MAIN_H
#define MAIN_H

#include  <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(30, 3, NEO_GRB + NEO_KHZ800);
int button = 2;
unsigned long previousMillis = 0; //überprüfen !!!
int animation = 0;
const long interval = 100; //überprüfen !!!
int r = 30;
int l = 0;

void setup () {
    pixels.begin ();
    pinMode(button, INPUT_PULLUP);
}

void loop () {
    if (animation == 0) {
        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= interval) {
            previousMillis = currentMillis;
            if (r >= 15) {
                pixels.setPixelColor(r, pixels.Color(0, 250, 0));
                r--;
            }
            if (l < 15) {
                pixels.setPixelColor(l, pixels.Color(0, 250, 0));
                l++;
            }
            pixels.show();
            if (r== 14 && l == 15) {
                animation = 1;
            }
        }
    }
    else {
        if (digitalRead(button) == 0) {
            for (int i = 0; i < 30; i++) {
                pixels.setPixelColor(i, pixels.Color(0, 255, 0));
            }
            pixels.show();
        }
        else {
            pixels.clear();
            pixels.show();
        }
    }
}
#endif //MAIN_H