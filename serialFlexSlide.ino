const int FLEX_PIN = A2; // Pin connected to voltage divider output
const int X_PIN = A0;
const int Y_PIN = A1;

int xValue = 0 ;
int yValue = 0 ; 

// 5V and 47k resistor
const float VCC = 3.3;
const float R_DIV = 47500.0;

// Upload the code, then try to adjust these values to more
// accurately calculate bend degree.
const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0; // resistance at 90 deg

void setup() 
{
  Serial.begin(9600);
  pinMode(FLEX_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
}

void loop() 
{
  xValue = analogRead(X_PIN) ;  
  yValue = analogRead(Y_PIN) ; 
  int flexADC = analogRead(FLEX_PIN);
  
  float flexV = flexADC * VCC / 1023.0;
  int flexR = R_DIV * (VCC / flexV - 1.0);
  float angle = map(flexR, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 180.0);  // bend angle
  int anglePlus = -angle;
  
      String xValSt = String(xValue);
      Serial.print(xValue);
      Serial.print(",");

      Serial.print(yValue);
      Serial.print(",");

      Serial.print(anglePlus);
      Serial.println(",");  
  delay(10);
}
