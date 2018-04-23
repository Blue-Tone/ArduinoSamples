#define LED_PIN 5 // PWMが使えるピンにする。3・5・6・10・11

#define BTN_1 10
#define BTN_2 9
#define BTN_3 8
#define BTN_4 7

#define STATE_OFF     0 // 消灯
#define STATE_ON      1 // 点灯
#define STATE_RANDOM  2 // ランダム
#define STATE_BLINK   3 // 点滅

int state = STATE_OFF;
bool isLedOn = false;
byte brightness = 0;  // 明るさ
unsigned long limitTime = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(BTN_4, INPUT_PULLUP);
  
  Serial.begin(9600);
  Serial.write("start");
}

void loop() {
  if(LOW == digitalRead(BTN_1)){
    state = STATE_ON;
    ledOn();
  }
  
  if(LOW == digitalRead(BTN_2)){
    state = STATE_OFF;
    ledOff();
  }
  
  if(LOW == digitalRead(BTN_3)){
    state = STATE_RANDOM;
  }
  
  if(LOW == digitalRead(BTN_4)){
    state = STATE_BLINK;
  }

  switch(state){
    case STATE_RANDOM:
      ledRandom();
      break;
    case STATE_BLINK:
      ledBlink();
      break;
    default:
      break;
  }
}

// 点灯
void ledOn(){
  brightness = 0;
  while(brightness < 255){
    Serial.println(brightness++, DEC);
    analogWrite(LED_PIN, brightness);
  
    delay( ((255-brightness)) * ((255-brightness)/64) /64);
  }
}

// 消灯
void ledOff(){
  digitalWrite(LED_PIN, LOW);
}

// ランダム
void ledRandom(){
  if(limitTime < millis()){
    limitTime = millis() + random(20,400);
    isLedOn = isLedOn ? false : true;
    digitalWrite(LED_PIN, isLedOn);
  }
}

// 点滅
void ledBlink(){
  if(limitTime < millis()){
    limitTime = millis() + 500;
    isLedOn = isLedOn ? false : true;
    digitalWrite(LED_PIN, isLedOn);
  }
}

