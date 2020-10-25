
#include "Keyboard.h"
#include "Mouse.h"

// キー数
const int num = 6;
// ピン番号指定
const int key[num] = {2, 3, 4, 5, 6, 7};
// チャタリング防止用のカウンター
int flag[num];
// チャタリング防止用のカウント数
const int count = 5500;

void setup() {
    // 初期化
    for(int i = 0; i < num; i++){
        pinMode(key[i], INPUT);
        flag[i] = 0;
    }

    Serial.begin(9600);
    Mouse.begin();
    Keyboard.begin();
}

void loop() {
    // key入力
    for(int i = 0; i < num;i++){
        if(digitalRead(key[i]) == HIGH) {
            flag[i] += 1;
            if(flag[i] > count) {
                switch(i){
                    case 0:
                      Keyboard.press(KEY_LEFT_CTRL);
                      Keyboard.write(KEY_PAGE_UP);
                      Keyboard.release(KEY_LEFT_CTRL);
                      break;
                    case 1:
                      Keyboard.press(KEY_LEFT_CTRL);
                      Keyboard.write(KEY_PAGE_DOWN);
                      Keyboard.release(KEY_LEFT_CTRL);
                      break;
                    case 2:
                      Keyboard.write(KEY_UP_ARROW);
                      break;
                    case 3:
                      Keyboard.write(KEY_DOWN_ARROW);
                      break;
                    case 4:
                      Mouse.move(0, 0, 1);
                      break;
                    case 5:
                      Mouse.move(0, 0, -1);
                      break;
                }
                flag[i] = 0;
            }
        }
    }
}
