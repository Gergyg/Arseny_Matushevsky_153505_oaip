#include <iostream>
#include <locale>
#include "..\Static Lib\Header.h"
double check_in();
int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    std::cout << "Данная программа вычисляет мат. ожидание и дисперсию массива с количеством элементов n.\nВведите n (натуральное число, не превосходящее 10000): ";
    do {
        n = check_in();
        if (n < 1 || n>10000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (n < 1 || n>10000);
    double* a = new double[n];
    arr_fill(a,n);
    std::cout << "Массив:\n";
    for (int i = 1; i <= n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
    std::cout << "Математическое ожидание: " << expected_value(a, n);
    std::cout << "\nДиспенсия: " << Dispertion(a, n, expected_value(a, n));
}


double check_in() {
    while (true) {
        double t;
        std::cin >> t;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "Некорректный ввод, повторите попытку:\n";
        }
        else {
            std::cin.ignore(32768, '\n');
            return t;
        }
    }
}