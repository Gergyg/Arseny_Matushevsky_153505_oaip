#include <iostream>
#include <locale>
double check_in();
void solve(int x, int y);
int F(int n);
int main()
{
	setlocale(LC_ALL, "Russian");
	int p, q;
    do {
        p = check_in();
        q = check_in();
        if (p >= 0 && q >= 0) 
            solve(p, q);
        
    } while (p >= 0 && q >= 0);
}

void solve(int x, int y) {
    int result=0;
    for (int i = x; i <= y; i++)
        result += F(i);
    std::cout << result << '\n';
}
int F(int n) {
    if (n % 10 > 0)
        return n % 10;
    if (n == 0)
        return 0;
    return F(n / 10);
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