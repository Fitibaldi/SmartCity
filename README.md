# 🏙️ Проект: Умен град

Arduino-базиран проект, създаден с участието на дете и възрастен, който симулира град с улично осветление, пожар, и обир – чрез сензори, светлини, звуци и 3D принтирани сгради.

---

## 🎯 Основни функционалности

### 🚦 1. Улично осветление – `simulateStreetLights()`

При активиране на сензор светват всички улици чрез LED диоди. Осветлението се управлява с реле и може да бъде придружено със звукови сигнали:

- `playStartSignal()` – мелодия при включване
- `playEndSignal()` – мелодия при изключване

---

### 🔥 2. Пожар – `simulateFire()`

Симулация на пожар в сграда с визуални и звукови ефекти:

- Светване на сградата с червени и жълти LED поетапно (етаж по етаж)
- `playFireSiren()` – сирена на пожарната
- Мигаща пожарна кола (LED)
- Движение на пожарнат акола посредством серво моторче
- Пожарът се гаси – червено и жълто загасват

---

### 🚨 3. Обир – `simulateRobbery()`

Активира се при приближаване на обект до ултразвуков сензор на под 10 см:

1. `playGlassBreak()` – звук от счупено стъкло
2. Три изстрела със синхронно премигване на червено-жълти диоди
3. Светват съседните къщи (паника)
4. `playPhoneCall911()` – обаждане до полицията
5. `playPoliceSiren()` – сирена и мигаща светлина на патрулка
6. Диалог: „ОК! ОК!“
7. Светлините в съседните къщи изгасват
8. Финално мигане и сирена от патрулката

---

## ⚙️ Използвани технологии

- Arduino Uno
- Ултразвукови сензори (HC-SR04)
- Релета, транзистори (BC337)
- LED диоди в различни цветове
- Пиезо зумер
- 3D принтирани сгради и улици
- Servo мотор

---

## 🛒 Части за закупуване

- Жълти LED – 20 бр.
- Червени LED – 20 бр.
- Сини LED – 10 бр.
- Бели LED – 10 бр.
- Зелени LED – 10 бр.
- Резистори:
  - 220 Ω – за червени, зелени, жълти LED
  - 330 Ω – за сини и бели LED
  - 1kΩ – за базата на транзистори
- BC337 транзистори – 10 бр.
- Ултразвукови сензори – 2 бр.
- Релета – 4 бр.
- Servo мотори – 2–3 бр.

---

## 👩‍🎨 Участници и роли

## 📌 Задачи на Леа

- Създаване на история на града – как е възникнал, какви са му особеностите
- Дизайн на града
- Разписване на изисквания и функционалности
- Украсяване на града
- Измисляне на имена на улици и сгради
- Изработка на табели и декорации
- Създаване на легенда/карта на града
- Презентация на проекта пред класа

---

## 🔧 Задачи на Тедо

- Дизайн на сгради
- 3D принт на сгради
- Окабеляване
- Програмиране на Ардуино за управление на функционалности

---

## 📎 Лиценз

Този проект е за образователни цели. Използвайте и адаптирайте свободно.
