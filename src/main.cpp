/*
  浮点例子
  本程序初始化浮点值至1.1
  每循环一次减少0.1，直到该值为0

*/

#include <Arduino.h>

float value = 1.1;

//如果a和b之间的差很小，则返回true
//把DELTA的值设成能视作相等的最大差值
int almostEqual(float a,float b)
{
  const float DELTA = .00001;//视作几乎相等的最大差值
  if (a == 0) return fabs(b) <= DELTA;
  if (b == 0) return fabs(a) <= DELTA;
  return fabs((a-b)/max(fabs(a),fabs(b))) <= DELTA;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = value - 0.1;
  if(value==0)
    Serial.println("The value is exactly zero");
  else if(almostEqual(value,0))
  {
    Serial.print("The value");
    Serial.print(value,7);//打印到第七位小数
    Serial.println("is almost equal to zero");
  }
  else
    Serial.println(value);

  delay(100);
}

void test_one(){
  
}