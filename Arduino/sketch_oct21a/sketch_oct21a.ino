const int potPin = 13 ;

int potValue = 0 ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  if (potValue > 500) {
    Serial.println(potValue);
    Serial.println("Turn 'on' fan!!");
  }
  else {
  Serial.println(potValue);
}

delay(1000);

}
