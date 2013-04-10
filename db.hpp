#ifndef _DB_HW3
#define _DB_HW3

#include <string>
#include <iostream>
#include <fstream>


using namespace std;

class Person{
public:
	Person( int, string, short int );
	Person();
	
	int getID();
	string getName();
	short int getAge();
	
	friend istream& operator>>( istream& ins,  Person& obj );
	friend ostream& operator<<( ostream& outs, Person obj );
	
private:
  int ID;
  string name;
  short int age;
};


class Db{
public:
  Db( const string&);
  ~Db();
	int hash(  Person& ) const;
  int add( Person );
  int rm ( Person );
  Person& find( int );
  int save();


private:
  static const int EMPTY = 0;
  static const int USED = 2;
  static const int PREV_USED = 1;
	
	static const int SIZE = 19;
  const Person NO_PERSON;
	
	ifstream db_read;
	ofstream db_write;
  Person array[19];
  short int status[SIZE];
};

#endif
