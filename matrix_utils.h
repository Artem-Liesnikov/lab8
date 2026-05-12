// matrix_utils.h
// Заголовки функцій для роботи з двовимірними масивами (завдання 2)
// Варіант: Matrix36 — кількість рядків, схожих на перший рядок

#pragma once
#include <string>

const int MAX_M   = 20;  // максимальна кількість рядків
const int MAX_NM  = 20;  // максимальна кількість стовпців
const int MAX_VAL = 101; // значення елементів: 0..100

// Зчитати цілочисельну матрицю з файлу
// Формат: перший рядок — M N (рядки і стовпці), далі — елементи по рядках
void get_matrix(const std::string& filename,
                int in_mx[][MAX_NM], int& in_m, int& in_n);

// Вивести матрицю у консоль
void print_matrix(const int mx[][MAX_NM], int m, int n);

// Matrix36: знайти кількість рядків (2..M), схожих на перший рядок
// Два рядки «схожі», якщо збігаються множини різних чисел, що в них зустрічаються
int count_similar_rows(const int mx[][MAX_NM], int m, int n);

// Дописати результат у той самий файл (завдання 2 вимагає дописати, не перезаписати)
void append_result(const std::string& filename, int similar_count);
