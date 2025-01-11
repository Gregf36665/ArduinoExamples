// Pick any pin by looking at the board.
// Don't pick RX or RX ports
const int ledPin = 2;
// Specific the baud rate. Since this is larger than an int it needs to be a long
const long baudRate = 115200;
// Specify the duration of half a cycle
const int duration = 500;
// This code assumes a duty cycle of 50%

void setup() {
	// Specify which pin should be the output pin
	pinMode(ledPin, OUTPUT);
	// Set up the serial connection so we can send messages back
	Serial.begin(baudRate);
}

void loop() {
	digitalWrite(ledPin, HIGH);
	Serial.write("The LED is on\n");
	delay(duration);
	digitalWrite(ledPin, LOW);
	Serial.write("The LED is off\n");
	delay(duration);

}
