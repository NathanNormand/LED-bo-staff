void glitter()  // this creates a random rainbow sparkle
{

  if (random8() < 100) leds[random8(NUM_LEDS)] += CHSV(random8(255), 255, 255);
  fadeToBlackBy(leds, NUM_LEDS, 20);
  FastLED.show();
}
