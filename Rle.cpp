#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "Rle.h"



Rle::Rle()
{
}
Rle::~Rle()
{
}

void Rle::rle_decode(string str) {
	ofstream outfile("decoded_rle.txt"); // creates file
	bool openCount = false;
	string temp="";
	string letterCountStr="";
	for (char letter : str) {
		if (letter == ']') {
			openCount = false;
		}
		else if (openCount == true)
			letterCountStr = letterCountStr + letter;
		else if (letter == '[')
			openCount = true;
		else if (letter != ']' && openCount == false) {
			int letterCount = stoi(letterCountStr);
			letterCountStr = "";
			for (int i = 0; i < letterCount; i++) {
				outfile << letter;
			}
		}
	}
	outfile.close();
}


void Rle::rle_encode(string str) {

	ofstream outfile("encoded_rle.txt"); // creates file
	int n = str.length();
	for (int i = 0; i < n; i++) {
		// Count occurrences of current character 
		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		// Print character and its count 
		outfile << count << str[i];
	}
	outfile.close();
}


