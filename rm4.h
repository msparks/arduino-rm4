// Copyright (c) 2012 Matt Sparks. All rights reserved.
//
// rm4: an Arduino library for interfacing with 4-channel RF remotes.
//
// Such remotes are very similar to the RM4SG-M module
// (http://www.e-madeinchn.com/ReceiverModules.html). This library expects four
// data pins on the remote module, one for each channel. When exactly one
// button on the remote is pressed, exactly one of the four data pins goes
// high.
//
// This library also supports multiple data pins pressed simultaneously. If
// multiple data pins are high, a button code distinct from all individual
// button codes will be returned. Specifically, the bitwise OR of the button
// codes will be returned. For example, if buttons A (code 1) and C (code 4)
// are pressed simultaneously on the remote, button code 5 (0001 | 0100 = 0101)
// will be returned.
//
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright
//     notice, this list of conditions and the following disclaimer in the
//     documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
#ifndef ARDUINO_RM4_H_
#define ARDUINO_RM4_H_

#include <stdint.h>

class RM4 {
 public:
  // Initializes object with the given pin assignments.
  //
  // All of the data pins specified here will be set as input pins.
  RM4(uint8_t data0_pin, uint8_t data1_pin,
      uint8_t data2_pin, uint8_t data3_pin);

  // Read the button code from the data pins. Returns 0 if no buttons are
  // pressed. Multiple buttons pressed simultaneously return the bitwise OR of
  // the individual buttons pressed. The highest possible button code is 15,
  // representing all four buttons pressed simultaneously.
  uint8_t buttonCode() const;

 private:
  const uint8_t data0_pin_;
  const uint8_t data1_pin_;
  const uint8_t data2_pin_;
  const uint8_t data3_pin_;
};

#endif
