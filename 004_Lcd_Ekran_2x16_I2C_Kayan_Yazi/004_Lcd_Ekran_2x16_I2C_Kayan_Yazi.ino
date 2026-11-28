/*
  PROJE: I2C LCD Kayan Yazi Uygulaması
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
  LCD ekranın ilk satırında "Merhaba" Sağdan Sola kayar.
  ******************************************************************************
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// LCD özellikleri
const int LCD_SUTUN = 16;
const int LCD_SATIR = 2;

// Kaydırılacak metin
const char METIN[] = "Merhaba";
const int METIN_UZUNLUK = sizeof(METIN) - 1;

// Animasyon ayarları
const unsigned long KAYMA_SURESI = 250;

// Zaman ve animasyon değişkenleri
unsigned long oncekiZaman = 0;
int adim = 0;

const int TOPLAM_ADIM = LCD_SUTUN + METIN_UZUNLUK;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {

  unsigned long simdikiZaman = millis();

  if (simdikiZaman - oncekiZaman >= KAYMA_SURESI) {

    oncekiZaman = simdikiZaman;

    lcd.clear();

    int konum = LCD_SUTUN - 1 - adim;
    int baslangic = 0;

    // Yazı ekranın solundan çıkmaya başladıysa
    if (konum < 0) {
      baslangic = -konum;
      konum = 0;
    }

    lcd.setCursor(konum, 0);
    lcd.print(METIN + baslangic); //pointer: METIN dizisinin başlangıç adresine baslangic kadar ilerliyoruz.

    adim++;

    // Animasyonu yeniden başlat
    if (adim >= TOPLAM_ADIM) {
      adim = 0;
    }
  }
}