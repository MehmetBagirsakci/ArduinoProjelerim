//IRremote Kütüphanesi ArminJo tarafından yazılmıştır.
//https://github.com/Arduino-IRremote/Arduino-IRremote

#include <IRremote.hpp>
#define ir_sensor 2
uint32_t komut = 0;

#define ileri 0xF30C7F00
#define geri 0xF20D7F00
#define sag 0xF10E7F00
#define sol 0xF00F7F00
#define dur 0xEF107F00
#define tekrar 0x00000000

uint32_t sonKomut = dur;
uint32_t sonKomutAlinmaZamani = 0;

#define IN1 4
#define IN2 5
#define IN3 6
#define IN4 7
#define ENA 9
#define ENB 10

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(ir_sensor, true);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);  // Print "old" raw data
    komut = IrReceiver.decodedIRData.decodedRawData;
    if (komut != tekrar) {
      sonKomut = komut;
    }
    sonKomutAlinmaZamani = millis();
    IrReceiver.resume();  // Enable receiving of the next value
  }
  if (sonKomut == ileri) {
    Serial.println("Araba ileri gidiyor");
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (sonKomut == geri) {
    Serial.println("Araba geri gidiyor");
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

  } else if (sonKomut == sag) {
    Serial.println("Araba SAGA donuyor");
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else if (sonKomut == sol) {
    Serial.println("Araba SOLA donuyor");
    analogWrite(ENA, 150);
    analogWrite(ENB, 150);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (komut == dur) {
    Serial.println("Araba durduruldu");
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  } else {
    Serial.println("Araba DURDU");
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }

  // 200ms içinde komut gelmezse motorları durdur.
  if (millis() - sonKomutAlinmaZamani > 200) {
    sonKomut = dur;
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}
