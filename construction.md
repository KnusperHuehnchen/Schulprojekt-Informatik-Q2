# Aufbau

## Was benötigt wird

- Snare oder andere Trommel  
  &rarr; Fell muss abmontiert werden
- Obligatorisch ein ESP32 mit WIFI Funktionalität
<table>
  <tr>
    <td align="center">
      <img src="pictures/esp32%20C6%20pins.jpeg" alt="ESP32 C6 Pins" width="300"/>
    </td>
  </tr>
</table>

- Piezo Sensor
  &rarr; mit Tesafilm möglichst Richtung die Mitte des oberen Fells kleben

<table>
  <tr>
    <th>Piezo-Positionierung</th>
    <th>Piezo-Verkabelung</th>
  </tr>
  <tr>
    <td align="center">
      <img src="pictures/Piezo-Positionierung.jpeg" alt="Piezo-Positionierung" width="300"/>
    </td>
    <td align="center">
      <img src="pictures/Piezo-Verkabelung.jpeg" alt="Piezo-Verkabelung" width="300"/>
    </td>
  </tr>
</table>

<img src="pictures/Piezoelectric-Sensor-Pinout.jpg" alt="Piezoelectric Sensor Pinout" width="120"/>

- LED Streifen _(Länge muss im Code angegeben werden)_

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + Signal-Frequenz);

- <div style="display: flex; align-items: center;">
  <span>3 Potentiometer &rarr; für die Modi und die Farben</span>
  <img src="pictures/pot-pins.jpg" alt="Potentiometer Pins" width="80" style="margin-left: 12px;"/>
</div>

- <div style="display: flex; align-items: center;">
  <span>1 Taster</span>
  <img src="pictures/Taster.jpg" alt="Taster" width="80" style="margin-left: 12px;"/>
</div>

- Viele Jumper Kabel
- Optional: eine Steckplatine, damit man nicht löten muss
- Tesafilm oder Kleber  
  &rarr; zum Anbringen des LED Streifens und des Piezo Sensors

## Zum Aufbau

<table>
  <tr>
    <th>Schaltplan</th>
    <th>Beispiel Aufbau</th>
  </tr>
  <tr>
    <td align="center">
      <img src="pictures/Schaltplan-Aufbau.png" alt="Schaltplan Aufbau" width="300"/>
    </td>
    <td align="center">
      <img src="pictures/Beispiel-Physischer-Aufbau.jpeg" alt="Beispiel physischer Aufbau" width="300"/>
    </td>
  </tr>
</table>
