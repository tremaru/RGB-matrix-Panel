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

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);    // Объявляем объект matrix для работы с матрицей 64х32, всключаем двойную буферизацию

const char str[] = "Input your text here!";                   // Массив для хранения текста, выводимого на матрицу
int16_t    textX         = matrix.width();                    // Переменная с X-координатой текста

// Минимальное значение координаты текста (количество символов в строке, помноженное на ширину одного символа), после которой текст начнёт повторно выводиться
int16_t    textMin       = sizeof(str) * -6;

void setup() {
  matrix.begin();                                             // Инициируем работу с матрицей
  matrix.setTextWrap(false);                                  // Отключаем перенос текста на следующую строку
  matrix.setTextSize(1);                                      // Устанавливаем размер текста равным 1 (6 пикселей на символ)
}

void loop() {
  matrix.fillScreen(0);                                       // Очищаем экран
  matrix.setTextColor(matrix.Color333(3,3,3));                // Устанавливаем цвет текста
  matrix.setCursor(textX, 12);                                // Указываем начальную координату вывода текста {textX; 12}
  matrix.print(str);                                          // Выводим текст
  --textX;                                                    // Сдвигаем текст на 1 пиксель при каждом выполнении цикла
  if(textX < textMin) textX = matrix.width();                 // Если был отображён весь текст, то начинаем его выводить заново
  matrix.swapBuffers(false);                                  // Выводим текст из буфера на матрицу
}
