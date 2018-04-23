// LEDピン
#define LED_OFFSET  3 // LEDピンの開始番号
#define LED_HEAD  3 // ヘッドライト・テールランプ
#define LED_BRAKE 4 // ブレーキランプ
#define LED_L     5 // 左ウインカー
#define LED_R     6 // 右ウインカー

// ボタンピン
#define BTN_OFFSET  7 // ボタンピンの開始番号
#define BTN_HEAD  7 // ヘッドライト・テールランプ
#define BTN_BRAKE 8 // ブレーキランプ
#define BTN_L     9 // 左ウインカー
#define BTN_R    10 // 右ウインカー

// ライト種別のインデックス
enum LightKind
{
    HEAD  = 0,
    BRAKE,
    L,
    R,
    LIGHT_KIND_MAX,
};

bool states[LIGHT_KIND_MAX];  // 点灯状態
bool oldBtn[LIGHT_KIND_MAX];  // 前回ボタン押下状態

#define BLINK_TIME 500        // 点滅間隔
bool isLedOn = false;         // 点滅状態
unsigned long limitTime = 0;  // 次回点滅時間

void setup() {
  Serial.begin(9600);
  Serial.println("start");

  // ピンの初期化
  for(int i = 0; i < LIGHT_KIND_MAX; i++){
    pinMode(LED_OFFSET + i, OUTPUT);
    pinMode(BTN_OFFSET + i, INPUT_PULLUP);
  }
}

void loop() {
  delay(10);
  
  // ボタン押下判定で、状態変更
  for(int i = 0; i < LIGHT_KIND_MAX; i++){
    if(LOW == digitalRead(BTN_OFFSET + i)){
      if(oldBtn[i] == HIGH){ // ボタン押し始めた時だけ、状態変更。
        states[i] = states[i] ? false : true;
      }
      oldBtn[i] = LOW;
    }else{
      oldBtn[i] = HIGH;
    }
    Serial.print(i);
    Serial.print(", btn=");
    Serial.print(digitalRead(BTN_OFFSET + i));
    Serial.print(", state=");
    Serial.print(states[i]);
    Serial.print(" | ");
  }  
    Serial.print("\n");

  // 現在の状態でLED点灯
  digitalWrite(LED_HEAD, states[HEAD]);
  digitalWrite(LED_BRAKE, states[BRAKE]);
  ledBlink(LED_L, states[L]);
  ledBlink(LED_R, states[R]);

  // 点滅状態更新
  if(limitTime < millis()){ // 点滅時間経過しているか？
    limitTime = millis() + BLINK_TIME;  // 次回点滅時間をセット
    isLedOn = isLedOn ? false : true;   // 点滅状態を反転
  }
  
}

// 点滅
void ledBlink(int pin, bool state){
  if(state){
    // オンなら、点滅
    digitalWrite(pin, isLedOn);
  }else{
    // オフなら消灯
    digitalWrite(pin, LOW);
  }
}

