#pragma once
#include <iostream>
#include "Human.h"
#include <vector>
#include "Memento.h"
class CareTaker
{
public:
    void add(Memento state) {
        history.push_back(state);
    }
    Memento get(int index) {
        return history[index];
    }
    std::vector<Memento> get_history() {
        return history;
    }
private:
    std::vector<Memento> history;
};
