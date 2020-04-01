// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <vector>

#include "Character.h"
#include "Behaviour.h"
#include "ChaseBehaviour.h"
#include "EvadeBehaviour.h"

double delay = 0.2;
double previousFrameTime = 0.0;
int maxWidth = 100;
std::vector<std::string> scene;

bool running = true;
int turns = 3;

std::vector<Character*>* PlaceCharacters(std::vector<std::string>* field, std::vector<Character*>* vector,
	                                     Character* character, std::vector<std::string>* iconList)
{
	character->SetPosition(rand() % (field->size()));
	character->SetIcon(&(iconList->at(rand() % 2)));
	character->SetTarget(aTarget);
	vector->push_back(character);
	vector->at(0)->SetTarget(vector->at(1));
	return vector;
}

std::vector<Character*>* RemoveCharacters(std::vector<Character*>* vector, int begPos, int endPos)
{
	vector->erase(vector->begin() + begPos, vector->begin() + endPos);
	return vector;
}

int CheckTurn(int amount, HANDLE* thisHandle)
{
	if (amount > 1)
	{
		amount--;
	}
	else
	{
		SetConsoleTextAttribute(*thisHandle, 2);
		std::cout << "\nGAME OVER\nPress ENTER to quit" << std::endl;
		running = false;
	}

	return amount;
}

Character* SetIcon(Character* current, Character* target, std::vector<std::string>* iconList)
{
	if (current->GetPosition() > target->GetPosition()) {
		current->SetIcon(&(iconList->at(3)));
	}
	else {
		current->SetIcon(&(iconList->at(2)));
	}

	return current;
}

void SetTextColor(std::string* string, HANDLE* thisHandle, std::vector<std::string>* iconList)
{
	if (*string == iconList->at(0) ||
		*string == iconList->at(1) ||
		*string == iconList->at(2) ||
		*string == iconList->at(3)) {
		SetConsoleTextAttribute(*thisHandle, 13);
	}
	else {
		SetConsoleTextAttribute(*thisHandle, 6);
	}
}

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	std::vector<std::string> icons =
	{ "( ; )", "( * )", "8====D", "C====8" };

	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, 20, icons.at(rand() % 2));
	Character enemy(Character::AvailableBehaviours::CHASE, 40, icons.at(2), &player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//alle spelers in een lijst
	std::vector<Character*> characters{ &enemy, &player };

	//een scene van 100 breed aanmaken
	scene.resize(50);

	//deze scene vullen met _
	
	previousFrameTime = clock();
	//de game zelf
	while (running) {
		//een eigen timer
		if ((clock() - previousFrameTime) / CLOCKS_PER_SEC >= delay)
		{
			std::fill(scene.begin(), scene.end(), "_");
			system("cls");
			//std::cout << "[" << clock() << "] updating" << std::endl;

			for (Character* aCharacter : characters){
				if (aCharacter == &enemy) {
					aCharacter = SetIcon(aCharacter, aCharacter->GetTarget(), &icons);
				}
				scene.at(aCharacter->Update(0, (int)(scene.size() - 1))) = aCharacter->GetIcon();
			}

			std::cout << std::endl;
			for (std::string s : scene) {
				SetTextColor(&s, &handle, &icons);
				std::cout << s;
			}
			SetConsoleTextAttribute(handle, 12);
			std::cout << "\nYou want to commit crimes?!\nWell, this is JAIL, MOTHERFUCKER!";

			previousFrameTime = clock();
		}

		if (characters.at(0)->GetPosition() == characters.at(1)->GetPosition())
		{
			characters = *RemoveCharacters(&characters, 1, 2);
			characters = *PlaceCharacters(&scene, &characters, &player, &icons);
			turns = CheckTurn(turns, &handle);
		}
		SetConsoleTextAttribute(handle, 2);
	}
	std::cin.get();
}


