#include "Arduino.h"
#include "midiusb.h"
#include "WiFi.h"
#include <SimpleKalmanFilter.h>

#define MULTI_DEPTH 300

MIDIusb midi;

char adcPins[5] = {5, 4, 3, 2, 1};
char prevCC[5];

int multisampling[5][MULTI_DEPTH];
int multisamplingWritePos = 0;
SimpleKalmanFilter* filters[5];
bool bBufferFilled = false; // Set this after the buffer is filled for the first time

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
    for (int j = 0; j < MULTI_DEPTH; j++) {
      multisampling[i][j] = 0;
    }
  }
}

void loop() {
//  bool bUpdate = false;
//  if (millis() > refresh_time) {
//    bUpdate = true;
//  }

  for (int i = 0; i < 5; i++) {
//    multisampling[i][multisamplingWritePos] = analogRead(adcPins[i]);

    float value = filters[i]->updateEstimate(analogRead(adcPins[i]) / 1600.0);
    char cc = value * 128;
    if(prevCC[i] != cc)
      midi.controlChange(i, cc, 0);
    prevCC[i] = cc;

//    if(bUpdate){
//      Serial.print((int)cc); Serial.print("\t");
//    }
    
    // Get mode of buffer
//    if (bBufferFilled) {
//      int total = 0;
//      for (int j = 1; j < MULTI_DEPTH; j++)
//        total += multisampling[i][j];
//
//      total /= (float)MULTI_DEPTH;
//      char cc = (total / 1600.0) * 128;
//      if (cc != prevCC[i]) {
//        // Send CC
//        midi.controlChange(i, cc, 0);
        
//      }
//      prevCC[i] = cc;
//    }
  }
//  if (bUpdate) {
//    Serial.println();
//    refresh_time = millis() + 50;
//  }
  
//
//  multisamplingWritePos++;
//  if (multisamplingWritePos >= MULTI_DEPTH) {
//    if (!bBufferFilled)
//      bBufferFilled = true;
//    multisamplingWritePos = 0; // reset
//  }
  
//  delayMicroseconds(10);
}
