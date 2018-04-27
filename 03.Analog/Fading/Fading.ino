/*
 Fading
 フェード
  
  日本語訳
  Copyright © 2018 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

 This example shows how to fade an LED using the analogWrite() function.
analogWrite()を使用して、LEDをフェード（ふんわり点灯）するサンプル。
 
 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */


int ledPin = 9;    // デジタル9番ピンにLEDを接続

void setup() {
  // 初期化処理なし
}

void loop() {
  // 最小から最大まで、5ずつ増やしてフェードイン
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // 値を設定(範囲：0～255)
    analogWrite(ledPin, fadeValue);
    // 調光がわかるように30ミリ秒待つ
    delay(30);
  }

  // 最大から最小まで、5ずつ減らしてフェードアウト
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // 値を設定(範囲：0～255)
    analogWrite(ledPin, fadeValue);
    // 調光がわかるように30ミリ秒待つ
    delay(30);
  }
}


