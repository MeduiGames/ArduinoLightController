/*
 Name:		ColorPicker.ino
 Created:	23.09.2019 17:07:53
 Author:	Vladimir Mistrukov
*/

#define PIN_LED_RED 9
#define PIN_LED_YELLOW 8
#define PIN_LED_GREEN A4

byte currentState;
boolean currentMode; 

void setup() {
	pinMode(PIN_LED_RED, OUTPUT);
	pinMode(PIN_LED_YELLOW, OUTPUT);
	pinMode(PIN_LED_GREEN, OUTPUT);

	currentState = PIN_LED_RED;
	currentMode = true;
}

void loop() {
	digitalWrite(currentState, HIGH);
	delay(1000);  
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
