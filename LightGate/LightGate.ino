const int analoguePin = 0; // Which A# to use 
const int statusLED = 5;

const int offValue = 300;

const long baudRate = 115200;

int sensorVal = 0; // Use this variable to read the sensor value
bool tripped = false;
bool lastTripped = false;
void setup() {
  Serial.begin(baudRate);

}

void loop() {
	// Watch out on this function spelling. It's the American way
	sensorVal = analogRead(analoguePin);

  lastTripped = tripped;
  tripped = sensorVal < offValue;
  digitalWrite(statusLED, tripped);
  // If there is a change in status
  if (tripped != lastTripped){
    // Just started being blocked
    if (tripped){
      Serial.write("Blocked\n");
    }
    // Just finished being blocked
    else {
      Serial.write("Unblocked\n");
    }
  }
}
