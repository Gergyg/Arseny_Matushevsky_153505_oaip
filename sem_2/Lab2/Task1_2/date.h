#ifndef DATE_H
#define DATE_H
#include <string>

class Date
{
    int day,month,year;
public:
    Date(std::string s);
    bool IsLeap();
    bool validCheck();


};

#endif // DATE_H
