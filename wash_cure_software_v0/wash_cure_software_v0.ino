#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C  // najczęściej 0x3C (sprawdź, jeśli nie działa)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// TextSize(1) - szerokość 6px, wysokość 8px, TextSize(2) - szerokość 12px, wysokość 16px, TextSize(3) - szerokość 18px, wysokość 24px

// Button pins
int btn_up = 15;
int btn_down = 16;
int btn_right = 17;
int btn_left = 14;

// variables
int menu_num = 1;
int submenu_num = 0;
bool wash_function = 0;
bool cure_function = 0;
int wash_time[2] = {0, 30};
int cure_time[2] = {0, 30};
String display_time = "";


// version number
String ver = "1.0";

// menu selector
void menu_selection(int x, int y){
  if(submenu_num == 0){
    menu_num = menu_num + x;
  }
  if(menu_num < 1){
    menu_num = 3;
  }
  else if (menu_num > 3){
    menu_num = 1;
  }
  if (y == 1 && submenu_num == 0){
    submenu_num = menu_num;
  }
  else if (y == -1){
    submenu_num = 0;
  }
  if (x == -1 && submenu_num == 1 && wash_function == 0){ // setting wash time up
    wash_time[1] = wash_time[1] + 30;
    if (wash_time[1] >= 60){
      wash_time[0] = wash_time[0]+1;
      wash_time[1] = 0;
    }
    string_creator(wash_time[0], wash_time[1]);
  }
  if (x == 1 && submenu_num == 1 && wash_function == 0){  // settings wash time down
    wash_time[1] = wash_time[1] - 30;
    if (wash_time[1] < 0){
      wash_time[0] = wash_time[0] - 1;
      wash_time[1] = 30;
      if (wash_time[0] < 0){
        wash_time[0] = 0;
        wash_time[1] = 0;
      }
    }
    string_creator(wash_time[0], wash_time[1]);
  }
  return menu_num, submenu_num;
}

// proper menu selecting
void display_selection(){
  if(menu_num == 1 && submenu_num == 0){
    menu_1();
  }
  else if(menu_num == 2 && submenu_num == 0){
    menu_2();
  }
  else if(menu_num == 3 && submenu_num == 0){
    menu_3();
  }
  else if(submenu_num == 1){
    menu_wash();
  }
  else if(submenu_num == 2){
    menu_cure();
  }
  else if(submenu_num == 3){
    menu_settings();
  }
}

// creating string from list to display as time
void string_creator(int x, int y){
  String sec = String(y);
  if (sec == "0"){
    sec = "00";
  }
  String min = String(x);
  display_time = min + ":"+ sec;
  return(display_time);
}

// modifying time variable
void time_modify(int x, String y){
  //TODO

}

void showMessage(const char* message) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20); // wyśrodkuj jak chcesz
  display.println(message);
  display.display();
}

// ##################################################### FUNCTIONS FOR DISPLAY SCREENS ################################################

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
  display.println(display_time);
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


void setup() {
  Serial.begin(9600);

  // Initialize display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Zatrzymaj jeśli nie działa
  }

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

  menu_1();
  string_creator(wash_time[0], wash_time[1]);

  // Button pin modes
  pinMode(btn_up, INPUT);
  pinMode(btn_down, INPUT);
  pinMode(btn_right, INPUT);
  pinMode(btn_left, INPUT);

}

void loop() {


  if (digitalRead(btn_up) == LOW) {
    menu_selection(-1, 0);
    display_selection();
    Serial.println("UP");
    while (digitalRead(btn_up) == LOW) {}
  }
  else if (digitalRead(btn_down) == LOW) {
    menu_selection(1, 0);
    display_selection();
    Serial.println("DOWN");
    while (digitalRead(btn_down) == LOW) {}
  }
  else if (digitalRead(btn_right) == LOW) {
    menu_selection(0, 1);
    display_selection();
    Serial.println("RIGHT");
    while (digitalRead(btn_right) == LOW) {}
  }
  else if (digitalRead(btn_left) == LOW) {
    menu_selection(0, -1);
    display_selection();
    Serial.println("LEFT");
    while (digitalRead(btn_left) == LOW) {}
  }

  delay(100); // debounce
}