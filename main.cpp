#include "Database.h"
#include "Book.h"
#include "Menu.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
using namespace std;
extern bool exit_program; // this allows me to share this var
// with the menu.cpp file

bool exit_program = false;

int main(){
	srand(time(nullptr));
	Menu mymenu;
	int temp;
	bool check = false;
	while(!exit_program){
		do {
			mymenu.display_options();
			cout << "Press a number" << endl;
			cin >> temp;
	    	if (cin.fail() || temp < 0 || temp > 9) {
	        	cin.clear();
	        	cin.ignore();
	    	}
	    else{
	        check = true;
	    }
		}	while(!check);

	
		mymenu.handle_options(temp);
		cout << "Process succeeded" << endl;

	}
	return 0;
}