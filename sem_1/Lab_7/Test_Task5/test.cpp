#include "pch.h"
#include <iostream>
TEST(TestCaseName, TestName) {
    char minuses[1000];
    char result[1000];
    char a[1000]="9999999";
    int k = 0;
    int i = 7;
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
    std::string x = result;
    EXPECT_EQ(x , "MXCMXCMXCMXCIX");
    x = minuses;
    EXPECT_EQ(x, "_=____ _      ");
  EXPECT_TRUE(true);
}