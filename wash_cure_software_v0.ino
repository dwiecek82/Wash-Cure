#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3C  // najczęściej 0x3C (sprawdź, jeśli nie działa)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Button pins
int btn_up = 15;
int btn_down = 16;
int btn_right = 17;
int btn_left = 14;

// version number
String ver = "1.0";

void showMessage(const char* message) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0, 20); // wyśrodkuj jak chcesz
  display.println(message);
  display.display();
}

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


  // Button pin modes
  pinMode(btn_up, INPUT_PULLUP);
  pinMode(btn_down, INPUT_PULLUP);
  pinMode(btn_right, INPUT_PULLUP);
  pinMode(btn_left, INPUT_PULLUP);
}

void loop() {
  menu_1();
  delay(1000);
  menu_2();
  delay(1000);
  menu_3();
  delay(1000);

  // if (digitalRead(btn_up) == LOW) {
  //   showMessage("UP");
  //   Serial.println("UP");
  //   while (digitalRead(btn_up) == LOW) {}
  // }
  // else if (digitalRead(btn_down) == LOW) {
  //   showMessage("DOWN");
  //   Serial.println("DOWN");
  //   while (digitalRead(btn_down) == LOW) {}
  // }
  // else if (digitalRead(btn_right) == LOW) {
  //   showMessage("RIGHT");
  //   Serial.println("RIGHT");
  //   while (digitalRead(btn_right) == LOW) {}
  // }
  // else if (digitalRead(btn_left) == LOW) {
  //   showMessage("LEFT");
  //   Serial.println("LEFT");
  //   while (digitalRead(btn_left) == LOW) {}
  // }

  // delay(100); // debounce
}