/*
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  Lチカ
  スケッチ例「Blink」の日本語解説版。

  ボードのLEDが点滅します。
  デジタル13番PINにLEDを挿すと点滅します。
*/

// セットアップ関数は、電源ON時に1度だけ実行される
void setup() {
  // ピンの初期化
  pinMode(13, OUTPUT);
}

// ループ関数は、ずっと実行され続ける
void loop() {
  digitalWrite(13, HIGH);   // 点灯
  delay(1000);              // 1秒待つ
  digitalWrite(13, LOW);    // 消灯
  delay(1000);              // 1秒待つ
}
