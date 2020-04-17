
#include "Menu.h"
#include <random>

using namespace std;
// basic inputter
extern bool exit_program;

Menu::Menu(){}


// Starting menu
void Menu::display_options(){
    cout << endl << "Welcome to the MENU" << endl << endl;;
    cout << "Please type everything in lower case for easy use" << endl;
	cout << "Press a number key to perform" << endl; 
	cout << "the following functions" << endl;
    cout << "0.Display Database" << endl;
	cout << "1.Add" << endl;
	cout << "2.Delete"  << endl;
	cout << "3.Change a field"  << endl;
	cout << "4.Simple Searches" << endl;
	cout << "5.Complex Searches" << endl;
	cout << "6.Sorts by fields" << endl;
	cout << "7.Save Database" << endl;
	cout << "8.Load Database" << endl;
	cout << "9.Terminate Program" << endl;

}
// specific change field option menu
void Menu::change_fields_display(){
	cout << "Press a number key to perform" << endl; 
	cout << "your choses function" << endl;
	cout << "1.Title" << endl;
	cout << "2.Author" << endl;
	cout << "3.Date of Publication"  << endl;
    cout << "4.Book type"  << endl;
	cout << "5.ISBN" << endl;
	cout << "6.# of pages" << endl;
}
// Pre-Condition: i is in between 1 and 6 (inclusive)
void Menu::change_fields(int index_of_book, int field_number){
    switch(field_number){

        case 1: {
            cout << "Enter new title" << endl << endl;
            string title;
            cin.ignore();
            getline(cin,title);
            current.database[index_of_book].set_title(title);
            break;
        }

        case 2: {

            cout << "Enter new author" << endl << endl;
            string author;
            cin.ignore();
            getline(cin,author);
            current.database[index_of_book].set_author(author);
            break;
        }
        case 3: {

            cout << "Enter new date of publication" << endl << endl;
            string dt;
            cin.ignore();
            getline(cin,dt);
            current.database[index_of_book].set_date(dt);
            break;
        }
        case 4: {

            cout << "Enter new booktype" << endl << endl;
            string type;
            cin.ignore();
            getline(cin,type);
            current.database[index_of_book].set_book_type(type);
            break;
        }
        case 5: {

            cout << "Enter new ISBN" << endl << endl;
            string isbn;
            cin.ignore();
            getline(cin,isbn);
            current.database[index_of_book].set_isbn(isbn);
            break;
        }
        case 6: {

            cout << "Enter new amount of pages" << endl << endl;
            int pages;
            cin.ignore();
            cin >> pages;
            current.database[index_of_book].set_pages(pages);
            break;
        }

    }
}

// handling unidentified input, asks user to enter it again
void Menu::input_error_handling(){
	cout << "What you entered could not be read" << endl;
	cout << "Please reenter" << endl;

}
Book Menu::input_book_handler(){
	string title;
	string author;
	int pages = 0; // number of pages
	string date;
	string book_type;
	string isbn;
	// the do-while loop checks for invalud input
	bool check = false;


	do {
        
		cout << "Input the title of the book" << endl;
        cin.ignore();
		getline(cin,title);
    	if (cin.fail() || title.size()==0) {
        	cin.clear();
        	cin.ignore();
    	}
        else{
            check = true;

        }
	}	while(!check);

	check = false;

	
	do {
		cout << "Input the author of the book" << endl;
		getline(cin,author);
    	if (cin.fail() || author.size()==0 ) {
        	cin.clear();
        	cin.ignore();
    	}
        else{
            check = true;
        }
	}	while(!check);

    check = false;
    
    do {
        cout << "Input the date of publciation" << endl;
        getline(cin,date);
        if (cin.fail() || date.size()==0) {
            cin.clear();
            cin.ignore();
        }
        else{
            check = true;
        }
    }   while(!check);

    check = false;

    do {
        cout << "Input the book type" << endl;
        cin >> book_type;
        if (cin.fail() || !(book_type == "hardcover" || 
            book_type == "softcover" || book_type == "digital")) {
            cin.clear();
            cin.ignore();
        }
        else{
            check = true;
        }
    }   while(!check);


    check = false;

    do {
        cout << "Input the ISBN of the book" << endl;
        cin >> isbn;
        if (cin.fail() || !(isbn.size()== 10 || isbn.size()== 13)) {
            cin.clear();
            cin.ignore();
        }
        else{
            check = true;
        }
    }   while(!check);

    check = false;

	do {
		cout << "Input the number of pages" << endl;
		cin >> pages;
    	if (cin.fail() || pages <= 0) {
        	cin.clear();
        	cin.ignore();
    	}
        else{
            check = true;
        }
	}	while(!check);
	
	
	check = false;

	Book book1(title,author,date,book_type, isbn, pages);
	return book1;

}


void Menu::handle_options(int a){
	switch(a) {

    // display database
    case 0:{

		current.display_database();
        break;

    }
    // add book
    case 1: {// call the add function
    		// Make sure to add proper  
    	cout << "You will now be able to input your book" << endl;
    	current.database.push_back(input_book_handler());
    	break;
    }
    	// delete an existing book
    case 2: {
		current.display_database();
		cout << "Input which line you wish to remove" << endl;
        cout << "Note: the first line is considered 0" << endl;
		bool check = false;
		int index = 0;
		do {
			cout << "Choose the index" << endl;
			cin >> index;
			if (cin.fail() || index < 0 || index > (current.database.size()-1)) {
    			cin.clear();
    			cin.ignore();
			}
			else{
    			check = true;
			}
			}	while(!check);
		check = false;
		
		current.database.erase(current.database.begin()+index);
		// change a field
		break;
    }
    // Change a field
    case 3: {

        bool check = false;
        int index = 0;
        current.display_database();
        do {
            cout << "Choose the line number to determine book you wish to change" << endl;
            cout << "Note: First line is zero" << endl;
            cin >> index;
            if (cin.fail() || index < 0 || index > (current.database.size()-1)) {
                cin.clear();
                cin.ignore();
            }
            else{
                check = true;
            }
        }   while(!check);

        check = false;
        change_fields_display();
        int field_number = 0;
        do {
            cout << "Enter field number" << endl;
            cin >> field_number;
            cout << "The number you picked is: " << field_number << endl;
            // field number is between 1-6
            if (field_number < 1 || field_number > 6) {
                cin.clear();
                cin.ignore();
            }
            else{
                check = true;
            }
        }   while(!check);

        change_fields(index, field_number);



	    break;
            

    }
    // Simple searches
    case 4: {
        results.database.clear();
        cout << "What field do you wish to search for?";
        change_fields_display(); // this will display the respective options
        bool check = false;
        int temp = 0;
        do{
            
            cin >> temp;
            if(cin.fail()){
                
                cin.clear();
                cin.ignore();
            } else{
                check = true;
            }
        } while(!check);

        if(temp < 6){
            cout << "What value are you searching for?" << endl;
            string s;
            cin >> s;
            // search by field method name is overloaded
            // search by field returns a book vector
            results.database = current.search_by_field(temp,s);
        } else{
            cout << "What value are you searching for?" << endl;
            int n;
            cin >> n;
            // dont need to pass temp since we only have one int
            results.database = current.search_by_field(n);
        }
        results.display_database();
        results.database.clear();

        break;
    }
    // complex searches
    // - 5 different personally implemented complex searches
    case 5: {
        cout << "1.Search books with less than 200 pages" << endl;
        cout << "2.Search books with more than 200 pages"<< endl;
        // books published after 1980
        cout << "3.Search for modern books" << endl; 
        // books published before 1980
        cout << "4.Search for Older books" << endl; 
        // books that follow a special algorithm
        // more detal explained below
        // on how editors choice is determined
        cout << "5.Search for Editors choice books" << endl; 
        
        bool check = false;
        int temp = 0;
        results.database.clear();
        do{
            
            cin >> temp;
            if(cin.fail()){
                
                cin.clear();
                cin.ignore();
            } else{
                check = true;
            }
        } while(!check);

        if(temp == 1){
            for(int i = 0; i < current.database.size(); i++){
                if(current.database[i].get_pages() < 200){
                    results.database.push_back(current.database[i]);
                }
            }
        } else if(temp == 2){
            for(int i = 0; i < current.database.size(); i++){
                if(current.database[i].get_pages() > 200){
                    results.database.push_back(current.database[i]);
                }
            }
        } else if(temp == 3){
            for(int i = 0; i < current.database.size(); i++){
                if(stoi(current.database[i].get_date()) > 1980){
                    results.database.push_back(current.database[i]);
                }
            }
        } else if(temp == 4){
            for(int i = 0; i < current.database.size(); i++){
                if(stoi(current.database[i].get_date()) < 1980){
                    results.database.push_back(current.database[i]);
                }
            }

        } 
        // This else will augment a special selection to determine
        // the editors choice books
        // How this algorithm works:
        // Two characters are randomely chosen by manipulating rand
        // Then the title is searched to see if it has those
        // two characters or not
        else {

            int r1 = rand() % 26;
            char c1 = 'a' + r1;
            int r2 = rand() % 26;
            char c2 = 'a' + r2;
            string empty;
            string join = empty + c1 + c2;

            cout << "The SECRET CHARACTERS FOR EDITORS CHOICE WERE: " << join << endl;
            for(int i = 0; i < current.database.size(); i++){
                string title;
                title = current.database[i].get_title();
                cout << title << endl;
                if(title.find(join) != string::npos){
                    results.database.push_back(current.database[i]);
                }
            }

        }


        results.display_database();
        results.database.clear();
        break;
    }
    // sorts 
    case 6: {
        results.database.clear();
        cout << "What field do you wish to sort for?";
        change_fields_display(); // this will display the respective options
        bool check = false;
        int temp = 0;
        do{
            
            cin >> temp;
            if(cin.fail()){
                
                cin.clear();
                cin.ignore();
            } else{
                check = true;
            }
        } while(!check);
        
        current.sort_by_field(temp);
        current.display_database();

        break;
    }
    // Save File
    case 7: {
        ofstream output_file;
        string s;
        cout << "Input the name of the file you want to save it in: ";
        cin.ignore();
        getline(cin, s);
        output_file.open(s);
        for(int i = 0; i < current.database.size(); i++){
            output_file << current.database[i].to_str_converted() << endl;
        }


        break;
    }
    // Load file
    case 8: {
        ifstream input_file;
        string s;
        cout << "Input the name of the file you want to load a book database from. Note it must exist in the current folder: " << endl;
        cin >> s;
        input_file.open(s);
        if(input_file.is_open()){
            cout << "File has been opened" << endl;
        }
        else{
            cout << "File failed to open" << endl;
            break;
        }
        Book data; // new book object called data
       
        string line; 
        
        while(getline(input_file,line)){
            string val;
            stringstream ss(line);
            vector<string> list;
            while(getline(ss,val,',')){ // As long as it reads the first symbol {"["}
            
                list.push_back(val);

            }
            // Note: this was written for testig purposes
            // for(int i = 0; i < list.size(); i++){
            //     cout << list[i] << endl;
            // }
        
            if(list.size() != 6){
                cout << "File was not in correct format, exitting program" << endl;
                exit(0);
            }
            string s1 = list[0].substr(1);
            string s2 = list[1].substr(1);
            string s3 = list[2].substr(1);
            string s4 = list[3].substr(1);
            string s5 = list[4].substr(1);
            string s6 = list[5].substr(1,list[1].size()-2);
            int pages = stoi(s6);

            // EVERYTHING TO LOWERCASE
            transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
            transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
            transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
            transform(s4.begin(), s4.end(), s4.begin(), ::tolower);
            transform(s5.begin(), s5.end(), s5.begin(), ::tolower);



            data.set_title(s1);
            data.set_author(s2);
            data.set_date(s3);
            data.set_book_type(s4);
            data.set_isbn(s5);
            data.set_pages(pages);

            current.database.push_back(data);
        }


        cout << "Data was laoded succesfully from the file you chose" << endl;

        break;
    }

    case 9: {
        exit_program = true;
        exit(0);
        break;
    }


    default: 
        cout << "Not defined. Please renter" << endl; // no error - should neve run!
        break;
}

}

