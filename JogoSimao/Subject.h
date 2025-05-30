#pragma once
#include <vector>
class Observer;

class Subject
{
private:
	std::vector<Observer*> observers;

public:
	Subject();
	~Subject();
	void attach(Observer* observer);
	void detach(Observer* observer);
	void notify();
};

