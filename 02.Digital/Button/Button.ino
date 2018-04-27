/*
  Button
  ボタン

  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples
  
 */

// ピン番号設定。変数は変化しません
const int buttonPin = 2;     // ボタンピン番号
const int ledPin =  13;      // LEDピン番号

// 変数は変化します
int buttonState = 0;         // ボタン状態読み取り用変数

void setup() {
  // LEDを出力として初期化
  pinMode(ledPin, OUTPUT);
  // ボタンピンを入力として初期化
  pinMode(buttonPin, INPUT);
}

void loop() {
  // ボタンの状態を読み込む
  buttonState = digitalRead(buttonPin);

  // ボタンが押されているかチェック
  // 押されていたら、HIGHになる
  if (buttonState == HIGH) {
    // LEDオン:
    digitalWrite(ledPin, HIGH);
  } else {
    // LEDオフ:
    digitalWrite(ledPin, LOW);
  }
}
