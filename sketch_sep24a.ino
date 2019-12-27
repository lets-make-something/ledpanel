#include "Adafruit_GFX.h" // Core graphics library
#include "RGBmatrixPanel.h" // Hardware-specific library

#define CLK 8 // MUST be on PORTB!
#define LAT A3
#define OE 9
#define A A0
#define B A1
#define C A2

// Last parameter = 'false' disable double-buffering
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);

void setup() {
matrix.begin();
}

int H=0;
void loop() {
  //matrix.fillScreen(matrix.Color333(0, 0, 0));
  for(int y=0;y<16;y++){
    for(int x=0;x<32;x++){
      matrix.drawPixel(x,y,matrix.ColorHSV(x*30+y*10+H,128,128,true));
    }
  }
  H+=10;
// fill the screen with black
//matrix.fillScreen(matrix.Color333(0, 0, 0));
//delay(1000);
}
