//
// Created by Luka Hofmann on 21.04.25.
//
#ifndef MAIN_H
#define MAIN_H

#include  <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(30, 3, NEO_GRB + NEO_KHZ800);
int button = 2;

unsigned long previousMillis = 0;
const long interval = 100;

int r = 30;
int l = 0;

void setup() {
    Serial.begin(9600);
    pixels.begin();
    pixels.clear();
    pixels.setBrightness(255);
    pinMode(button,INPUT_PULLUP);
}
void loop() {
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) { //diese wird nur einmal ausgeführt !
        previousMillis = currentMillis;

        if (r >= 15) {
            pixels.setPixelColor(r, pixels.Color(0, 0, 255));
            r--;
        }

        if (l < 15) {
            pixels.setPixelColor(l, pixels.Color(0, 0, 255));
            l++;
        }

        pixels.show();
    }
}
#endif //MAIN_H