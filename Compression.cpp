#include "Compression.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


Compression::Compression()
{
}


Compression::~Compression()
{
}


string Compression::getText() {
	return text;
}

void Compression::setText(string textToSet) {
	text = textToSet;
}

string Compression::readText(string file) {
	string line;
	string str;
	ifstream myfile(file + ".txt");
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			str.append(line);
		}
		myfile.close();
		return str;
	}
	else cout << "Unable to open file" << endl;
}



