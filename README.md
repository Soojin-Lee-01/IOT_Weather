# Iot_project
사물인터넷 프로젝트

 <주제>
 - 여름날씨에 자동으로 동작하는 IOT
 - 낮 : 조도센서를 이용하여 빛을 감지, 낮이라고 판단하면 서보모터를 +90도로 돌리고 위에 부착한 dc모터를 회전시켜준다.
 - 밤 : 조도센서를 이용하여 밤을 감지, 밤이라고 판단하면 dc모터의 작동을 멈추고 LED를 깜빡여준다.
 - 비 : 물감지센서를 이용하여 물을 감지, 비가온다고 판단하면 서보모터를 -90도로 돌리고 위에 부착한 미니 우산을 씌어준다.

<개발환경>
   1. 하드웨어
      - Rasberry Pi 3
      - GPIO, DC Motor, Servo Motor, LED, Photoresistor, Water Sensor
        
   2. 소프트웨어
      - 개발언어 : C
      - 개발 tool : Wiring Pi 라이브러리

<라즈베리파이 회로도> 
![회로도](https://github.com/Soojin-Lee-01/IOT_Weather/assets/87466284/2f3a998a-456e-4a37-80b2-d72043a88fc7)

<코드 알고리즘>
