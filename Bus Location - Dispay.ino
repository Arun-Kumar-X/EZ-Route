#include <Arduino.h>
#include <TM1637Display.h>

#define CLK 2
#define DIO 3

TM1637Display display(CLK, DIO);

int time = 1620;

void setup() {
    display.setBrightness(1);
}

void loop() {
  display.clear();
  display.showNumberDecEx(time, 0b01000000);
  delay(1000);
  display.showNumberDec(time,true);
  delay(1000);
};

int G1 = 2;
int G2 = 4;
int G3 = 6;
int G4 = 8;
int G5 = 10;
int G6 = 12;
int G7 = 13;
int stop = 1;
int time = 3;

void setup() {
  pinMode(G1, OUTPUT);
  pinMode(G2, OUTPUT);
  pinMode(G3, OUTPUT);
  pinMode(G4, OUTPUT);
  pinMode(G5, OUTPUT);
  pinMode(G6, OUTPUT);
  pinMode(G7, OUTPUT);
}

void loop() {
  if (stop == 1) {
    digitalWrite(4, 0);
    digitalWrite(6, 0);
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    digitalWrite(12, 0);
    digitalWrite(2, 1);
    delay(time*1000);
    digitalWrite(2, 0);
    digitalWrite(4,1);
    stop = stop + 1;
  }
  if (stop == 2) {
    digitalWrite(2, 0);
    digitalWrite(4, 0);
    digitalWrite(6, 0);
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    digitalWrite(12, 0);
    digitalWrite(4, 1);
    delay(time*1000);
    digitalWrite(4, 0);
    digitalWrite(6, 1);
    stop = stop + 1;
  }
  if (stop == 3) {
    digitalWrite(2, 0);
    digitalWrite(4, 0);
    digitalWrite(6, 0);
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    digitalWrite(12, 0);
    digitalWrite(6, 1);
    delay(time*1000);
    digitalWrite(6, 0);
    digitalWrite(8, 1);
    stop = stop + 1;
  }
  if (stop == 4) {
    digitalWrite(2, 0);
    digitalWrite(4, 0);
    digitalWrite(6, 0);
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    digitalWrite(12, 0);
    digitalWrite(8, 1);
    delay(time*1000);
    digitalWrite(8, 0);
    digitalWrite(10, 1);
    stop = stop + 1;
  }
  if (stop == 5) {
    digitalWrite(2, 0);
    digitalWrite(4, 0);
    digitalWrite(6, 0);
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    digitalWrite(10, 1);
    delay(time*1000);
    digitalWrite(8, 0);
    digitalWrite(10, 1);
    stop = stop + 1;
  }
  if (stop == 6) {
    digitalWrite(2, 0);
    digitalWrite(4, 0);
    digitalWrite(6, 0);
    digitalWrite(8, 0);
    digitalWrite(10, 0);
    digitalWrite(10, 1);
    delay(time*1000);
    digitalWrite(10, 0);
    digitalWrite(13, 1);
    stop = stop + 1;
  }
}