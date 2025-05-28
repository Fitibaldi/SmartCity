const int trigPin = 10;
const int echoPin = 11;
const int buzzerPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  long duration;
  int distance;

  // Изпращане на ултразвуков импулс
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Измерване на времето за връщане
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 20) {
    playPoliceSiren();
  } else if (distance < 40) {
    playFireSiren();
  } else if (distance < 60) {
    playScream();
    playPhoneCall911();   
    for (int i = 0; i <= 3; i++) {
      playPoliceSiren();
    }
  } else {
    noTone(buzzerPin);
  }

  delay(200);
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

void playScream() {
// Кратък, остър писък
//  tone(buzzerPin, 3500, 300); // Висока честота
//  delay(350);
//  tone(buzzerPin, 3800, 200); // Още по-висока
//  delay(250);
//  tone(buzzerPin, 3200, 150); // Спад
//  delay(200);
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
  // Сирена на пожарна
  for (int i = 1000; i <= 2000; i += 50) {
    tone(buzzerPin, i);
    delay(10);
  }
  for (int i = 2000; i >= 1000; i -= 50) {
    tone(buzzerPin, i);
    delay(10);
  }
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
