#include "config.h"
#include "lcdWrite.h"
#include "byteLcd.h"
#include <stdio.h>
void move_ball(void)
{
    
  uchar j;
    
  const  bool upper_pos[17] = {0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xc0,0xe0,0xc0,0x80,0x00,0x00,0x00,0x00,0x00,0x00};    // up and down positions
  const  bool start_pos[19] ={0xe0,0xe0,0xe0,0x70,0x38,0x1c,0x0e,0x07,0x03,0x01,0x00,0x01,0x03,0x07,0x0e,0x1c,0x38,0x70,0xe0};
  uchar temp[4] ={0xe0,0xe0,0xe0};
     //                         0    1     2    3   4     5     6   7   8     9     10  11  12   13   14   15   16    
 
  if(z == 0 && col <81)                              // print out 0x00, 0xe0 for 3 spaces x
  {
    lcdWrite(SET_Y|row, LOW);
    lcdWrite(SET_X|col, LOW);
   // printf("col = %d\n",col);
    for(j = 0;j <3;j++)
    {
       lcdWrite(start_pos[j]|gameplay_area[row][col], HIGH);       // initially draw ball at row 4 columns 1,2,3
       
    }
    col = col+1;
  }
 
  if(z == 1 && col < 81)
  {
    col = col-1; 
    lcdWrite(SET_Y|row, LOW);
    lcdWrite(SET_X|col, LOW);
   // printf("colzero = %d\n",col);
    for(j = 0;j <3;j++)
    {
       lcdWrite(0x00|gameplay_area[row][col], HIGH);       // erase ball at row 4 columns 1,2,3     
       
    } 
    col = col+1;
  }
}


  

