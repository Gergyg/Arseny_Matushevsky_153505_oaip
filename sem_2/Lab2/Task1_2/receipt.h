#ifndef RECEIPT_H
#define RECEIPT_H
#include <string>
using namespace std;
class Receipt
{
public:
    Receipt(string s1, string s2, string s3, string s4);
    Receipt();
    string group, mark, date, ready;
    int next = -1;
    int previos = -1;
    string toSort();
};

#endif // RECEIPT_H
