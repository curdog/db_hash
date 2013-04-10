#include "db.hpp"
#include "person.hpp"
#include <fstream>
#include <iostream>

using namespace std;

Db::Db( const string &file_name ){
	//open file
	db_read.open( file_name.c_str() );
	
	for (int i; i < 19; i++) {
		status[i] = (short int )EMPTY;
	}
	
	if (db_read.is_open()) {
		Person temp;
		while (!db_read.eof()) {
			db_read >> temp;
			array[ hash( temp ) % SIZE ] = temp;
			status[ hash(temp) % SIZE ] = USED;
			if (db_read.eof()) {
				break;
			}
		}
	}
	
}

Db::~Db(){
	db_write.flush();
	db_read.close();
	db_write.close();
	
}

int Db::hash(  Person& addMe ) const{
	return addMe.getID();
}

int Db::add( Person addMe ){
	//linear probing
	for (int i = 0; i < 19 ; i++) {
		if (status[hash(addMe) % SIZE] <= PREV_USED) {
			status[hash(addMe) % SIZE] = USED;
			array[hash(addMe) % SIZE] = addMe;
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
		if (status[hash(rmMe) % SIZE + i] == USED && rmMe.getID() == array[ hash(rmMe) % SIZE + i ].getID() ) {
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
		if (status[hash_id % SIZE + i] == USED && hash_id == array[ hash_id % SIZE + i ].getID() ) {
			return array[ hash_id % SIZE + i];
		} 
	}
	
	cerr << "Cannot find " << hash_id << endl;
	return const_cast<Person&>(NO_PERSON);
}

int Db::save(){
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
