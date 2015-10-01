// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      24

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 500;// delay for half a second
int[] cur = new int[24];
int[] next = new int[24];
int left, right, it;
int iterations;
int index = 0;
int ruleset = new int[8];

void setup() {
  for(int i = 0; i<24; i ++) {
    cur[i] = 0;
    next[i] = 0;
  }
  cur[NUMPIXELS/2] = 1;
  
  ruleset = {0, 0, 0, 1, 1, 1, 1, 0};
  iterations = 0;
  left = 0;
  right = 0;
  it = 0;
  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {
    // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  for(int i=0;i<NUMPIXELS;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setBrightness(i,0);
    if(cur[i]) {
    pixels.setBrightness(i,100);
    pixels.setPixelColor(i, pixels.Color(0,150,0));}}
    // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    
    for (int i = 1; i < NUMPIXELS-1; i++) {
       left   = cur[(i-1)%NUMPIXELS];
       me     = cur[i];
       right  = cur[(i+1)%NUMPIXELS];
       next[i] = rules(left, me, right);
    }
    cur = next;
    iterations++;
    
    delay(delayval);
}

int rules(int a, int b, int c) {
  
    index = a*4+b*2+c*1;
    return ruleset[index];
  }

