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
        if (i == index)
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
Task::Task(const Task &przypisanie) : description(przypisanie.description)
{
    if (przypisanie.head == nullptr)
    {
        this->head = nullptr;
        return;
    }
    head = new SubtaskNode(przypisanie.head->data);
    SubtaskNode *temp1 = head;
    SubtaskNode *temp2 = przypisanie.head->next;
 
    while (temp2 != nullptr)
    {
        SubtaskNode *nowy = new SubtaskNode(temp2->data);
        temp1->next = nowy;
        temp1 = nowy;
        temp2 = temp2->next;
    }
    temp1->next = nullptr;
}

Task::Task(Task &&przeniesienie) : description(przeniesienie.description)
{
    this->head = przeniesienie.head;
    przeniesienie.head = nullptr;
} // zmienna ktora zaraz umrze
Task &Task::operator=(Task &przypisanie)
{
    if (this == &przypisanie) return *this;
    clear();
    if (przypisanie.head == nullptr)
    {
        this->head = nullptr;
        return *this;
    }
    this->description = przypisanie.description;
    head = new SubtaskNode(przypisanie.head->data);
    SubtaskNode *temp1 = head;
    SubtaskNode *temp2 = przypisanie.head->next;
 
    while (temp2 != nullptr)
    {
        SubtaskNode *nowy = new SubtaskNode(temp2->data);
        temp1->next = nowy;
        temp1 = nowy;
        temp2 = temp1->next;
    }
    return *this;
}
Task &Task::operator=(Task &&przeniesienie)
{
    this->head = przeniesienie.head;
    przeniesienie.head = nullptr;
    return *this;
}
