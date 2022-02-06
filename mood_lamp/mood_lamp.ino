//input variables
int pulseSpeed = 5;

//ldr and led pins
int ldrPin = 0;
int redLed = 11;
int greenLed = 10;
int blueLed = 9;

int ambientLight;
int power = 150;
float RBG[3];
float CommonMathVariable = 180/PI; //called in "loop" function

void setup() {

//data output to LEDs from UNO R3
pinMode (redLed,OUTPUT);
pinMode (greenLed,OUTPUT);
pinMode (blueLed,OUTPUT);

//the OUTPUT above is that the LEDs are off until told otherwise
digitalWrite (redLed,LOW);
digitalWrite (greenLed,LOW);
digitalWrite (blueLed,LOW);

}

void loop() {

//continually adjust ligthing
for (float x - 0; x < Pl; x - x + 0.00001) { 
  // Red LED. 
  RGB[O] - power * abs(sin(x * (CommonMathVariable))); // Green LED. 
  RGB[l] - power * abs(sin((x + Pl/3) * 
  (CommonMathVariable))); 
  // Blue LED. 
  RGB[2] - power * abs(sin((x + (2 * Pl) / 3) * 
  (CommonMathVariable))); 

  //read and store light in room as number
  ambientLight = analogRead(ldrPin);

  //lamp turns on if dark; the higher the #, the darker it is
  if (ambientLight > 600) {
    
    //values above communicated to LEDs on breadboard
    analogWrite (redLed,RGB[0]);
    analogWrite (greenLed,RGB[1]);
    analogWrite (blueLed,RGB[2])  
   } else {
    //turns light off if room is too bright
    digitalWrite (redLed,LOW); 
    digitalWrite (greenLed,LOW);
    digitalWrite (blueLed,LOW);
   }
   //calculate delay -- brighter LEDs change color more slowly
  for (int i=0); i < 3; i++) {
    if (RGB[i] < 1) {
      delay (20 * pulseSpeed);  
    } else if (RGB[i] < 5) {
      delay (20 * pulseSpeed  
    } else if (RGB[i] < 10 {
      delay (2 * pulseSpeed);  
    }
    
    }
    
  }
  



}
