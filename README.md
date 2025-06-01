# Schulprojekt-Informatik-Q2
# Q2 Projekt: Licht am Schlagzeug

## Projekt &nbsp;<img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white" /> <img src="https://img.shields.io/badge/ESP32-000000?style=for-the-badge&logo=espressif&logoColor=white" /> <img src="https://img.shields.io/badge/Adafruit_NeoPixel-00C3E6?style=for-the-badge&logo=adafruit&logoColor=white" /> <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />

Mein Ziel ist es, an meiner Snare einen voll funktionsfähigen LED-Streifen anzubringen. Der LED-Streifen soll mithilfe  
von 3 Potis ansteuerbar sein. Je ein Poti für eine Farbe. Diese Potis sind dennoch nur ein Bestandteil von 3 Modis.  
Es gibt 3 Modi:

1. **Lichtschlageffekt mit frei wählbarer Farbe**
2. **Dauerlicht ohne Effekte**
3. **Licht ist aus**

**Optional:**  <img src="https://img.shields.io/badge/Home_Assistant-41BDF5?style=for-the-badge&logo=home-assistant&logoColor=white" />

\- Mit Homeassistant verbinden (v.2) 

[→ Homeassistant Anleitung (homeassistant.integration/README.md)](homeassistant.integration/README.md)

---

## Das soll ich alles bei meinem Projekt gelernt haben

### Hardware

- LED-Streifen in C++ benutzen
- Sensoren, Schalter und Licht miteinander abstimmen

[→ Zur Bauanleitung (construction.md)](construction.md)

### Software  <img src="https://img.shields.io/badge/Arduino_IDE-00979D?style=for-the-badge&logo=arduino&logoColor=white" /> <img src="https://img.shields.io/badge/JetBrains-CLion-000000?style=for-the-badge&logo=clion&logoColor=white" /> <img src="https://img.shields.io/badge/PlatformIO-FF6600?style=for-the-badge&logo=platformio&logoColor=white" />

- Mit RGB programmieren
- GitHub zu erkunden
- via WLAN/Zigbee den ESP32 benutzen über Homeassistant (v.2)
- Vokabular von C++ (siehe unten)

---

## Gelerntes Vokabular (C++)

- **int**: Ganze Zahl (Datentyp)
- **unsigned long**: Ganze Zahl ohne Vorzeichen, für große Werte (z.B. Zeitmessung)
- **const**: Konstantenwert, der nicht verändert werden kann
- **void setup()**: Initialisierungsfunktion, wird einmal beim Start ausgeführt
- **void loop()**: Hauptprogrammschleife, läuft immer wieder
- **pinMode(PIN, MODE)**: Setzt den Modus eines Pins (INPUT, OUTPUT)
- **digitalRead(PIN)**: Liest digitalen Wert (HIGH/LOW) von einem Pin
- **analogRead(PIN)**: Liest analogen Wert (0-1023) von einem Pin
- **delay(ms)**: Wartet eine bestimmte Zeit in Millisekunden
- **Serial.begin(BAUDRATE)**: Startet serielle Kommunikation
- **if/else**: Bedingte Anweisungen
- **switch/case**: Mehrfachauswahl
- **for-Schleife**: Wiederholt Anweisungen mehrfach
- **Adafruit_NeoPixel**: Bibliothek zur Steuerung von LED-Streifen
- **setPixelColor()**: Setzt die Farbe einer LED
- **show()**: Überträgt die Farben auf den LED-Streifen
- **clear()**: Schaltet alle LEDs aus
- **millis()**: Gibt die vergangene Zeit seit Programmstart zurück
