#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <string>
using namespace std;
class Participant
{
private:

public:
    Participant(string s1, string s2, string s3, int i1, int i2, int i3, int i4);
    Participant* next = nullptr;
    Participant* previos = nullptr;
    string country;
    string comandName;
    string fio;
    int number;
    int age;
    int height;
    int weight;
};

#endif // PARTICIPANT_H
