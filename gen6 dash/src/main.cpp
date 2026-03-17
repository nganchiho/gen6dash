/**
 * @file main.cpp
 * @brief This file contains the GPIO testing code for the Gen6 Dash project.
 *        It is designed to cycle through General Purpose Input/Output
 *        pins on the ATmega328P microcontroller, setting them HIGH and LOW.
 *        This can be observed with a multimeter or an LED connected to the respective pins
 * @note This code is intended for testing purposes only.
 */

#include <Arduino.h>
#include <mcp2515.h>
#include <LiquidCrystal_I2C.h>

// Define pin assignment using actual Arduino pin numbers
// SPI Pins for CAN Controllers (MCP2515)
#define CAN0_CS_PIN    10    ///< @brief Chip Select pin for CAN Controller 0 (PB2/SS)
#define CAN1_CS_PIN    9     ///< @brief Chip Select pin for CAN Controller 1 (PB1)

// HC-12 Wireless Serial Communication Module Pins
#define HC12_RX_PIN    0     ///< @brief Receive pin for HC-12 module (PD0 - Serial RX)
#define HC12_TX_PIN    1     ///< @brief Transmit pin for HC-12 module (PD1 - Serial TX)
#define HC12_SET_PIN   8     ///< @brief SET pin for HC-12 module (PB0)

// Rotary Encoder Pins
#define ENC_A_PIN      A0    ///< @brief Pin for Rotary Encoder A output (PC0 - Analog 0)
#define ENC_B_PIN      A1    ///< @brief Pin for Rotary Encoder B output (PC1 - Analog 1)

// I2C Communication Pins
#define SDA_PIN        A4    ///< @brief SDA pin for I2C communication (PC4 - Analog 4)
#define SCL_PIN        A5    ///< @brief SCL pin for I2C communication (PC5 - Analog 5)

// General Purpose Input/Output (GPIO) Pins
#define GPIO_1_PIN     A2    ///< @brief General Purpose I/O Pin 1 (PC2 - Analog 2)
#define GPIO_2_PIN     A3    ///< @brief General Purpose I/O Pin 2 (PC3 - Analog 3)
#define GPIO_3_PIN     7     ///< @brief General Purpose I/O Pin 3 (PD7 - Digital 7)
#define GPIO_4_PIN     2     ///< @brief General Purpose I/O Pin 4 (PD2 - Digital 2)
#define GPIO_5_PIN     3     ///< @brief General Purpose I/O Pin 5 (PD3 - Digital 3)
#define GPIO_6_PIN     4     ///< @brief General Purpose I/O Pin 6 (PD4 - Digital 4)
#define GPIO_7_PIN     5     ///< @brief General Purpose I/O Pin 7 (PD5 - Digital 5)
#define GPIO_8_PIN     6     ///< @brief General Purpose I/O Pin 8 (PD6 - Digital 6)

/**
 * @brief An array containing all the GPIO pins to be tested.
 */
const int gpioPins[] = {
  GPIO_1_PIN, GPIO_2_PIN, GPIO_3_PIN, GPIO_4_PIN,
  GPIO_5_PIN, GPIO_6_PIN, GPIO_7_PIN, GPIO_8_PIN
};
const int numGpioPins = sizeof(gpioPins) / sizeof(gpioPins[0]);


MCP2515 can0(10);
LiquidCrystal_I2C lcd(0x27,20,4);

//update ticks
uint32_t lastLcdTick = 0;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
Serial.println("Setup complete");

  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Test");
Serial.println("LCD complete");
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);

  Serial.begin(9600);
  Serial.println("AT+C069");

  digitalWrite(3,HIGH);
}

void loop() {
    // put your main code here, to run repeatedly:

    // wait for first time receive long frame from VCU, then wait 9ms and send a synchronization frame to both SSRUs
    // make sure if not received (not ERROR::OK) then need retry, in case other systems not powered on / have issues




    uint32_t tick = millis();

    if(tick - lastLcdTick >= 100) {
        lastLcdTick = tick;
        
        //update lcd
    }


    can_frame rx_msg;
    if(can0.readMessage(&rx_msg) == MCP2515::ERROR_OK) {
    }
}