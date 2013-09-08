
//naming pins
int led1 = 13;
int led2 = 12;
int button1 = 10;

int buttoncounter = 0; //counts how many times button pushed
int buttonstate = 3;  //tells current state of button
int laststate = 3;  //tells previous state of button

int debouncebuttonstate;
int lastdebouncebuttonstate = LOW;
long lastdebouncetime = 0;         // the last time the output pin was toggled
long debouncedelay = 200;   // the debounce time, increase if the output flickers

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led1, OUTPUT); 
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT); 
  Serial.begin (9600);

}

// the loop routine runs over and over again forever:
// all blinking
void loop() {
int reading = digitalRead (button1);
if (reading != laststate) {
  lastdebouncetime = millis ();
}

if ((millis() - lastdebouncetime) > debouncedelay) {
  if (reading != laststate) {
    laststate = reading;
  //if buttonstate has changed, increment counter
  if (buttonstate == HIGH) {
    buttoncounter++; // button went from "off' to "on"
  }
  }
}


//bouncing
if (buttoncounter % 4==0) {
  Serial.println("mode 0");
  digitalWrite(led1, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(200);
  digitalWrite(led2, HIGH);
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, LOW);
  delay(1000);               // wait for a second
}
//all on
if (buttoncounter % 5==0) {
  digitalWrite(led1, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);
}
//flashing together
if (buttoncounter % 6==0) {
  digitalWrite(led1, HIGH);  // turn the LED on (HIGH is the voltage level)
  digitalWrite(led2, HIGH);
  delay(1000);               // wait for a second
  digitalWrite(led1, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led2, LOW);
  delay(1000);               // wait for a second  
} 
//all off
if (buttoncounter % 7==0) {
  digitalWrite(led1, LOW);  // turn the LED off (LOW is the voltage level)
  digitalWrite(led2, LOW);
if (buttoncounter >= 8) {
  buttoncounter=4;
}
}
}


