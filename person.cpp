#include "person.hpp"
#include <string.h>
#include <iostream>

using namespace std;

Person::Person( int id, char* name, short int age ){
	//enforce limits by cheating ;-)
	this->ID = (unsigned int)id % 10000;
	strncpy( name, this->name, 25 );
	this->age = (unsigned int )age % 121;
	
}

Person::Person( ){
	ID = -1;
	age = -1;
	memset(name, '\0', 25);
}
int Person::getID(){
	return ID;
}

char* Person::getName(){
	return name;
}

short int Person::getAge(){
	return age;
}

istream& operator>>( istream& ins, Person& obj ){
	ins >> obj.ID;
	ins.getline( obj.name, 25, '\n' );
	
	ins >> obj.age;
	
	return ins;
}

ostream& operator<<( ostream& outs, Person obj ){
  outs << obj.ID << '\n';
	outs << obj.name << '\n';
	outs << obj.age << '\n';
	return outs;
}