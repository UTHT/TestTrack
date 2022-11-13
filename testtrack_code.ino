

int SensorPin = 2;
int OutputPin = 13;

int act_length = 10;
int disk_radius = 20;
int act_radius;;
int prot_radius;
int disk_circumference = 2 * 3.14 * disk_radius;

int paper_angle = (act_length / disk_circumference) * 360;
int ang_velocity = 0;
int rpm = 0;

void setup() {
  pinMode(OutputPin, OUTPUT);
  pinMode(SensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int SensorValue = digitalRead(SensorPin);
  
  delay(10);
  if (SensorValue==LOW){ // LOW MEANS Object Detected
    int timer_var = 0;
    //start timer
    while (SensorValue == LOW)
    {
      SensorValue = digitalRead(SensorPin);
      delay(10);
    }
    //stop timer
    ang_velocity = paper_angle / timer_var;
    rpm = ang_velocity / 6;
    // display rpm
  }
  else
  {
    int timer_var = 0;
    //start timer
    while (SensorValue == HIGH)
    {
      SensorValue = digitalRead(SensorPin);
      delay(10);
    }
    //stop timer
    ang_velocity = paper_angle / timer_var;
    rpm = ang_velocity / 6;
    // display rpm
  }
}
