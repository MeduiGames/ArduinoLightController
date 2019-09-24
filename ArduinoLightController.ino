/*
 Name:    Traffic Light Controller
 Created: 23.09.2019 17:07:53
 Author:  Vladimir Mistrukov
*/

#define PIN_LED_RED 8
#define PIN_LED_YELLOW 9
#define PIN_LED_GREEN 10

#define PIN_CONTROLLER_BUTTON 4

void controllerUpdate();
void lightsUpdate();

byte currentState;
boolean currentMode;
int currentSpeed;

void setup() {
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);

  pinMode(PIN_CONTROLLER_BUTTON, INPUT);

  currentState = PIN_LED_RED;
  currentMode = true;
  currentSpeed = 1000;

  Serial.begin(9600);
}

void loop() {
  controllerUpdate();
  lightsUpdate();
}

void controllerUpdate()
{
  if(digitalRead(PIN_CONTROLLER_BUTTON) == LOW){
    digitalWrite(currentState, LOW);
    currentState = PIN_LED_YELLOW;
    currentMode = false;
  }
}

void lightsUpdate()
{
  digitalWrite(currentState, HIGH);
  
  if(micros() % 10 != 0 || millis() % 1000 != 0){ 
    return;  
  }
  
  delay(1);
  digitalWrite(currentState, LOW);
  if(currentMode){
    if(currentState == PIN_LED_RED){
      currentState = PIN_LED_YELLOW;
    }
    else if(currentState == PIN_LED_YELLOW){
      currentState = PIN_LED_GREEN;
      currentMode = false;
    }
  }
  else {
    if(currentState == PIN_LED_GREEN){
      currentState = PIN_LED_YELLOW;
    }
    else if(currentState == PIN_LED_YELLOW){
      currentState = PIN_LED_RED;
      currentMode = true;
    }
  }
}

