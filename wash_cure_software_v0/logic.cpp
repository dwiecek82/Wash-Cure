#include "logic.h"
#include "screen.h"


// declared variables
int menu_num = 1;
int submenu_num = 0;
bool wash_function = 0;
bool cure_function = 0;
int wash_time = 30;
int cure_time = 30;
String display_time = "";
int wash_speed = 50;
int cure_speed = 50;
String display_speed = "50%";



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
  if (submenu_num == 0){   //main menu navigation
    menu_num += x;        // moving up and down in main menu
    if (menu_num > 3){menu_num = 1;}         // when setting value greater than 3, then go to begining  
    else if (menu_num < 1){menu_num = 3;}    // when setting value lower than 1, then go to end to create a loop
  }
  else if (submenu_num == 1){
    if (menu_num == 1){
      wash_time = wash_time - 10 * x;   // increasing/decreassing wash_time by 10s every button press
    }
    else if (menu_num == 2){
      cure_time = cure_time - 10 * x;   // increasing/decreassing cure_time by 10s every button press
    }
    if (wash_time < 0){wash_time = 0;}  // not allowing wash_time to be set below 0
    if (cure_time < 0){cure_time = 0;}  // not allowing cure_time to be set below 0
  }
  else if (submenu_num == 2){
    if (menu_num == 1){
      wash_speed = wash_speed - 5 * x;  // increasing/decreasing wash_speed by 5 % every up/down pressed
      if(wash_speed > 100){wash_speed = 100;}
      else if(wash_speed < 10){wash_speed = 10;}
    }
    else if (menu_num == 2){
      cure_speed = cure_speed - 5 * x;  // increasing/decreasing cure_speed by 5 % every up/down pressed
      if(cure_speed > 100){cure_speed = 100;}     // not allowing cure_speed to be set above 100
      else if(cure_speed < 10){cure_speed = 10;}  // not allowing cure_speed to be set below 10
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
    if (menu_num == 1){
      display_time = time_format_str(wash_time);
      menu_wash(display_time);
      }
    else if (menu_num == 2){
      display_time = time_format_str(cure_time);
      menu_cure(display_time);
      }
    else if (menu_num == 3){menu_settings();}
  }
  else if (submenu_num == 2){
    if (menu_num == 1){
      display_time = time_format_str(wash_time);
      display_speed = percentage_format_str(wash_speed);
      washing(display_time, display_speed);
    }
    else if (menu_num == 2){
      display_time = time_format_str(cure_time);
      display_speed = percentage_format_str(cure_speed);
      curing(display_time, display_speed);
    }
  }
}

//converting to time format and returning result
String time_format_str(int time){
  String x = "";
  String y = "";
  if((time / 60) < 10){x = "0" + String(time / 60);}  // adding "0" if there is only one diggit
  else {x = String(time / 60);}
  if((time % 60) < 10){y = "0" + String(time % 60);}  // adding "0" if there is only one diggit
  else {y = String(time % 60);}
  String result = x + ":" + y;  // putting together minuts and seconds
  return(result);
}


// convert percentage int to displayed String
String percentage_format_str(int per){
  String result = String(per)+"%";
  return result;

}
