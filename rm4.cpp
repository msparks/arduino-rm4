// Copyright (c) 2012 Matt Sparks. All rights reserved.
#include "rm4.h"

#include <stdint.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

RM4::RM4(const uint8_t data0_pin, const uint8_t data1_pin,
         const uint8_t data2_pin, const uint8_t data3_pin)
    : data0_pin_(data0_pin), data1_pin_(data1_pin),
      data2_pin_(data2_pin), data3_pin_(data3_pin) {
  pinMode(data0_pin, INPUT);
  pinMode(data1_pin, INPUT);
  pinMode(data2_pin, INPUT);
  pinMode(data3_pin, INPUT);
}

uint8_t RM4::buttonCode() const {
  // Read data pins, shifting appropriately. Data 0 is in the first bit
  // position, data 1 is in the second bit position, etc.
  const uint8_t data0 = digitalRead(data0_pin_);
  const uint8_t data1 = digitalRead(data1_pin_) << 1;
  const uint8_t data2 = digitalRead(data2_pin_) << 2;
  const uint8_t data3 = digitalRead(data3_pin_) << 3;

  // Resulting button code simply the nibble consisting of [D3 D2 D1 D0].
  return (data3 | data2 | data1 | data0);
}
