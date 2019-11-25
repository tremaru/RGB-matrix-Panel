#include <RGBmatrixPanel.h>                                             // Подключаем библиотеку для работы с матрицей

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

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);             // Объявляем объект matrix для работы с матрицей 64х32
uint8_t r, g, b;                                                        // Переменные цвета светодиодов

void setup() {
  matrix.begin();                                                       // Инициируем работу с матрицей
}

void loop() {
  matrix.fillScreen(0);                                                 // очищаем экран при каждом выполнении цикла
  r = random(1,8);g = random(1,8);b = random(1,8);                      // задаём случайные значения для цвета светодиодов
  matrix.drawPixel(random(64), random(32), matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
  delay(90);                                                            // задержка 90мс
  }
