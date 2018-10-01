// sep30.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
using namespace std;

class MyException : public exception {
public:
	virtual const char* what() const throw() {
		return "Something bad happened!";
	};
};
class Test {
public:
	void goesWrong(){
		throw MyException();
	};
};
int main()
{
	Test test;
	try {
		test.goesWrong();
	}
	catch (MyException &e) {
		cout << e.what() << endl;
	}
    return 0;
}

