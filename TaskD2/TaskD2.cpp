#include <iostream>
#include <locale>
double check_in();
unsigned long long solve(unsigned long long x, unsigned long long y, unsigned long long n);
int main()
{
    unsigned long long k, n, t, m ,cas=0;
    
    do {
        m = 1;
        k = check_in();
        n = check_in();
        do {
            t = check_in();
            if (n <= 0 || n >= 10)
                std::cout << "Некорректный ввод, повторите попытку:\n";
        } while (n <= 0 || n > 10); 
        if (k != 0 && n != 0 && t != 0) {
            for (int i = 0; i < t; i++) m *= 10;
            cas++;
            std::cout<<"Case #"<<cas<<": "<<solve(k % m, n, m)<<'\n';
            
        }


    } while (k != 0 && n != 0 && t != 0);
}
unsigned long long solve(unsigned long long x, unsigned long long y, unsigned long long n) {
    if (y == 0) return 1;
    if (y % 2 == 1) return (x * solve((x * x) % n, y / 2, n)) % n;
    return solve((x * x) % n, y / 2, n);
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