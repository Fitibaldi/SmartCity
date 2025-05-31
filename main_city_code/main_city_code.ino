#include <Servo.h>
Servo fireTruckServo;

//common pins
const int buzzerPin = 2;

// street lamps scenario
const int lampsTriggPin = 10;
const int lampsEchoPin = 11;
const int lampsRelayPin = 3;

// Fire scenario pins
const int fireTriggPin = 8;
const int fireEchoPin = 9;
const int hotelYellowFireLeds = 7;
const int hotelRedFireLeds = 6;
const int fireTruckLed = A0;
const int fireTruckServoPin = 5;


void setup() {
  //common initialization
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);

  //street lamps initialization
  pinMode (lampsTriggPin, OUTPUT);
  pinMode(lampsEchoPin, INPUT);
  pinMode(lampsRelayPin, OUTPUT);

  // Fire scenario initialization
  pinMode(fireTriggPin, OUTPUT);
  pinMode(fireEchoPin, INPUT);
  pinMode(hotelRedFireLeds, OUTPUT);
  pinMode(hotelYellowFireLeds, OUTPUT);
  pinMode(fireTruckLed, OUTPUT);
  fireTruckServo.attach(fireTruckServoPin);
  fireTruckServo.write(170);

}

void loop() {
  int distance;

  //Lamps Scenario
  distance = measureDistance(lampsTriggPin, lampsEchoPin);
  Serial.print("Lamps Distance: ");
  Serial.println(distance);

  if (distance <= 10) {
    turnStreetLamps(1);
  } else {
    turnStreetLamps(0);
  }

  // Fire Scenario
  distance = measureDistance(fireTriggPin, fireEchoPin);
  Serial.print("Fire Distance: ");
  Serial.println(distance);

  if (distance <= 10) {
    simulateFire();
  }

  delay(200);
}

int measureDistance(int triggPin, int echoPin) {
  long duration;
  int distance;

  // Изпращане на ултразвуков импулс
  digitalWrite (triggPin, LOW);
  delayMicroseconds(2);
  digitalWrite (triggPin, HIGH);
  delayMicroseconds(10);
  digitalWrite (triggPin, LOW);

  // Измерване на времето за връщане
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  return distance;
}

void turnStreetLamps(int onOff) {
  if (onOff == 1) {
    digitalWrite(lampsRelayPin, LOW);
  } else {
    digitalWrite(lampsRelayPin, HIGH);
  }
}

void simulateFire() {
  // Запалване на хотела
  hotelFire(12);

  // Сирена
  playFireSiren();
  hotelFire(3);

  // Завъртане на серво мотор (пожарната тръгва)
  fireTruckServo.write(10);
  hotelFire(3);
  playFireSiren();

  delay(5000);

  fireTruckServo.write(170);
}

void hotelFire(int reps) {
  for (int i = 0; i < reps; i++) {
    digitalWrite(hotelRedFireLeds, HIGH);
    delay(100);
    digitalWrite(hotelRedFireLeds, LOW);
    digitalWrite(hotelYellowFireLeds, HIGH);
    delay(100);
    digitalWrite(hotelYellowFireLeds, LOW);
  }
}

void playPhoneCall911() {
  // 1. Две позвънявания (пауза между тях)
  for (int i = 0; i < 2; i++) {
    tone(buzzerPin, 500, 300); // Звън
    delay(1000);                // Пауза между звънене
  }

  // 2. Глас на оператор на 911 (по-ниски, равномерни тонове)
  playOperatorVoice();

  delay(500); // Пауза между говорещите

  // 3. Миньон отговаря (забързан бърборещ стил)
  int minionTones[] = {1600, 1800, 1400, 1700, 1500, 1900, 1300, 2000};
  int durations[] = {80, 60, 70, 50, 60, 40, 70, 50};

  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, minionTones[i], durations[i]);
    delay(durations[i] + 30);
  }
}

void playOperatorVoice() {
  // „Hello“
  tone(buzzerPin, 600, 300);
  delay(350);
  tone(buzzerPin, 550, 200);
  delay(300);

  // „Nine“
  tone(buzzerPin, 700, 250);
  delay(300);

  // „One“
  tone(buzzerPin, 650, 200);
  delay(250);

  // „One?“
  tone(buzzerPin, 600, 300);
  delay(400);
}

void playPhoneCallMinions() {
  // Анимационен бърборещ разговор
  int tones[] = {1600, 1800, 1400, 1700, 1500, 1900, 1300, 2000};
  int durations[] = {80, 60, 70, 50, 60, 40, 70, 50};

  for (int i = 0; i < 8; i++) {
    tone(buzzerPin, tones[i], durations[i]);
    delay(durations[i] + 30); // кратка пауза между „думи“
  }
}

void playPhoneCall() {
  // Симулация на телефонен разговор
  tone(buzzerPin, 1200, 200);
  delay(250);
  tone(buzzerPin, 1000, 200);
  delay(250);
  tone(buzzerPin, 800, 200);
  delay(250);
}

void playFireSiren() {
  const int ledToggleInterval = 100; // на всеки 100 ms
  const int toneStepDelay = 10;      // на всеки 10 ms
  unsigned long lastLedToggleTime = millis();
  bool ledState = false;

  for (int cycle = 0; cycle < 10; cycle++) {
    // Нарастваща честота
    for (int freq = 1000; freq <= 2000; freq += 50) {
      tone(buzzerPin, freq);

      // Проверка дали е време да сменим LED състоянието
      if (millis() - lastLedToggleTime >= ledToggleInterval) {
        ledState = !ledState;
        digitalWrite(fireTruckLed, ledState ? HIGH : LOW);
        lastLedToggleTime = millis();
      }

      delay(toneStepDelay);
    }

    // Намаляваща честота
    for (int freq = 2000; freq >= 1000; freq -= 50) {
      tone(buzzerPin, freq);

      if (millis() - lastLedToggleTime >= ledToggleInterval) {
        ledState = !ledState;
        digitalWrite(fireTruckLed, ledState ? HIGH : LOW);
        lastLedToggleTime = millis();
      }

      delay(toneStepDelay);
    }

    delay(30);  // пауза между циклите
  }

  noTone(buzzerPin);
  digitalWrite(fireTruckLed, LOW); // изгасяне след края
}


void playGlassBreak() {
  // Симулира бърз пук
  tone(buzzerPin, 3000, 20);  // висок пик
  delay(30);
  
  // Няколко "трош" импулса
  for (int i = 0; i < 3; i++) {
    tone(buzzerPin, random(400, 800), 30);
    delay(40);
  }

  // Бързи "падания" на честота
  for (int i = 1000; i > 200; i -= 100) {
    tone(buzzerPin, i, 20);
    delay(25);
  }

  noTone(buzzerPin);  // спиране на звука
}

void playPoliceSiren() {
  // Полицейска сирена
  for (int i = 800; i <= 1000; i += 100) {
    tone(buzzerPin, i);
    delay(100);
  }
  for (int i = 1000; i >= 800; i -= 100) {
    tone(buzzerPin, i);
    delay(10);
  }
}
