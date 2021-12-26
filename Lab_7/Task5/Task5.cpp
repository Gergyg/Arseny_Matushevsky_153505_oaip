#include <iostream>

int main()
{
    char minuses[1000];
    char result[1000];
    char a[1000];
    bool flag = true;
    int i;
    std::cout << "Input the number(1 - 9 999 999): ";
    do {
        flag = true;
        

        std::cin >> a;
        if (a[0] == '0') {
            std::cout << "Error, try again\n";
            flag = false;
            break;
        }

        for (i = 0; a[i]; i++) {

            int k = (int)a[i];     
            if (!(k <= 57 && k >= 48)) {
                std::cout << "Error, try again\n";
                flag = false;
                break;
            }
        }
        if (i > 7) {
            std::cout << "The number is too large, please enter a smaller one\n";
            flag = false;
        }
    } while (!flag);

    int k = 0;
    for (int j = 0; j < i; j++) {
        if (i - j == 7) {
            if (a[j] == '1') {
                result[k] = 'M';
                minuses[k++] = '_';
            }
            if (a[j] == '2') {
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
            }
            if (a[j] == '3') {
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
            }
            if (a[j] == '4') {
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'V';
                minuses[k++] = '=';
            }
            if (a[j] == '5') {
                result[k] = 'V';
                minuses[k++] = '=';
            }
            if (a[j] == '6') {
                result[k] = 'V';
                minuses[k++] = '=';
                result[k] = 'M';
                minuses[k++] = '_';
            }
            if (a[j] == '7') {
                result[k] = 'V';
                minuses[k++] = '=';
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
            }
            if (a[j] == '8') {
                result[k] = 'V';
                minuses[k++] = '=';
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
            }
            if (a[j] == '9') {
                result[k] = 'M';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '=';
            }
        }
        if (i - j == 6) {
            if (a[j] == '1') {
                result[k] = 'C';
                minuses[k++] = '_';
            }
            if (a[j] == '2') {
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
            }
            if (a[j] == '3') {
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
            }
            if (a[j] == '4') {
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'D';
                minuses[k++] = '_';
            }
            if (a[j] == '5') {
                result[k] = 'D';
                minuses[k++] = '_';
            }
            if (a[j] == '6') {
                result[k] = 'D';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
            }
            if (a[j] == '7') {
                result[k] = 'D';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
            }
            if (a[j] == '8') {
                result[k] = 'D';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
            }
            if (a[j] == '9') {
                result[k] = 'C';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = '_';
            }
        }
        if (i - j == 5) {
            if (a[j] == '1') {
                result[k] = 'X';
                minuses[k++] = '_';
            }
            if (a[j] == '2') {
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
            }
            if (a[j] == '3') {
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
            }
            if (a[j] == '4') {
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'L';
                minuses[k++] = '_';
            }
            if (a[j] == '5') {
                result[k] = 'L';
                minuses[k++] = '_';
            }
            if (a[j] == '6') {
                result[k] = 'L';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
            }
            if (a[j] == '7') {
                result[k] = 'L';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
            }
            if (a[j] == '8') {
                result[k] = 'L';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'X';
                minuses[k++] = '_';
            }
            if (a[j] == '9') {
                result[k] = 'X';
                minuses[k++] = '_';
                result[k] = 'C';
                minuses[k++] = '_';
            }
        }
        if (i - j == 4) {
            if (a[j] == '1') {
                result[k] = 'M';
                minuses[k++] = ' ';
            }
            if (a[j] == '2') {
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
            }
            if (a[j] == '3') {
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
            }
            if (a[j] == '4') {
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'V';
                minuses[k++] = '_';
            }
            if (a[j] == '5') {
                result[k] = 'V';
                minuses[k++] = '_';
            }
            if (a[j] == '6') {
                result[k] = 'V';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = ' ';
            }
            if (a[j] == '7') {
                result[k] = 'V';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
            }
            if (a[j] == '8') {
                result[k] = 'V';
                minuses[k++] = '_';
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
            }
            if (a[j] == '9') {
                result[k] = 'M';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = '_';
            }
        }
        if (i - j == 3) {
            if (a[j] == '1') {
                result[k] = 'C';
                minuses[k++] = ' ';
            }
            if (a[j] == '2') {
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
            }
            if (a[j] == '3') {
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
            }
            if (a[j] == '4') {
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'D';
                minuses[k++] = ' ';
            }
            if (a[j] == '5') {
                result[k] = 'D';
                minuses[k++] = ' ';
            }
            if (a[j] == '6') {
                result[k] = 'D';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
            }
            if (a[j] == '7') {
                result[k] = 'D';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
            }
            if (a[j] == '8') {
                result[k] = 'D';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
            }
            if (a[j] == '9') {
                result[k] = 'C';
                minuses[k++] = ' ';
                result[k] = 'M';
                minuses[k++] = ' ';
            }
        }
        if (i - j == 2) {
            if (a[j] == '1') {
                result[k] = 'X';
                minuses[k++] = ' ';
            }
            if (a[j] == '2') {
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
            }
            if (a[j] == '3') {
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
            }
            if (a[j] == '4') {
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'L';
                minuses[k++] = ' ';
            }
            if (a[j] == '5') {
                result[k] = 'L';
                minuses[k++] = ' ';
            }
            if (a[j] == '6') {
                result[k] = 'L';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
            }
            if (a[j] == '7') {
                result[k] = 'L';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
            }
            if (a[j] == '8') {
                result[k] = 'L';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
            }
            if (a[j] == '9') {
                result[k] = 'X';
                minuses[k++] = ' ';
                result[k] = 'C';
                minuses[k++] = ' ';
            }
        }
        if (i - j == 1) {
            if (a[j] == '1') {
                result[k] = 'I';
                minuses[k++] = ' ';
            }
            if (a[j] == '2') {
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
            }
            if (a[j] == '3') {
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
            }
            if (a[j] == '4') {
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'V';
                minuses[k++] = ' ';
            }
            if (a[j] == '5') {
                result[k] = 'V';
                minuses[k++] = ' ';
            }
            if (a[j] == '6') {
                result[k] = 'V';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
            }
            if (a[j] == '7') {
                result[k] = 'V';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
            }
            if (a[j] == '8') {
                result[k] = 'V';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'I';
                minuses[k++] = ' ';
            }
            if (a[j] == '9') {
                result[k] = 'I';
                minuses[k++] = ' ';
                result[k] = 'X';
                minuses[k++] = ' ';
            }
        }
    }
    result[k] = '\0';
    minuses[k] = '\0';
    std::cout << "Result: \n"<<minuses << '\n' << result;
}