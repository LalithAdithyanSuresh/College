#include <ESP8266WiFi.h>

int ConnectionErrors = 0;
const int ledR = 0;        // GPIO 0
const char* ssid = "SSN";
const char* password = "Ssn1!Som2@Sase3#";
const char* host = "129.154.41.7";



void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(ledR, LOW);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.begin(115200);
  digitalWrite(ledR, HIGH);
  digitalWrite(LED_BUILTIN, LOW);

  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(ledR, HIGH);
    delay(100);
    digitalWrite(ledR, LOW);
    Serial.print(".");
    delay(100);
  }

  Serial.println("\nConnected to Wi-Fi!");
  digitalWrite(ledR, LOW);
  digitalWrite(LED_BUILTIN, HIGH);
}
void loop() {
  if (Serial.available() > 0) {
    digitalWrite(ledR, LOW);
      String data = Serial.readStringUntil('\n');
    if (data.startsWith("SensorValue:")) {
      float sensorValue = data.substring(12).toFloat();
      WiFiClient client;
      const int httpPort = 80;
      if (!client.connect(host, httpPort)) {
        digitalWrite(ledR, HIGH);
        delay(200);
        digitalWrite(ledR, LOW);
      } else {
        digitalWrite(ledR, LOW);
        String url = "/api/mysqlEntry/index.php?user=PhysicsProj&pass=Project&db=APIstorage&mode=windSpeed&speed=" + String(sensorValue,3) + "&Sid=2";
        client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");
        digitalWrite(ledR, HIGH);
        delay(100);
        digitalWrite(ledR, LOW);
        delay(100);
        digitalWrite(ledR, HIGH);
        delay(100);
      }
    }
  }
}


// #include <ESP8266WiFi.h>
// #include <SoftwareSerial.h>

// int ConnectionErrors = 0;
// const int ledR = 0;        // GPIO 0
// const int ledG = 2;
// const char* ssid = "las";
// const char* password = "Lalith778306";
// const char* host = "129.154.41.7";

// #define ESP_TX_PIN 2
// #define ESP_RX_PIN 3

// SoftwareSerial espserial(ESP_TX_PIN, ESP_RX_PIN);



// String readString(SoftwareSerial& serial) {
//   String result = "";
//   while (serial.available()) {
//     char c = serial.read();
//     if (c == '\n') {
//       break;
//     }
//     result += c;
//   }
//   serial.println(result);
//   return result;
// }



// void setup() {
//   pinMode(ledR, OUTPUT);
//   pinMode(ledG, OUTPUT);
//   digitalWrite(ledR, LOW);
//   digitalWrite(ledG, LOW);

//   Serial.begin(115200);  // Increase baud rate for faster communication
//   espserial.begin(115200);
//   digitalWrite(ledR, HIGH);
//   digitalWrite(ledG, LOW);

//   Serial.println("Connecting to Wi-Fi...");

//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     digitalWrite(ledR, HIGH);
//     delay(100);
//     digitalWrite(ledR, LOW);
//     Serial.print(".");
//     delay(100);
//   }

//   Serial.println("\nConnected to Wi-Fi!");
//   digitalWrite(ledR, LOW);
//   digitalWrite(ledG, HIGH);

// }

// void loop() {
//   if (espserial.available()) {
//     digitalWrite(ledR, HIGH);
//     digitalWrite(ledG, LOW);
//     delay(10);
//     digitalWrite(ledR, LOW);
//     digitalWrite(ledG, LOW);
//     String receivedString = readString(espserial);
//     float receivedValue = atof(receivedString.c_str());

//     Serial.print("Received value from Arduino: ");
//     Serial.println(receivedValue);

//     if (!isnan(receivedValue)) {
//       WiFiClient client;
//       const int httpPort = 80;

//       if (!client.connect(host, httpPort)) {
//         Serial.println("Connection to server failed");
//         digitalWrite(ledR, HIGH);
//         digitalWrite(ledG, LOW);
//         delay(200);
//         digitalWrite(ledR, LOW);
//         digitalWrite(ledG, LOW);
//       } else {
//         digitalWrite(ledR, LOW);
//         digitalWrite(ledG, LOW);

//         String url = "/api/mysqlEntry/index.php?user=PhysicsProj&pass=Project&db=APIstorage&mode=windSpeed&speed=" + String(receivedValue) + "&Sid=2";
//         client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

//         digitalWrite(ledR, HIGH);
//         digitalWrite(ledG, HIGH);
//         delay(100);
//       }
//     }
//   }
// }