#include "ChaseBehaviour.h"


ChaseBehaviour::ChaseBehaviour()
{
}

ChaseBehaviour::~ChaseBehaviour()
{
}

Vector ChaseBehaviour::Update(Vector* ownPosition, Vector* targetPosition, Vector* minPosition, Vector* maxPosition)
{
	if (ownPosition->X() < targetPosition->X() && ownPosition->X() < maxPosition->X()) {
		ownPosition->SetVector(ownPosition->X() + 1, ownPosition->Y());
	}
	else if (ownPosition->X() > targetPosition->X() && ownPosition->X() > minPosition->X()) {
		ownPosition->SetVector(ownPosition->X() - 1, ownPosition->Y());
	}
	return *ownPosition;
}
