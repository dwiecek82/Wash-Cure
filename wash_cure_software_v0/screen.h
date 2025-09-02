#ifndef SCREEN_H
#define SCREEN_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "logic.h"


// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C  // najczęściej 0x3C (sprawdź, jeśli nie działa)


extern Adafruit_SSD1306 display; // globalnie widziany obiekt wyświetlacza

// udostępnione funkcje, zawarte w .cpp
void init_display();
void menu_1();
void menu_2();
void menu_3();
void menu_wash(String display_time);
void menu_cure();
void menu_settings();
void begin_screen();


#endif  