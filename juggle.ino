void juggle() {  //update this to use the gyro
  BPM = 10;
  fadeToBlackBy(leds, NUM_LEDS, 5);


  leds[beatsin16(BPM, 0, NUM_LEDS - 1)] += CHSV(gHue, 200, 150);


  FastLED.show();
  EVERY_N_MILLISECONDS(10) {
    gHue++;
  }
}
