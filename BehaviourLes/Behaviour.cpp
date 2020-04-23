#include "Behaviour.h"
#include "Character.h"

Behaviour::Behaviour()
{

}

Behaviour::~Behaviour()
{
}

Vector Behaviour::Update(Vector* ownPosition, Vector* targetPosition, Vector* minPosition, Vector* maxPosition)
{
	return Vector(0, 0);
}
