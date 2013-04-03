#ifndef _DB_PERSONHW3
#define _DB_PERSONHW3

class Person{
public:
	Person( int, char*, short int );
	
	int getID();
	char* getName();
	short int getAge();
	
private:
  int ID;
  char name[25];
  short int age;
};

#endif
