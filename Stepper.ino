// Include the Stepper library:
#include <Stepper.h>
#include <Wire.h>
#include "Adafruit_AS726x.h"

// Define number of steps per revolution:
const int stepsPerRevolution = 200;

Adafruit_AS726x ams;

unsigned int myTime;

//buffer to hold raw values
uint16_t sensorValues[AS726x_NUM_CHANNELS];

// Initialize the stepper library on pins 8 through 11:
Stepper myStepper = Stepper(stepsPerRevolution, 10, 11, 12,13);

// Initialize output values to other arduino

const int RED_OUT = 2;
const int GREEN_OUT = 3;
const int CONVEYOR_OUT = 4;

// Check to see if red or green are the most prominent colors
bool isGreater(int color, int* colors){
  bool greater = true;
  for (int i = 0; i < 6; ++ i){
    if (color < colors[i]){ // Violet and orange seem to be really finicky consider removing them.
      greater = false;
    }
  }
  return greater;
}

bool isConveyer(int colors[]){
  if(colors[2] > 1000){
    return true; //Based on testing the yellow value seems to always be > 1000 when detecting the conveyer belt
  }
  return false;
}


void setup() {
  Serial.begin(9600);
  while(!Serial);


  // Set the motor speed (RPMs):
  
  myStepper.setSpeed(200);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RED_OUT, OUTPUT);
  pinMode(GREEN_OUT, OUTPUT);
  pinMode(CONVEYOR_OUT, OUTPUT);
}

bool start = true;
const int delayTime = 2000;
bool is_conveyer = true;
bool is_red = false;
bool is_green = false;

void loop() {
  //Serial.println("HELLO");
  // Step one revolution in one direction:
 
  int currentTime = millis();
  if(start){
    myStepper.step(1000);
    myTime = millis();
    start = false;
  }

  if(currentTime - myTime < delayTime & is_red == false & is_green == false){ // Only run if within delay or color has not been found yet
   ams.startMeasurement(); //begin a measurement
   //Serial.println("HELLO THERE");
  
  //wait till data is available
  bool rdy = false;
  while(!rdy){
    delay(5);
    rdy = ams.dataReady();
    }
   int green = sensorValues[AS726x_GREEN];
   int red  = sensorValues[AS726x_RED];
   int violet = sensorValues[AS726x_VIOLET];
   int blue = sensorValues[AS726x_BLUE];
   int yellow = sensorValues[AS726x_YELLOW];
   int orange = sensorValues[AS726x_ORANGE];

   //Serial.print("Red: ");Serial.println(red);

   int colors[6] ={red, orange, yellow, green, blue, violet};


  is_conveyer = isConveyer(colors);
  if(!is_conveyer){
    is_red = isGreater(red, colors);
    is_green = isGreater(green, colors);
  }
  if(is_red){
    digitalWrite(RED_OUT, HIGH);
    digitalWrite(CONVEYOR_OUT, HIGH);
    Serial.println("red");
  }
  else{
    digitalWrite(RED_OUT, LOW);
    digitalWrite(CONVEYOR_OUT, LOW);
    Serial.println("no reed");
  }
  if(is_green){
    digitalWrite(GREEN_OUT, HIGH);
    digitalWrite(CONVEYOR_OUT, HIGH);
    Serial.println("grren");
  }
  else{
    digitalWrite(GREEN_OUT, LOW);
    digitalWrite(CONVEYOR_OUT, LOW);
    Serial.println("nogreen");
  }
   delay(5);
  }
  else{
    digitalWrite(CONVEYOR_OUT, HIGH);
    Stepper.setSpeed(0);
    Serial.println("done");
    delay(5);
  }

  if(currentTime - myTime >= delayTime) myStepper.step(0);
  

  //myTime = millis();


  // Step on revolution in the other direction:
  
 
}
