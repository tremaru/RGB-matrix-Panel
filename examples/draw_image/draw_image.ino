﻿#include <RGBmatrixPanel.h>                                                       // Подключаем библиотеку для работы с матрицей

// Используем эти выводы, если матрица подключена к Arduino UNO
//#define CLK  8
//#define OE   9
//#define LAT 10

// Используем эти выводы, если матрица подключена к Arduino MEGA
//#define CLK 11
//#define OE   9
//#define LAT 10

// Используем эти выводы, если матрица подключена к Piranha ULTRA
#define CLK 11                                                                    // Вывод Arduino, к которому подключён вывод CLK матрицы
#define OE  12                                                                    // Вывод Arduino, к которому подключён вывод OE матрицы
#define LAT 13                                                                    // Вывод Arduino, к которому подключён вывод LAT матрицы

#define A   A0                                                                    // Вывод Arduino, к которому подключён вывод A матрицы
#define B   A1                                                                    // Вывод Arduino, к которому подключён вывод B матрицы
#define C   A2                                                                    // Вывод Arduino, к которому подключён вывод C матрицы
#define D   A3                                                                    // Вывод Arduino, к которому подключён вывод D матрицы

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);                        // Объявляем объект matrix для работы с матрицей 64х32, всключаем двойную буферизацию

static const uint8_t PROGMEM img[] = {                                            // Массив с изображением
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000111,B11111000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00001111,B11111100,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00111111,B11111111,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B01111111,B11111111,B10000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111110,B00011111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111100,B00001111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111111,B11111111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111111,B11111111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B11111111,B11111111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00111000,B11111000,B00000111,B11000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
};

void setup() {
  matrix.begin();                                                                 // Инициируем работу с матрицей
}

void loop() {
  matrix.fillScreen(0);                                                           // Очищаем экран
  matrix.drawBitmap(0, 0, img, 64, 32, matrix.Color333(3,3,3));                   // Выводим изображение из массива, задав ему белый цвет
  matrix.swapBuffers(false);                                                      // Выводим изображение из буфера на матрицу
}
