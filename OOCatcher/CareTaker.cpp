#include "CareTaker.h"

CareTaker::~CareTaker()
{
	for (unsigned int i = 0; i < history.size(); i++)
	{
		delete history.at(i);
	}
	history.clear();
}

void CareTaker::save()
{
	history.push_back(originator->createMemento());
}

void CareTaker::undo()
{
	if (history.empty())
	{
		return;
	}

	Memento* m = history.back();
	originator->setMemento(m);

	history.pop_back();
	delete m;
}

Memento CareTaker::get_memento(int index)
{
	return *history[index];
}

std::vector<Memento*> CareTaker::get_history()
{
	return history;
}
