#include "subtask.hpp"
#include <iostream>

void Subtask::mark_completed()
{
    completed = true;
}

bool Subtask::is_completed() const{
    return completed;
}
unsigned int Subtask::get_priority() const
{
    return priority;
}
void Subtask::print() const {
    bool a = is_completed();
    if(a)
    {
        std::cout<<"[x]";
    }else{
        std::cout<<"[]";
    }
    std::cout<<"P: "<<priority<<", "<<description<<std::endl;

}