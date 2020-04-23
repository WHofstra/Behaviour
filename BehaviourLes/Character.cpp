#include "Character.h"

Character::Character(AvailableBehaviours aStartBehaviour, Vector aStartPosition, std::string anIcon, Character* aTarget)
	:position(&aStartPosition), icon(anIcon), startBehaviour(&aStartBehaviour), currentBehaviour(new Behaviour()), target(aTarget)
{
	if (aTarget) {
		switch (aStartBehaviour)
		{
		case Character::AvailableBehaviours::CHASE:
			currentBehaviour = new ChaseBehaviour();
			break;
		case Character::AvailableBehaviours::EVADE:
			currentBehaviour = new EvadeBehaviour();
			break;
		default:
			break;
		}
		target = aTarget;
	}
}

Character::~Character()
{
}

void Character::SetTarget(Character* aTarget)
{
	target = aTarget;
}

Character* Character::GetTarget()
{
	return target;
}

Character::AvailableBehaviours Character::GetBehaviour()
{
	return *startBehaviour;
}

void Character::Setbehaviour(AvailableBehaviours aBehaviour)
{
	startBehaviour = &aBehaviour;

	switch (aBehaviour)
	{
	case Character::AvailableBehaviours::IDLE:
		currentBehaviour = nullptr;
		break;
	case Character::AvailableBehaviours::CHASE:
		currentBehaviour = new ChaseBehaviour();
		break;
	case Character::AvailableBehaviours::EVADE:
		currentBehaviour = new EvadeBehaviour();
		break;
	default:
		break;
	}
}
Vector Character::Update(Vector* min, Vector* max)
{
	if (target && currentBehaviour) {
		position = &currentBehaviour->Update(position, &(target->GetPosition()), min, max);
	}
	return *position;
}

void Character::SetPosition(Vector aPos)
{
	position = &aPos;
}

Vector Character::GetPosition()
{
	return *position;
}

void Character::SetIcon(std::string* newIcon)
{
	icon = *newIcon;
}

std::string Character::GetIcon()
{
	return icon;
}
