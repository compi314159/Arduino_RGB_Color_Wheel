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
float xvalue = 0;
float yvalue = 0;
float theta;
float radius; 
float bluetheta = theta;
float redtheta = theta;
float greenValue;
float blueValue; 
float redValue;
int Switch;

void loop() {
  xvalue = analogRead(Y_pin)-505;
  yvalue = analogRead(X_pin)-507;
  theta = atan(yvalue/xvalue);
  radius = (sqrt(xvalue*xvalue+yvalue*yvalue))/(sqrt(505.5*505.5+507*507));
  if (radius >= 1) {
    radius = 1;
  }
  //add if statement here to account for 0 and 1 for xvalue at theta = 0
  if (xvalue < 0 && yvalue >= 0) {
    theta = theta + 3.14159265359;
  }
  else if (xvalue < 0 && yvalue < 0) {
    theta = theta - 3.14159265359;
  }
  greenValue = (1-abs(theta/2.09439510239))*255*radius;
  if (greenValue <= 0) {
    greenValue = 0;
  }
  if (theta < 0) {
    theta = theta + 6.28318530718;
  }
  bluetheta = theta - 2.09439510239;
  blueValue = (1-abs(bluetheta/2.09439510239))*255*radius;
  if (blueValue <= 0) {
    blueValue = 0;
  }
  if (bluetheta < 0) {
    bluetheta = bluetheta + 6.28318530718;
  }
  redtheta = bluetheta - 2.09439510239;
  redValue = (1-abs(redtheta/2.09439510239))*255*radius;
  if (redValue <= 0) {
    redValue = 0;
  }
  Switch = digitalRead(SW_pin);
  if (Switch == 0){
    redValue = 255;
    blueValue = 255;
    greenValue = 255;
  }
  //Write values to LED
  analogWrite(RED, redValue);
  analogWrite(GREEN, greenValue);
  analogWrite(BLUE, blueValue); 
  //Print to Serial Monitor
  Serial.print("X-axis: ");
  Serial.print(xvalue);
  Serial.print("\t");
  Serial.print("Y-axis: ");
  Serial.print(yvalue);
  Serial.print("\t");
  Serial.print("Theta: ");
  Serial.print(theta);
  Serial.print("\t");
  Serial.print("R: ");
  Serial.print(radius);
  Serial.print("\t\t");
  Serial.print("Green Value:");
  Serial.print(greenValue);
  Serial.print("\t\t");
  Serial.print("Blue Value:");
  Serial.print(blueValue);
  Serial.print("\t\t");
  Serial.print("Red Value:");
  Serial.print(redValue);
  Serial.print("\n\n");
}
