#pragma once
#include <iostream>
#include "Human.h"
#include <vector>
#include "Memento.h"
class CareTaker
{
public:
    CareTaker(Human* const h) : originator(h) {}

    ~CareTaker()
    {
        for (unsigned int i = 0; i < history.size(); i++)
        {
            delete history.at(i);
        }
        history.clear();
    }

    void save()
    {
        std::cout << "Save state." << std::endl;
       // history.push_back(originator->createMemento());
    }

    void undo()
    {
        if (history.empty())
        {
            std::cout << "Unable to undo state." << std::endl;
            return;
        }

        Memento* m = history.back();
       // originator->setMemento(m);
        std::cout << "Undo state." << std::endl;

        history.pop_back();
        delete m;
    }

private:
    Human* originator;
    std::vector<Memento*> history;
};
