// this is the define pins

#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define pinPIR 5 // 
#define buttonPin 4 //

// defines variables

long duration; // variable for the duration of sound wave travel

// setup funtion

void setup()
{
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(pinPIR, INPUT); // Sets the trigPin as an OUTPUT
  pinMode(buttonPin, INPUT); // Sets the trigPin as an OUTPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed

}

// void loop funtion

void loop() {
  IsDistanceSensorActived();
  IsMovementSensorActivated();
  IsButtonTriggerActivated();



}

// (this is reading the distance and retuning
//it from the distance senser)

int ReadDistance()
{
  int distance; // variable for the distance measurement
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

//this funtion it reading the distance and determining weather it is < 100 and returning the bool

bool IsDistanceSensorActived()
{
  int readDistance;
  readDistance = ReadDistance();
  bool distanceActivated;
  distanceActivated = readDistance < 100;
  Serial.print("Distance activated: ");
  Serial.println(distanceActivated);
  return distanceActivated;

}

//this funtion is reading the pinPIR resaults and retuning them as a int

int ReadMovementSensor()
{
  int pirTrigger;
  pirTrigger = digitalRead(pinPIR);
  Serial.print("PIR Trigger: ");
  Serial.println(pirTrigger);
  delay(500);
  return pirTrigger;
}

// this funtion read and then retuning it as a bool

bool IsMovementSensorActivated()
{
  int readMovementSensor;
  readMovementSensor = ReadMovementSensor();
  bool movementSensorActervated;
  movementSensorActervated = (readMovementSensor == 1);
  Serial.print("movement sensor activated: ");
  Serial.println(movementSensorActervated);
  return movementSensorActervated;
}

// this is reading the button ans retuning it as an int

int ReadButton()
{
  int buttonTrigger;
  buttonTrigger = digitalRead(buttonPin);
  Serial.print ("ButtonTrigger:");
  Serial.println(buttonTrigger);
  delay(500);
  return buttonTrigger;
}

// this funtion reads then retuns the value as a bool

bool IsButtonTriggerActivated()
{
  int readButton;
  readButton = ReadButton();
  bool buttonActervated;
  buttonActervated = (readButton == 1);
  Serial.print ("Button actervated: ");
  Serial.println(buttonActervated);
  return buttonActervated;
}

void TurnAlarmOn()
{
  // turn the alarm on
}
