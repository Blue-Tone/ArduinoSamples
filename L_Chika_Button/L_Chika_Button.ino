/*
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  ボタンでLチカ
  ボタンを押すと点灯します。

  Try:
*/

#define LED_PIN 13
#define BUTTON_PIN 12

// セットアップ関数は、電源ON時に1度だけ実行される
void setup() {
  // ピンの初期化
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// ループ関数は、ずっと実行され続ける
void loop() {
  bool isPush = digitalRead(BUTTON_PIN);
  if(isPush){
    digitalWrite(LED_PIN, LOW);    // 消灯
  }else{
    digitalWrite(LED_PIN, HIGH);   // 点灯
  }
  delay(100);
}
