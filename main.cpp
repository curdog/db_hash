#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>


#include "db.hpp"

/*function that displays a formatted function*/
void printMenu();

/*decalring variables*/
Db test("input.txt");

int main( int argc, char** argv )
{

	//process loop
	printMenu();
	
#ifdef _WIN32
	system("PAUSE");
#endif
	
	return 0;
}


void printMenu()
{
	int tempID;
	char tempName[25];
	int num;
	int tempAge;
	
	int input;
	do{
		cout << "Database Simulation" << endl;
		cout << "Menu Options" << endl;
		cout << "1. Add a new record" << endl;
		cout << "2. Delete an existing record" << endl;
		cout << "3. Search through the database" << endl;
		cout << "4. Save the database" << endl;
		cout << "5. Exit" << endl;
		cout << "Please enter a number 1-5: ";
		
		/*error checking*/
		while(!(cin >> input) || cin.peek() != '\n' || input < 1 || input > 5)
		{
			cout << endl << "Please choose one of the available options: ";
			cin.clear();                                    
			cin.ignore(30000, '\n'); 
		}
		
		/*choice 1 was selected*/
		
		if(input == 1)
		{
			cout << endl << "Enter the new ID number: ";
			/*error checking*/
			while(!(cin >> num) || cin.peek() != '\n' || num <= 0 || num >= 9999)
			{
				cout << endl << "Enter a positive ID number, no longer than four digits: ";
				cin.clear();
				cin.ignore(30000, '\n');
			}
			tempID = num;	
			
			cout << endl << "Enter the new name(max 25 chars): ";
			/*error checking*/
			
			cin >> tempName;
			                         
			cout << endl << "Enter the NEW age: ";
			/*error checking*/
			while(!(cin >> num) || cin.peek() != '\n' || num < 18 || num > 120)
			{
				cout << endl << "Enter an age from 18 - 120: ";
				cin.ignore(30000, '\n');
				cin.clear();
			}                       
			tempAge = num;          
			test.add( Person(tempID, tempName, tempAge)); 
			
		} /*ends the if, for choice 1*/
		
		/*the user selected choice 2*/
		if(input == 2)
		{
			cout << endl << "Enter the record's ID number that you want to delete: ";
			/*error checking*/
			while(!(cin >> num) || cin.peek() != '\n' || num < 0 || num > 9999)
			{
				cout << endl << "Enter a positive ID number up to four digits: ";
				cin.clear();                                    
				cin.ignore(30000, '\n'); 
			}
			cout << test.find(num);
			test.rm( test.find(num) );
			cout<<"The record was deleted."<< endl;
		}
		
		
		/*the user selected choice 3*/
		if (input == 3)
		{
			cout << endl << "Enter the record's ID number that you would like to search for: ";
			/*error checking*/
			while(!(cin >> num) || cin.peek() != '\n' || num < 0 || num > 9999)
			{
				cout << endl << "Enter a positive ID number up to four digits: ";
				cin.clear();                                    
				cin.ignore(30000, '\n'); 
			}    
			if (test.find(num).getID() == -1)
			{
				cout << "Error: That record does not exist." << endl;
			}
			else
				cout << test.find(num); 
		}
	
	
	/*the user selected choice 4*/
	if (input == 4)
	{
		if( !test.save() ){
			cout << "There was an error saving" << endl;
		}
	}
	
} while (input != 5);
/*program terminates*/

}
