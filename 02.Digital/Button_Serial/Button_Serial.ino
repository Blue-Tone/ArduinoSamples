/*
  Button
  ボタン

  日本語訳
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  サンプルをPULLUPにして、抵抗接続不要にしています。

  回路接続：
  ボタンをデジタル2番ピンとGNDに接続。
  LEDをデジタル13番ピンに接続。

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
  pinMode(buttonPin, INPUT_PULLUP); // PULLUPを指定することで、内部の抵抗を使用する

  // シリアル初期化
  Serial.begin(9600);
}

void loop() {
  // ボタンの状態を読み込む
  buttonState = digitalRead(buttonPin);

  // 変数の状態を表示
  Serial.print("buttonState=");
  Serial.println(buttonState); 

  // ボタンが押されているかチェック
  // 押されていたら、LOWになる
  if (buttonState == LOW) {
    // LEDオン:
    digitalWrite(ledPin, HIGH);
  } else {
    // LEDオフ:
    digitalWrite(ledPin, LOW);
  }
}
