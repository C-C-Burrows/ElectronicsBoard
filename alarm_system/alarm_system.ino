// this is the define pins

#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
#define pinPIR 5 // 
#define buttonPin 4 //
#define pinAlarm 2

// defines variables

bool isDistanceSensorTriggerValue = false;
bool isButtonSensorTriggerValue = false;
bool isMovementSensorsTriggerValue = false;

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

  if (HowManyAlarmsHaveBeenTriggered() >= 2)
  {
    TurnAlarmOn();
  }
  else
  {
    TurnAlarmOff();
  }

  DebugSensors();

}

int HowManyAlarmsHaveBeenTriggered()
{

  int triggerAlarm = 0;
  if (IsDistanceSensorActived() == true)
  {
    triggerAlarm++;
  }

  if (IsMovementSensorActivated() == true)
  {
    triggerAlarm++;
  }

  if (IsButtonTriggerActivated() == true)
  {
    triggerAlarm++;
  }
  return triggerAlarm;
}

// (this is reading the distance and retuning
//it from the distance senser)

int ReadDistance()
{
  int distance; // variable for the distance measurement
  int duration;
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
  return distance;
}

//this funtion it reading the distance and determining weather it is < 100 and returning the bool

bool IsDistanceSensorActived()
{
  int readDistance;
  readDistance = ReadDistance();
  bool distanceActivated;
  distanceActivated = readDistance < 100;

  // Has the sensor been activated
  if (distanceActivated)
  {
    //Set the global variable to be true
    //indicating that the sensor has been triggered
    isDistanceSensorTriggerValue = true;
  }

  //Return whether or not the sensor has been activated at all
  return isDistanceSensorTriggerValue;

}

//this funtion is reading the pinPIR resaults and retuning them as a int

int ReadMovementSensor()
{
  int pirTrigger;
  pirTrigger = digitalRead(pinPIR);
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


  // Has the sensor been activated
  if (movementSensorActervated)
  {
    //Set the global variable to be true
    //indicating that the sensor has been triggered
    isMovementSensorsTriggerValue = true;
  }


  return isMovementSensorsTriggerValue;
}

// this is reading the button ans retuning it as an int

int ReadButton()
{
  int buttonTrigger;
  buttonTrigger = digitalRead(buttonPin);
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

  if (buttonActervated == true)
  {

    isButtonSensorTriggerValue = true;
  }
  return isButtonSensorTriggerValue;
}

void DebugSensors()
{
  Serial.println("*******************");
  Serial.print ("Button Has been Activated: ");
  Serial.println(isButtonSensorTriggerValue);
  Serial.print ("Movement Has been Activated: ");
  Serial.println(isMovementSensorsTriggerValue);
  Serial.print ("Distance Has been Activated: ");
  Serial.println(isDistanceSensorTriggerValue);
  Serial.println("*******************");

}
// turn alram on
void TurnAlarmOn()
{
  digitalWrite(pinAlarm, HIGH);
}
//turn alarm off
void TurnAlarmOff()
{
  digitalWrite(pinAlarm, LOW);
}
