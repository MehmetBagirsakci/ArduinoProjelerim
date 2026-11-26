String gelenKomut = "";


void setup() {
  Serial.begin(9600);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    gelenKomut = Serial.readStringUntil('\n');
    gelenKomut.trim();

    if (gelenKomut == "LED1_ON") {
      digitalWrite(8, HIGH);
    } else if (gelenKomut == "LED1_OFF") {
      digitalWrite(8, LOW);
    } else if (gelenKomut == "LED2_ON") {
      digitalWrite(9, HIGH);
    } else if (gelenKomut == "LED2_OFF") {
      digitalWrite(9, LOW);
    } else if (gelenKomut == "LED3_ON") {
      digitalWrite(10, HIGH);
    } else if (gelenKomut == "LED3_OFF") {
      digitalWrite(10, LOW);
    } else if (gelenKomut == "ALL_ON") {
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
    } else if (gelenKomut == "ALL_OFF") {
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    }
  }
}
