#include "EvadeBehaviour.h"

EvadeBehaviour::EvadeBehaviour()
{
}

EvadeBehaviour::~EvadeBehaviour()
{
}

Vector EvadeBehaviour::Update(Vector* ownPosition, Vector* targetPosition, Vector* minPosition, Vector* maxPosition)
{
	if (abs(ownPosition->X() - targetPosition->X()) < 5) {
		if (ownPosition->X() < targetPosition->X() && ownPosition->X() > minPosition->X()) {
			ownPosition->SetVector(ownPosition->X() - 1, ownPosition->Y());
		}
		else if (ownPosition->X() > targetPosition->X() && ownPosition->X() < maxPosition->X()) {
			ownPosition->SetVector(ownPosition->X() + 1, ownPosition->Y());
		}
	}
	return *ownPosition;
}

	

