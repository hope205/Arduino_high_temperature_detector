//********************************************************
//the goal of this project is to turn on an  alarm when the temperature of the user exceeds the set threashold
//********************************************************


//include the required library
#include "DHT.h"

#define DHTPIN 2     // Digital pin connected to the DHT sensor


//define the buzzer pin
#define buzzerPin 3

// i am using dht11
#define DHTTYPE DHT11   // DHT 11

//set the threashold
int threashold = 28;  


// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.



DHT dht(DHTPIN, DHTTYPE);

void setup() {

  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin,LOW);
  
  
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
 
  float temperature = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  
  // Checks the threshold and activates the buzzer if it exceeds it
  if (temperature >=  threashold){
    
    digitalWrite(buzzerPin,HIGH)
    delay(3000);
    digitalWrite(buzzerPin,LOW);
    delay(2000);
    Serial.println(F("high tempearture);
    
  }

  
}
