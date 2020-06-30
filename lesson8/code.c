#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262

// 定义旋律
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

// 音符持续时间：4 =四分音符，8 =八分音符，依此类推。:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup() {
  // 重复旋律的音符:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // 计算音符持续时间，需要一秒钟
    // 除以音符类型。
    // 例如 四分音符= 1000/4，八分音符= 1000/8，依此类推。
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // 为了区分音符，请在它们之间设置最短时间。
    // 持续时间+ 30％似乎运行良好：
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // 停止播放音调：
    noTone(8);
  }
}

void loop() {
  // 无需重复旋律。
}