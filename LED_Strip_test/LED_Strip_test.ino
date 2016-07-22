#include <Adafruit_NeoPixel.h>




Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, 6, NEO_GRB + NEO_KHZ800);
                                                    //first argument is the number of leds in the strip
                                                    //seconds argument is the pin that Data_in is connected to
                                                    //third argument is the golors and frequency

int snake;                                          //sneaky snake for lights

int gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };     
                                                    //idk what gamma is for yet. came from Neopixel library
                                                    //thought it might be useful.



void setup() {
  Serial.begin(115200);

  //-------------LED STRIP(3PIN)--------------------------------
  strip.setBrightness(50);
  //not sure what min-max to set for brightness
  strip.begin();
  strip.show();
  
  //initializes all the LEDs to off
  colorWipe(strip.Color(0,0,255),1);//BLUE;
  delay(1);
 

  snake = 0;

  
}


void loop() {
  int i,j,k;
 /* for(i = 0; i<250;i =i+50){
    for(j = 0; j <250; j=j+50){       
      for(k = 0; k<250; k=k+50){
        colorWipe(strip.Color(j ,k,i),.01);//red;
        Serial.print(i);
      }
    }
  }
  //just a random generation on the whole strip. kinda epeleptic
  i = random(1,250);
  j = random(1,250);
  k = random(1,250);
 
  colorWipe(strip.Color(i,j,k), 1);
  */
  colorSnake(strip.Color(0,255,0),strip.Color(0,0,255), 10);
}



//will have a little 2 led snake that runs down the strip.
void colorSnake(uint32_t c,uint32_t e, uint8_t wait){
  int j = 0;
  for(int i = 0; i<strip.numPixels(); i = i++) {
    j = snake;
    strip.setPixelColor(j+2, e);
    strip.setPixelColor(j+3, e);
    strip.setPixelColor(j+4, e);
    Serial.print("j :");Serial.println(j);
    Serial.print("snake :");Serial.println(snake);
    
    strip.setPixelColor(j, c);
    strip.setPixelColor(j+1, c);
    strip.show();
    delay(wait);
    if(snake > 58){
      snake=0;
      }else{
      snake++;
      
      }
    }
  }


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}




