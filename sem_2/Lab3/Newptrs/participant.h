#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <string>
#include "my_shared_ptr.h"
using namespace std;
class Participant
{
private:

public:
    Participant(string s1, string s2, string s3, int i1, int i2, int i3, int i4);
    my_shared_ptr<Participant> next;
    my_weak_ptr<Participant> previos;
    string country;
    string comandName;
    string fio="-1";
    int number;
    int age;
    int height;
    int weight;
};

#endif // PARTICIPANT_H
