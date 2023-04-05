#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define FIREBASE_HOST "https://iotproject2023-fef7f-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "YWIPsq4YJPiBEsi9JqvWyB4LTNnUzf95V7enDJCA"

#define WIFI_SSID "Lavida"
#define WIFI_PASSWORD "14062002"
#define rainAnalog 35
#define rainDigital 34
#define ledEnable 33
#define DHTPIN 13
#define DHTTYPE DHT11

WiFiClient client;
DHT dht(DHTPIN, DHTTYPE);
FirebaseData firebaseData;

void setup() {
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to wifi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nWifi connected\nIP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  dht.begin();
}
void rainSensor() {
  int rainAnalogVal = analogRead(rainAnalog);
  
  if (rainAnalogVal < 90) {
    Serial.println("It's raining !");
    digitalWrite(ledEnable, HIGH);
    Firebase.setBool(firebaseData,"rain", true);
    Firebase.setString(firebaseData, "rain-status", "It's raining !");
  } else {
    Serial.println("No rain detected.");
    digitalWrite(ledEnable, LOW);
    Firebase.setBool(firebaseData,"rain", false);
    Firebase.setString(firebaseData, "rain-status", "No rain detected");
  }
}
void loop() {
  delay(500); 

  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();

  if (isnan(humidity) || isnan(temperatureC)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity (%): ");
  Serial.print(humidity);
  Serial.print(". Temperature (°C): ");
  Serial.println(temperatureC);

  
  // Đẩy dữ liệu lên Firebase Realtime Database
  Firebase.setDouble(firebaseData, "humidity", humidity);
  Firebase.setDouble(firebaseData, "temperature", temperatureC);
  rainSensor();
}
