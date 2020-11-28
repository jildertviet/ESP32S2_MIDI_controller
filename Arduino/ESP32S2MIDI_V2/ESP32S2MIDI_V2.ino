#include "Arduino.h"
#include "midiusb.h"
#include "WiFi.h"
#include <SimpleKalmanFilter.h>

MIDIusb midi;

char adcPins[5] = {5, 4, 3, 2, 1};
char prevCC[5];

SimpleKalmanFilter* filters[5];

long refresh_time; // Temp
bool bTest;

void setup() {
  WiFi.mode( WIFI_OFF );

  Serial.begin(115200);
  Serial.println("Setup");
  midi.begin();
  delay(500);
  for (int i = 0; i < 5; i++) {
    pinMode(adcPins[i], INPUT);
    filters[i] = new SimpleKalmanFilter(0.1, 0.1, 0.01);
    prevCC[i] = 0;
  }
}

void loop() {
  for (int i = 0; i < 5; i++) {
    float value = filters[i]->updateEstimate(analogRead(adcPins[i]) / 1600.0);
    char cc = value * 128;
    if(prevCC[i] != cc)
      midi.controlChange(i, cc, 0);
    prevCC[i] = cc;
  }
}
