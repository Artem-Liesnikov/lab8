// matrix_utils.cpp
// Визначення функцій для роботи з двовимірними масивами (завдання 2)

#include "matrix_utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
using namespace std;

// Зчитати цілочисельну матрицю з файлу
void get_matrix(const string& filename, int in_mx[][MAX_NM],
                int& in_m, int& in_n) {
    ifstream fin(filename);
    if (!fin.is_open())
        throw runtime_error("Не вдалося відкрити файл: " + filename);

    // Перший рядок файлу: кількість рядків і стовпців
    fin >> in_m >> in_n;
    if (!fin || in_m < 2 || in_m > MAX_M || in_n < 2 || in_n > MAX_NM)
        throw runtime_error("Некоректний розмір матриці (має бути 2.." +
                            to_string(MAX_M) + " x 2.." + to_string(MAX_NM) + ")");

    // Зчитуємо елементи по рядках
    for (int i = 0; i < in_m; i++) {
        for (int j = 0; j < in_n; j++) {
            fin >> in_mx[i][j];
            if (!fin)
                throw runtime_error("Помилка читання елемента [" +
                                    to_string(i+1) + "][" + to_string(j+1) + "]");
            if (in_mx[i][j] < 0 || in_mx[i][j] > 100)
                throw runtime_error("Значення елементів мають бути 0..100");
        }
    }
    fin.close();
}

// Вивести матрицю у консоль
void print_matrix(const int mx[][MAX_NM], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << mx[i][j];
        cout << "\n";
    }
}

// Matrix36: підрахувати кількість рядків (починаючи з 2-го), схожих на перший
// Алгоритм: для кожного рядка будуємо булеву маску присутності значень 0..100,
// порівнюємо маску з маскою першого рядка
int count_similar_rows(const int mx[][MAX_NM], int m, int n) {
    // Маска присутності значень першого рядка (індекс = значення елемента)
    bool row0_set[MAX_VAL];
    memset(row0_set, 0, sizeof(row0_set));
    for (int j = 0; j < n; j++)
        row0_set[mx[0][j]] = true;

    int count = 0;
    for (int i = 1; i < m; i++) {  // порівнюємо рядки з 2-го по M-й
        // Маска присутності значень i-го рядка
        bool row_set[MAX_VAL];
        memset(row_set, 0, sizeof(row_set));
        for (int j = 0; j < n; j++)
            row_set[mx[i][j]] = true;

        // Порівнюємо дві маски поелементно
        bool similar = true;
        for (int v = 0; v < MAX_VAL; v++) {
            if (row0_set[v] != row_set[v]) {
                similar = false;
                break;
            }
        }
        if (similar) count++;
    }
    return count;
}

// Дописати результат у той самий файл матриці
void append_result(const string& filename, int similar_count) {
    ofstream fout(filename, ios::app); // режим app = дописування в кінець
    if (!fout.is_open())
        throw runtime_error("Не вдалося відкрити файл для дописування: " + filename);

    fout << "\nКількість рядків, схожих на перший: " << similar_count << "\n";
    fout.close();
}
