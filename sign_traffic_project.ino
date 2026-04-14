int yellow = 13;
int green = 11;

void setup() {
pinMode (yellow, OUTPUT);
pinMode (green, OUTPUT);
}

void loop() {
  digitalWrite (yellow, LOW);
  digitalWrite (green, HIGH);
  delay (5000);
  digitalWrite (yellow, HIGH);
  digitalWrite (green, LOW);
  delay (3000);
}
