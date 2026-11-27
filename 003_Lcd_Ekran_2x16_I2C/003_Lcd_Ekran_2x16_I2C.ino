/*
  PROJE: I2C LCD Merhaba Dünya Uygulaması
  ********************************************
  GELİŞTİRME KARTI: Arduino UNO
  ********************************************
  KULLANILAN KÜTÜPHANE:
  "LiquidCrystal_I2C" by Frank de Brabander
  ******************************************************************************
  LCD ÖZELLİKLERİ:
  16x2 I2C LCD
  I2C Adresi: 0x27
  ******************************************************************************
  BAĞLANTI:
  VCC  -> 5V
  GND  -> GND
  SDA  -> A4
  SCL  -> A5
  ******************************************************************************
  AÇIKLAMA:
  LCD ekranın ilk satırında "Merhaba",
  ikinci satırında "Dunya" mesajı
  500 ms aralıklarla görüntülenir.
  ******************************************************************************
*/

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  //1.satır: Merhaba
  lcd.setCursor(0, 0);
  lcd.print("Merhaba");
  delay(500);
  lcd.clear();

  //2.satır: Dunya
  lcd.setCursor(0, 1);
  lcd.print("Dunya");
  delay(500);
  lcd.clear();
}
