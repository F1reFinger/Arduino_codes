//#include <I2C.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeSans12pt7b.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32


#define OLED_RESET -1  // GPIO0
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int select = 0;
int pin2 = 2;
int timer = 100;

const unsigned char PROGMEM igni [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b00000000, 0b00000000,0b00000000,//6
  0b00000000, 0b00000000, 0b00000000,0b00000000,//7
  0b00000000, 0b00000001, 0b10000000,0b00000000,//8
  0b00000000, 0b00000011, 0b00000000,0b00000000,//9
  0b00000000, 0b00000110, 0b00000000,0b00000000,//10
  0b00000000, 0b00001100, 0b00000000,0b00000000,//11
  0b00000000, 0b00011000, 0b00011000,0b00000000,//12
  0b00000000, 0b00110000, 0b00001100,0b00000000,//13
  0b00000000, 0b01100000, 0b00000110,0b00000000,//14
  0b00000000, 0b11000000, 0b00000011,0b00000000,//15
  0b00000001, 0b10000000, 0b00000001,0b10000000,//16
  0b00000011, 0b00000000, 0b00000000,0b11000000,//17
  0b00000110, 0b00000000, 0b00000000,0b01100000,//18
  0b00001100, 0b00000000, 0b00000000,0b00110000,//19
  0b00011000, 0b00000000, 0b00000000,0b00011000,//20
  0b00110000, 0b00000000, 0b00000000,0b00001100,//21
  0b01100000, 0b00000000, 0b00000000,0b00000110,//22
  0b01111111, 0b11111111, 0b11111111,0b11111111,//23
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b00111100, 0b01111100, 0b11100011,0b00111100,//27
  0b00011000, 0b10000010, 0b11110011,0b00011000,//28
  0b00011000, 0b10000000, 0b11011011,0b00011000,//29
  0b00011000, 0b10011100, 0b11001111,0b00011000,//30
  0b00011000, 0b10000010, 0b11000111,0b00011000,//31
  0b00111100, 0b01111100, 0b11000011,0b00111100//32
  //0b11111111, 0b00000000, 0b00000000,0b11111111,//33
};

const unsigned char PROGMEM aard [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b00000000, 0b00000000,0b00000000,//6
  0b00000000, 0b00000000, 0b00000000,0b00000000,//7
  0b00000000, 0b00000001, 0b10000000,0b00000000,//8
  0b00000000, 0b00000011, 0b11000000,0b00000000,//9
  0b00000000, 0b00000110, 0b01100000,0b00000000,//10
  0b00000000, 0b00001100, 0b00110000,0b00000000,//11
  0b00000000, 0b00000000, 0b00011000,0b00000000,//12
  0b00000000, 0b00000000, 0b00001100,0b00000000,//13
  0b00000000, 0b00000000, 0b00000110,0b00000000,//14
  0b00000000, 0b00000000, 0b00000011,0b00000000,//15
  0b00000000, 0b00000000, 0b00000001,0b10000000,//16
  0b00000011, 0b11111110, 0b00000000,0b11000000,//17
  0b00000110, 0b00000000, 0b00000000,0b01100000,//18
  0b00001100, 0b00000000, 0b00000000,0b00110000,//19
  0b00011000, 0b00000000, 0b00000000,0b00011000,//20
  0b00110000, 0b00000000, 0b00000000,0b00001100,//21
  0b01100000, 0b00000000, 0b00000000,0b00000110,//22
  0b01111111, 0b11111111, 0b11111111,0b11111111,//23
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b00111100, 0b00111100, 0b01111100,0b01111100,//27
  0b11000011, 0b11000011, 0b01100010,0b01100010,//28
  0b11000011, 0b11000011, 0b01100010,0b01100010,//29
  0b11111111, 0b11111111, 0b01111100,0b01100010,//30
  0b11000011, 0b11000011, 0b01111000,0b01100010,//31
  0b11000011, 0b11000011, 0b01101110,0b01111100//32
  //0b11111111, 0b00000000, 0b00000000,0b11111111,//33
};

const unsigned char PROGMEM yrden [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b00000000, 0b00000000,0b00000000,//6
  0b11111111, 0b11111111, 0b11111111,0b11111111,//7
  0b11100000, 0b00000000, 0b00000000,0b00000111,//8
  0b00111000, 0b00000000, 0b00000000,0b00011100,//9
  0b00001110, 0b00000000, 0b00000000,0b01110000,//10
  0b00000011, 0b10000000, 0b00000001,0b11000000,//11
  0b00000000, 0b11100000, 0b00000111,0b00000000,//12
  0b00000000, 0b00111000, 0b00011100,0b00000000,//13
  0b00000000, 0b00001110, 0b01110000,0b00000000,//14
  0b00000000, 0b00000011, 0b11000000,0b00000000,//15
  0b00000000, 0b00000111, 0b11100000,0b00000000,//16
  0b00000000, 0b00011100, 0b00111000,0b00000000,//17
  0b00000000, 0b01110000, 0b00001110,0b00000000,//18
  0b00000001, 0b11000000, 0b00000011,0b10000000,//19
  0b00000111, 0b00000000, 0b00000000,0b11100000,//20
  0b00011100, 0b00000000, 0b00000000,0b00111000,//21
  0b01110000, 0b00000000, 0b00000000,0b00001110,//22
  0b11111111, 0b11111111, 0b11111111,0b11111111,//23
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b10000001, 0b01111100, 0b01111001,0b11000111,//27
  0b11000011, 0b01100010, 0b01000100,0b10100010,//28
  0b01100110, 0b01100010, 0b01000100,0b10010010,//29
  0b00011000, 0b01111100, 0b01000100,0b10010010,//30
  0b00011000, 0b01111000, 0b01000100,0b10001010,//31
  0b00111100, 0b01101110, 0b01111001,0b11000111//32
  //0b11111111, 0b00000000, 0b00000000,0b11111111,//33
};

const unsigned char PROGMEM quen [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b00000000, 0b00000000,0b00000000,//6
  0b00000000, 0b00000000, 0b00000000,0b00000000,//7
  0b01111111, 0b11111111, 0b11111111,0b11111111,//8
  0b01100000, 0b00000000, 0b00000000,0b00000110,//9
  0b00110000, 0b00000000, 0b00000000,0b00001100,//10
  0b00011000, 0b00000000, 0b00000000,0b00011000,//11
  0b00001100, 0b00000000, 0b00000000,0b00110000,//12
  0b00000110, 0b00000000, 0b11111111,0b11100000,//13
  0b00000011, 0b00000000, 0b00000000,0b00000000,//14
  0b00000001, 0b10000000, 0b00000000,0b00000000,//15
  0b00000000, 0b11000000, 0b00000000,0b00000000,//16
  0b00000000, 0b01100000, 0b00000000,0b00000000,//17
  0b00000000, 0b00110000, 0b00000000,0b00000000,//18
  0b00000000, 0b00011000, 0b00011000,0b00000000,//19
  0b00000000, 0b00001100, 0b00110000,0b00000000,//20
  0b00000000, 0b00000110, 0b01100000,0b00000000,//21
  0b00000000, 0b00000011, 0b11000000,0b00000000,//22
  0b00000000, 0b00000001, 0b10000000,0b00000000,//23
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b00111100, 0b01100110, 0b01111110,0b11100011,//27
  0b11000011, 0b01000010, 0b01100010,0b11110011,//28
  0b11000011, 0b01000010, 0b01111100,0b11011011,//29
  0b11000011, 0b01000010, 0b01111100,0b11011011,//30
  0b11011011, 0b01000010, 0b01100010,0b11001111,//31
  0b00111111, 0b00111100, 0b01111110,0b11000111//32
  //0b11111111, 0b00000000, 0b00000000,0b11111111,//33
};

const unsigned char PROGMEM axii [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b00000000, 0b00000000,0b00000000,//6
  0b00000000, 0b00000000, 0b00000000,0b00000000,//7
  0b01111111, 0b11111111, 0b11111111,0b11111110,//8
  0b01100000, 0b00000000, 0b00000000,0b00000110,//9
  0b00110000, 0b00000000, 0b00000000,0b00001100,//10
  0b00011000, 0b00000000, 0b00000000,0b00011000,//11
  0b00001100, 0b00000000, 0b00000000,0b00110000,//12
  0b00000110, 0b00000000, 0b00000000,0b01100000,//13
  0b00000011, 0b00000000, 0b00000000,0b11000000,//14
  0b00000001, 0b10000000, 0b00000000,0b00000000,//15
  0b00000000, 0b11000000, 0b00000000,0b00000000,//16
  0b00000000, 0b01100000, 0b00000000,0b00000000,//17
  0b00000000, 0b00110000, 0b00000000,0b00000000,//18
  0b00000000, 0b00011000, 0b00011000,0b00000000,//19
  0b00000000, 0b00001100, 0b00110000,0b00000000,//20
  0b00000000, 0b00000110, 0b01100000,0b00000000,//21
  0b00000000, 0b00000011, 0b11000000,0b00000000,//22
  0b00000000, 0b00000001, 0b10000000,0b00000000,//23
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b00111100, 0b11000011, 0b00111100,0b00111100,//27
  0b11000011, 0b01100110, 0b00011000,0b00011000,//28
  0b11000011, 0b00111100, 0b00011000,0b00011000,//29
  0b11111111, 0b00111100, 0b00011000,0b00011000,//30
  0b11000011, 0b01100110, 0b00011000,0b00011000,//31
  0b11000011, 0b11000011, 0b00111100,0b00111100//32
  //0b11111111, 0b00000000, 0b00000000,0b11111111,//33
};

const unsigned char PROGMEM BOBINHO [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b00000000, 0b00000000,0b00000000,//6
  0b00000000, 0b00000000, 0b00000000,0b00000000,//7
  0b00000000, 0b00000000, 0b00000000,0b00000000,//8
  0b00000000, 0b00000000, 0b00000000,0b00000000,//9
  0b00000000, 0b00000000, 0b00000000,0b00000000,//10
  0b00000000, 0b00000000, 0b00000000,0b00000000,//11
  0b00000000, 0b00000000, 0b00000000,0b00000000,//12
  0b00000000, 0b00000000, 0b00000000,0b00000000,//13
  0b00000000, 0b00000000, 0b00000000,0b00000000,//14
  0b00000000, 0b00000000, 0b00000000,0b00000000,//15
  0b00000000, 0b00000000, 0b00000000,0b00000000,//16
  0b00000000, 0b00000000, 0b00000000,0b00000000,//17
  0b00000000, 0b00000000, 0b00000000,0b00000000,//18
  0b00000000, 0b00000000, 0b00000000,0b00000000,//19
  0b00000000, 0b00000000, 0b00000000,0b00000000,//20
  0b00000000, 0b00000000, 0b00000000,0b00000000,//21
  0b00000000, 0b00000000, 0b00000000,0b00000000,//22
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b00000000, 0b00000000, 0b00000000,0b00000000,//27
  0b00000000, 0b00000000, 0b00000000,0b00000000,//28
  0b00000000, 0b00000000, 0b00000000,0b00000000,//29
  0b00000000, 0b00000000, 0b00000000,0b00000000,//30
  0b00000000, 0b00000000, 0b00000000,0b00000000,//31
  0b00000000, 0b00000000, 0b00000000,0b00000000,//32
  0b00000000, 0b00000000, 0b00000000,0b00000000 //33
};

const unsigned char PROGMEM STOP [] = {
  0b00000000, 0b00000000, 0b00000000,0b00000000,//1
  0b00000000, 0b00000000, 0b00000000,0b00000000,//2
  0b00000000, 0b00000000, 0b00000000,0b00000000,//3
  0b00000000, 0b00000000, 0b00000000,0b00000000,//4
  0b00000000, 0b00000000, 0b00000000,0b00000000,//5
  0b00000000, 0b01111111, 0b11111110,0b00000000,//6
  0b00000001, 0b10000000, 0b00000001,0b10000000,//7
  0b00000110, 0b00000000, 0b00000000,0b01100000,//8
  0b00011000, 0b00000000, 0b00000000,0b00011000,//9
  0b01100000, 0b00000000, 0b00000000,0b00000110,//10
  0b10000000, 0b00000000, 0b00000000,0b00000001,//11
  0b10011110, 0b01111110, 0b01111100,0b01111001,//12
  0b10100001, 0b00011000, 0b10000010,0b01100101,//13
  0b10011100, 0b00011000, 0b10010010,0b01111001,//14
  0b10000010, 0b00011000, 0b10000010,0b01100001,//15
  0b10111100, 0b00011000, 0b01111100,0b01100001,//16
  0b10000000, 0b00000000, 0b00000000,0b00000001,//17
  0b01100000, 0b00000000, 0b00000000,0b00000110,//18
  0b00011000, 0b00000000, 0b00000000,0b00011000,//19
  0b00000110, 0b00000000, 0b00000000,0b01100000,//20
  0b00000001, 0b10000000, 0b00000001,0b10000000,//21
  0b00000000, 0b01111111, 0b11111110,0b00000000,//22
  0b00000000, 0b00000000, 0b00000000,0b00000000,//24
  0b00000000, 0b00000000, 0b00000000,0b00000000,//25
  0b00000000, 0b00000000, 0b00000000,0b00000000,//26
  0b00000000, 0b00000000, 0b00000000,0b00000000,//27
  0b00000000, 0b00000000, 0b00000000,0b00000000,//28
  0b00000000, 0b00000000, 0b00000000,0b00000000,//29
  0b00000000, 0b00000000, 0b00000000,0b00000000,//30
  0b00000000, 0b00000000, 0b00000000,0b00000000,//31
  0b00000000, 0b00000000, 0b00000000,0b00000000,//32
  0b00000000, 0b00000000, 0b00000000,0b00000000 //33
};

const unsigned char PROGMEM inv [] = {
  0b11111111, 0b11111111, 0b11111111,0b11111111,//1
  0b11111111, 0b11111111, 0b11111111,0b11111111,//2
  0b11111111, 0b11111111, 0b11111111,0b11111111,//3
  0b11111111, 0b11111111, 0b11111111,0b11111111,//4
  0b11111111, 0b11111111, 0b11111111,0b11111111,//5
  0b11111111, 0b10000000, 0b00000001,0b11111111,//6
  0b11111110, 0b01111111, 0b11111110,0b01111111,//7
  0b11111001, 0b11111111, 0b11111111,0b10011111,//8
  0b11100111, 0b11111111, 0b11111111,0b11100111,//9
  0b10011111, 0b11111111, 0b11111111,0b11111001,//10
  0b01111111, 0b11111111, 0b11111111,0b11111110,//11
  0b01100001, 0b10000001, 0b10000011,0b10000110,//12
  0b01011110, 0b11100111, 0b01111101,0b10011010,//13
  0b01100011, 0b11100111, 0b01101101,0b10000110,//14
  0b01111101, 0b11100111, 0b01111101,0b10011110,//15
  0b01000011, 0b11100111, 0b10000001,0b10011110,//16
  0b01111111, 0b11111111, 0b11111111,0b11111110,//17
  0b10011111, 0b11111111, 0b11111111,0b11111001,//18
  0b11100111, 0b11111111, 0b11111111,0b11100111,//19
  0b11111001, 0b11111111, 0b11111111,0b10011111,//20
  0b11111110, 0b01111111, 0b11111110,0b01111111,//21
  0b11111111, 0b10000000, 0b00000001,0b11111111,//22
  0b11111111, 0b11111111, 0b11111111,0b11111111,//24
  0b11111111, 0b11111111, 0b11111111,0b11111111,//25
  0b11111111, 0b11111111, 0b11111111,0b11111111,//26
  0b11111111, 0b11111111, 0b11111111,0b11111111,//27
  0b11111111, 0b11111111, 0b11111111,0b11111111,//28
  0b11111111, 0b11111111, 0b11111111,0b11111111,//29
  0b11111111, 0b11111111, 0b11111111,0b11111111,//30
  0b11111111, 0b11111111, 0b11111111,0b11111111,//31
  0b11111111, 0b11111111, 0b11111111,0b11111111,//32
  0b11111111, 0b11111111, 0b11111111,0b11111111 //33
};

int xx=48;
int yy=0;
//int tt=0;

void ISR1(){
  if(select == 6){
    select = 0;
  }
  else{
    select++;
  }
}

void setup() {
  // put your setup code here, to run once:isplay.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 64x48)
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
   display.display();
   display.clearDisplay();
   //display.setFont(&FreeSans9pt7b);
  
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  Serial.begin(9600); // abre a porta serial a 9600 bps:
  pinMode(pin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(pin2), ISR1, FALLING);
}

void loop() {
  if(select == 1){
    
    display.clearDisplay();
    display.drawBitmap(xx, yy, igni, 32, 32, 1);
    delay(500);
    display.display();

    display.clearDisplay();
    display.drawBitmap(xx, yy, BOBINHO, 32, 32, 1);
    delay(500);
    display.display();
  }
  else if(select == 2){
    
    display.clearDisplay();
    display.drawBitmap(xx, yy, yrden, 32, 32, 1);
    delay(500);
    display.display();

    display.clearDisplay();
    display.drawBitmap(xx, yy, BOBINHO, 32, 32, 1);
    delay(500);
    display.display();
  }
  else if(select == 3){
    
    display.clearDisplay();
    display.drawBitmap(xx, yy, aard, 32, 32, 1);
    delay(500);
    display.display();

    display.clearDisplay();
    display.drawBitmap(xx, yy, BOBINHO, 32, 32, 1);
    delay(500);
    display.display();
    
  }
  else if(select == 4){
    
    display.clearDisplay();
    display.drawBitmap(xx, yy, quen, 32, 32, 1);
    delay(500);
    display.display();

    display.clearDisplay();
    display.drawBitmap(xx, yy, BOBINHO, 32, 32, 1);
    delay(500);
    display.display();
  }
  else if(select == 5){
    
    display.clearDisplay();
    display.drawBitmap(xx, yy, axii, 32, 32, 1);
    delay(500);
    display.display();

    display.clearDisplay();
    display.drawBitmap(xx, yy, BOBINHO, 32, 32, 1);
    delay(500);
    display.display();

  }
  else{
    display.clearDisplay();
    display.drawBitmap(xx, yy, STOP, 32, 32, 1);
    delay(500);
    display.display();
    
    display.clearDisplay();
    display.drawBitmap(xx, yy, inv, 32, 32, 1);
    delay(500);
    display.display();
  }
}
