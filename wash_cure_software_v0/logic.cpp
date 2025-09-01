#include "logic.h"
#include "screen.h"


// declared variables
int menu_num = 1;
int submenu_num = 0;
bool wash_function = 0;
bool cure_function = 0;
int wash_time[2] = {0, 30};
int cure_time[2] = {0, 30};
String display_time = "";



// buttons initialization, set for input becouse there are pullup resistors connected to switches
void button_init(){
  pinMode(btn_up, INPUT);
  pinMode(btn_down, INPUT);
  pinMode(btn_right, INPUT);
  pinMode(btn_left, INPUT);
}



// button press function
void button_press(){
  if (digitalRead(btn_up) == LOW) {
    menu_selection(-1, 0);
    Serial.println("UP");
    while (digitalRead(btn_up) == LOW) {}
  }
  else if (digitalRead(btn_down) == LOW) {
    menu_selection(1, 0);
    Serial.println("DOWN");
    while (digitalRead(btn_down) == LOW) {}
  }
  else if (digitalRead(btn_right) == LOW) {
    menu_selection(0, 1);
    Serial.println("RIGHT");
    while (digitalRead(btn_right) == LOW) {}
  }
  else if (digitalRead(btn_left) == LOW) {
    menu_selection(0, -1);
    Serial.println("LEFT");
    while (digitalRead(btn_left) == LOW) {}
  }
  delay(100); // debounce
}

// function for navigation while pressing button
void menu_selection(int x, int y) {
  // selection in main menu
  if (submenu_num == 0){
    menu_num += x;        // moving up and down in main menu
    if (menu_num > 3){    // when exceed then go to begining 
    menu_num = 1;
    }
  else if (menu_num < 1){   
    menu_num = 3;
    }
  }
  submenu_num += y;   // moving left and right in menu
  if (submenu_num > 2){submenu_num = 2;}        // interupt setting submenu_num above 2
  else if(submenu_num < 0){submenu_num = 0;}    // interupt setting submenu-num below 0
  display_selection();
}

// select screen to display
void display_selection(){
  // main menu display
  if (submenu_num == 0){
    if (menu_num == 1){menu_1();}
    else if (menu_num == 2){menu_2();}
    else if (menu_num == 3){menu_3();}
  }
  //submenu display
  else if (submenu_num == 1){
    if (menu_num == 1){menu_wash();}
    else if (menu_num == 2){menu_cure();}
    else if (menu_num == 3){menu_settings();}
  }
}