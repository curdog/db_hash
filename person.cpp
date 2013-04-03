#include "person.hpp"
#include <string.h>

Person::Person( int id, char* name, short int age ){
	this->ID = id;
	strncpy( name, this->name, 25 );
	this->age = age;
	
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