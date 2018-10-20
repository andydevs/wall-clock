/**
 * Experiments with RTC Interface
 * 
 * Author:  Anshul Kharbanda
 * Created: 10 - 20 - 2018
 */

#include <Wire.h>
#include <RTClib.h>

// Define RTC
RTC_PCF8523 rtc;

/**
 * Sets up serial port and RTC
 */
void setup() {
  // Set up serial
  Serial.begin(9600);

  // Set up rtc
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
  } else {
    Serial.println("RTC found");
  }
  if (!rtc.initialized()) {
    Serial.println("RTC not initialized!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

/**
 * Gets time from RTC And prints onto the serial monitor
 */
void loop() {
  // Get time
  DateTime now = rtc.now();

  // Print date
  Serial.print(now.month(), DEC); Serial.print("/");
  Serial.print(now.day(), DEC); Serial.print("/");
  Serial.print(now.year(), DEC); Serial.print(" ");

  // Print time
  Serial.print(now.hour() % 12 == 0 ? 12 : now.hour() % 12, DEC); Serial.print(":");
  Serial.print(now.minute(), DEC); Serial.print(":");
  Serial.print(now.second(), DEC); Serial.print(" ");
  Serial.print(now.hour() < 12 ? "AM" : "PM"); Serial.println();

  // Wait a second
  delay(1000);
}
