/*
  Analog input, analog output, serial output
  アナログ入力、アナログ出力、シリアル出力。
  
  日本語訳
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  可変抵抗向けのスケッチを、光センサー(CdSセル:フォトレジスタ)向けに修正。
  
 */

// ピン番号設定。変数は変化しません
const int analogInPin = A0;  // アナログ入力ピン センサーに接続。もう片方はGNDへ。
const int analogOutPin = 9;  // アナログ出力ピン LEDに接続

int sensorValue = 0;        // センサー値の読取り用
int outputValue = 0;        // PWM出力用 (アナログ出力)

void setup() {
  // シリアルを通信速度9600bpsで初期化
  Serial.begin(9600);
  pinMode(analogInPin, INPUT_PULLUP);   // プルアップ
}

void loop() {
  // アナログ入力読取り
  sensorValue = analogRead(analogInPin);
  // アナログ出力範囲に変換(0～1023→0～255)
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // アナログ出力値を変更
  analogWrite(analogOutPin, outputValue);

  // シリアルモニターに結果表示
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // ADC(アナログ・デジタル・コンバーター)の読み取りから、
  // 次のループまで2ミリ秒待つ。
  delay(2);
}
