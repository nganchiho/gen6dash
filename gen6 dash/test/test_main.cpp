#include <Arduino.h>

// Define pin assignments based on the schematic
// SPI for CAN Controllers
#define CAN0_CS_PIN    10   // PB2
#define CAN1_CS_PIN    9    // PB1

// HC-12 Wireless Module
#define HC12_RX_PIN    0    // PD0 (Serial RX)
#define HC12_TX_PIN    1    // PD1 (Serial TX)
#define HC12_SET_PIN   8    // PB0

// Rotary Encoder
#define ENC_A_PIN      A0   // PC0
#define ENC_B_PIN      A1   // PC1

// I2C (SDA, SCL are typically handled by Wire library (A4, A5))
#define SDA_PIN        A4   // PC4
#define SCL_PIN        A5   // PC5

// General Purpose Input/Output (GPIO) Pins
#define GPIO_1_PIN     A2   // PC2
#define GPIO_2_PIN     A3   // PC3
#define GPIO_3_PIN     7    // PD7
#define GPIO_4_PIN     2    // PD2
#define GPIO_5_PIN     3    // PD3
#define GPIO_6_PIN     4    // PD4
#define GPIO_7_PIN     5    // PD5
#define GPIO_8_PIN     6    // PD6

// Array of GPIO pins to test
const int gpioPins[] = {
  GPIO_1_PIN, GPIO_2_PIN, GPIO_3_PIN, GPIO_4_PIN,
  GPIO_5_PIN, GPIO_6_PIN, GPIO_7_PIN, GPIO_8_PIN
};
const int numGpioPins = sizeof(gpioPins) / sizeof(gpioPins[0]);

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Starting Dash Testing Code...");
  Serial.println("--- GPIO Test ---");

  // Initialize GPIO pins as OUTPUTs and set them LOW
  for (int i = 0; i < numGpioPins; i++) {
    pinMode(gpioPins[i], OUTPUT);
    digitalWrite(gpioPins[i], LOW);
  }
}

void loop() {
  // Cycle through each GPIO pin, setting it HIGH, waiting, then LOW
  for (int i = 0; i < numGpioPins; i++) {
    Serial.print("Testing GPIO Pin: ");
    Serial.print(gpioPins[i]);
    Serial.println(" - Setting HIGH");
    digitalWrite(gpioPins[i], HIGH);
    delay(1000); // Wait for 1 second

    Serial.print("Testing GPIO Pin: ");
    Serial.print(gpioPins[i]);
    Serial.println(" - Setting LOW");
    digitalWrite(gpioPins[i], LOW);
    delay(500); // Wait for 0.5 seconds
  }

  Serial.println("--- GPIO Test Cycle Complete ---");
  delay(2000); // Wait before repeating the cycle
}
