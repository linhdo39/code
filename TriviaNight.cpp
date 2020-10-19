#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()	
{	
	int correct; 			// the number of correct answer
	int Total;  			// total correct answer
	char answer; 			// the answer the player will type in
	char goagain; 			// input for whether the player want to try again or not
	bool runagain = true; 	// if the player enter Y or y, the program will start again
	
	
	do
	{
		cout << endl << endl;
		cout << string (60,'-') << endl;  							// horizontal line of dash
		cout << "Welcome to Linh's World Trivia Game!" << endl; 	// title of the program
		cout << string (60,'-') << endl << endl;					// horizontal line of dash
		cout << "Choose the answer you think is correct by typing the letter of your answer." << endl; // instruction for the player
		cout << endl << endl;
		
		correct = 0; // initial value of correct answer is 0
		
// Question 1
	
		cout << "1. What is the biggest landmass country?" << endl << endl;
		cout << "\tA: China" << endl; 
		cout << "\tB: Russia"  << endl;
		cout << "\tC: United State of America" << endl;
		cout << "\tD: Canada" << endl;
		cout << "\tE: India" << endl;
		//the program will print out the question and the choices for the player
		
		cout << "Answer: ";
		cin >> answer; // the player inputs the answer 
	
		if (answer == 'B'||answer == 'b') // The correct answer for this question is B: Russia 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1; 
		// if the play inputs B or b, the number of correct answer will increase by 1 point and the congratulation message will appear
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
		// any input other than B or b will count as a wrong answer, the player will not have point added to the total and the message will appear
		cout << endl;

/* All the questions from 2 to 10 have similar code to question 1*/

// Question 2
		
		cout << "2. How many people were born in Antarctica?" << endl << endl;
		cout << "\tA: 0" << endl;
		cout << "\tB: 5" << endl;
		cout << "\tC: 8" << endl;
		cout << "\tD: 11" << endl;
		cout << "\tE: 14" << endl;
		
		cout << "Answer: ";
		cin >> answer;
		
		if (answer == 'D'||answer == 'd') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
		cout << endl;

// Question 3
		
		cout << "3. Where did tea come from?" << endl << endl;
		cout << "\tA: Britain" << endl;
		cout << "\tB: Japan" << endl;
		cout << "\tC: Korea" << endl;
		cout << "\tD: United State of America" << endl;
		cout << "\tE: China" << endl;
		
		cout << "Answer: ";
		cin >> answer;
	
		if (answer == 'E'||answer == 'e') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else 
			cout << "Incorrect. Maybe try a different answer?" << endl;
	
		cout << endl;

// Question 4
		
		cout << "4. Where did French fries originate?" << endl << endl;
		cout << "\tA: France" << endl;
		cout << "\tB: the Netherlands" << endl;
		cout << "\tC: Belgium" << endl;
		cout << "\tD: Germany" << endl;
		cout << "\tE: Luxembourg" << endl;
		
		cout << "Answer: ";
		cin >> answer;
		
		if (answer == 'C'||answer == 'c') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
	
		cout << endl;

// Question 5	
	
		cout << "5. Which country has the most official languages?" << endl << endl;
		cout << "\tA: Zimbabwe" << endl;
		cout << "\tB: Zambia" << endl;
		cout << "\tC: Mozambique" << endl;
		cout << "\tD: Namibia" << endl;
		cout << "\tE: Malawi" << endl;
		
		cout << "Answer: ";
		cin >> answer;
	
		if (answer == 'A'||answer == 'a') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
	
		cout << endl;
	
//Question 6
	
		cout << "6. What country is famous for Pho?" << endl << endl;
		cout << "\tA: Thailand" << endl;
		cout << "\tB: Laos" << endl;
		cout << "\tC: Japan" << endl;
		cout << "\tD: Malaysia" << endl;
		cout << "\tE: Vietnam" << endl;
		
		cout << "Answer: ";
		cin >> answer;
	
		if (answer == 'E'||answer == 'e') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
		
		cout << endl;
	
// Question 7
	
		cout << "7. Which country has the city named 'Santa Claus'?" << endl << endl;
		cout << "\tA: Belgium" << endl;
		cout << "\tB: Sweden" << endl;
		cout << "\tC: Finland" << endl;
		cout << "\tD: United State of America" << endl;
		cout << "\tE: Canada" << endl;
		
		cout << "Answer: ";
		cin >> answer;
		
		if (answer == 'D'||answer == 'd') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
	
		cout << endl;

// Question 8	

		cout << "8. What is the biggest country in South America?" << endl << endl;
		cout << "\tA: Argentina" << endl;
		cout << "\tB: Brazil" << endl;
		cout << "\tC: Peru" << endl;
		cout << "\tD: Colombia" << endl;
		cout << "\tE: Venezuela" << endl;
		
		cout << "Answer: ";
		cin >> answer;
		
		if (answer == 'B'||answer == 'b') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
	
		cout << endl;
	
// Question 9
	
		cout << "9. Which country does Greenland belong to?" << endl << endl;
		cout << "\tA: Norway" << endl;
		cout << "\tB: Sweden" << endl;
		cout << "\tC: Denmark" << endl;
		cout << "\tD: United State of America" << endl;
		cout << "\tE: Greenland" << endl;
		
		cout << "Answer: ";
		cin >> answer;
		
		if (answer == 'C'||answer == 'c') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct + 1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
	
		cout << endl;

// Question 10
		
		cout << "10. Which country has the first police force named 'The Night Watch'?" << endl << endl;
		cout << "\tA: Australia" << endl;
		cout << "\tB: Britain" << endl;
		cout << "\tC: Scotland" << endl;
		cout << "\tD: New Zealand" << endl;
		cout << "\tE: Westeros" << endl;
		
		cout << "Answer: ";
		cin >> answer;
		
		if (answer == 'A'||answer == 'a') 
		{
			cout << "Correct! Good job!" << endl;
			correct= correct +1;
		}
		else
			cout << "Incorrect. Maybe try a different answer?" << endl;
		
		Total = correct; // the total number of correct answer 
		
		cout << endl << endl;
		cout << setw(28) << "RESULTS" << endl; //Result section heading
		cout << setw(60) << string (60,'-') << endl;
		cout << "You scored " << Total << " out of 10 points.";	
		// print out how many correct answer(s) the player got	
		
		if (Total < 5 )	
			cout << " Don't worry! Next time will be better." << endl;
			// if they have less than 5 point, the screen will display this message
		else
		{
			if ( Total >= 5 and Total <=9 ) 
				cout << " You did a great job!" << endl;
				// if their score is between 5 and 9 (both inclusive), the following message will display
			else 							
				cout << " Awesome job! A perfect score!" << endl;
				// the message is for people with perfect score
		}
	
		cout << setw(60) << string (60,'-') << endl << endl;
	
		cout << "Do you want to try again? Please enter Y/N:";
		cin >> goagain;
		// ask if the player wants to play the game again and the answer for that question
		if (goagain == 'N' || goagain == 'n')
			runagain = false;
		// if the player types in N or n, the program will not run again
	}
	while(runagain); // this allows the program to run as many times as the player wants
	
	return 0;
}
