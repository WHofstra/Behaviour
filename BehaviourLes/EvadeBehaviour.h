#pragma once
#include "Behaviour.h"

class EvadeBehaviour :
	public Behaviour
{
public:
	EvadeBehaviour();
	~EvadeBehaviour();
	Vector Update(Vector* ownPosition, Vector* targetPosition,
		Vector* minPosition = &Vector(0, 0), Vector* maxPosition = &Vector(100, 0));
};

