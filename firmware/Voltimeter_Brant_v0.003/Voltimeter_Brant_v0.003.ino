//V0.001
// Leitor ADS1115 funcionando
//V0.002
// OLED funcionando
//v0.003
// Sensor de corrente

#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <U8x8lib.h>
#include <SPI.h>
#include "ACS712.h"

Adafruit_ADS1115 ads(0x49);
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

float Voltage1 = 0;
int VoltFACTOR1 = 3;
float Voltage2 = 0;

ACS712 sensor(ACS712_30A, A0);
byte i = 0;
float Amps = 0;

float Pot1 = 0;


void setup(void)
{
  u8x8.begin();
  ads.begin();
  Serial.begin(9600);


  u8x8.setFont(u8x8_font_8x13B_1x2_r  );
  u8x8.setCursor(0, 0);
  u8x8.setInverseFont(1);
  u8x8.println("   Volt-Brant   ");
  u8x8.setCursor(2, 2);
  u8x8.setInverseFont(0);
  u8x8.setFont(u8x8_font_8x13_1x2_f    );
  u8x8.println("CALIBRANDO");
  float zero = sensor.calibrate();
  delay(100);
  zero = zero + sensor.calibrate();
  delay(100);
  zero = zero + sensor.calibrate();
  delay(100);
  zero = zero / 3; 
  u8x8.println("PRONTO!");
  delay(1000);
  u8x8.clear();


}

void loop(void)
{


  int16_t dif1, dif2;

  dif1 = ads.readADC_Differential_0_1();
  Voltage1 = (dif1 * 0.1875) / 1000 * VoltFACTOR1 ;
  dif2 = ads.readADC_Differential_2_3();
  Voltage2 = (dif2 * 0.1875) / 1000;


  //Calculo da corrente
  //Serial.println(analogRead(VrefIn));
  float media = 0;
  for (int i = 0; i < 100; i++) {
    media = media + sensor.getCurrentDC();
    delay(1);
  }
  Amps = (media / 100);

  //Calculo Resistência
  Pot1 = Voltage1 * Amps;


  u8x8.setFont(u8x8_font_8x13B_1x2_r  );
  u8x8.setCursor(0, 0);
  u8x8.setInverseFont(1);
  u8x8.println("   Volt-Brant   ");
  u8x8.setCursor(2, 2);
  u8x8.setInverseFont(0);
  //  u8x8.print("V1: ");
  u8x8.setFont(u8x8_font_8x13_1x2_f    );
  u8x8.print(Voltage1);
  u8x8.print("V   ");
  u8x8.setCursor(2, 4);
  u8x8.print(Amps);
  u8x8.print("A   ");
  u8x8.setCursor(2, 6);
  u8x8.print(Pot1);
  u8x8.println("W   ");
  //u8x8.setFont(u8x8_font_8x13B_1x2_r  );
  //u8x8.print("V2: ");
  //u8x8.setFont(u8x8_font_8x13_1x2_n   );
  //u8x8.print(Voltage2);
  //u8x8.print("V");


  delay(1000);
}
