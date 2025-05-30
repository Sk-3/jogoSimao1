#include "Subject.h"
#include "Observer.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::attach(Observer* observer)
{
}

void Subject::detach(Observer* observer)
{
}

void Subject::notify()
{
	for (const auto& observ : observers) {
		observ->Update();
	}
}
