/*
  Copyright © 2017 BlueTone (bluetoneinfo@gmail.com)
  https://github.com/Blue-Tone/ArduinoSamples

  ボタンでふわっとLチカ
  ボタンを押すと、ふわっと点灯・消灯します。

*/

#define LED_PIN 5 // PWMが使えるピンにする。3・5・6・10・11
#define BUTTON_PIN 12
bool state = false; // 点灯状態 true:点灯 false:消灯
bool oldIsPush = HIGH; // 前回ボタン状態

// セットアップ関数は、電源ON時に1度だけ実行される
void setup() {
  // ピンの初期化
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.write("start");
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
      ledOnPwm();
      state = true;
    }
  }
  
  oldIsPush = isPush; // 前回のボタン状態を保持
  delay(100);
}

// ゆっくり点灯
void ledOnPwm(){
  byte brightness = 0;
  while(brightness < 255){★forに書き換え
    brightness++; // brightness = brightness + 1;と同じ意味。
//    Serial.println(brightness, DEC);
    analogWrite(LED_PIN, brightness); // 明るさを調整して点灯

    float delayTime;
    delayTime = 10;
    // delayTime = ((255.0-brightness)) * ((255.0-brightness)/64) /64);
    
    delay(delayTime) ;
    Serial.println(delayTime);
  }
}
