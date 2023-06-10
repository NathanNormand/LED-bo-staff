// gyro bo staff
//6/7/2023

#include <FastLED.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

#define NUM_LEDS 100
#define BRIGHTNESS 150
#define CLICKTHRESHHOLD 80             // accelerometer threshhold
#define Serial SERIAL_PORT_USBVIRTUAL  // make qtpy happy
#define G 9.8                          //gravity acceleration, may need small tweaking
#define T 0.02                         //200hz mean reading every 5 milliseconds
#define weight 0.9                     // used in averaging, smaller = less smoothing
#define friction 0.99                  // used to slow speed down, smaller number = more slowing
#define clickDelay 1000                //how long to wait between clicks

Adafruit_LIS3DH lis = Adafruit_LIS3DH();
CRGB leds[NUM_LEDS];
CRGB temp[NUM_LEDS];


uint8_t BPM = 10;
uint8_t aHue = 0;
uint8_t bHue = 64;
uint8_t cHue = 128;
uint8_t dHue = 192;
uint8_t gHue = 0;
uint8_t mode = 0;
unsigned long lastTime = 0;
unsigned long lastClick = 0;
int vBat;
float pos = 50;
float vel, acc;
float aAcc;

void setup() {
  FastLED.addLeds<WS2811, 3, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.setMaxPowerInMilliWatts(1000);
  //Serial.begin(9600);
  lis.begin(0x18);  //200hz means reading every 5 milliseconds
  lis.setRange(LIS3DH_RANGE_8_G);
  lis.setClick(2, CLICKTHRESHHOLD);
}

void loop() {

  if (lis.getClick() >= 100) {
    if (millis() - lastClick > clickDelay) {
      mode++;
      lastClick = millis();
    }
    //Serial.println(mode);
  }

  switch (mode) {
    case 0: getvBat(); break;
    case 1: tracer(); break;
    case 2: rainbowStick(); break;
    case 3: glitter(); break;
    case 4: juggle(); break;
    case 5: ballBounce(); break;
    case 6: gyroRainbow(); break;
  }
  if (mode > 6) mode = 1;
}
