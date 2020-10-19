/********************************************************
*PROGRAM FIVE: CSC 1300 - 003							*
*AUTHOR: My Linh Do            							*
*DATE: 11/25/2019           							*
*DESCRIPTION: Jurassic Park			                    *
*********************************************************/	

#include "prog5.h"
//define enterDinosaur function with dinoArray and numDino as parameter
int enterDinosaur(Dinosaurs dinoArray[], int numDino){
	int choice;		//variable for the user input
	ifstream inFS;  //for file input
	string dangerous_input; //allow user to input whether the dinosaur is dangerous or not
	char another_input; //variable for the user input if they want to add another dinosaur
	string input_file;	//for name of the file
	
	//display message if the number of dinosaur in the array reach 100
	if(numDino == 100){
		cout << "\nThe zoo is at full capacity. You cannot add Dinosaurs.";
		return 0;
	}
	
	else{
		do{
		//display instruction for user and allow them to input their choice
		cout << "\nWhat do you want to do?" << endl;
		cout << "\t 1. Load my dinosaurs from a file." << endl;
		cout << "\t 2. Enter one dinosaur manually. " << endl;
		cout << "\t Choose 1 or 2." << endl << "CHOICE: ";
		cin >> choice;
		
		//loop to validate user's choice
		while (choice !=1 && choice !=2){
			cout << "Invalid. Please reenter your choice: " << endl;
			cin >> choice;
		}
		
		if (choice == 1){
			//display instruction and allow input
			cout << "\nWhat is the name of the file with your list of dinosaurs? (ex: filename.txt)" << endl;
			cout << "FILENAME: ";
			cin >> input_file;
			
			inFS.open(input_file.c_str()); //open the file with the name the user inputs
			
			//loop to check if the file could be opened before reading
			while(!inFS.is_open()){
				cout << "The file does not exist or cannot be opened" << endl;
				cout << "Please reenter the file name: ";
				cin >> input_file;
				inFS.open(input_file.c_str());
			}
			
			//variables to extract data from the file
			string dinoInfo = "";
			getline(inFS, dinoInfo);
			istringstream ss(dinoInfo);
			string data;
			
			//loop to get data from the file and add them to the correct position in array
			for(data;getline(ss, data,'#');){
				dinoArray[numDino].name = data ;
				getline(ss, data,'#');
				dinoArray[numDino].description = data;
				getline(ss, data,'#');
				dinoArray[numDino].average_length = convertToFloat(data);
				getline(ss, data,'#');
				dinoArray[numDino].average_height = convertToFloat(data);
				getline(ss, data,'#');
				dinoArray[numDino].location = data;
				getline(ss, data,'#');
				if (data == "1")
					dinoArray[numDino].dangerous= true;
				else
					dinoArray[numDino].dangerous= false;
				getline(ss, data,'#');
				dinoArray[numDino].expense.num_hours = convertToFloat(data);
				getline(ss, data,'#');
				dinoArray[numDino].expense.cost_taking_care = convertToFloat(data);
				getline(ss, data,'#');
				dinoArray[numDino].expense.cost_of_food = convertToFloat(data);
				getline(ss, data,'#');
				dinoArray[numDino].expense.cost_of_materials =convertToFloat(data);
		
				numDino ++; // increase number of dinosaurs	
			}
			
			//display message and close the file
			cout << "\n\nAll dinosaurs from " << input_file << " have been added to the program." << endl;
			inFS.close();
		}
		
		else if (choice ==2){
			//allow user to enter the dinosaur information
			cin.ignore();
			cout << "\nName: ";
			getline(cin, dinoArray[numDino].name);
			cout << "Description: ";
			getline (cin, dinoArray[numDino].description);
			cout << "Average length (in feet): ";
			cin >> dinoArray[numDino].average_length;
			cout << "Average height (in feet): ";
			cin >> dinoArray[numDino].average_height;
			cin.ignore();
			cout << "Location: ";
			getline (cin,dinoArray[numDino].location);
			cout << "Is it a dangerous dinosaur? (yes or no) ";
			cin >> dangerous_input;
			
			if (dangerous_input == "yes" || dangerous_input == "Yes")
				dinoArray[numDino].dangerous = true;
			else
				dinoArray[numDino].dangerous = false;
			
			cout << "How many hours do you spend caring for the " << dinoArray[numDino].name << "? \t";
			cin >> dinoArray[numDino].expense.num_hours;
			cout << "What is the cost per hour do you spend caring for the " << dinoArray[numDino].name << "? \t";
			cin >> dinoArray[numDino].expense.cost_taking_care;
			cout << "How much money do you spend on food for the " << dinoArray[numDino].name << "? \t";
			cin >> dinoArray[numDino].expense.cost_of_food;
			cout << "How much money do you spend on grooming and medical supplies for the " << dinoArray[numDino].name << "? \t";
			cin >> dinoArray[numDino].expense.cost_of_materials;
			
			numDino++;	//increase the number of dinosaur		
		}
		
		//display instruction and allow user to enter their choice
		cout << "\nDo you want to add another dinosaur? (Y/N) ";
		cin >> another_input;
		
		} while (another_input == 'Y'|| another_input =='y'); //allow the function to run as many times as the user wants	
	}

	return numDino;
}

//define function to convert string to float
float convertToFloat(string s){
	istringstream i(s);
	float x;
	
	if (!(i >> x))
		x = 0;
	
	return x;
}

//define deleteDinosaur function with dinoArray and numDino as parameter
int deleteDinosaur(Dinosaurs dinoArray[], int numDino){
	string removeDino; //the user enters the dinosaur they want to remove
	
	//print out all the dinosaurs in the array
	cout << "\nThe following is a list of all the Dinosaurs you take care of: " << endl;
	for (int i = 0; i < numDino; i++){
		cout << dinoArray[i].name << endl;
	}
	
	//display instruction and allow user to enter their choice
	cout << "\nWhat Dinosaurs do you wish to remove?" << endl;
	cin >> removeDino;
	
	//call moveArrayElement function and depend on the return, the corresponding message will be shown
	if (moveArrayElement(dinoArray, numDino, removeDino) == true){
		cout << "\nYou have removed " <<  removeDino << "." << endl;
		numDino--;
	}
	else
		cout << endl << removeDino << " cannot be found." << endl;
	
	return numDino;
}

//define the moveArrayElement function with dinoArray, numDino and removeDino as parameter
bool moveArrayElement(Dinosaurs dinoArray[], int numDino, string removeDino){

	//loop to find the matching removed dinosaur with the position in the array
	for (int i = 0; i < numDino; i++){
		if (dinoArray[i].name == removeDino){	
			//loop to overwrite the remove dinosaur name with the next element
			for (int j = i; j <numDino;j++){					
				dinoArray[j].name = dinoArray[j+1].name;
				dinoArray[j].description = dinoArray[j+1].description;
				dinoArray[j].average_length = dinoArray[j+1].average_length;
				dinoArray[j].average_height = dinoArray[j+1].average_height;
				dinoArray[j].location = dinoArray[j+1].location;
				dinoArray[j].dangerous= dinoArray[j+1].dangerous;
				dinoArray[j].expense.num_hours = dinoArray[j+1].expense.num_hours;
				dinoArray[j].expense.cost_taking_care = dinoArray[j+1].expense.cost_taking_care;
				dinoArray[j].expense.cost_of_food = dinoArray[j+1].expense.cost_of_food;
				dinoArray[j].expense.cost_of_materials = dinoArray[j+1].expense.cost_of_materials;
			}
		return true;
		}
	}
	return false;
}

//define printDinosaurs function with dinoArray and numDino as parameter
void printDinosaurs(Dinosaurs dinoArray[], int numDino){
	
	int choice; //variable for user input
	ofstream outFS; //for output file
	string output_file; //variable for name of the file
	
	//print instruction and allow the user to enter the choice
	cout << "\nWhat would you like to do? " << endl;
	cout << "\t1. Print Dinosaurs to the Screen." << endl;
	cout << "\t2. Print Dinosaurs to a file." << endl;
	cout << "\tChoose 1 or 2." << endl;
	cout << "Choice: ";
	cin >> choice;
	
	//loop for validate the input
	while (choice !=1 && choice !=2){
		cout << "\nInvalid. Please reenter your choice: " << endl;
		cin >> choice;
	}
	
	cout << string(50, '-') << endl;
	
	if (choice == 1){
		//loop to print out all dinosaurs information on the screen
		for (int i =0; i < numDino; i++){
			cout << "\nDINOSAUR " << i+1 << ": " << endl;
			cout << "Name: \t" << dinoArray[i].name << endl;
			cout << "Description: " << endl;
			//call the wrap text function
			cout <<	"\t" << wrap_text(dinoArray[i].description) << endl;
			cout << "\nLength: \t" << dinoArray[i].average_length << endl;
			cout << "Height: \t" << dinoArray[i].average_height << endl;
			cout << "Location: \t" << dinoArray[i].location << endl;
			if (dinoArray[i].dangerous == true)
				cout << "Dangerous? \t yes" << endl;
			else 
				cout << "Dangerous? \t no" << endl;
			cout << "Number of Hours to Care of Dinosaurs: \t" << dinoArray[i].expense.num_hours << endl;
			cout << "Cost Per Hour of Taking Care of Dinosaur: \t" << dinoArray[i].expense.cost_taking_care << endl;
			cout << "Cost to Feed Dinosaur: \t" << dinoArray[i].expense.cost_of_food << endl;
			cout << "Grooming and Supplies Cost: \t" << dinoArray[i].expense.cost_of_materials << endl;
		}
		cout << endl;
	}
	
	else if (choice ==2){
		//print instruction and allow user to enter the output file name
		cout << "What is the name of your file you wish to write to? " << endl;
		cout <<"FILENAME: ";
		cin >> output_file;
		
		outFS.open(output_file.c_str()); //open the output file 
		
		outFS << string(50, '-') << endl;
		
		//loop to print out all the dinosaurs information into a file
		for (int i =0; i < numDino; i++){
			outFS << "\nDINOSAUR " << i+1 << ": " << endl;
			outFS << "Name: \t" << dinoArray[i].name << endl;
			outFS << "Description: " << endl;
			outFS << "\t" << wrap_text(dinoArray[i].description) << endl;
			outFS << "\nLength: \t" << dinoArray[i].average_length << endl;
			outFS << "Height: \t" << dinoArray[i].average_height << endl;
			outFS << "Location: \t" << dinoArray[i].location << endl;
		
			if (dinoArray[i].dangerous == true)
				outFS << "Dangerous? \t yes" << endl;
			else 
				outFS << "Dangerous? \t no" << endl;
			outFS << "Number of Hours to Care of Dinosaurs: \t" << dinoArray[i].expense.num_hours << endl;
			outFS << "Cost Per Hour of Taking Care of Dinosaur: \t" << dinoArray[i].expense.cost_taking_care << endl;
			outFS << "Cost to Feed Dinosaur: \t" << dinoArray[i].expense.cost_of_food << endl;
			outFS << "Grooming and Supplies Cost: \t" << dinoArray[i].expense.cost_of_materials << endl;
		}
		cout << "\nYour dinosaurs have been entered into " << output_file << "." << endl;
		outFS.close();
	}
}

//define wrap text file with dinoDescription as a parameter
string wrap_text(string dinoDescription){
	size_t line_length = 100; //variable for how long each line will be
	istringstream words(dinoDescription); //string input
	ostringstream wrapped;	//string output
    string word;
 
    if (words >> word) {
        wrapped << word;
        size_t space_left = line_length - word.length();
		/*loop for each word, if it reaches the end of the line,
		the word will be move to the next line with a tab indent*/ 
        while (words >> word) {
            if (space_left < word.length() + 1) {
                wrapped << "\n\t" << word;
                space_left = line_length - word.length();
            } 
			
			else {
                wrapped << ' ' << word;
                space_left -= word.length() + 1;
            }
        }
    }
    return wrapped.str();
	
}

//define printStatistics function with dinoArray and numDino as parameter
void printStatistics(Dinosaurs dinoArray[], int numDino){
	float cost; //variable to calculate the cost of each dinosaur
	float total_cost=0; //variable to calculate the cost of every dinosaurs
	
	cout << setprecision(2) << fixed;
	cout << "\nCOST OF EACH DINOSAUR FOR ONE WEEK: " << endl << endl;
	cout << setw(20) << left << "DINOSAUR" << setw(20) << right << "COST" << endl;
	//loop to calculate the cost
	for (int i = 0; i <numDino; i++){
		cost = dinoArray[i].expense.num_hours*dinoArray[i].expense.cost_taking_care+dinoArray[i].expense.cost_of_food+dinoArray[i].expense.cost_of_materials;
		cout << setw(20) << left << dinoArray[i].name << "$" << setw(19) << right << cost << endl;
		total_cost+=cost;
	}
	cout << endl << setw(20) << left << "TOTAL COST: "  << "$" << setw(19) << right << total_cost; 
}

//define saveDinosaursToFile function with dinoArray and numDino as parameter
void saveDinosaursToFile(Dinosaurs dinoArray[], int numDino) {
	ofstream outFS; //for output file
	string output_file; //variable for name of the file
	
	//print instruction and allow user to enter the output file name
	cout << "What is the name of your file you wish to write to? " << endl;
	cout <<"FILENAME: ";
	cin >> output_file;
		
	outFS.open(output_file.c_str()); //open the output file 
	
	//loop to print out the information, separate by #
	for (int i =0; i < numDino; i++){
		outFS << dinoArray[i].name << "#" << dinoArray[i].description << "#" << dinoArray[i].average_length; 
		outFS << "#" << dinoArray[i].average_height << "#" << dinoArray[i].location << "#";
		
		if (dinoArray[i].dangerous == true)
			outFS << "1#";
		else 
			outFS << "0#";
		outFS << dinoArray[i].expense.num_hours << "#" << dinoArray[i].expense.cost_taking_care;
		outFS << "#" << dinoArray[i].expense.cost_of_food << "#" << dinoArray[i].expense.cost_of_materials << "#";
	}
	cout << "\nYour dinosaurs were successfully saved to " << output_file << "." << endl;
	outFS.close();
}