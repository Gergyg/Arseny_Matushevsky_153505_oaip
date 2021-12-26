#include <iostream>
#include <locale>
double check_in();
int solve(int** a, int x, int y, int*& c);


int main() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    std::cout << "������ ��������� ������� ������ �� �������� ��������� ������ �������� ������� ������������ n �� k.\n������� n � k (����������� �����, �� ������������� 1000): ";
    do {
        n = check_in();
        if (n <= 0 || n > 1000)
            std::cout << "������������ ����, ��������� �������:\n";
    } while (n <= 0 || n > 1000);
    do {
        k = check_in();
        if (k <= 0 || k > 1000)
            std::cout << "������������ ����, ��������� �������:\n";
    } while (k <= 0 || k > 1000);

    int** A = new int* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[k];
    }

    std::cout << "������� �������� ������� (����� ����� ����� -1000 � 1000): ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            do {
                A[i][j] = check_in();
                if (A[i][j] < -1000 || A[i][j]>1000)
                    std::cout << "������������ ����, ��������� �������:\n";
            } while (A[i][j] < -1000 || A[i][j]>1000);
        }
    }

    int* g = new int[n * k];
    int size = solve(A, n, k, g);

    if (size == 0) {
        std::cout << "\n���������� ������ ����.\n";
    }
    else {
        int sum = 0;
        std::cout << "\n���������� ������: ";
        for (int i = 0; i < size; i++) {
            std::cout << g[i] << " ";
            sum += g[i];
        }
        std::cout << "\n������� �������������� ��� ���������: " << (double)sum / size<<'\n';
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
            std::cout << "������������ ����, ��������� �������:\n";
        }
        else {
            return t;
        }
    }
}
