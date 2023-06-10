void rainbowStick()// fill the whle staff with a slow moving rainbow
{
  fill_rainbow(leds, NUM_LEDS, gHue, 7);
  FastLED.show();
  EVERY_N_MILLISECONDS(10) {
    gHue++;
  }
}
