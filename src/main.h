//
// Created by Luka Hofmann on 21.04.25.
//
#ifndef MAIN_H
#define MAIN_H

#include  <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels(30, 3, NEO_GRB + NEO_KHZ800);
int button = 2;

void setup() {
    Serial.begin(9600);
    pixels.begin();
    pixels.clear();
    pixels.setBrightness(255);
    pinMode(button,INPUT_PULLUP);
    for (int i = 30; i >= 15; i--) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
        pixels.show();
        delay(100);
    }
    for (int i = 0; i < 15; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
        pixels.show();
        delay(100);
    }
    delay(2500);
}

#endif //MAIN_H
