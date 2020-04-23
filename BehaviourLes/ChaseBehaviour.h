#pragma once
#include "Behaviour.h"

class ChaseBehaviour :
	public Behaviour
{
public:
	ChaseBehaviour();
	~ChaseBehaviour();
	Vector Update(Vector* ownPosition, Vector* targetPosition,
		Vector* minPosition = &Vector(0, 0), Vector* maxPosition = &Vector(100, 0));
};

