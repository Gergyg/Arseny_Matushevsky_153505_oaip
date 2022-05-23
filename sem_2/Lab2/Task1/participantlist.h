#ifndef PARTICIPANTLIST_H
#define PARTICIPANTLIST_H
#include "participant.h"

class ParticipantList
{
public:
    Participant* head = nullptr;
    Participant* tail = nullptr;
public:
    ~ParticipantList();
    ParticipantList();
    void Add(Participant* item);
    void Remove(int index);
    void QSort_country(Participant* left, Participant* right);
    void QSort_comandName(Participant* left, Participant* right);
    void QSort_fio(Participant* left, Participant* right);
    void QSort_number(Participant* left, Participant* right);
    void QSort_age(Participant* left, Participant* right);
    void QSort_height(Participant* left, Participant* right);
    void QSort_weight(Participant* left, Participant* right);
};

#endif // PARTICIPANTLIST_H
