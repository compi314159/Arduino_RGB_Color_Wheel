//www.elegoo.com
//2016.12.09

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
int xvalue = 0;
int yvalue = 0;
void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

// define variables
float greenValue; 
float redValue;
float blueValue;

void loop() {
  xvalue = analogRead(X_pin);
  yvalue = analogRead(Y_pin);
  greenValue = ((507-((float)xvalue))/507)*255;
  redValue = (((float)xvalue-507)/507)*255;
  blueValue = (((float)yvalue-507)/507)*255;

  if(greenValue <= 0){
    greenValue = 0;
  }
  if(redValue >= 255){
    redValue = 255;
  }
  if(redValue <= 0){
    redValue = 0;
  }
  if(blueValue >= 255){
    blueValue = 255;
  }
  if(blueValue <= 0){
    blueValue = 0;
  }
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue); 
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n");
  Serial.print(redValue);
  Serial.print("\n");
  Serial.print(blueValue);
  Serial.print("\n");
  Serial.print(greenValue);
  Serial.print("\n\n");
}
