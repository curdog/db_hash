#ifndef _DB_HW3
#define _DB_HW3

#include <string>
#include <iostream>
#include <fstream>

#include "person.hpp"

using namespace std;

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
