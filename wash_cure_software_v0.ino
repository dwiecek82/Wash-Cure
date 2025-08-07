

// setting pins for buttons
int btn_up = 15;
int btn_down = 16;
int btn_right = 17;
int btn_left = 14;

// bool btn_up_state = 1;
// bool btn_down_state = 1;
// bool btn_right_state = 1;
// bool btn_left_state = 1;


void setup() {
  // initialized serial communication at 9600 bps
  Serial.begin(9600);

  // define pinMode for buttons
  pinMode(btn_up, INPUT_PULLUP);
  pinMode(btn_down, INPUT_PULLUP);
  pinMode(btn_right, INPUT_PULLUP);
  pinMode(btn_left, INPUT_PULLUP);

}


void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(btn_up)== LOW) {
    Serial.println("wciśnięto przycisk UP");
    while(digitalRead(btn_up)==LOW){}
  }
  else if (digitalRead(btn_down)==LOW) {
    Serial.println("wciśnięto przycisk DOWN");
    while(digitalRead(btn_down)==LOW){}
  }
  else if (digitalRead(btn_right)==LOW) {
    Serial.println("wciśnięto przycisk RIGHT");
    while(digitalRead(btn_right)==LOW){}
  }
  else if (digitalRead(btn_left)==LOW) {
    Serial.println("wciśnięto przycisk LEFT");
    while(digitalRead(btn_left)==LOW){}
  }
  
  delay(100);
}
