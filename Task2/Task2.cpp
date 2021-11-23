#include <iostream>
#include <Windows.h>
#include <locale>
double check_in();
int main()
{
    setlocale(LC_ALL, "Russian");
	HINSTANCE load;
	load = LoadLibrary(L"Dynamic Lib.dll");
	typedef int (*count) (double*, int, int);
	count Count;
	Count = (count)GetProcAddress(load, "Count");
	double X[1001];
	int n;
	std::cout << "Для заданного одномерного массива X из N элементов программа находит количество элементов массива, для которых выполняется условие sin(Xi) / 2 < 0\nВведите количество элементов (натуральное число, не превосходящее 1000): ";
    do {
        n = check_in();
        if (n < 1 || n>1000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (n < 1 || n>1000);
    std::cout << "Введите элементы массива(значения от -1000 до 1000):\n";
    for (int i = 1; i <= n; i++) {
        do {
            X[i] = check_in();
            if (X[i] < -1000 || X[i]>1000)
                std::cout << "Некорректный ввод, повторите попытку:\n";
        } while (X[i] < -1000 || X[i]>1000);
    }
    std::cout << Count(X, 1, n);
	FreeLibrary(load);
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