/*
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  ボタンでLチカ
  ボタンを押すと、点灯・消灯します。

  Try:
*/

#define LED_PIN 13
#define BUTTON_PIN 12
bool state = false; // 点灯状態 true:点灯 false:消灯
bool oldIsPush = HIGH; // 前回ボタン状態

// セットアップ関数は、電源ON時に1度だけ実行される
void setup() {
  // ピンの初期化
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// ループ関数は、ずっと実行され続ける
void loop() {
  bool isPush = digitalRead(BUTTON_PIN);

  // ボタンOFF⇒ボタンONの時だけ
  if(HIGH == oldIsPush && LOW == isPush){
    if(state){                      // true == trueと同じ。
      digitalWrite(LED_PIN, LOW);   // 消灯
      state = false;
    }else{
      digitalWrite(LED_PIN, HIGH);  // 点灯
      state = true;
    }
  }
  
  oldIsPush = isPush; // 前回のボタン状態を保持
  delay(100);
}
