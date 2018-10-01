// sep30.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

class CanGoWrong {
public:
	CanGoWrong() {
		char *pMemory = new char[99999];
		delete[] pMemory;
	};
};
int main()
{
	try {
		CanGoWrong wrong;
	}
	catch (bad_alloc &e) {
		cout << "Caught exception" << e.what() << endl;
	};
	
    return 0;
}

