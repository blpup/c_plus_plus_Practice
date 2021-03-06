// oct 1
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Pushing a directive on top of a stack
//When we say 1 it means align the data to single line boundarys
//to remove the padding off the struct
//Padding means, the struct will show a size of 64 even though the size is actually 62
//So using this line will make it show 62.
#pragma pack(push, 1)


struct Person {
	char name[50];
	int age;
	double weight;
};

//Turn off the padding on the struct
//So that the padding does not affect other areas of the program.
#pragma pack(pop)


int main()
{
	cout << sizeof(Person) << endl;
    return 0;
}

