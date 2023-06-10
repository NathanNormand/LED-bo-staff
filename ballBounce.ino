void ballBounce() {  //use the accelerometer to move a ball across the stick, bouncing off of the ends
  lis.read();        // get X Y and Z data at once

  acc = map(lis.x, -4000, 4000, -G, G);  // 4k is the value of gravity


  aAcc = weight * aAcc + (1 - weight) * acc;       // quick averaging function
  vel += (aAcc * T);                               // velocity = acceleration * time
  vel = friction * vel;                            // add friction to stop velocity from going infinite
  if (pos == 0 && vel < 5) vel = -vel;             // make ball bounce off ends
  if (pos == NUM_LEDS - 1 && vel > 5) vel = -vel;  // make ball bounce off ends
  pos += vel * T;                                  // pos = pos0 + velocity * time
  pos = constrain(pos, 0, NUM_LEDS - 1);           // keep pos inside the pole


  leds[round(pos)] = CHSV(gHue, 255, 255);
  FastLED.show();
  fadeToBlackBy(leds, NUM_LEDS, 20);
}