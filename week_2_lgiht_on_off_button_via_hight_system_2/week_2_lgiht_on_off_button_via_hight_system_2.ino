// C++ code
//
/*
  AnalogReadSerial
  Reads an analog input (potentiometer) on pin 0,
  prints the result to the serial monitor.

  OPEN THE SERIAL MONITOR TO VIEW THE OUTPUT FROM
  THE POTENTIOMETER >>

  Attach the center pin of a potentiometer to pin
  A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

int sensorValue = 0;
// These constants won't change:
const int analogPin = A0;    // pin that the sensor is attached to
const int ledPin = 13;       // pin that the LED is attached to
const int threshold = 400;   // an arbitrary threshold level that's in the range of the analog input


void setup()
{
  pinMode(2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A0, OUTPUT);
  Serial.begin(9600);
  // initialize serial communications:
}

void loop()
{
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(10); // Delay a little bit to improve simulation performance
  // read the value of the potentiometer:
  int analogValue = analogRead(analogPin);
  Serial.println(analogValue);
  if (analogValue > threshold)
  {
    // turn LED on
    digitalWrite(LED_BUILTIN, HIGH);
  }
  if (analogValue < threshold)
  {
    // turn LED off
    digitalWrite(LED_BUILTIN, LOW);
  }
}
