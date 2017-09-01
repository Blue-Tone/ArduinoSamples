/*
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  ランダムLチカ

  ボードのLEDがランダム点滅します。
  デジタル13番PINにLEDを挿すとランダム点滅します。

  Try:
  delayTimeをシリアルに出力してみよう。
  13番ピンを定数化して、12番ピンに変更してみよう。
  ランダム値取得とdelay();の処理を関数化して、ランダムの範囲を変更してみよう。
*/

// セットアップ関数は、電源ON時に1度だけ実行される
void setup() {
  // ピンの初期化
  pinMode(13, OUTPUT);
}

// ループ関数は、ずっと実行され続ける
void loop() {
  int delayTime;            // 待ち時間の変数

  digitalWrite(13, HIGH);   // 点灯
  delayTime = random(20,400);// 20ms～400msでランダム値取得
  delay(delayTime);
  
  digitalWrite(13, LOW);    // 消灯
  delayTime = random(20,400);
  delay(delayTime);
}
