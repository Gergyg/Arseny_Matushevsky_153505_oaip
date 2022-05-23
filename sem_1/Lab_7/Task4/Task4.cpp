#include <iostream>
void summ(short l[1000], short m[1000]);
void razn(short l[1000], short m[1000]);
void isms(short l[1000], short m[1000]);
bool msms2 = false;
int main()
{
   
    char a[1000];
    bool flag = true, ms = false, ms2 = false;
    int i;
    int sum1 = 0,sum2=0;
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
                sum1++;
            }
            else {
                std::cout << "Error, try again\n";
                flag = false;
                sum1 = 0;
                break;
            }
        }
        
    } while (!flag);
    short c[1000] = {};
    int t = ms ? 1 : 0;
    int ss = 0;
    for (int i = sum1-1+t ; i >= t; i--) {
        if (a[i] == 'A') c[ss++] = 10;
        else c[ss++] = int(a[i]) - 48;
    }
    std::cout << "Input the second number in 11th: ";
    do {
        flag = true;
        ms2 = false;
        int p;

        std::cin >> a;
        if (a[0] == '-') {
            ms2 = true;
            p = 1;
        }
        else {
            p = 0;
        }
        for (i = p; a[i]; i++) {
            int k = (int)a[i];
            if ((k <= 57 && k >= 48) || k == 65) {
                sum2++;
            }
            else {
                std::cout << "Error, try again\n";
                flag = false;
                sum2 = 0;
                break;
            }
        }

    } while (!flag);
    short d[1000] = {};
    t = ms2 ? 1 : 0;
    ss = 0;
    for (int i = sum2-1+t ; i >= t; i--) {
        if (a[i] == 'A') d[ss++] = 10;
        else d[ss++] = int(a[i]) - 48;
    }
    isms(c, d);
    if (ms && ms2) {
        std::cout << "\nSum:\n";
        std::cout << '-';
        summ(c, d);
        std::cout << "\nRazn:\n";
        if (!msms2) std::cout << '-';
        razn(c, d);
    }
    if (ms && !ms2) {
        std::cout << "\nSum:\n";
        if (!msms2) std::cout << '-';
        razn(c, d);
        std::cout << "\nRazn\n";
        std::cout << '-';
        summ(c, d);
    }
    if (!ms && ms2) {
        std::cout << "\nSum:\n";
        if (msms2) std::cout << '-';
        razn(c, d);
        std::cout << "\nRazn\n";
        summ(c, d);
    }
    if (!ms && !ms2) {
        std::cout << "\nSum:\n";
        summ(c, d);
        std::cout << "\nRazn\n";
        if (msms2) std::cout << '-';
        razn(c, d);
    }

}

void summ(short l[1000], short m[1000]) {
    short x[1000], y[1000];
    for (int i = 0; i < 1000; i++) {
        x[i] = l[i];
        y[i] = m[i];
    }
    for (int i = 0; i < 1000; i++) {
        x[i] = x[i] + y[i];
        
    }
    for (int i = 0; i < 1000; i++) {
        if (x[i] >= 11) {
            int temx = x[i] / 11;
            x[i] = x[i] % 11;
            x[i + 1] += temx;
        }
    }
    bool f = true;
    for (int i = 999; i >= 0; i--) {
        if (!(x[i] == 0 && f)) {
            f = false;
            if (x[i] == 10)
                std::cout << "A";
            else
                std::cout << x[i];
        }
        else {
            if (i == 0) std::cout << "0";
        }
    }

}
void razn(short l[1000], short m[1000]) {
    short x[1001], y[1000];
    for (int i = 0; i < 1000; i++) {
        x[i] = l[i];
        y[i] = m[i];
    }
    for (int i = 0; i < 1000; i++) {
        x[i] = x[i] - y[i];
    }
    for (int i = 0; i < 999; i++) {
        if (x[i] < 0) {
            x[i] = x[i] + 11;
            x[i + 1] -= 1;
        }
    }
    if (x[999] < 0) {
        razn(m,l);
    }
    else {
        bool f = true;
        for (int i = 999; i >= 0; i--) {
            if (!(x[i] == 0 && f)) {
                f = false;
                if (x[i] == 10)
                    std::cout << "A";
                else 
                    std::cout << x[i];
            }
            else {
                if (i == 0) std::cout << "0";
            }
        }
    }
}

void isms(short l[1000], short m[1000]) {
    short x[1001], y[1000];
    for (int i = 0; i < 1000; i++) {
        x[i] = l[i];
        y[i] = m[i];
    }
    for (int i = 0; i < 1000; i++) {
        x[i] = x[i] - y[i];
    }
    for (int i = 0; i < 999; i++) {
        if (x[i] < 0) {
            x[i] = x[i] + 11;
            x[i + 1] -= 1;
        }
    }
    if (x[999] < 0) {
        msms2 = true;
    }
}
