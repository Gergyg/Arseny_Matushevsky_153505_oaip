#include <iostream>
#include <locale>
double check_in();
int solve(int** a, int x, int y, int*& c);


int main() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    std::cout << "Данная программа создает массив из нечетных элементов четных столбцов матрицы размерностью n на k.\nВведите n и k (Натуральные числа, не превосходящие 1000): ";
    do {
        n = check_in();
        if (n <= 0 || n > 1000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (n <= 0 || n > 1000);
    do {
        k = check_in();
        if (k <= 0 || k > 1000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (k <= 0 || k > 1000);

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[k];
    }

    std::cout << "Введите элементы матрицы (Целые числа между -1000 и 1000): ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            do {
                A[i][j] = check_in();
                if (A[i][j] < -1000 || A[i][j]>1000)
                    std::cout << "Некорректный ввод, повторите попытку:\n";
            } while (A[i][j] < -1000 || A[i][j]>1000);
        }
    }

    int* g = new int[n * k];
    int size = solve(A, n, k, g);

    if (size == 0) {
        std::cout << "\nПолученный массив пуст.\n";
    }
    else {
        int sum = 0;
        std::cout << "\nПолученный массив: ";
        for (int i = 0; i < size; i++) {
            std::cout << g[i] << " ";
            sum += g[i];
        }
        std::cout << "\nСреднее арифметическое его элементов: " << (double)sum / size<<'\n';
    }

    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] g;
}


int solve(int** a, int x, int y, int*& c) {
    int size = 0;
    for (int j = 1; j < y; j += 2) {
        for (int i = 0; i < x; i++) {
            if (a[i][j] % 2 == 1) {
                c[size] = a[i][j];
                size++;
            }
        }
    }
    return size;
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
            return t;
        }
    }
}
