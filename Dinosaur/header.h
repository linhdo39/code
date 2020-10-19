/********************************************************
*PROGRAM FIVE: CSC 1300 - 003							*
*AUTHOR: My Linh Do            							*
*DATE: 11/25/2019           							*
*DESCRIPTION: Jurassic Park			                    *
*********************************************************/	

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
//define Cost structure
struct Cost
{
	float num_hours;
	float cost_taking_care;
	float cost_of_food;
	float cost_of_materials;
};

//define Dinosaurs structure with expense as a variable to hold the Cost structure
struct Dinosaurs
{
	string name;
	string description;
	float average_length;
	float average_height;
	string location;
	bool dangerous;
	Cost expense;
};

//functions prototype 
int enterDinosaur(Dinosaurs dinoArray[], int numDino);
float convertToFloat(string s);
int deleteDinosaur(Dinosaurs dinoArray[], int numDino);
bool moveArrayElement(Dinosaurs dinoArray[], int numDino, string removeDino);
void printDinosaurs(Dinosaurs dinoArray[], int numDino);
string wrap_text (string);
void printStatistics(Dinosaurs dinoArray[], int numDino);
void saveDinosaursToFile(Dinosaurs dinoArray[], int numDino);