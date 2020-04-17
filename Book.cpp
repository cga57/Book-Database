#include "cmpt_error.h"
#include <iostream>
#include <string>
#include <vector>
#include "Database.h"
#include "Menu.h"
#include "Book.h"

// Constructor and getters
Book::Book(string title,string author, string date,string book_type,string isbn, int pages)
	: title(title), author(author), pages(pages), date(date), book_type(book_type),isbn(isbn){

}
Book::Book(){}

string Book::get_title() const{ return title;}
string Book::get_author() const{return author;}
int Book::get_pages() const{return pages;}
string Book::get_date() const{return date;}
string Book::get_type() const{return book_type;}
string Book::get_isbn() const{return isbn;}
// Note: You can use get_book_type or get_type
// Both do the same thing
string Book::get_book_type() const{return book_type;}

void Book::set_title(string &s){title = s;}
void Book::set_author(string &s) {author = s;}
void Book::set_pages(int new_pages) {pages = new_pages;}
void Book::set_date(string &s){date = s;}
void Book::set_book_type(string &s){book_type = s;}
void Book::set_isbn(string &s){isbn = s;}

// the cout version
void Book::to_str(){
	
	string s;
	s.append("[");
	s.append(title + ",");
	s.append(author + ",");
	s.append(book_type + ",");
	s.append(date + ",");
	s.append(isbn + ",");
	s.append(to_string(pages) + "]");
	cout << s << endl;


}
// the return string version
// same as above function but returns the 
// string instead of printing it
string Book::to_str_converted(){
	
	string s;
	s.append("[");
	s.append(title + ",");
	s.append(author + ",");
	s.append(book_type + ",");
	s.append(date + ",");
	s.append(isbn + ",");
	s.append(to_string(pages) + "]");
	return s;


}





