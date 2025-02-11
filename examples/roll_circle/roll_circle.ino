﻿#include <RGBmatrixPanel.h>                                             // Подключаем библиотеку для работы с матрицей

// Используем эти выводы, если матрица подключена к Arduino UNO
//#define CLK  8
//#define OE   9
//#define LAT 10

// Используем эти выводы, если матрица подключена к Arduino MEGA
//#define CLK 11
//#define OE   9
//#define LAT 10

// Используем эти выводы, если матрица подключена к Piranha ULTRA
#define CLK 11                                                          // Вывод Arduino, к которому подключён вывод CLK матрицы
#define OE  12                                                          // Вывод Arduino, к которому подключён вывод OE матрицы
#define LAT 13                                                          // Вывод Arduino, к которому подключён вывод LAT матрицы

#define A   A0                                                          // Вывод Arduino, к которому подключён вывод A матрицы
#define B   A1                                                          // Вывод Arduino, к которому подключён вывод B матрицы
#define C   A2                                                          // Вывод Arduino, к которому подключён вывод C матрицы
#define D   A3                                                          // Вывод Arduino, к которому подключён вывод D матрицы

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);              // Объявляем объект matrix для работы с матрицей 64х32, всключаем двойную буферизацию

int8_t ball[3][4] = {                                                   // Массив с начальными координатами кругов, а так же со значениями, на сколько координаты меняются при каждом выполнении цикла
  {  6,  6,  1,  1 },                                                   // Координаты Синего круга {6;6} и каждый цикл они меняются на 1 по X и на 1 по Y
  { 17, 15,  1, -1 },                                                   // Координаты Зелёного круга {17;15} и каждый цикл они меняются на 1 по X и на -1 по Y
  { 27,  6, -1,  1 }                                                    // Координаты Синего круга {27;6} и каждый цикл они меняются на -1 по X и на 1 по Y
};

static const uint16_t ballcolor[3] = {                                  // Массив с цветами кругов
  matrix.Color333(0, 0, 3),                                             // Синий
  matrix.Color333(0, 3, 0),                                             // Зелёный
  matrix.Color333(3, 0, 0)                                              // Красный
};

void setup() {
  matrix.begin();                                                       // Инициируем работу с матрицей
}

void loop() {
  byte i;                                                               // переменная для того, чтобы круги "бегали" по экрану, меняя координаты
  matrix.fillScreen(0);                                                 // очищаем экран
  for (byte i = 0; i < 3; i++) {                                        // запускаем счётчик для смены координат кругов
    matrix.fillCircle(ball[i][0], ball[i][1], 5, ballcolor[i]);         // Рисуем 3 круга с разными начальными координатами и разного цвета, но одинакового радиуса
    ball[i][0] += ball[i][2];                                           // Обновляем Х-координату кругов
    ball[i][1] += ball[i][3];                                           // Обновляем Y-координату кругов
    if ((ball[i][0] == 5) || (ball[i][0] == (matrix.width() - 5))) {    // Если круг по Х дошёл до границы, то
      ball[i][2] *= -1;                                                 // инициируем движение в обратную сторону
    }
    if ((ball[i][1] == 5) || (ball[i][1] == (matrix.height() - 5))) {   // Если круг по Y дошёл до границы, то
      ball[i][3] *= -1;                                                 // инициируем движение в обратную сторону
    }
  }
  matrix.swapBuffers(false);                                            // выводим объекты из буфера на экран
}
