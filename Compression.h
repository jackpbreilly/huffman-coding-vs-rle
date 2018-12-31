#pragma once
#include <string>
using namespace std;
class Compression
{
public:
	Compression();
	~Compression();
	string readText(string file);
	string readCompressed(string file);
	string getText();
	void setText(string textToSet);
private:
	string text;
};

