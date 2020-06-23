#include <MsTimer2.h>     //定时器库的头文件
#define IN1 8
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 13
#define LT 6
#define BT 7

volatile int pinInterrupt = 2; //接中断信号的脚
int i = 0;
int tick = 0; //计数值

//循环 
void onTimer()
{
  i++;
  tick = i;
  if(i == 9)
  {
    i=-1;
  }
}
//中断服务程序 清零
void onChange()
{
  i=-1;
}

void setup()
{
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH); 
  digitalWrite(S1,HIGH);
  Serial.begin(9600); //初始化串口
   
  pinMode( pinInterrupt, INPUT);//设置管脚为输入  

  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  MsTimer2::set(1000, onTimer); //设置中断，每1000ms进入一次中断服务程序 onTimer()
  MsTimer2::start(); //开始计时

}

void loop()
{
  
    digitalWrite(S1,LOW);
    digitalWrite(8,tick&0x1);
    digitalWrite(3,(tick>>1)&0x1);
    digitalWrite(4,(tick>>2)&0x1);
    digitalWrite(5,(tick>>3)&0x1);
    delay(1000);
  
}
