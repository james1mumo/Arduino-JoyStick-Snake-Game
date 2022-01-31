int xValue = 0 ;
int yValue = 0 ;
int bValue = 0 ;

int vRXPin = A5;
int vRYPin = A4;
int pushButtonPin = 2;


void setup(){
  Serial.begin(9600) ;
  pinMode(pushButtonPin,INPUT_PULLUP);
}

void loop(){
  xValue = analogRead(vRXPin);
  yValue = analogRead(vRYPin);
  bValue = digitalRead(pushButtonPin);

  Serial.print(xValue,DEC);
  Serial.print(",");
  Serial.print(yValue,DEC);
  Serial.print(",");
  Serial.print(!bValue);
  Serial.print("\n");
  delay(10);
}int xValue = 0 ;
int yValue = 0 ;
int bValue = 0 ;

int vRXPin = A5;
int vRYPin = A4;
int pushButtonPin = 2;


void setup(){
  Serial.begin(9600) ;
  pinMode(pushButtonPin,INPUT_PULLUP);
}

void loop(){
  xValue = analogRead(vRXPin);
  yValue = analogRead(vRYPin);
  bValue = digitalRead(pushButtonPin);
  

  Serial.print("x");
  Serial.print(xValue,DEC);
  Serial.print(",y");
  Serial.print(yValue,DEC);
  Serial.print(",b");
  Serial.print(!bValue);
  Serial.print("\n");
  delay(10);
}