#ifndef _DB_HW3
#define _DB_HW3

#include "person.hpp"
class Db{
public:
  Db( const string);
  ~Db();
  int add( Person );
  int rm ( Person );
  Person find( int );
  int save();

protected:
  void reStatus();

private:
  static const int EMPTY = 0;
  static const int USED = 1;
  static const int PREV_USED = 2;

  Person array[19];
  short int status[19];
};

#endif
