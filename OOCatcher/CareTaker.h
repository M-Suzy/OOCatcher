#include "Memento.h"
#include "Originator.h"
class CareTaker
{
public:
    CareTaker(Originator* const o) : originator(o) {}

    ~CareTaker();

    void save();
    void undo();
    Memento get_memento(int index);
    std::vector<Memento*> get_history();

private:
    Originator* originator;
    std::vector<Memento*> history;
    
};
