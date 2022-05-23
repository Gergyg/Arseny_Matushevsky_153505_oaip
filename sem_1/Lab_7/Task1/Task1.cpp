#include <iostream>
#include <string>
//void sum(short x[1000], short y[1000]);
std::string sole(long long n);
int main()
{
    
    char a[1000];
    bool flag = true, ms = false;
    int i;
    std::cout << "Input the number in 11th: ";
    do {
        flag = true;
        ms = false;
        int p;
        
        std::cin >> a;
        if (a[0] == '-') {
            ms = true;
            p = 1;
        }
        else {
            p = 0;
        }
        for (i = p; a[i]; i++) {
            int k = (int)a[i];
            if ((k <= 57 && k >= 48) || k == 65) {
                ;
            }
            else {
                std::cout << "Error, try again\n";
                flag = false;
                break;
            }
        }
        if (i >= 19) {
            std::cout << "The number is too large, please enter a smaller one\n";
            flag = false;
        }
    } while (!flag);
    std::cout << a;
    long long sum = 0;
    for (int j = ms?1:0; j < i; j++) {
        long long el = 1;
        for (int o = 0; o < i - j - 1; o++) {
            el *= 11;
        }
        int k = (int)a[j] == 65 ? 10 : (int)a[j] - 48;
        sum += k * el;
    }
    std::string res;
    res = sole(sum);
    if (ms) res = '-' + res;
    std::cout << "\nIn 7th:\n" << res;
}

/*void sum(short(&x)[1000], short y[1000]) {
    for (int i = 0; i < 1000; i++) {
        x[i] = x[i] + y[i];
    }
    for (int i = 0; i < 1000; i++) {
        if (x[i] >= 10) {
            int temx = x[i] / 10;
            x[i] = x[i] % 10;
            x[i+1] += temx;
        }
    }

}*/

std::string sole(long long n) {
    std::string result = "";
    if (n == 0) return "0";
    while (n > 0) {
        result = char(n % 7 + '0') + result;
        n /= 7;
    }
    return result;
}