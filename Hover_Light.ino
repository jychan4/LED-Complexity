/*
DigitalReadSerial
Reads a digital input on pin A0, prints the result to the Serial Monitor
This example code is in the public domain.
http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

/*for this assignment I combined the button press blink and the sensor form the in class assignments
but made the sensor perform as the button - I also made it flicker*/

/* The code works as follows: The light will be constatntly be blinking in regular room light 
 (At least for my darkish room lol). When you shine a light on the sensor the light only stays on
 and when you put you hand over the sensor the light stops.
 */

  //here I have where things are pulged in on the board
  const int InternalLED = 13; 
  const int ExternalLED = 12; 

  int HoverButton = A0;
  
  
  void setup() {
   // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
   // make the pins an inputs and outputs:
  
  pinMode(HoverButton, INPUT);
  pinMode(InternalLED, OUTPUT);
  pinMode(ExternalLED, OUTPUT);
  }

  // the main loop
  void loop() {

  //defining sensor vales as an int
  int sensorValue = analogRead(HoverButton);

  //saying that the light will only work under the following set of inputs on the terminal
  sensorValue = constrain(sensorValue, 1300, 3700);
  
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability

  if(sensorValue > 3000){
    digitalWrite(ExternalLED, HIGH);   // this turns the light on for good
  }
  
  else if(sensorValue > 1300 && sensorValue < 2500 ) {
    //this makes the button blink constantly
    digitalWrite(ExternalLED, HIGH); 
    delay(100);                       
    digitalWrite(ExternalLED, LOW);    
    delay(100);      
   }else{
    //this turns the button off
     digitalWrite(ExternalLED, LOW);
    }
   
  }
