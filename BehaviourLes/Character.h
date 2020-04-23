#pragma once
#include <string>
#include <cmath>
#include <typeinfo>

#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"
#include "Vector.h"

class Character
{
public:
	enum class AvailableBehaviours {
		IDLE,
		CHASE,
		EVADE
	};
public:
	Character(AvailableBehaviours aStartBehaviour, 
		Vector aStartPosition = Vector(0, 0), 
		std::string anIcon = "x",
		Character* aTarget = nullptr
	);
	~Character();
	void SetTarget(Character* aTarget);
	Character* GetTarget();

	AvailableBehaviours GetBehaviour();
	void Setbehaviour(AvailableBehaviours aBehaviour);
	Vector Update(Vector* min, Vector* max);

	void SetPosition(Vector aPos);
	Vector GetPosition();

	void SetIcon(std::string* newIcon);
	std::string GetIcon();
private:
	Behaviour* currentBehaviour;
	Character* target;
	AvailableBehaviours* startBehaviour;

	Vector* position;
	std::string icon;
};

