
#include <Servo.h>

Servo myservo;

// #define DEBUG 0
#define PIN_SERVO_SIGNAL 11
#define PIN_LIGHT_DO 12
#define PIN_LIGHT_POWER 13

#define RELEASE 80
#define PRESS 67

void setup()
{
    pinMode(PIN_LIGHT_POWER, OUTPUT);
    pinMode(PIN_LIGHT_DO, INPUT);
    digitalWrite(PIN_LIGHT_POWER, HIGH);
    myservo.attach(PIN_SERVO_SIGNAL);
    myservo.write(RELEASE);
    delay(1000);

#ifdef DEBUG
    Serial.begin(9600);
#endif
}

void loop()
{
#ifdef DEBUG
    Serial.println(analogRead(A0));
    Serial.println(digitalRead(PIN_LIGHT_DO));
#endif

    if (digitalRead(PIN_LIGHT_DO) == 0)
    {
        myservo.write(PRESS);
        delay(100);
        myservo.write(RELEASE);

        while (digitalRead(PIN_LIGHT_DO) == 0)
        {
            delay(500);
        }
    }
    else
    {
        myservo.write(RELEASE);
    }
    delay(100);
}
