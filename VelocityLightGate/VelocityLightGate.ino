const int analoguePin = 0; // Which A# to use 
const int statusLED = 5;

const int offValue = 300;
const float blockSize = 0.1; // Size of the block in m

const long baudRate = 115200;

long timeBroken = 0;
int sensorVal = 0; // Use this variable to read the sensor value
bool tripped = false;

void setup() {
  Serial.begin(baudRate);
  Serial.println("Time (ms), Velocity (m/s)");

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
    Serial.print(",");
    // Do the maths in ms so we don't get a divide by 0 for short times
    Serial.println((blockSize/timeBroken)*1000, 8); // Print the answer with 3 after the dp
    timeBroken = 0; // Make sure to reset the time
  }

}
