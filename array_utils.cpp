// array_utils.cpp
// Визначення функцій для роботи з одновимірними масивами (завдання 1, 3)

#include "array_utils.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Зчитати масив дійсних чисел з файлу
void get_mas(const string& filename, double in_mas[], int& in_n) {
    ifstream fin(filename);
    if (!fin.is_open())
        throw runtime_error("Не вдалося відкрити файл: " + filename);

    // Зчитуємо кількість елементів
    fin >> in_n;
    if (!fin || in_n < 2 || in_n > MAX_N)
        throw runtime_error("Некоректний розмір масиву (має бути 2.." +
                            to_string(MAX_N) + ")");

    // Зчитуємо елементи
    for (int i = 0; i < in_n; i++) {
        fin >> in_mas[i];
        if (!fin)
            throw runtime_error("Помилка читання елемента " + to_string(i + 1));
    }
    fin.close();
}

// Записати масив дійсних чисел у файл
void show_mas(const string& filename, const double out_mas[], int n) {
    ofstream fout(filename);
    if (!fout.is_open())
        throw runtime_error("Не вдалося відкрити файл для запису: " + filename);

    // Перший рядок — кількість елементів
    fout << n << "\n";
    // Другий рядок — елементи через пробіл
    fout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        fout << out_mas[i];
        if (i < n - 1) fout << " ";
    }
    fout << "\n";
    fout.close();
}

// Вивести масив у консоль
void print_mas(const double mas[], int n) {
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << mas[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}

// Array84: циклічний зсув вліво на 1 позицію
// Зберігаємо перший елемент, зсуваємо решту вліво, ставимо збережений в кінець
void cyclic_left_shift(double mas[], int n) {
    double first = mas[0];            // зберегти перший елемент
    for (int i = 0; i < n - 1; i++)  // кожен елемент замінюємо наступним
        mas[i] = mas[i + 1];
    mas[n - 1] = first;              // перший елемент іде в кінець
}

// Шейкерне сортування за спаданням
// Прохід зліва направо: менший елемент «тоне» вправо
// Прохід справа наліво: більший елемент «спливає» вліво
void shaker_sort_desc(double mas[], int n) {
    int left  = 0;       // ліва межа невідсортованої частини
    int right = n - 1;   // права межа невідсортованої частини
    bool swapped;

    do {
        swapped = false;

        // --- Прохід зліва направо ---
        // Якщо поточний елемент менший за наступний — міняємо місцями
        for (int i = left; i < right; i++) {
            if (mas[i] < mas[i + 1]) {
                double tmp  = mas[i];
                mas[i]      = mas[i + 1];
                mas[i + 1]  = tmp;
                swapped = true;
            }
        }
        right--; // після проходу найменший елемент стоїть на right+1 — виключаємо

        if (!swapped) break; // якщо жодної перестановки — масив вже впорядкований

        // --- Прохід справа наліво ---
        // Якщо поточний елемент більший за попередній — міняємо місцями
        for (int i = right; i > left; i--) {
            if (mas[i] > mas[i - 1]) {
                double tmp  = mas[i];
                mas[i]      = mas[i - 1];
                mas[i - 1]  = tmp;
                swapped = true;
            }
        }
        left++; // після проходу найбільший елемент стоїть на left-1 — виключаємо

    } while (swapped);
}
