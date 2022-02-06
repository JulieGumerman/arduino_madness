////input variables
//int pulseSpeed = 5;
//
////ldr and led pins
//int ldrPin = 0;
//int redLed = 11;
//int greenLed = 10;
//int blueLed = 9;
//
//int ambientLight;
//int power = 150;
//float RGB[3];
//float CommonMathVariable = 180/PI; //called in "loop" function
//
//void setup() {
//
////data output to LEDs from UNO R3
//pinMode (redLed,OUTPUT);
//pinMode (greenLed,OUTPUT);
//pinMode (blueLed,OUTPUT);
//
////the OUTPUT above is that the LEDs are off until told otherwise
//digitalWrite (redLed,LOW);
//digitalWrite (greenLed,LOW);
//digitalWrite (blueLed,LOW);
//
//}
//
//void loop() {
//
//////continually adjust ligthing
////for (float x = 0; x < PI; x - x + 0.00001) { 
////  // Red LED. 
////  RGB[0] - power * abs(sin(x * (CommonMathVariable))); // Green LED. 
////  RGB[1] - power * abs(sin((x + PI/3) * 
////  (CommonMathVariable))); 
////  // Blue LED. 
////  RGB[2] - power * abs(sin((x + (2 * PI) / 3) * 
////  (CommonMathVariable))); 
////
////  //read and store light in room as number
////  ambientLight = analogRead(ldrPin);
////
////  //lamp turns on if dark; the higher the #, the darker it is
////  if (ambientLight > 500) {
////    
////    //values above communicated to LEDs on breadboard
////    analogWrite (redLed,RGB[0]);
////    analogWrite (greenLed,RGB[1]);
////    analogWrite (blueLed,RGB[2]);  
////   } else {
////    //turns light off if room is too bright
////    digitalWrite (redLed,LOW); 
////    digitalWrite (greenLed,LOW);
////    digitalWrite (blueLed,LOW);
////   }
////   //calculate delay -- brighter LEDs change color more slowly
////  for (int i=0; i < 3; i++) {
////    if (RGB[i] < 1) {
////      delay (20 * pulseSpeed);  
////    } else if (RGB[i] < 5) {
////      delay (20 * pulseSpeed); 
////    } else if (RGB[i] < 10) {
////      delay (2 * pulseSpeed);  
////    } else if (RGB[i] < 100) {
////      delay (1 * pulseSpeed);  
////    } else {}
////    
////  } //close inner for loop
////  delay(10);
////  } //close outer for loop
//} //close loop

/*  Creation Crate Mood Lamp
This lamp smoothly cycles through a colour spectrum.
It only turns on when its surroundings are dark.
Color equations (we’ll be using these later):

These equations are how the program will calculate the brightness of the LEDs.
Red = sin(x)
Green = sin(x + PI/3)
Blue = sin(x + 2PI/3)

Step 1: Input User Defined Variables
Think of variables like containers - they’re used to store information. */

int pulseSpeed = 5; //  This value controls how fast the mood lamp runs. You can replace this with any whole number. 

//  These are the pins we are using with the UNO R3 (Arduino-compatible). You can see the numbers on the board itself.
int ldrPin = 0;     // LDR in Analog Input 0 to read the surrounding light.
int redLed = 11;    // red LED in Digital Pin 11.
int greenLed = 10;  // green LED in Digital Pin 10.
int blueLed = 9;    // blue LED in DIgital Pin 9.
int ambientLight;   // This variable stores the value of the light in the room.
int power = 150;    // This variable controls the brightness of the lamp (2-255).
float RGB[3];       // This is an ‘array’. It holds 3 values: RGB[0], RGB[1], and RGB[2], used to store the values of the Red, Blue, and Green LEDs.
float CommonMathVariable = 180/PI;

/* Step 2: Create Setup Function - This function runs once in the beginning to create the default values for our LEDs. */
void setup () 
{
  Serial.begin(9600);       //This sets the communication speed for the Serial Monitor, which can be used for testing.
  // These tell the UNO R3 that data is sent OUT of these pins to the LEDs.
  pinMode (redLed,OUTPUT);
  pinMode (greenLed,OUTPUT);
  pinMode (blueLed,OUTPUT);
  
  //  This sets all the outputs (LEDs) to low (as in off), so that they do not turn on during startup.
  digitalWrite (redLed,LOW);
  digitalWrite (greenLed,LOW);
  digitalWrite (blueLed,LOW);
}   // Opening brackets must be accompanied by closing brackets.

/* Step 3: Create Main Loop
The previous sections are where we set up the variables. This section is 
where we put them to work! This part of the program is a ‘loop’. It 
repeats itself over and over again, making a small change in the 
brightness of the LEDs each time - this creates a smooth transition in 
colour. */

void loop () {

for (float x = 0; x < PI; x = x + 0.00001) 
  {
    RGB[0] = power * abs(sin(x * (CommonMathVariable)));                  // Red LED.
    RGB[1] = power * abs(sin((x + PI/3) * (CommonMathVariable)));         // Green LED.
    RGB[2] = power * abs(sin((x + (2 * PI) / 3) * (CommonMathVariable))); // Blue LED.
    
    ambientLight = analogRead(ldrPin);      // This reads the light in the room and stores it as a number.
    Serial.println(ambientLight);           // We can print the value of the ldr to the Serial Monitor for testing
  
    // This ‘if statement’ will make the lamp turn on only if it is dark. The darker it is, the higher the number.
    if (ambientLight > 500) 
    {
    // These ‘analogWrite’ statements will send the values calculated above to the LEDs. 
    analogWrite (redLed,RGB[0]);
    analogWrite (greenLed,RGB[1]);
    analogWrite (blueLed,RGB[2]);
    } // Don’t forget to close this ‘if statement’ with a bracket!
  
  // This ‘else statement’ will only activate if the ‘if statement’ above does not (ie. If it is too bright in the room). The LEDs will turn off. 
    else {
    digitalWrite (redLed,LOW);
    digitalWrite (greenLed,LOW);
    digitalWrite (blueLed,LOW);
    }
  
  // This loop calculates the delay for each colour depending on its current brightness. Brighter LEDs will change colour slower and vice versa.
  for (int i = 0; i < 3; i++) {
  
    if (RGB[i] < 1) {
    delay (20 * pulseSpeed);
    }
  
  // using ’else if’ means only one of these conditions can activate at a time. Once one is true, the program jumps to the end of the statement.    
    else if (RGB[i] < 5) {
    delay (10 * pulseSpeed);
    }
    
    else if (RGB[i] < 10) {
    delay (2 * pulseSpeed);
    }
    
    else if (RGB[i] < 100) {
    delay (1 * pulseSpeed);
    }
     
    // This blank ‘else statement’ is a fail-safe mechanism. It instructs the program to do nothing if the conditions above do not activate. This prevents the program from generating errors when calculating delays. 
    else {}
  }
  
  delay(10);
  }
}
