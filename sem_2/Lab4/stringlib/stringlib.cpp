#include "stringlib.h"

#include <iostream>

namespace spd
{
     //s2-s1
    void* Memcpy(void* s1, const void* s2, size_t n)
    {
        char* csrc = (char*)s2;
        char* cdest = (char*)s1;

        for (int i = 0; i < n; i++)
            cdest[i] = csrc[i];
        return s1;
    }

    void* Memmove(void* s1, const void* s2, size_t n)
    {
        char* csrc = (char*)s2;
        char* cdest = (char*)s1;

        char* temp = new char[n];

        for (int i = 0; i < n; i++)
            temp[i] = csrc[i];

        //std::cout << "temp " << temp << "\n";

        for (int i = 0; i < n; i++)
            cdest[i] = temp[i];

        delete[] temp;
        return s1;
    }

    size_t Strlen(const char* s)
    {
        size_t n = 0;
        while (s[n] != '\0')
            n++;
        return n;
    }

    char* Strcpy(char* s1, const char* s2)
    {
        return (char*)Memcpy(s1, s2, Strlen(s2) + 1);
    }

    char* Strncpy(char* s1, const char* s2, size_t n)
    {
        Memcpy(s1, s2, n < spd::Strlen(s2) ? n : spd::Strlen(s2));
        if (n > spd::Strlen(s2))
        {
            for (int i = Strlen(s2); i < n; i++)
                s1[i] = '\0';
        }
        else
        {
            s1[n] = '\0';
        }
        return s1;
    }

    char* Strcat(char* s1, const char* s2)
    {
        return (char*)Memcpy(&s1[Strlen(s1)], s2, Strlen(s2) + 1);
    }

    char* Strncat(char* s1, const char* s2, size_t n)
    {
        Memcpy(&s1[Strlen(s1)], s2, n < (Strlen(s2) + 1) ? n : Strlen(s2) + 1);
        if (n < Strlen(s2))
            s1[Strlen(s1) + n] = '\0';
        return s1;
    }

    int Memcmp(const void* s1, const void* s2, size_t n)
    {
        int i;
        unsigned char* S1 = (unsigned char*)s1;
        unsigned char* S2 = (unsigned char*)s2;

        for (i = 0; i < n; i++, S1++, S2++)
        {
            if (*S1 < *S2)
            {
                return -1;
            }
            else if (*S1 > *S2)
            {
                return 1;
            }
        }
        return 0;
    }

    int Strcmp(const char* s1, const char* s2)
    {
        return Memcmp(s1, s2, Strlen(s1) + 1);
    }

    int Strcoll(const char* s1, const char* s2)
    {
        //хуета
        return spd::Strcmp(s1, s2);
    }

    int Strncmp(const char* s1, const char* s2, size_t n)
    {
        return Memcmp(s1, s2, n);
    }

    size_t Strxfrm(char* s1, const char* s2, size_t n)
    {
        //хуета2
        return 0;
    }

    char* Strtok(char* s1, const char* s2)
    {
        static char* input = nullptr;

        if (s1 != nullptr)
            input = s1;

        if (input == nullptr)
            return nullptr;

        char* result = new char[Strlen(input) + 1];

        int i = 0;
        int j = 0;

        while (IsInArr(input[j],s2)) { j++; }        //skip all delimitering simbols

        if (input[j] == '\0')                   //if it is end of array return null pointer
        {
            delete[] result;
            return nullptr;
        }

        for (; input[j] != '\0'; j++,i++)
        {
            if (!IsInArr(input[j], s2))
                result[i] = input[j];

            else                                      // we walk on the loop while simbol is not delimitering
            {
                result[i] = '\0';
                input = input + j + 1;
                return result;
            }
        }

        result[i] = '\0';
        input = nullptr;

        return result;
    }

    void* Memset(void* s, int c, size_t n)
    {
        char* st = (char*)s;
        for (int i = 0; i < n; i++)
            st[i] = (char)c;
        return s;
    }

    char* strerror(int errnum)
    {
        return sys_errlist[errnum];

    }

    bool IsInArr(char s, const char* arr)
    {
        for (size_t i = 0; i < Strlen(arr); i++)
        {
            if (s == arr[i] && arr[i] != '\0')
                return true;
        }

        return false;
    }



}

using namespace spd;


    String::String()
    {
        lenght = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String::String(const char* ptr)
    {
        lenght = spd::Strlen(ptr);
        str = new char[lenght + 1];
        spd::Strcpy(str, ptr);
    }

    String::String(char* ptr)
    {
        lenght = spd::Strlen(ptr);
        str = new char[lenght + 1];
        spd::Strcpy(str, ptr);
    }

    String::String(const String& Str)
    {
        lenght = Str.lenght;
        str = new char[lenght + 1];
        spd::Strcpy(str, Str.str);
    }

    String::~String()
    {
        if(lenght != 0)
            delete[]str;
        lenght = 0;
        str = nullptr;
    }

    int String::Lenght() { return lenght; }

    String& String::operator=(const char* ptr)
    {
        delete[]str;
        lenght = spd::Strlen(ptr);
        str = new char[lenght + 1];
        spd::Strcpy(str, ptr);
        str[lenght] = '\0';
        return *this;
    }

    String& String::operator=(const String& st)
    {
        if (this == &st)
            return *this;
        delete[]str;
        lenght = st.lenght;
        str = new char[lenght + 1];
        spd::Strcpy(str, st.str);
        return *this;
    }

    char& String::operator[](int i)
    {
        return str[i];
    }

    bool String::operator==(const String& st)
    {
        return (spd::Strcmp(str, st.str) == 0);
    }

    bool String::operator==(const std::string& st)
    {
        return (spd::Strcmp(str, st.c_str()) == 0);
    }

    bool String::operator==(const char* st)
    {
        return (spd::Strcmp(str, st) == 0);
    }

    bool String::operator<(const String& st) const{
        return (spd::Strcmp(str, st.str)<0);
    }

    bool String::operator<(const std::string& st)
    {
        return (spd::Strcmp(str, st.c_str()) < 0);
    }

    bool String::operator<(const char* st)
    {
        return (spd::Strcmp(str, st) < 0);
    }

    bool String::operator>(const String& st){
        return (spd::Strcmp(str, st.str)>0);
    }

    bool String::operator>(const std::string& st)
    {
        return (spd::Strcmp(str, st.c_str()) > 0);
    }

    bool String::operator>(const char* st)
    {
        return (spd::Strcmp(str, st) > 0);
    }

    String String::operator+(String& st)
    {
        String temp;
        delete[]temp.str;
        temp.lenght = this->lenght + spd::Strlen(st.str);
        temp.str = new char[temp.lenght + 1];
        spd::Strcpy(temp.str, this->str);
        spd::Strcpy(temp.str + this->lenght, st.str);
        return temp;
    }

    String String::operator+(char* st)
    {
        String temp;
        delete[]temp.str;
        temp.lenght = this->lenght + spd::Strlen(st);
        temp.str = new char[temp.lenght + 1];
        spd::Strcpy(temp.str, this->str);
        spd::Strcpy(temp.str + this->lenght, st);
        return temp;
    }

    String String::operator+(const char* st)
    {
        String temp;
        delete[]temp.str;
        temp.lenght = this->lenght + spd::Strlen(st);
        temp.str = new char[temp.lenght + 1];
        spd::Strcpy(temp.str, this->str);
        spd::Strcpy(temp.str + this->lenght, st);
        return temp;
    }

    String String::operator+(char st)
    {
        String temp;
        delete[]temp.str;
        temp.lenght = this->lenght + 1;
        temp.str = new char[temp.lenght + 1];
        spd::Strcpy(temp.str, this->str);
        temp[temp.lenght - 1] = st;
        temp[temp.lenght] = '\0';
        return temp;
    }

    String& String::operator+=(String& st)
    {
        *this = *this + st;
        return *this;
    }

    String& String::operator+=(char* st)
    {
        *this = *this + st;
        return *this;
    }

    String& String::operator+=(const char* st)
    {
        *this = *this + st;
        return *this;
    }

    String& String::operator+=(char st)
    {
        *this = *this + st;
        return *this;
    }

    bool String::is_empty()
    {
        return lenght == 0 || str[0] == '\0';
    }

    const char* String::c_str()
    {
        return str;
    }

    String& String::assign(String& st)
    {
        *this = st;
        return *this;
    }

    String& String::assign(const String& st, size_t s, size_t num)
    {
        String temp;
        delete[]temp.str;
        temp.lenght = this->lenght + num + 1;
        temp.str = new char[temp.lenght + num + 1];
        spd::Strncpy(temp.str, this->str, s);
        spd::Strncpy(&temp.str[s], st.str, num);
        spd::Strcpy(&temp.str[s + num], &this->str[s + 1]);
        return *this;
    }

    String& String::erase(size_t index, size_t num)
    {
        char* tmp = new char[Strlen(str) - num + 1];
        tmp[Strlen(str) - num] = '\0';
        Strncpy(tmp, str, index);
        str = str + num + index;
        Strncat(tmp, str, Strlen(str));
        str = tmp;
        this->lenght = spd::Strlen(tmp);
        return *this;
    }

    String& String::insert(size_t start, const String& st)
    {
        char* temp = new char[this->lenght + st.lenght + 1];
        spd::Strncpy(temp, this->str, start);
        spd::Strcpy(temp + start, st.str);
        if (start < this->lenght)
            spd::Strcpy(temp + start + st.lenght, this->str + start);
        delete[]this->str;
        this->str = temp;
        this->lenght = spd::Strlen(temp);
        return *this;
    }

    String& String::replace(size_t start, size_t num, const String& s)
    {
        char* temp = new char[this->lenght - num + s.lenght + 1];
        spd::Strncpy(temp, this->str, start);
        spd::Strcpy(temp + start, s.str);
        if (this->lenght > start + num)
            spd::Strcpy(temp + start + s.lenght, this->str + start + num);
        delete[]this->str;
        this->str = temp;
        this->lenght = spd::Strlen(temp);
        return *this;
    }


    int String::find(const String& other, size_t ind)
    {
        for(  ;ind + other.lenght < this->lenght;ind++)
        {
            String temp;
            temp.assign(*this, other.lenght, ind);

            if (temp == other)
                return ind;
        }

        return -1;
    }

    int String::compare(const String& other, size_t n, size_t ind)
    {
        String temp;
        temp.assign(other, n, ind);

        return Strcmp(str, temp.str);
    }

    int String::size()
    {
        return lenght;
    }
