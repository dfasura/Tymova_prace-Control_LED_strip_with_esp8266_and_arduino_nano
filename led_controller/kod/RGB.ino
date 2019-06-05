#include <Adafruit_NeoPixel.h>

#define PIXELSPIN   6
#define NUMPIXELS   24
#define CALIBRATIONTIME 20000

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXELSPIN, NEO_GRB + NEO_KHZ800);

unsigned long pixelsInterval=50;
unsigned long colorWipePreviousMillis=0;
unsigned long theaterChasePreviousMillis=0;
unsigned long rainbowPreviousMillis=0;
unsigned long redFadeInAndOutMillis=0;
unsigned long greenFadeInAndOutMillis=0;
unsigned long blueFadeInAndOutMillis=0;

int theaterChaseQ = 0;
int rainbowCycles = 0;

uint16_t currentPixel = 0;

void setup() {
  currentPixel = 0;
  
  pixels.begin();
  pixels.show();
      
}

void loop () {
  
        if ((unsigned long)(millis() - colorWipePreviousMillis) >= pixelsInterval) {
          colorWipePreviousMillis = millis();
          colorWipe(pixels.Color(255,0,0)); //red
        }
  
      if ((unsigned long)(millis() - colorWipePreviousMillis) >= pixelsInterval) {
          colorWipePreviousMillis = millis();
          colorWipe(pixels.Color(0,255,0)); //green
        }
        
      if ((unsigned long)(millis() - colorWipePreviousMillis) >= pixelsInterval) {
          colorWipePreviousMillis = millis();
          colorWipe(pixels.Color(0,0,255)); //blue
        }
  
      if ((unsigned long)(millis() - colorWipePreviousMillis) >= pixelsInterval) {
          colorWipePreviousMillis = millis();
          colorWipe(pixels.Color(255, 5, 180)); //pink
        }
  
      if ((unsigned long)(millis() - colorWipePreviousMillis) >= pixelsInterval) {
          colorWipePreviousMillis = millis();
          colorWipe(pixels.Color(255, 150, 0)); //orange
        }
  
        if ((unsigned long)(millis() - theaterChasePreviousMillis) >= pixelsInterval) {
          theaterChasePreviousMillis = millis();
          theaterChase(pixels.Color(127, 127, 127)); //White
        }
  
      if ((unsigned long)(millis() - theaterChasePreviousMillis) >= pixelsInterval) {
          theaterChasePreviousMillis = millis();
          theaterChase(pixels.Color(255, 0, 0)); //red
        }
  
      if ((unsigned long)(millis() - theaterChasePreviousMillis) >= pixelsInterval) {
          theaterChasePreviousMillis = millis();
          theaterChase(pixels.Color(0, 255, 0)); //green
        }
  
      if ((unsigned long)(millis() - theaterChasePreviousMillis) >= pixelsInterval) {
          theaterChasePreviousMillis = millis();
          theaterChase(pixels.Color(0, 0, 255)); //blue
        }
      
      if ((unsigned long)(millis() - rainbowPreviousMillis) >= pixelsInterval) {
        rainbowPreviousMillis = millis();
        rainbow();
        }
      if ((unsigned long)(millis() - blueFadeInAndOutMillis) >= pixelsInterval) {
          blueFadeInAndOutMillis = millis();
          blueFadeInAndOut(); //blue
        }
      if ((unsigned long)(millis() - redFadeInAndOutMillis) >= pixelsInterval) {
          redFadeInAndOutMillis = millis();
          redFadeInAndOut(); //red
        }
      if ((unsigned long)(millis() - greenFadeInAndOutMillis) >= pixelsInterval) {
          greenFadeInAndOutMillis = millis();
          greenFadeInAndOut(); //green
        }
}
void colorWipe(uint32_t c){
  pixels.setPixelColor(currentPixel,c);
  pixels.show();
  currentPixel++;
  if(currentPixel == NUMPIXELS){
    currentPixel = 0;
  }
}

void rainbow() {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, Wheel((i+rainbowCycles) & 255));
  }
  pixels.show();
  rainbowCycles++;
  if(rainbowCycles >= 256) rainbowCycles = 0;
}

void blueFadeInAndOut() {
  for(uint8_t b = 0; b <255; b++) {
     for(uint8_t i=0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 0 * b/255, 0 * b/255, 255 * b/255); //blue
     }
     pixels.show();
  }

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i = 0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 0 * b/255, 0 * b/255, 255 * b/255); //red
     }
     pixels.show();
  }
}

void redFadeInAndOut() {
  for(uint8_t b = 0; b <255; b++) {
     for(uint8_t i=0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 255 * b/255, 0 * b/255, 0 * b/255); //red
     }
     pixels.show();
  }

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i = 0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 255 * b/255, 0 * b/255, 0 * b/255);
     }
     pixels.show();
  }
}

void greenFadeInAndOut() {
  for(uint8_t b = 0; b <255; b++) {
     for(uint8_t i=0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 0 * b/255, 255 * b/255, 0 * b/255);
     }
     pixels.show();
  }

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i = 0; i < pixels.numPixels(); i++) {
        pixels.setPixelColor(i, 0 * b/255, 255 * b/255, 0 * b/255);
     }
     pixels.show();
  }
}

void theaterChase(uint32_t c) {
  for (int i=0; i < pixels.numPixels(); i=i+3) {
      pixels.setPixelColor(i+theaterChaseQ, c);    
    }
    pixels.show();
    for (int i=0; i < pixels.numPixels(); i=i+3) {
      pixels.setPixelColor(i+theaterChaseQ, 0);        
    }
    theaterChaseQ++;
    if(theaterChaseQ >= 3) theaterChaseQ = 0;
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
