// You need to just currentscreen vairaible,
//if statements 

// create numbers for the vari
#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <TouchScreen.h>
#include <stdint.h>

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
// these pins define the pins being used by the Arduino^^
#define TS_MINX 122
#define TS_MINY 111
#define TS_MAXX 942
#define TS_MAXY 890
#define YP A3
#define XM A2
#define YM 9
#define XP 8
// this code calibrates the screen
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);



TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
// these define the pins used to activate the screen
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xf81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF


int currentscreen = 0;
bool Camera = 0;
bool tracker = false;
bool Homevar = false;
bool backbutton = 1;
bool welcome = true;

void Home() {
  tft.fillScreen(RED);
  tft.setCursor(60, 100);
  tft.setTextSize(2);
  tft.print("CHOOSE APPLICATION");
  tft.fillRect(10, 10, 75, 75, BLUE);
  tft.fillRect(125, 10, 75, 75, BLUE);
  tft.fillRect(240, 10, 75, 75, BLUE);
  // creating buttons for applications, first test out using LED's
}
void Welcome() {
  tft.fillScreen(WHITE);                //WHat to fill the screen colour with- colours stated above
  tft.drawRect(0, 0, 319, 240, WHITE);  //the rectangularshape that the screen fills
  tft.setCursor(5, 5);                  //set cursor is where text will begin on the screen, top right corner of the text
  tft.setTextColor(BLACK);
  tft.setTextSize(2);
  tft.print("WELCOME LKAT");
  //add parameters
  tft.fillRect(50, 180, 210, 40, BLACK);
  tft.drawRect(50, 180, 210, 40, GREEN);
  tft.setCursor(60, 190);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
}

void LED() {
  tft.setCursor(5, 5); 
  tft.fillScreen(BLUE);
  tft.print("HELLO");
}


void setup(void) {
  tft.width(); //int16_t width(void);
tft.height(); //int16_t height(void);
Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();

  tft.begin(identifier);
  tft.setRotation(1);  //changing this value between 1 and 0 will change the layout of the text on screen. landscape portarait
  currentscreen = 0;

  Welcome();
}

void loop(void) {
 
  TSPoint p = ts.getPoint();
    int16_t t_x = map(p.x, TS_MINX, TS_MAXX, tft.width(), 0);
  int16_t t_y = (tft.height()-map(p.y, TS_MINY, TS_MAXY, tft.height(), 0));
  if (p.z > ts.pressureThreshhold) {
       p.y = map(p.y, TS_MINY, TS_MAXY, 0, 480);
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
pinMode(XP, OUTPUT);
  pinMode(XM, OUTPUT);
  pinMode(YP, OUTPUT);
  pinMode(YM, OUTPUT);
 
     Serial.println( p.x);
Serial.println(p.y );
    //set screen resolution
  
 
  if (currentscreen == 0 ) {
    if (p.x > 50 && p.x < 260 && p.y > 180 && p.y < 300) {

      currentscreen = 1;

      Homevar = true;
            Home();
    }
  }

  
  
    if (currentscreen == 1 && Homevar==true ){
          //p.y = map(p.y, TS_MINY, TS_MAXY, 0, 480);
   //p.x = map(p.x, TS_MINX, TS_MAXX, 0, 320);
//p.x= map(p.x, TS_MINX,  TS_MAXX, 0, tft.height());
//p.y= map(p.y, TS_MINY,  TS_MAXY, 0, tft.width());
    //check coordinates, screen has rotated
  
    
    if( p.y > 0 && p.y <85 && p.x >0 && p.x < 85) {
      LED();
      currentscreen = 2;
    }
    //other if
  }
 
  }
}