void draw_volt(void) {

  u8x8.setFont(u8x8_font_px437wyse700b_2x2_r);
  u8x8.drawString(0, 0, "V1:");
  u8x8.drawString(results * multiplier);
  u8x8.drawString("mV");

  u8x8.setFont(u8x8_font_px437wyse700b_2x2_r);
  u8x8.drawString(0, 2, "V2:");
  u8x8.drawString(results * multiplier);
  u8x8.drawString("mV");
  
}
