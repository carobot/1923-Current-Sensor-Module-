#define VIN A0
const float VCC = 5.0; // power supply voltage 
float cutOfflimit = 1.01;
float sensitivity = 0.185;
const float QOV = 0.5* VCC;
float voltage;


void setup() {
  Serial.begin(9600);
  Serial.println("ACS712 Current Sensor");
}

void loop() {
  float voltage_raw = (5.0 / 1023.0) * analogRead(VIN); // receive input value 
  // get values for voltage and current 
  voltage = voltage_raw - QOV + 0.012;
  float current = voltage/sensitivity;

  if (abs(current) > cutOfflimit){
    Serial.print("V: ");
    Serial.print(voltage,3); // print voltage with 3 decimal places
    Serial.print("V, I: ");
    Serial.print(current, 2); // print current with 2 deciaml places
    Serial.println("A");
  }
  else{ // if there is no current 
    Serial.println("No current");
  }
  delay(2000);

}
