// Book.h
#ifndef BOOK_H
#define BOOK_H

#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Book{

	friend class Database;
	
private:
	string title = "";
	string author = "";
	int pages = 1; // number of pages
	string date = "";
	string book_type = "";
	string isbn = ""; // storing as a isbn so far - possibly as a constant
public:
	
	Book(string title,string author, string date, string book_type, string isbn, int pages);
	Book();
	//  simple getters
	string get_title() const;
	string get_author() const;
	int get_pages() const;
	string get_date() const;
	string get_type() const;
	string get_isbn() const;
	string get_book_type() const;
	// setters
	void set_title(string &s);
	void set_author(string &s);
	void set_pages(int new_pages);
	void set_date(string &s);
	void set_book_type(string &s);
	void set_isbn(string &s);




	void to_str();
	string to_str_converted();
	// slightly more complicated setters

};





#endif