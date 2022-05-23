#ifndef RECEIPTLIST_H
#define RECEIPTLIST_H
#include "receipt.h"

class ReceiptList
{
public:
    int size;
    int head = -1;
    int tail = -1;
    ReceiptList* recArr;
    ReceiptList(int size);
    void Add(Receipt* item);
    void Remove(int index);
};

#endif // RECEIPTLIST_H
