/********************************************************
*PROGRAM FIVE: CSC 1300 - 003							*
*AUTHOR: My Linh Do            							*
*DATE: 11/25/2019           							*
*DESCRIPTION: Jurassic Park			                    *
*********************************************************/	

#include "prog5.h"

//define the main functions
int main ()
{
	int choice;			//the user inputs their choice
	char saveToList;	//variable for user if they choose to exist the program and save the info to a file
	bool run = true;	//variable to determine whether the program ends or not
	Dinosaurs dinoArray[100];	//array of element of the Dinosaurs type
	int numDino = 0;	//variable to keep up with the current number of dinosaurs
	
	do{
	
	//print out instruction for the user and allow them to enter their choice
	cout << "\n\n What would you like to do?" << endl;
	cout << "\t 1. Enter some Dinosaurs" << endl;
	cout << "\t 2. Delete a Dinosaur" << endl;
	cout << "\t 3. List/ Print Dinosaurs" << endl;
	cout << "\t 4. Print Statistics on Dinosaur Cost" << endl;
	cout << "\t 5. End Program" << endl;
	cout << "\t Enter 1,2,3,4, or 5." << endl;
	cout << "CHOICE: ";
	cin >> choice;	 
	
	//loop to validate the user input
	while (choice !=1 && choice !=2 && choice !=3 && choice != 4 && choice !=5)
	{
		cout << "Invalid input. Please reenter your choice: ";
		cin >> choice;
	}
	
	//call the corresponding functions depend on user input
	switch (choice)
	{
		case 1: //enter dinosaurs
			numDino = enterDinosaur(dinoArray, numDino);
			break;
			
		case 2:	//delete dinosaur
			numDino = deleteDinosaur(dinoArray, numDino);
			break;
			
		case 3:	//print dinosaurs
			printDinosaurs(dinoArray, numDino);
			break;
		
		case 4:	//print dinosaurs cost
			printStatistics(dinoArray, numDino);
			break;
		
		case 5: //ask the user if they want to save the info to a list and end the program
			cout << "\nDo you want to save your dinosaur list to a file? Enter Y or N: ";
			cin >> saveToList;
			
			//call saveDinosaursToFile function if the user entered y or Y
			if (saveToList == 'y' || saveToList =='Y')
			{
				saveDinosaursToFile(dinoArray, numDino);
				cout << "\nYou choose to end program. Thank you and Goodbye!" << endl;
				run = false;
			}
			else 
			{	
				cout << "\nYou chose to end the program. Thank you and Goodbye!" << endl;
				run = false;
				break;
			}
			
			break;
	}
	}while(run == true); //allow the program to run as many times as the user wants
	
	return 0;	
}