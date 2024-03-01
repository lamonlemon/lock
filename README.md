자전거 잠금장치 개발일지
=

자전거를 학원에 이동할때 사용하는데 자꾸 자물쇠를 잠그는 것을 깜박해 잠그고 가지않는다.  
그래서 자동 잠금장치를 생각해냈다.

*참고: *사선 글시는 있는 부품이다.*  
*참고: 솔레이노드는 12v다.(아두이노 출력 전압:5v)

* 부품 리스트:  
    * [솔레이노드x2](https://t.ly/c1NPf)  
    * *아두이노 우노*
    * *hc-06*
    * [hc-05](https://www.devicemart.co.kr/goods/view?no=1278894)
    * [아두이노 나노](https://t.ly/7SXEn)
    * *자이로 센서*
    * *부저*
    * 3D 모델링
    * *브래드보드X2*
    * *점퍼 케이블*
    * 9v배터리
    * [충전식 9v배터리](https://www.tmon.co.kr/deal/4540700634)
    * [9v배터리 교류 어뎁터](t.ly/F8_vg)
    * *USB A <-> USB MICO B* 
    * [태양광 충전기](http://item.gmarket.co.kr/Item?goodscode=2308230841&buyboxtype=ad)
    * 9v배터리 직류 어뎁터
  
솔레노이드
![](img/solanoid.png)
처음에는 솔레노이드를 사용할 계획이였으나,손으로 눌리기 때문에 실패.  
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