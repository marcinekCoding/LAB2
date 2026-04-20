#pragma once
#include <string>

class Subtask
{
private:
    std::string description;
    unsigned int priority;
    bool completed;

public:
    Subtask(std::string opis, int priorytet=0, bool status=false) : description(opis),priority(priorytet),completed(status){}

    void mark_completed();
    bool is_completed() const;
    unsigned int get_priority() const;
    void print() const;

};