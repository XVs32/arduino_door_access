
#include <Servo.h>

Servo myservo;

// #define DEBUG 0
#define PIN_SERVO_SIGNAL 11
#define PIN_MIC_DO 12
#define PIN_MIC_POWER 13

#define RELEASE 83
#define PRESS 70

void setup()
{
    pinMode(PIN_MIC_POWER, OUTPUT);
    pinMode(PIN_MIC_DO, INPUT);
    digitalWrite(PIN_MIC_POWER, HIGH);
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
    Serial.println(digitalRead(PIN_MIC_DO));
#endif

    if (digitalRead(PIN_MIC_DO) == 1)
    {
        myservo.write(PRESS);
        delay(100);
    }
    else
    {
        myservo.write(RELEASE);
    }
    delay(100);
}
