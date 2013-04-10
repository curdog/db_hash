#include "db.hpp"
#include <fstream>
#include <iostream>

#define MEM_ONLYN

using namespace std;

//Person imp

Person::Person( int id, string name, short int age ){
	//enforce limits by cheating ;-)
	this->ID = (unsigned int)id % 10000;
	this->name = name;
	this->age = (unsigned int )age % 121;
	
}

Person::Person( ){
	ID = -1;
	age = -1;
	name = "\0";
}
int Person::getID(){
	return ID;
}

string Person::getName(){
	return name;
}

short int Person::getAge(){
	return age;
}

istream& operator>>( istream& ins, Person& obj ){
	ins >> obj.ID;
	ins.get();
	getline(ins,obj.name);
	//ins.getline( obj.name, 25, '\n' );
	
	ins >> obj.age;
	
	return ins;
}

ostream& operator<<( ostream& outs, Person obj ){
  outs << obj.ID << '\n';
	outs << obj.name << '\n';
	outs << obj.age << '\n';
	return outs;
}

//begin DB implementation

Db::Db( const string &file_name ){
	//open file

	
	
	for (int i; i < 19; i++) {
		status[i] = EMPTY;
	}
	
	db_read.open( file_name.c_str() );
#ifndef MEM_ONLY
	if (db_read.is_open()) {
		Person temp;
		
		//read from file
		while (!db_read.eof()) {
			db_read >> temp;
			add( temp );
			if (db_read.eof()) {
				break;
			}
		}
	}
#endif
	
}

Db::~Db(){
	//flush and close open files
#ifndef MEM_ONLY
	db_write.flush();
	db_read.close();
	db_write.close();
#endif
	
}

int Db::hash(  Person& addMe ) const{
	return addMe.getID();
}

int Db::add( Person addMe ){
	//linear probing
	for (int i = 0; i < 19 ; i++) {
		if (status[(hash(addMe) + i) % SIZE ] < USED) {
			status[(hash(addMe) + i) % SIZE ] = USED;
			array[(hash(addMe) % SIZE + i)] = addMe;
			return 0;
		} 
	}
	//did not find a location, full?
	cerr << "Full hash table" << endl;
	return 1;
}

int Db::rm ( Person rmMe ){
	//linear probing
	for (int i = 0; i < 19 ; i++) {
		//check USED also Person.getID is same
		if ( (status[hash(rmMe) % SIZE + i] == USED ) && (rmMe.getID() == array[ hash(rmMe) % SIZE + i ].getID() ) ) {
			status[hash(rmMe) % SIZE +i] = PREV_USED;
			return 0;
		} 
	}
	
	cerr << "Cannnot remove what isn't there" << endl;
	return 1;
}

Person& Db::find( int hash_id ){
	for (int i = 0; i < 19 ; i++) {
		//check USED also Person.getID is same
		if ( (status[hash_id % SIZE + i] == USED) && (hash_id == array[ hash_id % SIZE + i ].getID() ) ) {
			return array[ hash_id % SIZE + i];
		} 
	}
	
	cerr << "Cannot find " << hash_id << endl;
	return const_cast<Person&>(NO_PERSON);
}

int Db::save(){
	//save, use trunc to clear file for deletes and write what we got.
	db_write.open("input.txt", ios_base::trunc);
	if (!db_write.is_open()) {
		return 1;
	}
	for (int i = 0; i < SIZE; i++) {
		if (status[i] == USED) {
			db_write << array[i];
		}
	}
	return 0;
	
}
