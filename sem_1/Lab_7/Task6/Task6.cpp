#include <iostream>
unsigned unsigned long long check_ull();
unsigned int check_uint();
int main()
{
    unsigned int t;
    unsigned long long n;
    std::cout << "Number of tests: ";
    t = check_uint();
    std::cout << "Enter the numbers: ";
    while (t--) {
        n = check_ull();
        std::cout << "Answer: " << ((n % 10 == 9) ? (n / 10 + 1) : (n / 10))<<'\n';
    }
}

unsigned long long check_ull() {
    while (true) {
        unsigned long long t;
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

unsigned int check_uint() {
    while (true) {
        unsigned int t;
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