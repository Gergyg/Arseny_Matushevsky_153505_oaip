#include <iostream>
#include <locale>
double check_in();
void ifzero(double** a,int x, int y);
void permutation(double**& a, int x, int y);
int main() {
    setlocale(LC_ALL, "Russian");
    int n, k;
    std::cout << "������ ��������� ���� ���� � ������� ������������ n �� k � ������������ �� �������� � �������� �������.\n������� n � k (����������� �����, �� ������������� 1000): ";
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

    double** A = new double* [n];
    for (int i = 0; i < n; i++) {
        A[i] = new double[k];
    }

    std::cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            do {
                A[i][j] = check_in();
                if (A[i][j] < -1000 || A[i][j]>1000)
                    std::cout << "������������ ����, ��������� �������:\n";
            } while (A[i][j] < -1000 || A[i][j]>1000);
        }
    }
    ifzero(A,n,k);
    permutation(A, n, k);
    std::cout << "\n������������ ������:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << A[i][j] << " ";
        }
        std::cout << '\n';
    }
    for (int i = 0; i < n; i++) {
        delete[] A[i];
    }
}
void permutation(double**& a, int x, int y) {
    int flag = (x * y + 1) / 2;
    int kol = 0;
    for (int i = 0; i < x && kol < flag; i++) {
        for (int j = 0; j < y && kol < flag; j++) {
            kol++;
            double t = a[i][j];
            a[i][j] = a[x - i - 1][y - j - 1];
            a[x - i - 1][y - j - 1] = t;
        }
    }
}
void ifzero(double** a, int x, int y) {
    int numberOfZero = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (a[i][j] == 0) numberOfZero++;
        }
    }
    if (numberOfZero == 0) {
        std::cout << "\n� ������� ��� ������� ���������.\n";
        return;
    }
    else {
        std::cout << "\n����� ���������� ������� ���������: "<<numberOfZero<<", �� ������� : \n";
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (a[i][j] == 0) std::cout<<i<<" "<<j<<'\n';
            }
        }
    }
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