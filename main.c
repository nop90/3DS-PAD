#include "main.h"
#include "memory.h"
#include "minlib.h"
#include "draw.h"
#include "ctr/types.h"
#include "ctr/HID.h"

int main(){

  u8 tused;
  u32 tx, ty, keys;
  s16 px;
  s16 py;


  tused=0;

  initbuffer();
  clearback(TOP_SCREEN | BOTTOM_SCREEN);
  draw_string("Hello!",10,10,255,255,255,TOP_SCREEN);
  draw_string("Try using the touchpad and the joypad",10,20,255,255,255,TOP_SCREEN);
  copyback2screen(TOP_SCREEN | BOTTOM_SCREEN);


  while(1){
    tused=(u8)((u32 *)HID_SHAREDMEM_DEFAULT)[0x33];
    tx=TOUCH_X(((u32 *)HID_SHAREDMEM_DEFAULT)[0x32]);
    ty=TOUCH_Y(((u32 *)HID_SHAREDMEM_DEFAULT)[0x32]);
    px=CPAD_X(((u32 *)HID_SHAREDMEM_DEFAULT)[0xD]);
    py=CPAD_Y(((u32 *)HID_SHAREDMEM_DEFAULT)[0xD]);
    draw_fillrect(0,0,319,239,0,0,0,BOTTOM_SCREEN);
    if(tused) {
      draw_fillcircle(tx,ty,2,255,0,0,BOTTOM_SCREEN);
    }
    draw_fillcircle(160+(160*px)/0x9C,120-(120*py)/0x9C,2,0,0,255,BOTTOM_SCREEN);

    copyback2screen(BOTTOM_SCREEN);
    msleep(25);
  }

  return 0;
}
