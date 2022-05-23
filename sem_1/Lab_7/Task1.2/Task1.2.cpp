#include <iostream>
int ss = 7;
bool flag = true;
long long eleven  = 1;
char znak = '+';
long long c = 0;
int kol = 0;
void fun(int num1)    // рекурсивная функция перевода (вывода на экран) в новую с/с
{                    // целой части исходного десятичного числа 
    int i;
    if (num1 >= ss)
    {
        i = num1 % ss;      // получаем остаток от деления на основание
        num1 /= ss;       // получаем целую часть от деления
        fun(num1);       // рекурсивный вызов функции fun
        std::cout << char(i + '0');
    }
    else std::cout << znak << char(num1 % ss + '0');
}
void vten() {
    char s;
    while (flag) {
        s = getchar();
        if (s == '-') {
            if (c != 0) {
                std::cout << "\nError, try again.\n";
                exit(0);
            }
            znak = '-';
            continue;
        }
        if (s == '\n') {
            flag = false;
            return;
        }
        else {
            int k = (int)s;
            if ((k <= 57 && k >= 48) || k == 65) {
                if (s == 'A') {
                    vten();
                    c += eleven * 10;
                    eleven *= 11;
                }
                else {
                    vten();
                    c += eleven * (int(s) - 48);
                    eleven *= 11;
                }
                kol++;
                if (kol >= 19) {
                    std::cout << "The number is too large, please enter a smaller one.\n";
                    exit(0);
                }
            }
            else {
                std::cout << "\nError, try again.\n";
                exit(0);
            }
        }
    }
}
int main()
{
    std::cout << "Input the number in 11th: ";
    vten();
    std::cout << "\nIn 7th:\n";
    fun(c);
}