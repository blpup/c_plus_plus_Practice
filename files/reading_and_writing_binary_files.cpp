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
	double height;
};

//Turn off the padding on the struct
//So that the padding does not affect other areas of the program.
#pragma pack(pop)


int main()
{
	Person someone = {"Frodo",220,120};
	string fileName = "test.bin";


	//Write binary file//

	ofstream outputFile;

	outputFile.open(fileName, ios::binary);

	if (outputFile.is_open()) {

		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

		outputFile.close();
	}
	else {
		cout << "Could not create file: " << fileName << endl;
	};


	//Read binary file//

	Person someoneElse = {};

	ifstream inputFile;

	inputFile.open(fileName, ios::binary);

	if (inputFile.is_open()) {
		//it will put the read bianry and place it inside of someoneElse
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(Person));

		inputFile.close();
	}
	else {
		cout << "Could not read file: " << fileName << endl;
	};

	cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.height << endl;
    return 0;
}

