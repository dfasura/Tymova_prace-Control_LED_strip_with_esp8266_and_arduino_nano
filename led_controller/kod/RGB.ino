#include <Adafruit_NeoPixel.h>

#define PIN 6
#define BRIGHTNESS 20

Adafruit_NeoPixel MagicLED = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  MagicLED.begin();
  MagicLED.show();
  MagicLED.setBrightness(BRIGHTNESS);
}

void loop() {
  //colorWipe(MagicLED.Color(255, 5, 180), 50); // Pink
  //colorWipe(MagicLED.Color(255, 0, 0), 50); // Red
  //colorWipe(MagicLED.Color(255, 150, 0), 50); // Orange
  //colorWipe(MagicLED.Color(255, 255, 5), 50); // Yellow
  //colorWipe(MagicLED.Color(0, 255, 0), 50); // Green
  //colorWipe(MagicLED.Color(0, 0, 255), 50); // Blue
  //colorWipe(MagicLED.Color(135, 10, 215), 50); // Purple
  //theaterChase(MagicLED.Color(127, 127, 127), 50); // White
  //theaterChase(MagicLED.Color(127, 0, 0), 50); // Red
  //theaterChase(MagicLED.Color(0, 0, 127), 50); // Blue
  //duha(20);
  //strips();
  //y();
  rainbowCycle(20);
}

void y () {
  vymaluj(MagicLED.Color(255, 0, 0), 50); //červená
  vymaluj(MagicLED.Color(0, 255, 0), 50); //zelená
  vymaluj(MagicLED.Color(0, 0, 255), 50); //modrá
}

void strips() {
  utikej(MagicLED.Color(127, 127, 127), 50); //bíla
  utikej(MagicLED.Color(127,   0,   0), 50); //červená
  utikej(MagicLED.Color(  0,   0, 127), 50); //modrá
}

void duha(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<MagicLED.numPixels(); i++) {
      MagicLED.setPixelColor(i, Wheel((i+j) & 255));
    }
    MagicLED.show();
    delay(wait);             
  }
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return MagicLED.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return MagicLED.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return MagicLED.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

void utikej(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  
    for (int q=0; q < 3; q++) {
      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, c);    //zapĂ­nĂˇnĂ­ vĹˇech pixelĹŻ najednou
      }
      MagicLED.show();
     
      delay(40);
     
      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, 0);        //vypĂ­nĂˇnĂ­ vĹˇech pixelĹŻ najednou
      }
    }
  }
}

void vymaluj(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<MagicLED.numPixels(); i++) {
      MagicLED.setPixelColor(i, c);
      MagicLED.show();
      delay(5);
  }

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<MagicLED.numPixels(); i++) {
    MagicLED.setPixelColor(i, c);
    MagicLED.show();
    delay(wait);
  }
}

void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< MagicLED.numPixels(); i++) {
      MagicLED.setPixelColor(i, Wheel(((i * 256 / MagicLED.numPixels()) + j) & 255));
    }
    MagicLED.show();
    delay(wait);
  }
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, c);    //turn every third pixel on
      }
      MagicLED.show();

      delay(wait);

      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
