#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int trig = 13;
int eco = 12;
int led = 11;
long duracion;
int distancia;

void setup() {
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(trig, LOW);
   delay(100);
  digitalWrite(trig, HIGH);
   delay(200);
  digitalWrite(trig, LOW);

  duracion = pulseIn(eco, HIGH);
  distancia = duracion / 58.2; 


  Serial.print("Distancia del objeto: ");
  Serial.print(distancia);
  Serial.println(" cm");


  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia obj. :");
  lcd.setCursor(0, 1);
  lcd.print(distancia);
  lcd.print(" cm");


  if (distancia <= 20) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }

  delay(200);
}
