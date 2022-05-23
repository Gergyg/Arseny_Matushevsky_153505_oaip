#ifndef STRINGLIB_H
#define STRINGLIB_H

#include <iostream>

namespace spd
{
    void* Memcpy(void* s1, const void* s2, size_t n);   //копирует содержимое одной области памяти в другую

    void* Memmove(void* s1, const void* s2, size_t n);  //memcpy, только учитывает, если области памяти пересекаются

    char* Strcpy(char* s1, const char* s2);             //копирует одну строку в другую

    char* Strncpy(char* s1, const char* s2, size_t n);  //копирует определенное количество

    char* Strcat(char* s1, const char* s2);             //присоединяет в конец к первой строчке вторую

    char* Strncat(char* s1, const char* s2, size_t n);  //присоединяет определенное количество символов второй строки

    int Memcmp(const void* s1, const void* s2, size_t n);//Сравнивает первые n символов массивов, на которые указывают s1, s2

    int Strcmp(const char* s1, const char* s2);         //сравнивает две строки

    int Strcoll(const char* s1, const char* s2);        //сравнивает две строки с учетом локали(но прекрасные локали
                                                //не работают, так что идентично strcmp
    int Strncmp(const char* s1, const char* s2, size_t n);//Сравнивает первые n символов двух строк

    size_t Strxfrm(char* s1, const char* s2, size_t n); //Переводит строку с учётом локали. Возвращает кол-во измененных
                                                //символов(хмммм, какой же тут может быть прикол...)
    char* Strtok(char* s1, const char* s2);             //Поиск лексем в строке(в основном для разбиения строки на подстроки)

    void* Memset(void* s, int c, size_t n);             //заполняет n байтов по указателю определенным символом
                                                //символ передается интовым значением
    char* Strerror(int errnum);                         //транслирует код ошибки(например, число) в понятную человеку
                                                //строку с ошибкой
    size_t Strlen(const char* s);                       //возвращает длинну строке(без учёта '\0')

    bool IsInArr(char s, const char* arr);


class String
{
    int lenght;
    char* str;
public:
    String();
    String(const char* ptr);
    String(char* ptr);
    String(const String& Str);
    ~String();

    int Lenght();

    String& operator=(const String& st);
    String& operator=(const char* ptr);

    char& operator[](int i);

    bool operator==(const String& st);
    bool operator==(const std::string& st);
    bool operator==(const char* st);
    bool operator<(const String& st) const;
    bool operator<(const std::string& st);
    bool operator<(const char* st);
    bool operator>(const String& st);
    bool operator>(const std::string& st);
    bool operator>(const char* st);

    String operator+(String& st);
    String operator+(char* st);
    String operator+(const char* st);
    String operator+(char st);

    String& operator+=(String& st);
    String& operator+=(char* st);
    String& operator+=(const char* st);
    String& operator+=(char st);

    bool is_empty();

    const char* c_str();

    String& assign(String& st);                                 //по факту копирование всей строки st в this

    String& assign(const String& st, size_t s, size_t num);   //копирование в this из st, где s - индекс начала, num - кол-во

    String& erase(size_t index, size_t num);                    //удаляет символы с позиции index, num = кол-во

    String& insert(size_t start, const String& st);             //вставляет всю строку всю строку st в this c позиции start

    String& replace(size_t start, size_t num, const String& s); //заменяет часть строки this на всю строку s

    int find(const String& other, size_t ind);                  //поиск подстроки в строке

    int compare(const String& other, size_t n, size_t ind);     //сравнивает часть одной строки с другой

    int size();

};
}
#endif // STRINGLIB_H
