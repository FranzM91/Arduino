/**

*/
float tempC;
int pinLM35 = 0;

void setup() {
  // put your setup code here, to run once:
  analogReference(INTERNAL);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempC = analogRead(pinLM35);
  tempC = (1.1 * tempC * 100.0)/1024.0; 
  if(27 > tempC && tempC < 30) {
    digitalWrite(13, HIGHT);
  } else {
    digitalWrite(13, LOW);
  }
  Serial.print("#");
  Serial.print(tempC);
  Serial.print("\n");
  delay(1000);
}