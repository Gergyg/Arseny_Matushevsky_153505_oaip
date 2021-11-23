#include <iostream>
#include <locale>
double check_in();
int diag(int** b, int x, int y, int*& c);
int compos(int* c, int r);
int main() {
	setlocale(LC_ALL, "Russian");
    int n, k;
    std::cout << "Данная программа создает массив из четных элементов главной диагонали матрицы размерностью n на k.\nВведите n и k (Натуральные числа, не превосходящие 1000): ";
    do {
        n = check_in();
        if (n <= 0 || n>1000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (n <= 0 || n>1000);
    do {
        k = check_in();
        if (k <= 0 || k>1000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (k <= 0 || k>1000);

    int** A = new int*[n];
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

    int* g = new int[n>k?n:k];

    int size = diag(A, n, k, g);
    int composition = compos(g, size);
    if (size > 0) {
        std::cout << "Полученный динамический массив:\n";
        for (int i = 0; i < size; i++) {
            std::cout << g[i] << " ";
        }
        std::cout << "\nПроизведение его элементов равно " << composition;
    }
    else {
        std::cout << "На главной диагонали матрицы нет четных элементов.";
    }
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
    delete[] g;
}

int compos(int* c, int r) {
    int res = 1;
    for (int i = 0; i < r; i++) {
        res *= c[i];
    }
    return res;
}
int diag(int** b,int x,int y, int*& c) {
    int razm = 0;
    for (int i = 0; i < (x<y?x:y); i++) {
        if (b[i][i] % 2 == 0) c[razm++] = b[i][i];
    }
    return razm;
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