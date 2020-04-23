// BehaviourLes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <vector>

#include "Vector.h"
#include "Character.h"
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
	character->SetPosition(Vector(rand() % (field->size()), 0));
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

void SetTextColor(std::string* string, HANDLE* thisHandle, std::vector<std::string>* iconList)
{
	if (*string == iconList->at(0) ||
		*string == iconList->at(1)) {
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
	{ "E", "C" };

	//Characters aanmaken
	Character player(Character::AvailableBehaviours::IDLE, Vector(20, 0), icons.at(0));
	Character enemy(Character::AvailableBehaviours::CHASE, Vector(40, 0), icons.at(1), &player);

	//Game mechanics activeren
	player.SetTarget(&enemy);
	player.Setbehaviour(Character::AvailableBehaviours::EVADE);

	//Zet minimale en maximale waarden
	std::vector<Vector> fieldValues = { Vector(0, 0), Vector(maxWidth, 0) };

	//alle spelers in een lijst
	std::vector<Character*> characters{ &enemy, &player };

	//een scene van 100 breed aanmaken
	scene.resize(50);
	std::vector<Vector> sceneSize = { fieldValues.at(0), Vector((int)scene.size() - 1, 0) };

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
				//Draw Character Icons
			}

			std::cout << std::endl;
			for (std::string s : scene) {
				SetTextColor(&s, &handle, &icons);
				std::cout << s;
			}
			//SetConsoleTextAttribute(handle, 12);
			//std::cout << "\nYou want to commit crimes?!\nWell, this is JAIL, MOTHERFUCKER!";

			previousFrameTime = clock();
		}

		if (characters.at(0)->GetPosition().X() == characters.at(1)->GetPosition().X())
		{
			characters = *RemoveCharacters(&characters, 1, 2);
			characters = *PlaceCharacters(&scene, &characters, &player, &icons);
			sceneSize.pop_back();
			sceneSize.push_back(Vector((int)scene.size() - 1, 0));
			turns = CheckTurn(turns, &handle);
		}
		SetConsoleTextAttribute(handle, 2);
	}
	std::cin.get();
}


