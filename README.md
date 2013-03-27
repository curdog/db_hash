CSC 328 – Program 3

Due:	Wednesday April 10, 10 minutes before class starts

Write a program to simulate a database (write a database class) implemented via open-address hashing with linear probing.  Your program should initially fill the database by reading records from a file.  Your program should then allow the user to interactively add, delete, or search for records.  The user should also be allowed to display all data, neatly formatted.  Show every array slot when displaying all data!  The file has been checked and is filled with good data.  Interactive data needs to be checked.  Use an array size (hash table size) of 19.

The layout of the file is (on separate lines):
1. ID Number (this is the key, up to 4 digits)
2. Name (up to 25 characters)
3. Age (18 – 120)

What to submit:
Submit source code via email.  If you are absent, it is still your responsibility to submit on time.  Put group members’ last names in the subject line.

Keep in mind the following:
Name your source files db.h, db.cpp, and main.cpp.
With invalid data, your program should respond appropriately.
Each function prototype should have a description, preconditions, and postconditions.
Test your code when you think you are finished.  Try to break it.  After you are done trying to break it, I will then try.

Good Luck!  Remember, questions are encouraged.  