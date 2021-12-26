#include <iostream>
#include <string>
std::string sole(long long n);
long long check_in();
int main() {

    bool ms=false,ms2 = false;

    long long n, n2;
    n = check_in();
    n2 = check_in();
    if (n < 0) {
        ms = true;
        n *= -1;
    } 
    if (n2 < 0) {
        ms2 = true;
        n2 *= -1;
    }

    std::string res = sole(n);
   
    res = (ms ? '1' : '0') + res;
    for (int i = 0; i <= 63; i++) {
       
        std::cout << res[i];
        if (i % 4 == 3) std::cout << " ";
    }
    std::cout << '\n';

    std::string res2 = sole(n2);
    
    res2 = (ms2 ? '1' : '0') + res2;
    for (int i = 0; i <= 63; i++) {

        std::cout << res2[i];
        if (i % 4 == 3) std::cout << " ";
    }

    std::cout << '\n';

    if (ms) {
        for (int i = 1; i <= 63; i++) {
            if (res[i] == '1') res[i] = '0';
            else res[i] = '1';
        }
    }

    if (ms2) {
        for (int i = 1; i <= 63; i++) {
            if (res2[i] == '1') res2[i] = '0';
            else res2[i] = '1';
        }
    }

    std::cout << "Ones' complement:\n";

    for (int i = 0; i <= 63; i++) {

        std::cout << res[i];
        if (i % 4 == 3) std::cout << " ";
    }
    std::cout << '\n';
    for (int i = 0; i <= 63; i++) {

        std::cout << res2[i];
        if (i % 4 == 3) std::cout << " ";
    }

    std::cout << '\n';
    int carry = 0;
    for (int i = 63; i >= 0; i--) {

        int g = int(res[i]) - 48;
        int h = int(res2[i]) - 48;
        g = g + h + carry;

        if (g == 3) {
            carry = 1;
            res[i] = '1';
        }
        if (g == 2) {
            carry = 1;
            res[i] = '0';
        }
        if (g == 1) {
            carry = 0;
            res[i] = '1';
        }
        if (g == 0) {
            carry = 0;
            res[i] = '0';
        }
    }

    if (carry == 1) {
        for (int i = 63; i >= 0; i--) {
            if (res[i] == '1') {
                res[i] = '0';
            }
            else {
                res[i] = '1';
                break;
            }
        }
    }

    if (res[0] == '1') {
        for (int i = 1; i <= 63; i++) {
            if (res[i] == '1') res[i] = '0';
            else res[i] = '1';
        }
    }
    std::cout << "Result:\n";

    for (int i = 0; i <= 63; i++) {

        std::cout << res[i];
        if (i % 4 == 3) std::cout << " ";
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