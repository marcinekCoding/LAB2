#include "task.hpp"
#include "iostream"

Task::~Task()
{
    // usuwanie
    description = "empty";
    // usuwanie zaalokowanej pamieci
    SubtaskNode *temp = head;
    while (temp->next != nullptr)
    {
        head = temp;
        temp = temp->next;
        head = nullptr;
    }
}

void Task::add_subtask(const Subtask &subtask)
{
    int priorytet = subtask.get_priority();
    SubtaskNode *temp = head;
    while (temp->next != nullptr && temp->data.get_priority() >= priorytet)
    {
        temp = temp->next;
    }
    SubtaskNode *doloczany;
    doloczany->data = subtask;
    doloczany->next = nullptr;
    temp->next = doloczany;
}
void Task::complete_subtask(unsigned int index)
{
    int i = 0;
    SubtaskNode *temp = head;
    while (temp->next != nullptr && i != index)
    {
        temp = temp->next;
    }
    if (temp->next == nullptr)
        return;
    temp->data.mark_completed();
}

bool Task::is_completed() const
{
    SubtaskNode *temp = head;
    int yes = 0;
    int number = 0;
    while (temp->next != nullptr)
    {
        if (temp->data.is_completed() == true)
        {
            yes++;
        }
        number++;
        temp = temp->next;
    }
    if (number == yes)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Task::clear()
{
    SubtaskNode *temp = head;
    while (temp->next != nullptr)
    {
        head = temp;
        temp = temp->next;
        head = nullptr;
    }
}

void Task::print() const
{
    if(is_completed())
    {
        std::cout<<"[x]";
    }else{
        std::cout<<"[] ";
    }
    std::cout<<description<<std::endl;
    
    SubtaskNode *temp = head;
    while(temp->next!=nullptr)
    {
        std::cout<<"- ";
        temp->data.print(); 
    }
}
