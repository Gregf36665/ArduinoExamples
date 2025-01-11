const int analoguePin = 0; // Which A# to use 

const long baudRate = 115200;

int sensorVal = 0; // Use this variable to read the sensor value

void setup() {
  Serial.begin(baudRate);

}

void loop() {
	// Watch out on this function spelling. It's the American way
	sensorVal = analogRead(analoguePin);

	Serial.write("Value:");
	// Need to use print here to convert sensorVal from a int
	// to a string
	Serial.print(sensorVal);
	Serial.write("\n");
	// delay(1000); // uncomment this to go only once a second
}
