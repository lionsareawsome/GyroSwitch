/*
  Script that reads and prints the data of the Arduino Nano 33 BLE's integrated LSM9DS1 IMU.

  Requires the Arduino LSM9DS1 Library:
  The Arduino LSM9DS1 Library allows for the use of the integrated inertial measurement unit(IMU)
  on the Arduino Nano 33 BLE. The IMU is a combination of a 3-axis accelerometer, gyroscope and
  magnetometer.

  2023, Lion Beck
*/

#include <Arduino_LSM9DS1.h>

// variables for title counter
int count = 0;
bool txt = false;

void setup() {
  // Connect Serial
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Serial connected");

  //Test if IMU connected
  if (!IMU.begin ()){
    Serial.println ("Failed to initialize IMU");
    while (1);
  }

}

void loop() {
  float xG, yG, zG;   //Variables for the Gyroscope
  float xA, yA, zA;   //Variables for the Accelerometer
  float xM, yM, zM;   //Variables for the Magnetometer

  //Title counter
  count++;
  if (count >= 9){
    txt = true;
    count = 0;
  }else{
    txt = false;
  }

  // Acceleration

  // Title Acceleration every 10 readouts
  if (txt == true){
    Serial.print("Acceleration : ");
  }else{
    Serial.print("---------------");
  }
  //Get data and print to Serial Monitor
  if (IMU.accelerationAvailable()){

    //Read the Acceleration Data from the IMU into the Variables xA, yA, zA
    IMU.readGyroscope(xA, yA, zA);
    //Print out that data into the Serial Monitor
    Serial.print("|");
    Serial.print(xA);
    Serial.print("    ");
    Serial.print(yA);
    Serial.print("    ");
    Serial.print(zA);
    Serial.print("|");

  }else{

    // so the table doesnt get ruined if there is no readout
    Serial.print("| ");
    Serial.print("----");
    Serial.print("    ");
    Serial.print("----");
    Serial.print("    ");
    Serial.print("----");
    Serial.print("|");

  }

  // Gyroscope

  // Title Gyroscope every 10 readouts
  if (txt == true){
    Serial.print("Gyroscope :    ");
  }else{
    Serial.print("---------------");
  }
  //Get data and print to Serial Monitor
  if (IMU.gyroscopeAvailable()){

    //Read the Gyroscope Data from the IMU into the Variables xG, yG, zG
    IMU.readGyroscope(xG, yG, zG);
    //Print out that data into the Serial Monitor
    Serial.print("|");
    Serial.print(xG);
    Serial.print("    ");
    Serial.print(yG);
    Serial.print("    ");
    Serial.print(zG);
    Serial.print("|");

  }else{

    // so the table doesnt get ruined if there is no readout
    Serial.print("| ");
    Serial.print("----");
    Serial.print("    ");
    Serial.print("----");
    Serial.print("    ");
    Serial.print("----");
    Serial.print("|");

  }

  // Magnetometer

  // Title Magnetometer every 10 readouts
  if (txt == true){
    Serial.print("Magnetometer : ");
  }else{
    Serial.print("---------------");
  }
  //Get data and print to Serial Monitor
  if (IMU.magneticFieldAvailable()){

    //Read the Magnetic Field Data from the IMU into the Variables xG, yG, zG
    IMU.readMagneticField(xM, yM, zM);
    //Print out that data into the Serial Monitor
    Serial.print("|");
    Serial.print(xM);
    Serial.print("    ");
    Serial.print(yM);
    Serial.print("    ");
    Serial.print(zM);
    Serial.print("|");

  }else{

    // so the table doesnt get ruined if there is no readout
    Serial.print("| ");
    Serial.print("----");
    Serial.print("    ");
    Serial.print("----");
    Serial.print("    ");
    Serial.print("----");
    Serial.print("|");

  }
  // new line
  Serial.print('\n');
  delay(500);
}