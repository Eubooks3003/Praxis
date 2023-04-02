
const int ENA_PIN_sweeper_red = 11;
const int IN1_PIN_sweeper_red = 12;
const int IN2_PIN_sweeper_red = 13;

const int ENB_PIN_sweeper_green = 9;
const int IN3_PIN_sweeper_green = 10;
const int IN4_PIN_sweeper_green = 8;

const int ENA_PIN_conveyer = 6;
const int IN1_PIN_conveyer = 7;
const int IN2_PIN_conveyer = 5;

const int ENB_PIN_conveyer = 3;
const int IN3_PIN_conveyer = 4;
const int IN4_PIN_conveyer = 2;

const int is_red = A1;
const int is_green = A0;
const int conveyer_toggle = A2;


//const int stepsPerRevolution = 200;

//Stepper myStepper = Stepper(stepsPerRevolution, 10, 11, 12, 13);

void runSweeper(int IN1, int IN2, int ENA){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 20);
  delay(200);
  analogWrite(ENA, 0);
}

void runConveyor(int timeMilliseconds) {
  digitalWrite(IN1_PIN_conveyer, LOW);
  digitalWrite(IN2_PIN_conveyer, HIGH);
  digitalWrite(IN3_PIN_conveyer, LOW);
  digitalWrite(IN4_PIN_conveyer, HIGH);
  
  analogWrite(ENA_PIN_conveyer, 100);
  analogWrite(ENB_PIN_conveyer, 100);
/*
  for (int i = 0; i < 50; i ++){
    analogWrite(ENA_PIN_conveyer, i);
    analogWrite(ENB_PIN_conveyer, i);
  }
  */
/*
  delay(timeMilliseconds);

  for (int i = 127; i >= 0; i --){
    analogWrite(ENA_PIN_conveyer, i);
    analogWrite(ENB_PIN_conveyer, i);
  }

  digitalWrite(IN1_PIN_conveyer, LOW);
  digitalWrite(IN2_PIN_conveyer, LOW);
  digitalWrite(IN3_PIN_conveyer, LOW);
  digitalWrite(IN4_PIN_conveyer, LOW);
  */
}


void setup() {
  // put your setup code here, to run once:

  pinMode(ENA_PIN_sweeper_red, OUTPUT);
  pinMode(IN1_PIN_sweeper_red, OUTPUT);
  pinMode(IN2_PIN_sweeper_red, OUTPUT);

  pinMode(ENB_PIN_sweeper_green, OUTPUT);
  pinMode(IN3_PIN_sweeper_green, OUTPUT);
  pinMode(IN4_PIN_sweeper_green, OUTPUT);

  pinMode(ENA_PIN_conveyer, OUTPUT);
  pinMode(IN1_PIN_conveyer, OUTPUT);
  pinMode(IN2_PIN_conveyer, OUTPUT);

  pinMode(ENB_PIN_conveyer, OUTPUT);
  pinMode(IN3_PIN_conveyer, OUTPUT);
  pinMode(IN4_PIN_conveyer, OUTPUT);

  pinMode(is_red, INPUT);
  pinMode(is_green, INPUT);
  pinMode(conveyer_toggle, INPUT);

}

bool start_conveyer = false;
bool green = false;
bool red = false;

void loop() {
/*
  start_conveyer = digitalRead(conveyer_toggle);
  red = digitalRead(is_red);
  green = digitalRead(is_green);
  if(start_conveyer){
    runConveyer(1000);
    if(red){
      runSweeper(IN1_PIN_sweeper_red, IN2_PIN_sweeper_red, ENA_PIN_sweeper_red);
    }
    else if (green){
      runSweeper(IN3_PIN_sweeper_green, IN4_PIN_sweeper_green, ENB_PIN_sweeper_green);
    }
    delay(1000)
  }
  */
  
/*
  digitalWrite(IN1_PIN_sweeper_red, HIGH);
  digitalWrite(IN2_PIN_sweeper_red, LOW);

  analogWrite(ENA_PIN_sweeper_red, 100);

  digitalWrite(IN3_PIN_sweeper_green, LOW);
  digitalWrite(IN4_PIN_sweeper_green, HIGH);

  analogWrite(ENB_PIN_sweeper_green, 100);
  */

  //runConveyor(5000);
  runConveyor(1000);
  //delay(2000);
}
