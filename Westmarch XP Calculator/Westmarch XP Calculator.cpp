// Westmarch XP Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Made by James Kelley. My first program! c:

#include <iostream>
using namespace std;
double roleplaying, creativity, etiquette, completion, questLevel;
char difficulty;

double retrieveQuestLevelXP(int level);
// Precondition: The user has entered the intended party level for the adventure.
// Postcondition: The function converts the party level into a base XP value.
double calculateDifficultyModifier(char difficulty);
//Precondition: The user enters the difficulty as Easy, Medium, or Hard.
//The function returns .01, .05, or .1 respectively.
double retrieveFinalXP(double baseXP, double roleplay, double creativity, double etiquette, double difficulty, double completion);
// Precondition: The user has inputted correct values for every step in the process.
// Postcondition: The final recommended experience value is calculated and displayed to the user.

int main()
{
	cout << "What was the intended party level for the adventure you designed?\n";
	cin >> questLevel;
	double baseXP = retrieveQuestLevelXP(questLevel);
	cout << "On a scale of 1 to 10, 5 being average, how much did the party roleplay?\n";
	cin >> roleplaying;
	cout << "Was the planned difficulty for this session (E)asy, (M)edium, or (H)ard? Only enter the first letter.\n";
	cin >> difficulty;
	double difficultyModifier = calculateDifficultyModifier(difficulty);
	cout << "On a scale of 1 to 10,, 5 being average, how creative was the party?\n";
	cin >> creativity;
	cout << "On a scale of 1 to 10, 5 being average, was your party respectful and polite? Did you enjoy playing with them?\n";
	cin >> etiquette;
	cout << "On a scale of 1 to 100, how much of the party's goal was completed?\n";
	cin >> completion;
	retrieveFinalXP(baseXP, roleplaying, creativity, etiquette, difficultyModifier, completion);
	cin >> completion;
}

double retrieveQuestLevelXP(int level)
{
	switch (level) {
	case 1:
		cout << "Base XP is: 150" << endl;
			return 150;
	case 2:
		cout << "Base XP is: 150" << endl;
			return 150;
	case 3:
		cout << "Base XP is: 200" << endl;
			return 200;
	case 4:
		cout << "Base XP is: 600" << endl;
			return 600;
	case 5:
		cout << "Base XP is: 950" << endl;
			return 950;
	case 6:
		cout << "Base XP is: 1250" << endl;
			return 1250;
	case 7:
		cout << "Base XP is: 2200" << endl;
			return 2200;
	case 8:
		cout << "Base XP is: 2800" << endl;
			return 2800;
	case 9:
		cout << "Base XP is: 2600" << endl;
			return 2600;
	case 10:
		cout << "Base XP is: 3500" << endl;
			return 3500;
	case 11:
		cout << "Base XP is: 2100" << endl;
			return 2100;
	case 12:
		cout << "Base XP is: 2800" << endl;
			return 2800;
	case 13:
		cout << "Base XP is: 2500" << endl;
			return 2500;
	case 14:
		cout << "Base XP is: 3125" << endl;
			return 3125;
	case 15:
		cout << "Base XP is: 3333" << endl;
			return 3333;
	case 16:
		cout << "Base XP is: 3000" << endl;
			return 3000;
	case 17:
		cout << "Base XP is: 2727" << endl;
			return 2727;
	case 18:
		cout << "Base XP is: 3333" << endl;
			return 3333;
	case 19:
		cout << "Base XP is: 4000" << endl;
			return 4000;
	case 20:
		cout << "Base XP is: 4350" << endl;
		return 4350;
	default:
		perror("Incorrect value received for party level");
		exit(0);
	}
}

double retrieveFinalXP(double baseXP, double roleplay, double creativity, double etiquette, double difficulty, double completion) {
	double roleplayingModifier = ((roleplay / 100));
	cout << "XP rewarded is increased by " << (roleplayingModifier*100) << "% for RP.\n";
	double creativityModifier = ((creativity / 100));
	cout << "XP rewarded is increased by " << (creativityModifier*100) << "% for creativity.\n";
	double etiquetteModifier = ((etiquette / 100));
	cout << "XP rewarded is increased by " << (etiquetteModifier*100) << "% for good table etiquette.\n";
	double completionPercentage = (completion / 100);
	cout << "XP rewarded is increased by " << (difficulty*100) << "% for the difficulty setting.\n";
	cout << "Your party completed " << completion << "% of their goal.\n";
	double totalModifiers = (roleplayingModifier + creativityModifier + etiquetteModifier + difficulty);
	cout << "Total experience gain will be increased by: " << (totalModifiers*100) << "%.\n";
	double finalXP = (baseXP * (1 + totalModifiers) * completionPercentage);
	cout << "\n----> The recommended XP to award each party member is " << finalXP << ". <----\n";
	return finalXP;
}

double calculateDifficultyModifier(char difficulty){
	switch (difficulty) {
	case 'E':
	case 'e':
		return 0.01;
	case 'M':
	case 'm':
		return 0.05;
	case 'H':
	case 'h':
		return 0.1;
	default:
		cout << "ERROR: Incorrect difficulty received. Final experience may not be accurate.\n";
		return 0;
	}
}