#pragma once
#include <string>
#include <cmath>
#include <typeinfo>
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

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
		int aStartPosition = 0, 
		std::string anIcon = "x",
		Character* aTarget = nullptr
	);
	~Character();
	void SetTarget(Character* aTarget);
	Character* GetTarget();

	AvailableBehaviours GetBehaviour();
	void Setbehaviour(AvailableBehaviours aBehaviour);
	int Update(int min, int max);

	void SetPosition(int aPos);
	int GetPosition();

	void SetIcon(std::string* newIcon);
	std::string GetIcon();
private:
	Behaviour* currentBehaviour;
	Character* target;
	AvailableBehaviours* startBehaviour;

	int position;
	std::string icon;
};

