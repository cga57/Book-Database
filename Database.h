// Database.h
#ifndef DATABASE_H
#define DATABASE_H

#include "Book.h"
#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>


class Database {

	friend class Menu;
	
private:
	vector<Book> database; // this is vector that stores the database of books
	// Note: vector default is empty - member initialization

public:
	Database();
	int search(Book a); // searches for book 
	void display_database();
	vector<Book> search_by_field(int n);
	vector<Book> search_by_field(int field_num, string s);
	void sort_by_field(int field_num);

};
inline bool operator==(Book const &a, Book const &b);

#endif

