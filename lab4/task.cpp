#include "task.hpp"
#include "iostream"

Task::~Task()
{
    // usuwanie
    description = "empty";
    clear();
}

void Task::add_subtask(const Subtask &subtask)
{
    int priorytet = subtask.get_priority();

    SubtaskNode *temp = head;
    SubtaskNode *prev = head;

    SubtaskNode *doloczany = new SubtaskNode(subtask);

    if (head == nullptr || head->data.get_priority() < priorytet)
    {
        doloczany->next = head;
        head = doloczany;
        return;
    }
    while (temp != nullptr)
    {

        if (temp->data.get_priority() < priorytet)
        {
            prev->next = doloczany;
            doloczany->next = temp;
            return;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    prev->next = doloczany; // To po wyjściu z pętli, jeśli nie zrobiono return
}
void Task::complete_subtask(unsigned int index)
{
    int i = 0;
    SubtaskNode *temp = head;
    while (temp != nullptr)
    {
        if(i == index)
        {
            temp->data.mark_completed();
            return;
        }
        temp = temp->next;
        i++;
    }
    
}

bool Task::is_completed() const
{
    SubtaskNode *temp = head;
    int yes = 0;
    int number = 0;
    while (temp != nullptr)
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
    while (temp != nullptr)
    {
        head = temp;
        temp = temp->next;
        delete head;
        head = nullptr;
    }
}

void Task::print() const
{
    if (is_completed())
    {
        std::cout << "[x]";
    }
    else
    {
        std::cout << "[ ] ";
    }
    std::cout << description << std::endl;

    SubtaskNode *temp = head;
    while (temp != nullptr)
    {
        std::cout << "  - ";
        temp->data.print();
        temp = temp->next;
    }
}
