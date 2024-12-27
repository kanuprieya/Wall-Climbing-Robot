
int ST = 8; // Suction top
int SB = 9; // Suction bottom
int CT = 11; // Cylinder top
int CB = 12; // Cylinder bottom
int k = 0;

void setup() {
  pinMode(ST, OUTPUT);
  pinMode(SB, OUTPUT);
  pinMode(CT, OUTPUT);
  pinMode(CB, OUTPUT);
  Serial.begin(9600);
}

void moveUp() {
  digitalWrite(SB, LOW);
  delay(1500);
  digitalWrite(ST, HIGH);
  delay(1500);
  digitalWrite(CB, LOW);
  delay(500);
  digitalWrite(CB, HIGH);
  delay(1500);
  digitalWrite(ST, LOW);
  delay(1500);
  digitalWrite(SB, HIGH);
  delay(1500);
  digitalWrite(CT, LOW);
  delay(500);
  digitalWrite(CT, HIGH);
  delay(1500);
  digitalWrite(SB, LOW);
}

void moveDown() {
  digitalWrite(ST, LOW);
  delay(1500);
  digitalWrite(SB, HIGH);
  delay(1500);
  digitalWrite(CB, LOW);
  delay(500);
  digitalWrite(CB, HIGH);
  delay(1500);
  digitalWrite(SB, LOW);
  delay(1500);
  digitalWrite(ST, HIGH);
  delay(1500);
  digitalWrite(CT, LOW);
  delay(500);
  digitalWrite(CT, HIGH);
  delay(1500);
  digitalWrite(ST, LOW);
}

void hold() {
  digitalWrite(CB, HIGH);
  digitalWrite(CT, HIGH);
  digitalWrite(ST, LOW);
  digitalWrite(SB, LOW);
}

void loop() {
  if (k == 0) {
    digitalWrite(ST, HIGH);
    digitalWrite(SB, HIGH);
    digitalWrite(CT, HIGH);
    digitalWrite(CB, HIGH);
    delay(1000);
    k++;
  }
  digitalWrite(ST, LOW);
  digitalWrite(SB, LOW);
  delay(5000);

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      moveUp();
      delay(2000);
    } else if (command == '2') {
      moveDown();
      delay(2000);
    } else if (command == '3') {
      hold();
    } 
  }
}
