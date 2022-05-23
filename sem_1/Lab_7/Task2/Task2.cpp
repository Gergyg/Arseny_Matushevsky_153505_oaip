#include <iostream>
#include <string>
std::string sole(long long n);
long long check_in();
int main()
{
    bool ms = false;
    std::cout << "Enter a number in natural form: ";
    long long n;
    n = check_in();
    if (n < 0) {
        ms = true;
        n *= -1;
    }
    std::cout << "Direct number code:\n";
    std::string res = sole(n);
    std::cout << ms ? '1' : '0';
    for (int i = 0; i <= 63; i++) {
        if (i % 4 == 3) std::cout << " ";
        std::cout << res[i];
    }
}

long long check_in() {
    while (true) {
        long long t;
        std::cin >> t;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "\nError, try again.\n";
        }
        else {
            std::cin.ignore(32768, '\n');
            return t;
        }
    }
}

std::string sole(long long n) {
    int dlin = 0;
    std::string result = "";
    if (n == 0) {
        result = "0";
        dlin = 1;
    }
    while (n > 0) {

            
        dlin++; 
        result = char(n % 2 + '0') + result;
        
        n /= 2;
    }
    for (int k = 0; k < 63 - dlin; k++)
        result = '0' + result;
    return result;
}