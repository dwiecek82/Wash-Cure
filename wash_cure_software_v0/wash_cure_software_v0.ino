#include "screen.h"
#include "logic.h"


void setup(){
  Serial.begin(9600); // begin serial transmition
  init_display();  // initialize display
  begin_screen();  // displaing 'welcome' screen on display for 5 sec
  pins_init();    //initalize button pins for input
  menu_1();
}

void loop(){
  button_press(); //button handling function
  proccess_check();
}
