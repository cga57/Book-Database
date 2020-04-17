
#include "Database.h"
using namespace std;

inline bool operator==(Book const &a, Book const &b){
	if(a.get_title() == b.get_title() || 
	   a.get_author() == b.get_author() ||
	   a.get_date() == b.get_date() ||
	   a.get_book_type() == b.get_book_type() ||
	   a.get_isbn() == b.get_isbn() ||
	   a.get_pages() == b.get_pages()
	  ){
		return true;
	}
	return false;
}

// Database is initialized with one sample book
// in default constructor
Database::Database(){
	Book sample("Harry", "Bob", "2","softcover","1111111111",100);
	database.push_back(sample);
}

// searches for the book in the vector
int Database::search(Book target){
	
	for(int i = 0; i < database.size(); i++){
		if(target == database[i]){
			return i;
		}
	}
	// if book not found
	
	cmpt::error("Invalid index in Menu search");
	return -1;
}

void Database::display_database() {

	for(int i = 0; i < database.size(); i++){
		database[i].to_str();
		cout << endl;
	}

}

// Note method is overloaded to deal with both ints and strings
// Note: U can add the sorts to these functions once implemented
vector<Book> Database::search_by_field(int n){
	vector<Book> results;
	for(int i = 0; i < database.size(); i++){
		if(n == database[i].get_pages()){
			results.push_back(database[i]);
		}
	}

	return results;
}
// note: Linear search proved to be fastest
// Due to no sorting required

vector<Book> Database::search_by_field(int field_num, string s){

	vector<Book> results;
	if(field_num == 1){
		for(int i = 0; i < database.size(); i++){
			if(s == database[i].get_title()){
				results.push_back(database[i]);
			}
		}
	}
	else if(field_num == 2){
		for(int i = 0; i < database.size(); i++){
			if(s == database[i].get_author()){
				results.push_back(database[i]);
			}
		}
	}
	else if(field_num == 3){
		for(int i = 0; i < database.size(); i++){
			if(s == database[i].get_date()){
				results.push_back(database[i]);
			}
		}
	} else if(field_num == 4){
		for(int i = 0; i < database.size(); i++){
			if(s == database[i].get_book_type()){
				results.push_back(database[i]);
			}
		}

	} else{
		for(int i = 0; i < database.size(); i++){
			if(s == database[i].get_isbn()){
				results.push_back(database[i]);
			}
		}

	}
	return results;

}


// These boolean functions will be accepted
// as a third parameter for C++ sort func.
// As per documentation  (mentioned in works sited which documentation I used)
bool sort_by_title(const Book &a, const Book &b){
	return a.get_title() < b.get_title();
}
bool sort_by_author(const Book &a, const Book &b){
	return a.get_author() < b.get_author();
}
bool sort_by_date(const Book &a, const Book &b){
	return a.get_date() < b.get_date();
}
bool sort_by_book_type(const Book &a, const Book &b){
	return a.get_book_type() < b.get_book_type();
}
bool sort_by_isbn(const Book &a, const Book &b){
	return a.get_isbn() < b.get_isbn();
}
bool sort_by_pages(const Book &a, const Book &b){
	return a.get_pages() < b.get_pages();
}
// Field_nums:
// 1 - Title
// 2 - Author
// 3 - Date
// 4 - Book type
// 5 - isbn
// 6 - pages 

void Database::sort_by_field(int field_num){
	
	if(field_num == 1){
		
		sort(database.begin(),database.end(),sort_by_title);
		
	} else if(field_num == 2){
		
		sort(database.begin(),database.end(),sort_by_author);
		
	} else if(field_num == 3){
		
		sort(database.begin(),database.end(),sort_by_date);

	} else if(field_num == 4){
		
		sort(database.begin(),database.end(),sort_by_book_type);
	} else if(field_num == 5){
		
		sort(database.begin(),database.end(),sort_by_isbn);
	} else{
		sort(database.begin(),database.end(),sort_by_pages);

	}
}
