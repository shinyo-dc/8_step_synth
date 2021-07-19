#include <Arduino.h>
#include "synth.h"

// Constants 
#define SINE     0
#define TRIANGLE 1
#define SQUARE   2
#define SAW      3
#define RAMP     4
#define NOISE    5

#define ENVELOPE0 0
#define ENVELOPE1 1
#define ENVELOPE2 2
#define ENVELOPE3 3

// Analog pins placeholder
#define WAVEFORM A0 // 0-5
#define PITCH A1    // 0-127
#define LENGTH A2   // 0-127
#define MOD A3      // 0-1023
#define SPEED A4    // 10-350


// Variables
synth edgar;
int pitch, length, mod, speed, waveform = 0;
long lastTime = 0;
long duration = 1000;
int i = 0;

void setup() {
  edgar.begin(CHA);
  pinMode(PITCH, INPUT);
  pinMode(LENGTH, INPUT);
  pinMode(MOD, INPUT);
  Serial.begin(115200);
}

void loop() {
  int pitch_raw = analogRead(PITCH);
  int length_raw = analogRead(LENGTH);
  int mod_raw = analogRead(MOD);
  int speed_raw = analogRead(SPEED);
  int waveform_raw = analogRead(WAVEFORM);

  pitch = map(pitch_raw, 0, 1023, 0, 127);
  length = map(length_raw, 0, 1023, 0, 127);
  mod = map(mod_raw, 0, 1023, 0, 1023);
  speed = map(speed_raw, 0, 1023, 10, 350);
  waveform = map(waveform_raw, 0, 1023, 0, 5);

  switch (waveform)
  {
    case 0:
      {
        edgar.setupVoice(0, SINE, 0, ENVELOPE1, 0, 64);
        break;
      }
    case 1:
      {
        edgar.setupVoice(0, TRIANGLE, 0, ENVELOPE1, 0, 64);
        break;
      }
    case 2:
      {
        edgar.setupVoice(0, SQUARE, 0, ENVELOPE1, 0, 64);
        break;
      }
    case 3:
      {
        edgar.setupVoice(0, SAW, 0, ENVELOPE1, 0, 64);
        break;
      }
    case 4:
      {
        edgar.setupVoice(0, RAMP, 0, ENVELOPE1, 0, 64);
        break;
      }
    case 5:
      {
        edgar.setupVoice(0, NOISE, 0, ENVELOPE1, 0, 64);
        break;
      }
  }

  while (millis() - lastTime > speed && i < 8)
  {
    edgar.setMod(0, mod);
    edgar.setLength(0, length);
    edgar.setPitch(0, pitch);
    edgar.trigger(0);
    delay(speed);
    i++;
    lastTime = millis();
  }
  if (i == 8) {
    i = 0;
  }
}