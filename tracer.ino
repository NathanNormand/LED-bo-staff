void tracer()  // four ball juggling effect
{
  // a colored dot sweeping back and forth, with fading trails
  BPM = 10;
  fadeToBlackBy(leds, NUM_LEDS, 50);
  int aPos = beatsin8(BPM, 0, NUM_LEDS - 1, 0, 0);
  int bPos = beatsin8(BPM, 0, NUM_LEDS - 1, 0, 63);
  int cPos = beatsin8(BPM, 0, NUM_LEDS - 1, 0, 127);
  int dPos = beatsin8(BPM, 0, NUM_LEDS - 1, 0, 191);
  leds[aPos] += CHSV(aHue, 255, 192);
  leds[bPos] += CHSV(bHue, 255, 192);
  leds[cPos] += CHSV(cHue, 255, 192);
  leds[dPos] += CHSV(dHue, 255, 192);

  FastLED.show();
  EVERY_N_MILLISECONDS(20) {
    aHue++;
  }
  EVERY_N_MILLISECONDS(30) {
    bHue++;
  }
  EVERY_N_MILLISECONDS(40) {
    cHue++;
  }
  EVERY_N_MILLISECONDS(50) {
    dHue++;
  }
}
