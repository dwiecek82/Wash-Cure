#ifndef LOGIC_H
#define LOGIC_H

#include "screen.h"

// Buttons pins
constexpr int btn_up = 15;
constexpr int btn_down = 16;
constexpr int btn_right = 17;
constexpr int btn_left = 14;


// included function from .cpp file
void button_press(); //button press handling
void button_init();
void menu_selection(int x, int y);
void display_selection();
String time_format_str(int time);
String percentage_format_str(int per);
void countdown(int &time);
void proccess_check();

#endif