
#include <Servo.h>

Servo myservo;

void setup()
{
    pinMode(13, OUTPUT);
    pinMode(8, INPUT);
    digitalWrite(13, HIGH);
    myservo.attach(11); // 設定要將伺服馬達接到哪一個PIN腳
    myservo.write(170);
    delay(1000);

    Serial.begin(9600);
}

void loop()
{
    int sensorValue = analogRead(A0); // 讀取A0的值
    Serial.println(sensorValue);
    Serial.println(digitalRead(8));

    if (digitalRead(8) == 1)
    {
        myservo.write(180);
        delay(1000);
    }
    else
    {
        myservo.write(170);
    }
    delay(10);
}
