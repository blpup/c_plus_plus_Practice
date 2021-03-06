// sep30.cpp
// inFile is over loaded so instead of saying inFile.eof(). We can just say inFile
//getline gets the file line instead of just one word.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main()
{
	string inFileName = "Text.txt";
	ifstream inFile;

	inFile.open(inFileName);

	if (inFile.is_open()) {

		string line;
		while (inFile) {
			getline(inFile, line);
			cout << line << endl;
		}
		inFile.close();
	}
	else {
		cout << "Can not open file: " << inFileName << endl;
	};
    return 0;
}

