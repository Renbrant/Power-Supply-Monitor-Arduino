//V0.001
// Leitor ADS1115 funcionando
//V0.002
// OLED funcionando

#include <Wire.h>
#include <Adafruit_ADS1015.h>
#include <U8x8lib.h>
#include <SPI.h>

Adafruit_ADS1115 ads(0x49);
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

float Voltage1 = 0;
float Voltage2 = 0;

void setup(void)
{
  u8x8.begin();
  ads.begin();
}

void loop(void)
{


  int16_t dif1, dif2;

  dif1 = ads.readADC_Differential_0_1();
  Voltage1 = (dif1 * 0.1875) / 1000;
  dif2 = ads.readADC_Differential_2_3();
  Voltage2 = (dif2 * 0.1875) / 1000;

  u8x8.setFont(u8x8_font_8x13B_1x2_r  );
  u8x8.setCursor(0, 0);
  u8x8.setInverseFont(1);
  u8x8.println("   Volt-Brant   ");
    u8x8.setCursor(2, 3);
  u8x8.setInverseFont(0);
//  u8x8.print("V1: ");
  u8x8.setFont(u8x8_font_profont29_2x3_f    );
  u8x8.print(Voltage1);
  u8x8.println("V");
  //u8x8.setFont(u8x8_font_8x13B_1x2_r  );
  //u8x8.print("V2: ");
  //u8x8.setFont(u8x8_font_8x13_1x2_n   );
  //u8x8.print(Voltage2);
  //u8x8.print("V");


  delay(1000);
}
