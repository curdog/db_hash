#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "person.hpp"
#include "db.hpp"

/*function that displays a formatted function*/
void printMenu();

/*decalring variables*/
Database test;
int tempID;
int tempName;
int num;
int num2;
int tempAge;

int main( int argc, char** argv )
{
//Open the input txt file	
ifstream inFile("input.txt");   
	if (inFile.is_open())
	{
	   //While loop
	   while (inFile.good())  
		{
	       //get info
	       inFile >> tID;       
	inFile >> tName;                    
	inFile >> tAge;                    
	      	}
	//Close input file
	inFile.close();                         
	}

printMenu();
	return 0;
}
	  

void printMenu()
{
	cout << "Database Simulation" << endl;
	cout << "Menu Options" << endl;
	cout << "1. Add a new record" << endl;
	cout << "2. Delete an existing record" << endl;
	cout << "3. Search through the database" << endl;
	cout << "4. Display the database" << endl;
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
	while(!(cin >> num) || cin.peek() != '\n' || num < 0 || num > 9999)
	{
		cout << endl << Enter a positive ID number, no longer than four digits: ;
		cin.clear();
		cin.ignore(30000, '/n');
	}
	tempID = num;	
	
	cout << endl << "Enter the new name: ";
	/*error checking*/
	while(!(cin >> num2) || cin.peek() != '\n')
	{
		cout << endl << "Enter a positive ID number up to four digits: ";
		cin.clear();                                    
		cin.ignore(30000, '\n'); 
	}         
	            tempName = num2;
	            
	cout << endl << "Enter the NEW age: ";
	/*error checking*/
	while(!(cin >> num) || cin.peek() != '\n' || num < 18 || value > 125)
	{
	 cout << endl << "Enter an age from 18 - 120: ";
	 cin.clear();                                    
	 cin.ignore(30000, '\n'); 
	 }                       
	 tempAge = num;          
	 test.put(tempID, tempName, tempAge); 

} /*ends the if, for choice 1*/

/*the user selected choice 2*/
if(input == 2)
{
	cout << endl << "Enter the record's ID number that you want to delete: "
	/*error checking*/
	while(!(cin >> num) || cin.peek() != '\n' || num < 0 || num > 9999)
	{
	cout << endl << "Enter a positive ID number up to four digits: ";
	cin.clear();                                    
	cin.ignore(30000, '\n'); 
	}
	test.printInfo(num);
	test.remove(value);
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
	if (test.getID(value) == -1)
	{
 	cout << "Error: That record does not exist." << endl;
      	}
      	else
    	test.printInfo(num); 
        }
}

/*the user selected choice 4*/
if (input == 4)
{
   test.printInfo(1);
}
                
} while (input != 5);
/*program terminates*/
                        
                        
	
	
#ifdef _WIN32
	system("PAUSE");
#endif
	
	return 0;
	
}
