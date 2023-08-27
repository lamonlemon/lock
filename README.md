자전거 잠금장치 개발일지
=

자전거를 학원에 이동할때 사용하는데 자꾸 자물쇠를 잠그는 것을 깜박해 잠그고 가지않는다.  
그래서 자동 잠금장치를 생각해냈다.

* 부품 리스트:  
    * [솔레이노드x2](https://t.ly/c1NPf)  
    * *아두이노 우노*
    * *hc-06*
    * [hc-05](https://www.devicemart.co.kr/goods/view?no=1278894)
    * 아두이노 나노
    * *자이로 센서*
    * *부저*
    * 3D 모델링
    * *브래드보드X2*
    * *점퍼 케이블*
    * 9v배터리
    * [충전식 9v배터리](https://www.tmon.co.kr/deal/4540700634)
    * 9v배터리 교류 어뎁터
    * [태양광 충전기](http://item.gmarket.co.kr/Item?goodscode=2308230841&buyboxtype=ad)
    * 9v배터리 직류 어뎁터
  
솔레노이드 원리
```
솔레노이드란 도선을 촘촘하고 균일하게 원통형으로 길게 감아 만든 기기이다.   
솔레노이드에 전기를 주지 않으면 트리거가 발동되어 스프링이 튀어나오고 전기를 주면 당겨진다.  
```

작동원리
```
나노를 가방에 부착한 후, 우노와 블루투스 통신을 한다.
블루투스가 끊어진 것을 우노가 감지하면 전기 신호를 줘 솔레노이드를 작동시킨다.
다시 나노와 통신이 되면 우노가 전기 신호를 꺼서 솔레노이드가 들어간다.
```

경보
```
경보는 자이로센서로 작동되며, 솔레노이드가 작동된 이후부터 작동된다.
움직임이 5번 감지될시 경보음을 울린다.
```

솔레노이드 소스 코드
```c
void setup() {
    pinMode(4, OUTPUT);
}

void loop() {
    // 불루투스 연결시
    digitalWrite(4, HIGH); 
    // 불루투스 연결 불가시
    digitalWrite(4, LOW); 
}
```

블루투스 연결 코드
```c
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); //BlueTooth(Rx, Tx)

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  if (bluetooth.available()){
    Serial.write(bluetooth.read());
  }
  if (Serial.available()){
    bluetooth.write(Serial.read());
  }
}

```

총합 코드
```c
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(2, 3); //BlueTooth(Rx, Tx)

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, INPUT); //state
}

void loop() {
  if (bluetooth.available()){
    Serial.write(bluetooth.read());
  }
  if (Serial.available()){
    bluetooth.write(Serial.read());
  }
  if(digitalRead(5)){
    digitalWrite(4, HIGH); 
  }else {
    digitalWrite(4, LOW);
  }
}
```