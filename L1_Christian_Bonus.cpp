// Author:				Jacob Christian
// Assignment Number:   Lab 1
// File Name:			L1_Chrisitan.cpp 
// Course/Section:      COSC 1337 Section 014
// Date:                Sept 14th, 2018
// Instructor:          Dr. Bernard Ku	

/*
STRUCTURE CHART:
1.0 INPUT
	1.1 Use a loop to prompt the user for a runner's name
	1.2 Validate the name is only characters or spaces
	1.3 Use saem loop to prompt the user for the same runner's time
	1.4 Validate the time is a float and is greater than zero
2.0 PROCESSING
	2.1 Run a bubble sort to verify which time was first
	2.2 When time found that needs to be swapped, swap name array as well
	2.3 Check the length of each index of the name array, find the longest name,
		and use that for the set-width modifer for pretty output.
3.0 OUTPUT
	3.1 Set up iomanipulator to set a width based on the longest name
	3.2 Set each with the same for nice formatting
	3.3 Display results
*/




//Preprocessor Directives
#include <iostream>		//Input and Output
#include <iomanip>		//To manipulate the output for formatting
#include <cctype>		//To compare characters and digits to validate input
#include <string>		//To accept string variable types

//Declaring namespace to ease typing
using namespace std;

//Functions to validate user input
bool  name_check (string);
bool  time_check(double);


int main()
{
	/* VARIABLE INITIALIZATION */

	//Global variable for all arrays
	const int ITERATION = 3;
		   
	//Initialize arrays for sorting
	string names[ITERATION];
	double times[ITERATION];     
	string place_names[ITERATION] = {"1st", "2nd", "3rd"};
		
	//For pretty formatting at the output. 
	unsigned int longest_name = 0;		//Note, compiler didn't like that it wasn't unsigned in comparison. Changed to appease comipler.
		
	//Opening message explaining process
	cout << "Enter the name of three runners and their finishing times (in seconds)." << endl;
	cout << "Then, I will tell you who came in first, second, and third.\n" << endl;
	
	//Loop to get user input
	for (int i = 0; i < ITERATION; i++)
		{
		cout << "Enter the name of the " << place_names[i] << " Runner: ";
		getline(cin, names[i]);
		if (!name_check(names[i]))
			{
			cout << "Improper character entered, please try again";
			return 0;
			}
		cout << "Enter " << names[i] << "'s run-time: ";
		cin >> times[i];
		cin.ignore();
		
		if (!time_check(times[i]))
			{	
			cout << "Please enter a valid run-time (cannot be less than zero)" ;
			return 0;
			}
		}

	//Bubble sort to sort through the values
	
	//Variables for bubble check below
	bool   sortFlag;				
	double tempTime;
	string tempName;		
	do
	{
		sortFlag = false;
		for (int count = 0; count < ITERATION -1; count++)
		{
			if (times[count] > times[count+1])
			{
				//Swapping run-time numbers 
				tempTime         = times[count];
				times[count]     = times[count+1];
				times[count + 1] = tempTime;
				
				//Swapping nameplaces to match run-times
				tempName         = names[count];
				names[count]     = names[count + 1];
				names[count + 1] = tempName;
				
				//Set boolean flag to true to run through while loop again 
				sortFlag = true;
			}
		}
	} while (sortFlag);
	
	//Checks for the longest string, then sets the formatting length to that name.
	for (int i = 0; i < ITERATION; i++)
		{
			if(names[i].length() > longest_name)
				longest_name = names[i].length(); 
		}
	
	//Return Results
	cout << endl << "\tRace Results:\n" << "\t-------------";
	//Setting up final output
	cout << fixed << showpoint << setprecision(2) << endl;
	for (int i = 0; i < ITERATION; i++)
		{
			cout << left << setw(3) << place_names[i] <<": "<< left << setw(longest_name + 3) << names[i] + " "<< right << setw(5) << times[i] << " seconds" << endl;
		}
	return 0;
}


//Function to check if character is valid or not
bool name_check(string runner_name)
{
	bool notAlpha = false;
	
	//For loop to iterate over the string to check for either characters or space
	for (unsigned int i = 0; i < runner_name.length(); i++) 
	{
		if(!(isalpha(runner_name[i]) || isspace(runner_name[i])))
		{
			notAlpha = true;
			break;
		}
	}
	//Conditional terny operator to return true or false
	return notAlpha ? false : true;

}

//Function to check if floating nubmer is valid or not
bool time_check(double run_time)
{
	//Conditional terny operator to return true or false
	return (run_time < 0 || cin.fail()) ? false : true; //cin.fail() will check if it's entered as a double, or at least a digit.
}


/*
												FINAL THOUGHTS
	1) I didn't have enough time to get the second extra credit done, although I think I know how I would approach it.
		a) I would've had a function pass in two arrays as an argument. However C++ doesn't allow a function to return
		   more than one value like Python can, but a void function with reference values were an option. I didn't have 
		   time, as I just read about them on the Thursday before it was due.
		b) I would do a loop to look through each array. If the values of the times were equal, then I would change the 
		   array with the first, second, and third place values, to copy each other, depending on the time placement.
	2) I wanted to put the bubble sort into a function for easier readability and to lessen the main() function's length.
	   Once again, this could be accomplished by passing refernce to the array itself (I think)?
	3) I'm not sure if conditional terny operators are kosher for return values, but I could do it and I wanted to practice them.
	   If you can, please let me know if this is too confusing to do. But it felt like list comprehension in Python, and doesn't
	   seem too confusing.
	4) I know we haven't covered some of these concepts yet, but it certainly made the code easier to write :)
*/


/*

		OUTPUTS (Including failsafe tests)
												
			  ---------------------------
			  |	   SUCCESSFUL OUTPUT    |
			  --------------------------
	Enter the name of three runners and their finishing times.
	Then, I will tell you who came in first, second, and third.
	
	Enter the name of the 1st Runner: Jacob Christian
	Enter Jacob Christian's run-time: 13.22
	Enter the name of the 2nd Runner: Kathryn DeBusk
	Enter Kathryn DeBusk's run-time: 9.98
	Enter the name of the 3rd Runner: Bernie Ku
	Enter Bernie Ku's run-time: 11.12

    	    Race Results:
        	-------------
	1st: Kathryn DeBusk    9.98 seconds
	2nd: Bernie Ku        11.12 seconds
	3rd: Jacob Christian  13.22 seconds
****************************************************************
			  ---------------------------
			  |	WON'T ACCEPT VALUES < 1 |
			  --------------------------	
	Enter the name of three runners and their finishing times.
	Then, I will tell you who came in first, second, and third.

	Enter the name of the 1st Runner: Jacob Christian
	Enter Jacob Christian's run-time: 13.44
	Enter the name of the 2nd Runner: Kathryn DeBusk
	Enter Kathryn DeBusk's run-time: 5.44
	Enter the name of the 3rd Runner: Bernie Ku
	Enter Bernie Ku's run-time: -44.55
	Please enter a valid run-time (cannot be less than zero)
****************************************************************
			
			   ---------------------------
			  |	WONT ACCEPT INVALID CHAR |
			   --------------------------
	Enter the name of three runners and their finishing times.
	Then, I will tell you who came in first, second, and third.

Enter the name of the 1st Runner: Jay Striker
Enter Jay Striker's run-time: 11.22
Enter the name of the 2nd Runner: Anna bo banna fo fanna da danna
Enter Anna bo banna fo fanna da danna's run-time: 41.41
Enter the name of the 3rd Runner: OMG111112319381290312839012
Improper character entered, please try again
*****************************************************************

			  ---------------------------
			  |	WON'T ACCEPT NONNUMERIC |
			  --------------------------	
	Enter the name of three runners and their finishing times.
	Then, I will tell you who came in first, second, and third.

	Enter the name of the 1st Runner: I can take any character as long as its A to Z
	Enter I can take any character as long as its A to Z's run-time: 1
	Enter the name of the 2nd Runner: The format will print according to the longest name
	Enter The format will print according to the longest name's run-time: 2
	Enter the name of the 3rd Runner: I wish I could have done the extra credit
	Enter I wish I could have done the extra credit's run-time: BOO
	Please enter a valid run-time (cannot be less than zero)
*/	
