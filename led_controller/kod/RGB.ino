#include <Adafruit_NeoPixel.h>

#define PIN 6
#define BRIGHTNESS 20

Adafruit_NeoPixel MagicLED = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);
const int ledPin =  6 ;
int ledState = LOW ;
unsigned long previousMillis = 0 ;
const long interval = 100;

void setup() {
  pinMode ( 6 , OUTPUT ) ; 
  MagicLED.begin();
  MagicLED.show();
  MagicLED.setBrightness(BRIGHTNESS);
}

void loop() {
  //colorWipe(MagicLED.Color(255, 5, 180), interval); //Pink
  //colorWipe(MagicLED.Color(255, 0, 0), interval); // Red
  //colorWipe(MagicLED.Color(255, 150, 0), interval); // Orange
  //colorWipe(MagicLED.Color(255, 255, 5), interval); // Yellow
  //colorWipe(MagicLED.Color(0, 255, 0), interval); // Green
  //colorWipe(MagicLED.Color(0, 0, 255), interval); // Blue
  //colorWipe(MagicLED.Color(135, 10, 215), interval); // Purple
  //theaterChase(MagicLED.Color(127, 127, 127), interval); // White
  //theaterChase(MagicLED.Color(127, 0, 0), interval); // Red
  //theaterChase(MagicLED.Color(0, 0, 127), interval); // Blue
  //duha(interval);
  //strips();
  //y();
  //rainbowCycle(interval);
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}

void y () {
  vymaluj(MagicLED.Color(255, 0, 0), interval); //červená
  vymaluj(MagicLED.Color(0, 255, 0), interval); //zelená
  vymaluj(MagicLED.Color(0, 0, 255), interval); //modrá
}

void strips() {
  utikej(MagicLED.Color(127, 127, 127), interval); //bíla
  utikej(MagicLED.Color(127,   0,   0), interval); //červená
  utikej(MagicLED.Color(  0,   0, 127), interval); //modrá
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
        MagicLED.setPixelColor(i+q, c);   
      }
      MagicLED.show();
     
      delay(interval);
     
      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, 0);     
      }
    }
  }
}

void vymaluj(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<MagicLED.numPixels(); i++) {
      MagicLED.setPixelColor(i, c);
      MagicLED.show();
      delay(interval);
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

  for(j=0; j<256*5; j++) {
    for(i=0; i< MagicLED.numPixels(); i++) {
      MagicLED.setPixelColor(i, Wheel(((i * 256 / MagicLED.numPixels()) + j) & 255));
    }
    MagicLED.show();
    delay(wait);
  }
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {
    for (int q=0; q < 3; q++) {
      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, c);
      }
      MagicLED.show();

      delay(wait);

      for (int i=0; i < MagicLED.numPixels(); i=i+3) {
        MagicLED.setPixelColor(i+q, 0);
      }
    }
  }
}
