void gyroRainbow() {                                             //use the accelerometer to change colors depending on how fast the staff is accelerating
  lis.read();                                                    //get data from gyro
  unsigned long scanTime = abs(map(lis.x, -500, 500, -10, 10));  // this could be skipped
  if (scanTime == 0) scanTime++;                                 // if scan time = 0 there is a divide by 0 error
  unsigned long now = millis();
  if (now - lastTime > 10000 / scanTime) {
    gHue++;
    fill_solid(leds, NUM_LEDS, CHSV(gHue, 255, 255));
    FastLED.show();
    lastTime = millis();
  }
}