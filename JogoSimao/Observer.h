#pragma once
#include "Actions.h"
class Observer
{
private:
public:
	Observer();
	~Observer();
	virtual void Update(Actions act) = 0;
};

