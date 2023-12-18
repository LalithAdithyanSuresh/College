/*
Connect the voltage signal wire to Arduino analog interface:
Yellow Cable<---->A0
*/


// void setup(){

// }
// void loop(){

// }



const int anemometerPin = A0;
const float voltageAtZeroWind = 0.0; 
const float voltageAtMaxWind = 5.0;  
const float maxWindSpeed = 30.0; 
float Cspeed = 0;
int iter = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensorValue = analogRead(anemometerPin);
  float voltage = sensorValue * (5.0 / 1023.0); 
  float windSpeed = ((voltage - voltageAtZeroWind) / (voltageAtMaxWind - voltageAtZeroWind) * maxWindSpeed)/5;

  Cspeed += windSpeed;
  iter += 1;

  if (iter == 500) {  // Collect data for 5 seconds (500 iterations at 10ms delay)
    float averageSpeed = Cspeed / 500.0;
    //Serial.println("Average Speed: " + String(averageSpeed));
    Serial.print("SensorValue:");
    Serial.println(averageSpeed);
    // Reset variables for the next average calculation
    Cspeed = 0;
    iter = 0;
  }

  delay(10);
}



// int RPin = 7,GPin=8,BPin=9;

// void setup() {
//   Serial.begin(9600);
//   pinMode(RPin, OUTPUT);
//   pinMode(GPin, OUTPUT);

// }

// void loop() {
//   if (Serial.available() > 0) {
//     char command = Serial.read();
//     if (command == '0') {
//       digitalWrite(RPin, HIGH); // Turn on the LED
//     } else if (command == '1') {
//       digitalWrite(RPin, LOW); // Turn off the LED
//     }else if (command == '2') {
//       digitalWrite(GPin, HIGH); // Turn on the LED
//     } else if (command == '3') {
//       digitalWrite(GPin, LOW); // Turn off the LED
//     }else if (command == '4') {
//       digitalWrite(BPin, HIGH); // Turn on the LED
//     } else if (command == '5') {
//       digitalWrite(BPin, LOW); // Turn off the LED
//     }
//   }
// }
