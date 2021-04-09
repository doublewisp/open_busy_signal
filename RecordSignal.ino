
//variable declaration
const int ledPin[] = {8,9}; //red,green
const int btnPin[] = {3,2,4}; //red, green, white

int ledStates[] = {0,0,0}; //red, green, white
int btnStates[] = {LOW,LOW,LOW}; //red, green, white

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {

  //set the mode of the pins...
  for(int i=0; i<=1; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  for(int i=0; i<=2; i++){
    pinMode(btnPin[i], INPUT);
  }
  
  //set initial led state
  for(int i=0; i<=1; i++){
    digitalWrite(ledPin[i], ledStates[i]);
  }
}

void loop() {

  //cycle through buttons and sample state
  for (int i=0; i<=2; i++){
    btnStates[i] = digitalRead(btnPin[i]); //read input pin
    
    //filter out any noise by setting a time buffer
    if ( (millis() - lastDebounceTime) > debounceDelay) {

      //if the button has been pressed
      if (btnStates[i] == HIGH) {

        switch (i) {
          case 0: //red pressed
              digitalWrite(ledPin[0], HIGH); //turn red LED on
              ledStates[0] = 1; //change LED state
              digitalWrite(ledPin[1], LOW); //turn gree LED off
              ledStates[1] = 0; //change LED state
              lastDebounceTime = millis(); //set the current time
            break;
          case 1: //green pressed
              digitalWrite(ledPin[1], HIGH); //turn LED on
              ledStates[1] = 1; //change LED state
              digitalWrite(ledPin[0], LOW); //turn LED on
              ledStates[0] = 0; //change LED state
              lastDebounceTime = millis(); //set the current time
            break;
          case 2: //white pressed
              for(int i=0; i<=1; i++){ //turn all LEDs off
                 digitalWrite(ledPin[i], LOW);
                ledStates[i] = 0; //change LED state
              }
              lastDebounceTime = millis(); //set the current time
            break;
          default:
            // statements
            break;
        }
      }
      btnStates[i] == LOW;
    }//close if(time buffer)
  }

}//close void loop
