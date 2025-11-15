# Arduino
--------------------------------------------------

# 1. 特性
HIGH 等于 1 \
LOW 等于 0


--------------------------------------------------
--------------------------------------------------
# 2. 界面

## 2.1 直观显示
Tools -> Serial Monitor (可获取Serial.println打印的信息)
Tools -> Serial Plotter (绘制 随时间变化的量 的图表)


--------------------------------------------------
--------------------------------------------------
# 3. 示例

## 3.1 电位器
```c++
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue); // [0,1023], 线性变化, 对应电压[0,5]V
  delay(1);  // delay in between reads for stability
}
```
## 3.2 电位器控制LED
```c++
// get it form the potentiometer, [0,1023]
sensorValue = analogRead(analogInPin);

// analogWrite function only accepts [0,255]
outputValue = map(sensorValue, 0, 1023, 0, 255); 

// write it to a PWM pin
analogWrite(analogOutPin, outputValue);
```

## 3.3 将PWM方波输出转为连续的模拟电压
![简易RC低通滤波]





--------------------------------------------------
