// Read RF remote button codes using the RM4 library and send them over serial.
#include <rm4.h>

// Arduino pin connected to the receiver VCC in. Set this high to enable the
// receiver.
static const int kEnablePin = 13;

// Arduino pins connected to the data pins on the receiver.
static const int kData0Pin = 9;
static const int kData1Pin = 10;
static const int kData2Pin = 11;
static const int kData3Pin = 12;

// Create an RM4 object to read the button codes from the remote.
RM4 remote(kData0Pin, kData1Pin, kData2Pin, kData3Pin);

void setup() {
  // Initialize the serial interface.
  Serial.begin(9600);

  // Turn on the receiver.
  pinMode(kEnablePin, OUTPUT);
  digitalWrite(kEnablePin, HIGH);
}

void loop() {
  // Print the button code to the serial interface every 100 ms.
  const int button_code = remote.buttonCode();
  Serial.println(button_code);
  delay(100);
}
