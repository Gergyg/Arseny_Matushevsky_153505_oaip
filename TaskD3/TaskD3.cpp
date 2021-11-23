#include <iostream>
#include <locale>
double check_in();
void solve(long long n);
long long f(long long n);
int main()
{
    long long n;
    do {
        n = check_in();
        if (n <= 0 || n > 1000000000)
            std::cout << "Некорректный ввод, повторите попытку:\n";
    } while (n <= 0 || n > 1000000000);
    solve(n);
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
void solve(long long n) {
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += f(i);
    }
    std::cout << sum << '\n';
}
long long f(long long n) {
    if (n % 2 == 1) return n;
    return f(n / 2);
}