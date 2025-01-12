const int analoguePin = 0; // Which A# to use 
const int statusLED = 5;

const int offValue = 300;

const long baudRate = 115200;

long timeBroken = 0;
int sensorVal = 0; // Use this variable to read the sensor value
bool tripped = false;

void setup() {
  Serial.begin(baudRate);

}

void loop() {
	// Watch out on this function spelling. It's the American way
	sensorVal = analogRead(analoguePin);


  if (sensorVal < offValue){
    // The light gate has been broken
    digitalWrite(statusLED, HIGH);  
    // Re-read tha analogue value in this loop or else this loop is stuck forever
    while (analogRead(analoguePin) < offValue){
      timeBroken++;
      delay(1); // could use delayMocroseconds too, this is ms
    }
    digitalWrite(statusLED, LOW);  
    Serial.print(timeBroken);
    Serial.println("ms");
    timeBroken = 0; // Make sure to reset the time
  }

}
