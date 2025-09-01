#include "screen.h"


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
String ver = "1.0"; //zmienna wersji oprogramowania

// Initialize display
void init_display(){
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Zatrzymaj jeśli nie działa
  }
}


// ##################################################### FUNCTIONS FOR DISPLAY SCREENS ################################################
// TextSize(1) - szerokość 6px, wysokość 8px, TextSize(2) - szerokość 12px, wysokość 16px, TextSize(3) - szerokość 18px, wysokość 24px

// screen with WASH lightened
void menu_1() {
  display.clearDisplay();
  display.fillRoundRect(0, 0, 128, 21, 2, WHITE);
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(5, 3);
  display.println("WASH");
  display.setTextColor(WHITE);
  display.setCursor(5, 24);
  display.println("CURE");
  display.setCursor(5, 45);
  display.println("SETTINGS");
  display.display();
}

//screen with CURE lightened
void menu_2() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(5, 3);
  display.println("WASH");
  display.fillRoundRect(0, 22, 128, 21, 2, WHITE);
  display.setTextColor(BLACK);
  display.setCursor(5, 24);
  display.println("CURE");
  display.setTextColor(WHITE);
  display.setCursor(5, 45);
  display.println("SETTINGS");
  display.display();
}

//screen with SETTINGS lightened
void menu_3() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(5, 3);
  display.println("WASH");
  display.setTextColor(WHITE);
  display.setCursor(5, 24);
  display.println("CURE");
  display.fillRoundRect(0, 43, 128, 21, 2, WHITE);
  display.setTextColor(BLACK);
  display.setCursor(5, 45);
  display.println("SETTINGS");
  display.display(); 
}

//WASH menu
void menu_wash(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40, 5);
  display.println("WASH");
  display.setCursor(5,25);
  display.print("Time ");
  display.println("display_time");
  display.fillTriangle(20, 63, 28, 50, 36, 63, WHITE);
  display.fillTriangle(92, 50, 100, 63, 108, 50, WHITE);
  display.display();
}

//CURE menu
void menu_cure(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(40, 0);
  display.println("CURE");
  display.display();
}

//SETTINGS menu
void menu_settings(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(16, 0);
  display.println("SETTINGS");
  display.display();
}

// welcome screen
void begin_screen(){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);
  display.println("Wash&Cure");
  display.setTextSize(1);
  display.setCursor(55, 45);
  display.print("Version:");
  display.print(ver);
  display.display();
  delay(5000);
}

