/********************************************************
*PROGRAM ONE: CSC 1300 - 003							*
*AUTHOR: My Linh Do            							*
*DATE: 09/23/2019           							*
*DESCRIPTION: MASH					                    *
*********************************************************/	

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	bool run = true; 									//if the player enter 1, the program will start running
	char answer;  										//the user inputs their choice for menu
	string house; 										//variable for which house the user will live in
	string married_person, person1, person2, person3; 	//3 different names input and married person would be random selected from the input   
	string city_live, city1, city2, city3; 				//3 different cities input and city they would live in is random selected from the input 
	string car_drive, car1, car2, car3; 				//3 different cars input and car they would drive is random selected from the input 
	string job, job1, job2, job3; 						//3 different jobs input and job they would have is random selected from the input 
	string company, company1, company2, company3; 		//3 different companies input and the chosen company is random selected from the input 
	int num, number1, number2, number3; 				//3 different numbers input and the random selected number would be the number of children 
	int salary, salary1, salary2, salary3; 				//3 different salary input and the random selected number would be the salary 
	
	do
	{
	/*print out the menu for the user*/
	cout << endl << endl;
	cout << "Pick from the following menu:" << endl;
	cout << "1. Let's play MASH!" << endl;
	cout << "2. End program. " << endl;
	cout << "Please enter your option: ";
	cin >> answer; 			// the user input their choice
	
	/*loop for the input, if the users input any other number than 1 or 2,
	the program will ask them to reenter the value till the value is valid*/
	while (answer != '1' && answer != '2')
	{
		run = false;
		cout << "Invalid choice. Select 1 or 2." << endl;
		cin >> answer;
	}
	
	/*if the users input 1, the bool run variable will be set to true 
	and if the users input 2, the variable will be set to false */
	if (answer == '1')
		run = true;
	if (answer == '2')
		run = false;
	
	/*depend on the users input above, the program will choose which case to proceed*/
	switch (run)
	{
		case true: 				//the program will proceed to this case if the bool value is true
		{
		cin.ignore (); 			//ignore any prior input
		srand(time(NULL));		//seed for the random generator
	
	/*choose which house the user would live in randomly*/	
		switch (rand()%4+1)
		{
			case 1: 
				house = " in a luxurious mansion";
			break;
		
			case 2:
				house = "in a comfortable apartment";
			break;
			
			case 3: 
				house = "in a disheveled shack";
			break;		
			case 4:
				house = "in a modest house";
			break;
		}
	
	/*display instruction and allow user to input the name based on the question*/
		cout << "Please enter the name of a person you like: ";
		getline(cin, person1);
		cout << endl;
		cout << "Please enter the name of another person you like: ";
		getline(cin, person2);
		cout << endl;
		cout << "Please enter the name of a person you do not like: ";
		getline(cin, person3); 
		cout << endl;
		
	/*choose which input names would be the person the user married to in the future*/ 	
		switch (rand()%3+1)
		{
			case 1: 
				married_person = person1;
			break;
			case 2:
				married_person = person2;
			break;
			case 3:
				married_person = person3;
			break;
		}
	
	/*display instruction and allow user to input three different numbers*/
		cout << "Please enter three number from 1 to 100 (seperated by enter):" << endl;
		cin >> number1 >> number2 >> number3;
	
	/*a loop that assess each number to make sure it is within 1 - 100 range, display
	message accordingly and allow user to reenter the numbers till valid*/
		while (number1 >100 || number1 <1 ||
			   number2 >100 || number2 <1 ||
			   number3 >100 || number3 <1)
		{
			if (number1 >100 || number1 <1)
			{	
			cout << "Invalid first number! Please reenter the first number." << endl;
			cin >> number1;
			}
			
			if (number2 >100 || number2 <1)
			{	
			cout << "Invalid second number! Please reenter the second number." << endl;
			cin >> number2;
			}
			
			if (number3 >100 || number3 <1)
			{	
			cout << "Invalid third number! Please reenter the third number." << endl;
			cin >> number3;
			}
		} 
	
	/*choose which input numbers would be the number of kids the user will have in the future*/
		switch (rand()%3+1)
		{
			case 1:
				num = number1;
			break;
			case 2:
				num = number2;
			break;
			case 3:
				num = number3;
			break;
		}
	
		cin.ignore(); 	//ignore any prior input
		cout << endl;	
	
	/*display instruction and allow user to input the name based on the question*/
		cout << "Please enter the city, country (or state) you like: ";
		getline(cin, city1);
		cout << endl;
		cout << "Please enter another city, country (or state) you like: ";
		getline(cin, city2);
		cout << endl;
		cout << "Please enter the city, country (or state) you hate: ";
		getline(cin, city3);
		cout << endl;
	
	/*choose which input cities would be the city the user will live in in the future*/ 	
		switch (rand()%3+1)
		{
			case 1:
				city_live = city1;
			break;
			case 2:
				city_live = city2;
			break;
			case 3:
				city_live = city3;
			break;
		}
		
	/*display instruction and allow user to input the name based on the question*/
		cout << "Please enter a perfect job title for you: ";
		getline(cin, job1);
		cout << endl;
		cout << "Please enter another great job title for you: ";
		getline(cin, job2);
		cout << endl;
		cout << "Please enter a job title that you do not want have: ";
		getline(cin, job3);
		cout << endl;
	
	/*choose which input jobs would be the job the user will have in the future*/ 	
		switch (rand()%3+1)
		{
			case 1:
				job = job1;
			break;
			case 2:
				job = job2;
			break;
			case 3:
				job = job3;
			break;
		}
	
	/*display instruction and allow user to input the name based on the question*/
		cout << "Please enter a company, business or restaurant you like: ";
		getline(cin, company1);
		cout << endl;
		cout << "Please enter another company, business or restaurant you like: ";
		getline(cin, company2);
		cout << endl;
		cout << "Please enter a company, business or restaurant you hate: ";
		getline(cin, company3);
		cout << endl;
	
	/*choose which input companies would be the company the user will work in the future*/
		switch (rand()%3+1)
		{
			case 1:
				company = company1;
			break;
			case 2:
				company = company2;
			break;
			case 3:
				company = company3;
			break;
		}
	
	/*display instruction and allow user to input three different numbers*/
		cout << "Please enter three numbers from 10,000 to 500,000 (seperated by enter):" << endl;
		cin >> salary1 >> salary2 >> salary3;
				
	/*a loop that assess each number to make sure it is within 10,000 - 500,000 range, display
	message accordingly and allow user to reenter the numbers till valid*/	
		while(salary1 >500000 || salary1 <10000 ||
			  salary2 >500000 || salary2 <10000 ||
			  salary3 >500000 || salary3 <10000)
		{	
			if(salary1 >500000 || salary1 <10000)
			{	
			cout << "Invalid first number! Please reenter the first number." << endl;
			cin >> salary1;
			}
			if (salary2 >500000 || salary2 <10000)
			{	
			cout << "Invalid second number! Please reenter the second number." << endl;
			cin >> salary2;
			}
			if(salary3 >500000 || salary3 <10000)
			{	
			cout << "Invalid third number! Please reenter the third number." << endl;
			cin >> salary3;
			}
		}
		
	/*choose which input salaries would be the salary the user will have in the future*/ 	
		switch (rand()%3+1)
		{
			case 1:
				salary = salary1;
			break;
			case 2:
				salary = salary2;
			break;
			case 3:
				salary = salary3;
			break;
		}
	
		cin.ignore(); 			//ignore any prior input
		cout << endl;
	
	/*display instruction and allow user to input the name based on the question*/
		cout << "Please enter a car you would like to have: ";
		getline(cin, car1);
		cout << endl;
		cout << "Please enter another car you would like to have: ";
		getline(cin, car2);
		cout << endl;
		cout << "Please enter a car you hate: ";
		getline(cin, car3);
		cout << endl;
	
	/*choose which input car's names would be the car the user will have in the future*/ 
		switch (rand()%3+1)
		{
			case 1:
				car_drive = car1;
			break;
			case 2:
				car_drive = car2;
			break;
			case 3:
				car_drive = car3;
			break;
		}
	
	/*display the user result*/
		cout << string (8,'*') << " MASH RESULTS " << string(8,'*') << endl;
		cout << "You will live " << house << "." << endl;
		cout << "You will be married to " << married_person << "." << endl;
		cout << "You will have " << num << " children" << "." << endl;
		cout << "You will live in " << city_live << "." << endl;
		cout << "You will work at " << company << " as a " << job <<" making $ " << salary << " a year." << endl;
		cout << "You will drive a " << car_drive << "." << endl;
		break;
		}
	
		case false: 	//the program will proceed to this case if the bool value is false
		{
		cout << endl;
		cout << "You chose to end the program." << endl;
		cout << "Thank you for using the program. Good bye!" << endl;
		break;
		}
		
	}	
	} while(run);		//this allows the program to run as many times as the player wants
	
return 0;
}