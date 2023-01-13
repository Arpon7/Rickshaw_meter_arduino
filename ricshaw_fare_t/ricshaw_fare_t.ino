
//required libraries

#include <LiquidCrystal.h>
#include <MPU6050_tockn.h>
#include <Wire.h>
#include <DHT.h>


//LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


//Global variables


//time
float minutes = 0;
uint32_t prevTime;

//LCD
int adc_key_in = 0;

//wheelRotation
int irPin = 13;

//Temp_Hum

#define DHTPIN 12

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float new_tempHum = 0;




//windSpeed

const int IR_sensor_pin = 11;  // pin for the IR sensor
float new_avg_wind_speed = 0;

//roadSteepness

MPU6050 mpu6050(Wire);
float new_steepness = 0;

//fare


float new_wheel_rotation = 0;


void setup() {



  // start serial communication
  // Serial.begin(9600);

  lcd.begin(16, 2);     // start the library
  lcd.setCursor(0, 0);  // set the LCD cursor position
  lcd.print("Fare Meter");


  //wheelRotatiion
  pinMode(irPin, INPUT);

  //tempHum
  dht.begin();

  //windSpeed
  pinMode(IR_sensor_pin, INPUT);  // set the IR sensor pin as an input

  //roadSteepness
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  //
  prevTime = millis();
}

void loop() {
  // unsigned long new_wheel_rotation = wheelRotation();
  adc_key_in = analogRead(0);

  // btnRIGHT:  if the right btn is pressed
  if (adc_key_in < 50 && millis() - prevTime > 100) {


    new_tempHum = tempHum();
    new_steepness = roadsteepness();
    new_avg_wind_speed = windSpeed();

    prevTime = millis();
  }


  //btnLEFT: if the left button is pressed

  if (adc_key_in> 80 && adc_key_in < 650 && millis() - prevTime > 1000) {

    fare();
    
    prevTime = millis();
  }
}