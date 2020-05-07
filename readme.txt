Full name: Chirag Gupta



Compilation Instructions
------------------------

// A precise, step-by-step, description of how to compile your program
// that the marker can cut-and-paste from to compile your program.

- Make sure to put the zip file in the same folder
- Type make test in the command terminal
- Then type in ./test
- incase of any errors (SHOULD NOT OCCUR), do make clean first, then make test

(FOR COPY AND PASTING - EASE OF USE):
make test
./test


Running Instructions
--------------------
***IMPORTANT:
- Press 9 to terminate program
-TYPE STRINGS IN LOWER CASE AS DECRIBED IN THE MENU FOR EASE OF USE
(EXCEPTION IS FOR FILE HANDLING. ANY CASE WORKS FOR THAT)
- The database by default INCLUDES ONE SAMPLE BOOK
- YOU SHOULD USE OPTION LOAD DATABASE ON book_data.txt to LOAD THAT DATABASE INTO THE PROGRAM. THIS DATABASE IS PUT IN THE CORRECT FORMAT (Identical to Dr.Donaldson's inclass code for random generation for help in the project)
- Marker may load in their own file as long as it follows the identical format as created by Toby Donaldson in the ranom generation C++ file. 
- TO EXIT THE PROGRAM PRESS 9

// Other Details

- As the program runs and you will be driven into a menu in which 
you can choose 9 different options by pressing the corresponding number key

- Each of these 9 different options implements one of the key feautures or bonus features

- There are seperate menus for choosing in some of the features
- The secondary menus also contain numeric digits which you can press to select 





Key Features
------------

My PERSONAL COMPLEX SEARCHES:
1. Search for books with a minimim of 200 pages
2. Search for books with a maximum of 200 pages
3. Search for older books (data < 1980)
4. Search for modern books(data > 1980)
5. A special and complex Editor's choice books feature
// Note: DETAILS on #5 is given under bonus features

ALL CRITERIA BELOW IMPLEMENTED:

// In Criteria Features - 

    Add a new book record.
    Delete an existing record.
    Update any field of a book record, e.g. the user might want to change the date of publication of a book.
    Search for book records by any field; the resulting books should be sorted in whatever order the user wants.
        Allow for both simple searches, e.g. all books with date=2005. Your program should let the user search for any book record whose field is equal to a value given by the user.
        Some searches can be more complex, e.g. all books from the 1990s with at least 200 pages not written by JK Rowling. Include as many complex searches as possible.
        Allow the user to sort the results by name, or by date, or by number of pages, etc.
        Searching and sorting features of this program could be quite sophisticated, and you should make them as useful an efficient as possible.
    Save the database to a text file, and load a database from a text file.
        You must design the format of this text file! You could, for instance, store every book record on one line of the file as a string of fields.

Bonus Features

ALL BONUS FEATURES OUR UNDER THE COMPLEX SEARCHES MENU

Description: I have a bonus feature which searches
for the editors choice of books. This is determined by  checking if the title of the books have a string that is made 
of the addition of two randomly determined characters (during runtime). If they do, it is put inside the Editor's list

// This else will augment a special selection to determine
// the editors choice books
// How this algorithm works:
// Two characters are randomely chosen by manipulating rand
// Then the title is searched to see if it has those
// two characters or not


Bugs and Limitations
--------------------

Limitation: The file you wish to LOAD should be IN THE SAME FOLDER AS THIS PROGRAM. 

Limitation#2: All strings typed in for input in menu interface must be in lower case for program to run smoothly (except for file names and FILE DATA - those can be in case). Note: This limitation is DONE ON PURPOSE as I saw no necessity in allowing the user to type upper case strings. For loading files however, this has been taken care of by using the built in C++ transform function

**IMPORTANT*** MY Testing: I have rigirously tested this program both manually by using cout and have also used cmpt::error to handle grey/unacceptable cases. Though I have generally avoided keeping the use of cpt::error as it crashes the program and that is bad. 

- You will see my testing comments throughout the code
- The cout statements that were used for testing
- ARE NOW ALL COMMENTED OUT, you can still see them when you inspect my code


All People, Websites, and Sources of Help
-----------------------------------------

// List all people, websites, books, chats, apps, etc. that you used for
- Class Notes
- Dr.Donaldson's (professor's) random_generator for book database is included in this file (he created this file to assist us with this project)
- Discussed Problems in a High level manner with classmate:
William Tjandra
- Used this stackoverflow answer by Treycos (First answer)
to help me handle invalid input by user using cin.fail()
Link: https://stackoverflow.com/questions/39861205/beginner-c-protecting-against-invalid-input-with-cin-fail

- For help on splitting a string (acting as a reference)
Link:http://www.martinbroadhurst.com/how-to-split-a-string-in-c.html

- For help on generating random characters (used for a personally created complex search function): I Used AbstractionAnon's Answer (At Bottom):
Link: http://www.cplusplus.com/forum/general/130902/

- Learning about the transform function for converting strings to lower case. Answer by ereOn:
Link: https://stackoverflow.com/questions/3403844/tolower-function-for-c-strings

-My C++ Reference/Documentation: http://www.cplusplus.com
