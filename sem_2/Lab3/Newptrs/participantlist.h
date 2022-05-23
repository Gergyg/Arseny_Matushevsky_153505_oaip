#ifndef PARTICIPANTLIST_H
#define PARTICIPANTLIST_H
#include "participant.h"

class ParticipantList
{
public:
    my_shared_ptr<Participant> head;
    my_shared_ptr<Participant> tail;
public:
    ParticipantList();
    void Add(my_shared_ptr<Participant> item);
    void Remove(int index);
};

#endif // PARTICIPANTLIST_H
