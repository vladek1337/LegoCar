#include <LiquidCrystal.h>

const int D4 = 2;
const int D5 = 3;
const int D6 = 4;
const int D7 = 5;
const int V0 = 6;
const int En = 7;
const int Rs = 12;

const int Pin0 = 8;
const int Pin1 = 9;
const int Pin2 = 10;
const int Pin3 = 11;

const int Echo = A0;
const int Trig = A1;

int stp = 0;
int i = 499; 
int dst = -1;
LiquidCrystal lcd(Rs, En, D4, D5, D6, D7);

void nextStep()
{
  stp++;
  if (stp > 7)
    stp = 0;
  switch (stp)
  {
    case 0:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    case 1:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      break;
    case 2:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 3:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      break;
    case 4:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 5:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 6:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
    case 7:
      digitalWrite(Pin0, HIGH);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      break;
    default:
      digitalWrite(Pin0, LOW);
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      break;
  }
}

int measureDistance()
{
  int dist = -1;
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  dist = pulseIn(Echo, HIGH);
  digitalWrite(Echo, LOW);
  return dist;
}

void printLCD()
{
  lcd.clear();
  lcd.print("DIST: ");
  lcd.print(dst*0.034/2);
  lcd.print("cm");
  lcd.setCursor(0,1);
  if(dst < 400)
    lcd.print("LOW DISTANCE!");
  else 
    lcd.print("Safe Distance!"); 
}

void setup()
{
  pinMode(Pin0, OUTPUT);
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);

  pinMode(Echo, INPUT);
  pinMode(Trig, OUTPUT);

  lcd.begin(16, 2);
  analogWrite(V0, 10);
  lcd.print("Lego Car v1.0");
  lcd.setCursor(0,1);
  lcd.print("Initializing...");
  delay(3000);
}
void loop()
{
  i++;
  
  if(i == 500) 
  {
    dst = measureDistance();
    printLCD();
    while (dst < 400)
    {     
      dst = measureDistance();
      printLCD();
      delay(500);
    }   
    i = 0;
  }
  else delay(1);
  nextStep();
}



