#pragma once
#include "Subject.h"
#include "Actions.h"
#include <vector>
class mediadorEventos
{
private:
	static mediadorEventos* pMediadorEventos;
	mediadorEventos();
	std::vector<Subject*> vectorSubjects;
public:
	~mediadorEventos();
	void incluirSubject(Subject* subject);
	static mediadorEventos* getMediadorEventos();
	void notify(Actions act);
};

