#include <iostream>
#include <locale>
double check_in();
int diag(int** b, int x, int y, int*& c);
int compos(int* c, int r);
int main() {
	setlocale(LC_ALL, "Russian");
    int n, k;
    std::cout << "������ ��������� ������� ������ �� ������ ��������� ������� ��������� ������� ������������ n �� k.\n������� n � k (����������� �����, �� ������������� 1000): ";
    do {
        n = check_in();
        if (n <= 0 || n>1000)
            std::cout << "������������ ����, ��������� �������:\n";
    } while (n <= 0 || n>1000);
    do {
        k = check_in();
        if (k <= 0 || k>1000)
            std::cout << "������������ ����, ��������� �������:\n";
    } while (k <= 0 || k>1000);

    int** A = new int*[n];
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

    int* g = new int[n>k?n:k];

    int size = diag(A, n, k, g);
    int composition = compos(g, size);
    if (size > 0) {
        std::cout << "���������� ������������ ������:\n";
        for (int i = 0; i < size; i++) {
            std::cout << g[i] << " ";
        }
        std::cout << "\n������������ ��� ��������� ����� " << composition;
    }
    else {
        std::cout << "�� ������� ��������� ������� ��� ������ ���������.";
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
            std::cout << "������������ ����, ��������� �������:\n";
        }
        else {
            return t;
        }
    }
}