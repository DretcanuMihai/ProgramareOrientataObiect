#include "Task.h"

Task::Task(int id0, const string& descriere0, const list<string>& programatori0, const string& stare0) :id{ id0 }, descriere{ descriere0 }, programatori{ programatori0 }, stare{ stare0 }
{
}

int Task::getId() const
{
    return id;
}

string Task::getDescriere() const
{
    return descriere;;
}

list<string> Task::getProgramatori() const
{
    return programatori;
}

string Task::getStare() const
{
    return stare;
}
