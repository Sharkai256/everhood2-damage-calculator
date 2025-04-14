/*
"Everhood 2 Damage Calculator" allows you to calculate the damage to one-shot the boss with a chosen weapon and other conditions

HOW TO USE:
	if you are literate - run the exe and follow the prompts.
	else - well sucks to be you.

PS:
	I learned that damage in Everhood 2 does not scale linearly but exponentially with some weapons* so formula should be a little different
	but it won't matter in most cases so I'm not willing to brainstorm myself over it.
*/

//TODO: add normal UI

#include <iostream>
#include <windows.h>
#include <vector>

typedef std::pair<std::string, WORD> Weapon;
typedef std::vector<Weapon> WeaponsList;

void consoleColorPrint(std::string message, WORD color, HANDLE console, WORD defaultColor){
	SetConsoleTextAttribute(console, color);
	std::cout << message << std::endl;
	SetConsoleTextAttribute(console, defaultColor);
};

//TODO: takes message and applies chosen options on each character
void consoleRandomPrint(std::string message, boolean randomColor = true, boolean randomHeight = true){

};

int main() {
	//TODO: add "WEAK" damage multiplier. might need tuples instead of pairs
	int notesAmmount = 0;
	int damageDealt = 0;
	int bossHP = 0;
	int weaponChoice = 4;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD defaultColor = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

	//TODO: add scaling to weapons depending on level if such exist
	//? https://learn.microsoft.com/en-us/windows/console/console-screen-buffers#character-attributes
	WeaponsList weaponsVec = {
		{"Fists", FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE},
		{"World Ender", FOREGROUND_RED | FOREGROUND_BLUE},
		{"Spear of Destiny", FOREGROUND_GREEN},
		{"Moon Blades", FOREGROUND_BLUE},
		{"Ragnarok", FOREGROUND_RED}
	};

	std::cout << "\/\/\/\/ EVERHOOD 2 DAMAGE CALCULATOR \/\/\/\/\n\n"; // ignore this puny warning
	std::cout << "\tHOW TO USE: FOLLOW THE PROMPTS\n";

	// this is for the future when I implement boss' weakness to weapon elements
	// std::cout << "\tATTENTION: EACH WEAPON IS IMPLIED TO BE USED WITH IT'S OWN ELEMENT\n";
	// std::cout << "\tKEEP THAT IN MIND WHEN PICKING BOSS' WEAKNESS TO SAID ELEMENT\n\n";
	while (1) {
		std::cout << "Enter amount of notes: \n";
		std::cin >> notesAmmount;

		std::cout << "Enter amount of damage dealt: \n";
		std::cin >> damageDealt;

		int index = 0;
		std::cout << "Enter weapon code:\n";
		for (Weapon& weapon : weaponsVec) {
			consoleColorPrint(std::to_string(index) + ": " + weapon.first, weapon.second, console, defaultColor);
			index++;
		}
		std::cin >> weaponChoice;

		std::cout << "Enter boss' HP: \n";
		std::cin >> bossHP;

		//! NEED TO CHECK THIS *
		// different weapons deal different amounts of damage to the same target*, hence damagePerNote will wary
		int damagePerNote = damageDealt / notesAmmount;

		std::cout << "\n" << damagePerNote << " Damage/note with ";
		consoleColorPrint(weaponsVec[weaponChoice].first, weaponsVec[weaponChoice].second, console, defaultColor);
		std::cout << "You need " << bossHP / damagePerNote << " notes to one-shot this boss \n" << std::endl;
	}
}