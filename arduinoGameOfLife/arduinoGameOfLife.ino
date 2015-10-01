// Adafruit_NeoMatrix example for single NeoPixel Shield.
// Scrolls 'Howdy' across the matrix in a portrait (vertical) orientation.
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define PIN 6
#define PI 3.1415926535897932384626433832795

// MATRIX DECLARATION:
// Parameter 1 = width of NeoPixel matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   NEO_MATRIX_TOP, NEO_MATRIX_BOTTOM, NEO_MATRIX_LEFT, NEO_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     NEO_MATRIX_TOP + NEO_MATRIX_LEFT for the top-left corner.
//   NEO_MATRIX_ROWS, NEO_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   NEO_MATRIX_PROGRESSIVE, NEO_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)


// Example for NeoPixel Shield.  In this application we'd like to use it
// as a 5x8 tall matrix, with the USB port positioned at the top of the
// Arduino.  When held that way, the first pixel is at the top right, and
// lines are arranged in columns, progressive order.  The shield uses
// 800 KHz (v2) pixels that expect GRB color data.
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8,8, 6, NEO_GRB + NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE, NEO_GRB +NEO_KHZ800);

   int nnAlive=0;//nearest neighbours alive index
   int s=8;
   boolean now[64];//matrix for the current setup
   boolean next[64];//matrix for the next setup, 1 for alive 0 for dead
   int n[9];
   
void setup() {
  
  matrix.begin();
  matrix.show(); // Initialize all pixels to 'off'
  matrix.setBrightness(10);
  
  for (int g = 0; g <(s*s) ; g++)
  {
    now[g]=false;
  }
  //initial conditions
  int ini []={26,27,34,43,36,44,24};
  for (int h=0; h<(sizeof(ini)/sizeof(ini[0]));h++)
  {
    now[ini[h]]=true;
  }
  
  
  
}


void loop() {
  //search for each pixel
  for (int x = 0; x <s; x++)
  {
    for(int y = 0; y<s;y++)
    {
      nnAlive=0;
      
      //hardcoding yO!
      n[0]= y*8+x;//the cell in question
      //n[0]= 26;//the cell in question
      
      //identifying the neighbours
      /*n[1]= y*8+(x+1)%8;//left
      n[2]= y*8+(x-1)%8;//right
      n[3]=((y+1)%8)*8+x;//right row
      n[4]=((y+1)%8)*8+(x+1)%8;
      n[5]=((y+1)%8)*8+(x-1)%8;
      n[6]=((y-1)%8)*8+x;//left row
      n[7]=((y-1)%8)*8+(x+1)%8;
      n[8]=((y-1)%8)*8+(x-1)%8;*/
      
      n[1]= y*8+mod((x+1),8);//left
      n[2]= y*8+mod((x-1),8);//right
      n[3]=mod((y+1),8)*8+x;//right row
      n[4]=mod((y+1),8)*8+mod((x+1),8);
      n[5]=mod((y+1),8)*8+mod((x-1),8);
      n[6]=mod((y-1),8)*8+x;//left row
      n[7]=mod((y-1),8)*8+mod((x+1),8);
      n[8]=mod((y-1),8)*8+mod((x-1),8);
      
      
      /*if (y==0)
      {
        n[8]=-1;//-1 is an invalid selection
        n[7]=-1;
        n[6]=-1;
      }
      if (y==s-1)
      {
        n[5]=-1;
        n[3]=-1;
        n[4]=-1;
      }
      
      if (x==0)
      {
        n[2]=-1;
        n[5]=-1;
        n[8]=-1;
      }
      
      if (x==s-1)
      {
        n[1]=-1;
        n[4]=-1;
        n[7]=-1;
      }*/
      
      //counting living neighbours
      for (int i=1; i<s+1; i++)
      {
        //if (n[i]>=0)
        //{
          if (now[n[i]])
          {
            nnAlive=nnAlive++;
          }
        //}
      }
      
      //CA rules
      if (now[n[0]])//condition for living cell
      {
        if ((nnAlive==2)||(nnAlive==3))
        {
          next[n[0]]=true;
        }
        else
        {
          next[n[0]]=false;
        }
      }
      else//conditions for dead cell
      {
        if (nnAlive==3)
        {
          next[n[0]]=true;
        }
        else
        {
          next[n[0]]=false;
        }
      }
      
      //temp rule-debug
      /*if (nnAlive==3)
      {
        next[n[0]]=true;
      }*/
      
      //set them on fire!
      if (now[n[0]])//should be next
      {
        matrix.setPixelColor(n[0],255,255,255);
      }
      else
      {
        matrix.setPixelColor(n[0],0,0,0);
      }
    }
  }
  
  //set live pixels on fire!
  for (int i = 0; i <(s*s) ; i++)
  {
     now[i]=next[i];//at the same time move next array as now
  }
  
  //matrix.setPixelColor(26,255,255,255);
  //matrix.setPixelColor(27,255,255,255);
  //matrix.setPixelColor(28,255,255,255);
  
  matrix.show(); 
  delay(500);

  //rainbow(1);
}

int mod(int a, int b)
{
  if (a>=b)
    return(a-b);
   else if(a<0)
    return(b+a);
   else
    return(a);
}



