int motorLpin1=6;
int motorLpin2=7;
int motorRpin1=9;
int motorRpin2=8;
int motorLpwm=10;
int motorRpwm=11;
int motorSpeed=40;
int turn=15;
int buzzer = 4;
int light = 5;

void setup() {
  Serial.begin(9600);
  pinMode(motorLpin1,OUTPUT);
  pinMode(motorLpin2,OUTPUT);
  pinMode(motorRpin1,OUTPUT);
  pinMode(motorRpin2,OUTPUT);
  pinMode(motorLpwm,OUTPUT);
  pinMode(motorRpwm,OUTPUT);
  pinMode(light, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
 
}

void loop() {
  String input="";
  while(Serial.available()){
    input+=(char)Serial.read();
    //delay(5);
  }
 
  if(input=="S"){
    stp();
  }
  else if(input=="F"){
   fwd();
  }
  else if(input=="B"){
    rev();
  }
  else if(input=="L"){
    lft();
  }
  else if(input=="R"){
    rght();
  }
  else if(input=="Q"){
   lightOn();
  }
  else if(input=="q"){
   lightOff();
  }
  else if(input=="P"){
   buzzerOn();
  }
   else if(input=="p"){
   buzzerOff();
  }
  else if(input=="W"){
    rotation();
  }  
  else if(input!=""){
    motorSpeed=(input.toInt()*25);

    Serial.println(motorSpeed);
    delay(1000);
  }
}

void lft(){
  analogWrite(motorLpwm,40);
  analogWrite(motorRpwm,40);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
Serial.println("left");
}

void rght(){
  analogWrite(motorLpwm,40);
  analogWrite(motorRpwm,40);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
  Serial.println("rev");
}

void rev(){
  analogWrite(motorLpwm,40);
  analogWrite(motorRpwm,40);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  Serial.println("rev");
}

void fwd(){
  analogWrite(motorLpwm,40);
  analogWrite(motorRpwm,40);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
  Serial.println("for");
}

void stp(){
  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,0);
  Serial.println("stop");
}
void rotation(){
  analogWrite(motorLpwm,40);
  analogWrite(motorRpwm,40);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  Serial.println("360rotation");
}
void buzzerOn() {
    digitalWrite(buzzer, HIGH);
    }
void lightOn()  {
    digitalWrite(light, HIGH);
  }
  void buzzerOff() {
    digitalWrite(buzzer, LOW);
    }
void lightOff()  {
    digitalWrite(light, LOW);
  }
