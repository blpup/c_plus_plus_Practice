// sep30.cpp
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	string filename = "stats.txt";
	ifstream input;

	input.open(filename);

	if (!input.is_open()) {
		return 1;
	};

	while (input) {
		string line;

		//Get the line the ':' is the delim
		//it seperates the values from that point
		getline(input, line,':');

		int population;
		input >> population;


		//Remove the enter space from the bottom
		//If you have a whitespace at the bottom
		//it will continue to try and read it even though there is nothing there
		//with this methodology it will remove the last line.
		//input.get();
		input >> ws;
		if (!input) {
			break;
		};


		cout << "'" << line << "'" << " -- '" << population << "'" << endl;
	};

	input.close();
    return 0;
}

