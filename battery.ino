void getvBat() {  // scale battery voltage to show much is left
  vBat = analogRead(A2);
  vBat = map(vBat, 200, 500, 0, NUM_LEDS - 1);
  fill_gradient_RGB(leds, NUM_LEDS, CRGB::Red, CRGB::Green);
  for (int i = NUM_LEDS - 1; i > vBat; i--) {
    leds[i] = CRGB::Black;
  }
  fadeToBlackBy(leds, NUM_LEDS, 50);
  FastLED.show();
}