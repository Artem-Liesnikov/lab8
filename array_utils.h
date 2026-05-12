// array_utils.h
// Заголовки функцій для роботи з одновимірними масивами (завдання 1, 3)
// Варіант: Array84 (циклічний зсув вліво) + Шейкерне сортування за спаданням

#pragma once
#include <string>

const int MAX_N = 20; // максимальний розмір одновимірного масиву

// Зчитати масив дійсних чисел з файлу
// Формат файлу: перший рядок - кількість елементів, другий - елементи через пробіл
void get_mas(const std::string& filename, double in_mas[], int& in_n);

// Записати масив дійсних чисел у файл
void show_mas(const std::string& filename, const double out_mas[], int n);

// Вивести масив у консоль
void print_mas(const double mas[], int n);

// Array84: циклічний зсув масиву вліво на 1 позицію
// A[0]→A[N-1], A[1]→A[0], A[2]→A[1], ..., A[N-1]→A[N-2]
void cyclic_left_shift(double mas[], int n);

// Шейкерне (коктейльне) сортування за спаданням
// Елементи типу double, порядок: від більшого до меншого
void shaker_sort_desc(double mas[], int n);
