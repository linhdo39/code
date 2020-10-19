/********************************************************
*PROGRAM THREE: CSC 1300 - 003							*
*AUTHOR: My Linh Do            							*
*DATE: 10/19/2019           							*
*DESCRIPTION: Board Game			                    *
*********************************************************/	

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

//declaring functions that would be called later in the main function
void get_player_name(int num_player, string player_name[]);
int roll_dice(int j, string player_name[]);
void player_finished_board(int num_player, int board_space[], double score[], string player_name[]);
void activate_action_on_space(int num_player, int j, int board_space[], double score[], string player_name[], int dice_number);

//main function
int main()
{
	bool run = true;			//if the player enters Y or y, the program will start again
	bool game = true; 			//if the player reaches space 25, the loop will end 
	char input;					//the user inputs their choice to either start the program again or not
	int num_player;				//variable for the number of player
	int j;						//integer value to identify which element position it is
	int dice_number;			//variable for dice value
	
	do 
	{
		//print out the name of the game and instructions for the user
		cout << endl << endl;
		cout << string (8,'*') << "WELCOME TO LINH'S KITCHEN" << string (8,'*') << endl<< endl << endl;
		cout << "Please enter the number of players: ";
		cin >> num_player;		//the user input the number of players
		
		/*loop for the input, if the users input a number lower or equal to 0 or higher than 20,
		the program will ask them to reenter the value till the value is valid*/
		while (num_player > 20 || num_player <= 0)
		{ 
			cout << "Invalid! Please reenter the number of players: ";
			cin >> num_player;
		}
		
		
		string player_name[num_player];		//define player_name array with num_player as numbers of element
		int board_space[num_player] = {0};	//define player_name array with numbers of element equal to num_player and are set to zero
		double score[num_player] ={0.0};	//define player_name array with numbers of element equal to num_player and are set to zero
		
		get_player_name(num_player, player_name); //call get_player_name function
				
		//loop for the game until one of the players reaches board space 25
		while (game == true)
		{
			j = 0; 		//initial value for element position
			//if the element position higher than the number of players, the value will be reset
			if (j >= num_player)
				j = 0;
			else
			{
				//loop for each player's turn
				while (j<num_player)
				{
					dice_number = roll_dice(j, player_name);
					activate_action_on_space(num_player, j, board_space, score, player_name, dice_number);
					
					if (board_space[j] >= 25) 
					{
						cout << "YOU FINISHED LINH'S KITCHEN!!" << endl;
						cout << string (10, '-') << endl << endl;
						player_finished_board(num_player, board_space, score, player_name);
						game = false;
						break;
					}
					j++; 	//add 1 value to j when the other player's turn finished
				}
			}
		}
		
		//display the instruction and allow user to input their choice
		cout << "Do you want to play again?" << endl;
		cout << "Y or N: ";
		cin >> input;
	
		if (input == 'N'|| input =='n') //if the user inputs N or n, the program will not run again
			run = false;
		
	} while (run);		//this allows the program to run as many times as the player wants
		
return 0;
}

//define get_player_name function with string array and integer as parameter to get the player name
void get_player_name(int num_player, string player_name[]) 
{
	string name;
	int i;
	
	cin.ignore();
	for (i = 0; i < num_player; i++) // loop to take in the players'name
	{
		cout << endl ;
		cout << "PLAYER " << i + 1 << ", WHAT IS YOUR NAME?" << endl;
		cout << "NAME: ";
		getline(cin,name); 		// the user can enter space between the name
		player_name[i] = name; 	// store the name at the appropriate element position
	}
	cout << endl;
}

//define the roll_dice function, return dice_number value with integer and string array as parameter to get a random dice number 
int roll_dice(int j, string player_name[])
{
	int dice_number; 					//store the dice value 
	cout << string (10,'-') << endl; 	//a string of dashes
	cout << player_name[j] << ", press enter to roll the dice." << endl; //tell the player the instructions
	cin.get();
	
	srand(time(NULL)); 		//seed for the random generator
	
	switch (rand()%6+1) 	//choose the dice value in randomly and display the corresponding message
	{
	case 1:
		cout << "You rolled a 1." << endl << endl;
		cout << " _________\n";
		cout << "|         |\n";
		cout << "|    o    |\n";
		cout << "|         |\n";
		cout << "|_________|\n\n";
		dice_number = 1;
		break;
	case 2:
		cout << "You rolled a 2." << endl << endl;
		cout << " _________\n";
		cout << "|         |\n";
		cout << "|  o      |\n";
		cout << "|      o  |\n";
		cout << "|_________|\n\n";
		dice_number = 2;
		break;
	case 3:
		cout << "You rolled a 3." << endl << endl;
		cout << " _________\n";
		cout << "| o       |\n";
		cout << "|    o    |\n";
		cout << "|       o |\n";
		cout << "|_________|\n\n";
		dice_number = 3;
		break;
	case 4:
		cout << "You rolled a 4." << endl << endl;
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "|         |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		dice_number = 4;
		break;
	case 5:
		cout << "You rolled a 5." << endl << endl;
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "|    o    |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		dice_number = 5;
		break;
	case 6:
		cout << "You rolled a 6." << endl << endl;
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "| o     o |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		dice_number = 6;
		break;
	}
	
return dice_number;
}

//define player_finished_board with an integer and three different arrays for when any player reaches board space 25
void player_finished_board(int num_player,int board_space[], double score[], string player_name[])
{
	int i,j; 					//the loop variable, i is for board space loop and j is for score loop
	int max; 					//variable for the highest board space
	double highest_score; 		//variable for the highest score
	string max_score; 			//name variable for the person with the highest score
	string winner; 				//name variable for the person with the highest board space
	
	winner = player_name[0]; 					//initial value for person with the highest board space
	max_score = player_name[0];					//initial value for person with the highest score
	
	if (num_player < 2)		// if only one person is playing, this will display the score and who wins
	{	
		cout << "The player who survived LINH'S KITCHEN: "<< player_name[0] << endl << endl;
		cout << "The player who has the high score is: " << player_name[0] << " with a score of " << score[0] << endl;
		cout << endl;
	}
	
	else	//for more than 1 person playing this game
		{
		max = board_space[0];					//initial value for the highest board space
		for (i = 0; i < num_player; i++) 		//loop to find who has the highest board space
		{
			if (board_space[i] > max)
			{
				max = board_space[i];
				winner = player_name[i];
			}
		}
	
		cout << "The player who survived LINH'S KITCHEN: "<< winner << endl << endl; //display the winner after the loop
		
		highest_score = score[0];				//initial value for the highest score
		for (j = 0; j < num_player; j++ ) 		//loop to find who has the highest score
		{
			if (score[j] > highest_score)
			{
				highest_score = score[j];
				max_score = player_name[j];
			}
		}
		
		//display the player with the highest score after the loop
		cout << "The player who has the high score is: " << max_score << " with a score of " << highest_score << endl << endl; 
	}
}	

//define activate_action_on_space with three different integer and three different arrays for when none of the players reaches the board space 25
void activate_action_on_space(int num_player, int j, int board_space[], double score[], string player_name[], int dice_number)
{
	ifstream inFS; 			//for file input
	int line, point,i; 		//variable for which line number in the file will be print, how much point they got this turn and i is for text output loop
	string sentence; 		//variable for which line corresponding with the line number will be print
	
	board_space[j] = board_space[j] + dice_number; //add the dice value to the appropriate element position in board space
	
	if(board_space[j] >= 25) //if any player reaches board space 25, the function will stop and return back to main function
		return;
	cout << player_name[j] << " is now on space " << board_space[j] << endl; //display whose turn and what board space they are currently in
	
	srand(time(NULL)); 	//seed for the random generator
	
	point = 0;			//initial value for the point
	line = 0;			//initial value for the line number
	
	switch (rand()%2+1) //randomly choose which case to proceed.
	{
		case 1:  		//good case
		//display a smiley face and a message
		cout << endl;
		cout << "                   >     < 	" << endl;
		cout << "                     ___   	" << endl;		
		cout << "              	     \\_/  	" << endl;   
		cout << endl << endl << "Awesome! ";
		
		line = rand()%20+1; 					//randomly choose which line number fromm 1 to 20

		inFS.open("Good.txt"); 					//open the good text file
		
		for (i = 0; i < line; i++) 				//find the corresponding line with the line number
		{
			sentence = "";
			getline(inFS,sentence);
		}
		
		cout << sentence << endl; 				//print out the sentence
		
		point = rand()%100000 +1; 				//randomly choose the point from 1 to 100000
		score[j] = score[j] + point ; 			//add the point value to the appropriate element position in score array
		cout << "Add " << point << " points to your score." << endl;
		break;
		
		case 2: //bad score
		//display a crying face and a message
		cout << endl;
		cout << "                 ___       ___ 	" << endl;
		cout << "                  |         |      " << endl;
		cout << "                  |    _    |      " << endl;		
		cout << "                  |   / \\   |     " << endl;
		cout << endl << endl << "Oh no! ";
		
		line = rand()%20+1;						//randomly choose which line number fromm 1 to 20
		
		inFS.open("Bad.txt");					//open the bad text file
		
		for (i = 0; i < line; i++)				//find the corresponding line with the line number
		{
			sentence = "";
			getline(inFS,sentence);
		}
		cout << sentence << endl;				//print out the sentence
		
		point = rand()%100000 +1;				//randomly choose the point from 1 to 100000
		score[j] = score[j] - point;			//subtract the point value to the appropriate element position in score array
		cout << "Subtracted " << point << " points from your score." << endl; 	
		break;
	}
	cout << "You now have a score of " << score[j] << "." << endl; //display the player current score
	cout << string(10,'-') << endl << endl;	

}