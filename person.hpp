#ifndef _DB_PERSONHW3
#define _DB_PERSONHW3

#include <iostream>

using namespace std;
class Person;

class Person{
public:
	Person( int, char*, short int );
	Person();
	
	int getID();
	char* getName();
	short int getAge();
	
	friend istream& operator>>( istream& ins,  Person& obj );
	friend ostream& operator<<( ostream& outs, Person obj );
	
private:
  int ID;
  char name[25];
  short int age;
};

#endif
