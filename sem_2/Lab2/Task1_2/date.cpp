#include "date.h"
#include <string>







bool Date::IsLeap()
{
    if((this->year % 400 == 0) || (this->year % 100 != 0 && this->year % 4 == 0)){
        return true;
    }
    else {
        return false;
    }
}







bool Date::validCheck()
{
    if(this->month>12||this->month<1){
        return false;
    }
    if(this->year<0) {
        return false;
    }
    if(this->month==1||this->month==3||this->month==4||this->month==5||this->month==6||this->month==8||this->month==10||this->month==12){
        if(this->day>31||this->day<1){
            return false;
        }
    } else if(this->month==2) {
        if(IsLeap()) {
            if(this->day>29||this->day<1){
                return false;
            }
        } else {
            if(this->day>28||this->day<1){
                return false;
            }
        }

    } else{
        if(this->day>30||this->day<1){
            return false;
        }
    }
    return true;

}

Date::Date(std::string s) {
    this->day = int(s[0] - '0') * 10 + int(s[1] - '0');
    this->month = int(s[3] - '0') * 10 + int(s[4] - '0');
    this->year = int(s[6] - '0') * 1000 + int(s[7] - '0') * 100 + int(s[8] - '0') * 10 + int(s[9] - '0');
}
