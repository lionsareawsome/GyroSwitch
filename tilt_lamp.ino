#include <Arduino_LSM9DS1.h>

bool debug = false;
bool light = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Serial connected");

  if (!IMU.begin ()){
    Serial.println ("Failed to initialize IMU");
    while (1);
  }

  Serial.println("IMU initialized");

  if (debug == true){
    Serial.println("Debug Mode")
    Serial.println("Gyroscope Data:");
    Serial.println("x\ty\tz");
  }else {
    Serial.println("Debug Deactivated");
  }
  

}

void loop() {
  float x, y, z;  //gyro x, y, z data
  int tresh = 100;  //switch threshold

  if (IMU.gyroscopeAvailable()){
    IMU.readGyroscope(x, y, z);

    if (debug == true){

      Serial.print(x);
      Serial.print('\t');
      Serial.print(y);
      Serial.print('\t');
      Serial.println(z);

    }
    
    if (y > tresh) {
      if (light == false){
        light = true;
        Serial.println("On");
      }else{
        light = false;
        Serial.println("Off");
      }
    }
  }else {
    if (debug == true){

      Serial.println("gyro not available");

    }
  }
}
