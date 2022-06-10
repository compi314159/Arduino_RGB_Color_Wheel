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
int xvalue = 0;
int yvalue = 0;
float redColor;
float blueColor;

void loop() {
  xvalue = analogRead(Y_pin)-506;
  yvalue = analogRead(X_pin)-506;
  float color = abs((float)atan((float)yvalue/xvalue));  
  if(xvalue<0&&yvalue<0){
    color = color + 3.14159265358979;
  }
  else if(xvalue>0&&yvalue<0){
    color = color + 4.71238898038;
    }
  else if(xvalue<0&&yvalue>0){
    color = color + 1.57079632679;
  }
  greenValue =((abs(3.14159265359-(float)color))/3.14159265359)*255;
  if((color - 2.09439510239)<0){
    blueColor = color + 6.28318530718;
  }
  blueValue = ((abs(3.14159265359-(blueColor-2.09439510239)))/3.14159265359)*255;
  if((color - 4.18879020479)<0){
    redColor = color + 6.28318530718;
  }
  redValue = ((abs(3.14159265359-(redColor-4.18879020479)))/3.14159265359)*255;
  if(greenValue <= 0){
    greenValue = 0;
  }
  /*if(2.09439510239<color<4.18879020479){
    greenValue = 0;
  }
  if(2.09439510239<redColor<4.18879020479){
    redValue = 0;
    }
  if(2.09439510239<blueColor<4.18879020479){
    blueValue = 0;
    }  */
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
  Serial.print("\t");
  Serial.print("X-axis: ");
  Serial.print(xvalue);
  Serial.print("\t");
  Serial.print("Y-axis: ");
  Serial.print(yvalue);
  Serial.print("\t");
  Serial.print(redValue);
  Serial.print("\t");
  Serial.print(blueValue);
  Serial.print("\t");
  Serial.print(greenValue);
  Serial.print("\t");  
  Serial.print("Color:");
  Serial.print(color);
  Serial.print("\n\n");
}
