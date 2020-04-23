#pragma once
#include <cmath>
#include "Vector.h"

class Character;

class Behaviour
{
public:
	Behaviour();
	~Behaviour();
	virtual Vector Update(Vector* ownPosition, Vector* targetPosition,
		Vector* minPosition = &Vector(0, 0), Vector* maxPosition = &Vector(100, 0));
};

