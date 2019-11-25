#include <RGBmatrixPanel.h>                                   // Подключаем библиотеку для работы с матрицей

// Используем эти выводы, если матрица подключена к Arduino UNO
//#define CLK  8
//#define OE   9
//#define LAT 10

// Используем эти выводы, если матрица подключена к Arduino MEGA
//#define CLK 11
//#define OE   9
//#define LAT 10

// Используем эти выводы, если матрица подключена к Piranha ULTRA
#define CLK 11                                                // Вывод Arduino, к которому подключён вывод CLK матрицы
#define OE  12                                                // Вывод Arduino, к которому подключён вывод OE матрицы
#define LAT 13                                                // Вывод Arduino, к которому подключён вывод LAT матрицы

#define A   A0                                                // Вывод Arduino, к которому подключён вывод A матрицы
#define B   A1                                                // Вывод Arduino, к которому подключён вывод B матрицы
#define C   A2                                                // Вывод Arduino, к которому подключён вывод C матрицы
#define D   A3                                                // Вывод Arduino, к которому подключён вывод D матрицы

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);   // Объявляем объект matrix для работы с матрицей 64х32, включаем двойную буферизацию
uint8_t j;                                                    // Переменная цвета

void setup() {
  matrix.begin();                                             // Инициируем работу с матрицей
}

void loop() {
  for (j = 0; j < 24; j++) {
    matrix.fillRect(2, 2, 28, 28, Color_wheel(j));            // выводим на экран квадрат размером 28х28
    delay(1);                                                 // задержка 1мс
    matrix.drawRect(34, 2, 28, 28, Color_wheel(j + 4));       // выводим на экран рамку квадрата размером 28х28
    delay(1);                                                 // задержка 1мс
  }
}

// смешивание цвета
uint16_t Color_wheel(byte Color) {                            // функция зависит от параметра Color
  if (Color < 8) {                                            // если значение параметра меньше 8, тогда
    return matrix.Color333(7 - Color, Color, 0);              // назначаем цвет с переходом от красного к зелёному
  } else if (Color < 16) {                                    // если значение параметра меньше 16, тогда
    Color -= 8;                                               // ограничиваем значение параметра Color, чтобы он входил в интервал от 0 до 7
    return matrix.Color333(0, 7 - Color, Color);              // назначаем цвет с переходом от зелёного к синему
  } else {                                                    // если значение параметра больше 16, тогда
    Color -= 16;                                              // ограничиваем значение параметра Color, чтобы он входил в интервал от 0 до 7
    return matrix.Color333(Color, 0, 7 - Color);              // назначаем цвет с переходом от синего к красному
  }
}