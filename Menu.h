#ifndef MENU_H
#define MENU_H

#include "Database.h"
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>


// inherits from Database
class Menu{

friend class Book;
friend class Database;
private:
	
	Database current; // this is the book database
	Database results; // temporary database for searching

public:
	Menu();
	void display_options();
	void handle_options(int a);
	void input_error_handling();
	void change_fields_display();
	void display_sorts();
	void display_complex_searches();
	void display_simple_searches();
	Book input_book_handler();
	void display_database();
	void change_fields(int index_of_book, int field_number);
	
	
};

#endif