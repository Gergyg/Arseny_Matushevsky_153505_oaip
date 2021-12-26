#include <stdio.h>
#include <iostream>
#include <stdint.h>
int subtract(unsigned int x, unsigned int y) {
    while (y) {
        unsigned int borrow = (~x) & y;

        x = x ^ y;

        y = borrow << 1;
    }
    return x;
}

unsigned int inc(unsigned int i) {
    unsigned int mask = 1;
    while (i & mask) {
        i &= ~mask;
        mask <<= 1;
    }
    i |= mask;
    return i;
}

unsigned int divide(unsigned int n, unsigned int d) {
    unsigned int q = 0;

     while (n >= d) {
        unsigned int i = 0, d_t = d;

        while (n >= (d_t << 1)) {
            i = inc(i);
            d_t <<= 1;
        }

        q |= 1 << i;

        n = subtract(n, d_t);
    }
    return q;
}

int add(unsigned int x, unsigned int y) {
    while (y) {
        unsigned int carry = x & y;

        x = x ^ y;

        y = carry << 1;
    }
    return x;
}

unsigned int multiply(unsigned int a, unsigned int b) {
    unsigned int result = 0;
    while (b) 
    {
        if (b & 01) 
        {
            result = add(result, a); 
        }
        a <<= 1; 
        b >>= 1; 
    }
    return result;
}

unsigned int mod(unsigned int a, unsigned int b) {
    unsigned int r = divide(a, b); 
    return subtract(a, multiply(r, b));
}

unsigned int check_in() {
    while (true) {
        unsigned int t;
        std::cin >> t;
        if (std::cin.fail()||t==0) {
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
int main() {
    unsigned int n;
    std::cout << "Input the number n (0<n<1e9): ";
    n = check_in();

    if (mod(n, 3) == 0) std::cout << "n is a multiple of 3\n";
    else std::cout << "n is not a multiple of 3\n";

    if (mod(n, 61) == 0) std::cout << "n is a multiple of 61\n";
    else std::cout << "n is not a multiple of 61\n";

    if (mod(n, 131) == 0) std::cout << "n is a multiple of 131\n";
    else std::cout << "n is not a multiple of 131\n";

    return 0;
}