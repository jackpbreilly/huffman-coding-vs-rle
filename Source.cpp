#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <queue>
#include <chrono>

#include "Compression.h"
#include "Rle.h"
#include "Huffman.h"
using std::chrono::duration_cast;
typedef std::chrono::steady_clock the_clock;
using std::chrono::milliseconds;

using namespace std;

void createText(int amount_of_letters) {
	//const int AMOUNT_OF_LETTERS = 10000;
	ofstream outfile("uncompressed.txt"); // creates file

	//adding random letters to uncompressed.txt
	for (int i = 0; i < amount_of_letters; i++) {
		char randLetter = (char)('a' + rand() % 26);
		outfile << randLetter;
	}
	outfile.close();
}

int rle() {
	

	
	// uncompressing RLE file
	//rle_example->setText(rle_example->readText("encoded_rle"));
	//rle_example->rle_decode(rle_example->getText());
	return 0;
}
long GetFileSize(std::string filename)
{
	struct stat stat_buf;
	int rc = stat(filename.c_str(), &stat_buf);
	return rc == 0 ? stat_buf.st_size : -1;
}

void rle_time() {
	int amount_of_letters = 1;
	auto avgTimeTaken = 0;
	for (int i = 1; i <= 20; i++) {
		the_clock::time_point start = the_clock::now();
		createText(amount_of_letters);
		Rle* rle_example = new Rle();
		rle_example->setText(rle_example->readText("uncompressed"));
		rle_example->rle_encode(rle_example->getText());
		amount_of_letters *= 2;
		the_clock::time_point end = the_clock::now();
		auto time_taken = duration_cast<milliseconds>(end - start).count();
		avgTimeTaken = avgTimeTaken + time_taken;
		cout << i << ". Time: " << time_taken << endl;
	}
	cout << "Average Time Taken: "<< avgTimeTaken / 20 << " MilliSeconds"<< endl;
}
void huffman_time() {
	int amount_of_letters = 1;
	auto avgTimeTaken = 0;
	for (int i = 1; i <= 20; i++) {
		the_clock::time_point start = the_clock::now();
		createText(amount_of_letters);
		Huffman* Huffman_example = new Huffman();		
		Huffman_example->huffman_encode("uncompressed");
		amount_of_letters *= 2;
		the_clock::time_point end = the_clock::now();
		auto time_taken = duration_cast<milliseconds>(end - start).count();
		avgTimeTaken = avgTimeTaken + time_taken;
		cout << i << ". Time: " << time_taken << endl;
	}
	cout << "Average Time Taken: " << avgTimeTaken / 20 << " MilliSeconds" << endl;
}

void rle_memory() {
	long uncompressedFileSize = 0;
	long encodedFileSize = 0;
	int amount_of_letters = 1;
	for (int i = 1; i <= 20; i++) {
		createText(amount_of_letters);
		Rle* rle_example = new Rle();
		uncompressedFileSize = uncompressedFileSize + ((rle_example->readText("uncompressed").length() * 8) / 1000);
		rle_example->rle_encode(rle_example->readText("uncompressed"));
		encodedFileSize = encodedFileSize + ((rle_example->readText("encoded_rle").length() * 8) / 1000);
		amount_of_letters *= 2;
		cout << i << ". Uncompressed: " << ((rle_example->readText("uncompressed").length() * 8) / 1000) <<"KB Encoded: " << ((rle_example->readText("encoded_rle").length() * 8) / 1000) <<"KB" <<endl;
	}
	cout << "Managed to turn " << uncompressedFileSize << "KB into " << encodedFileSize <<"KB"<<endl;
}

void huffman_memory() {
	long uncompressedFileSize = 0;
	long encodedFileSize = 0;
	int amount_of_letters = 1;
	for (int i = 1; i <= 20; i++) {
		createText(amount_of_letters);
		Huffman* Huffman_example = new Huffman();
		uncompressedFileSize = uncompressedFileSize + ((Huffman_example->readText("uncompressed").length() * 8) / 1000);
		Huffman_example->huffman_encode("uncompressed");
		encodedFileSize = encodedFileSize + ((Huffman_example->readText("huffman_encoded").length()) / 1000);
		amount_of_letters *= 2;
		cout << i << ". Uncompressed: " << ((Huffman_example->readText("uncompressed").length() * 8) / 1000) << "KB Encoded: " << ((Huffman_example->readText("huffman_encoded").length()) / 1000) << "KB" << endl;
	}
	cout << "Managed to turn " << uncompressedFileSize << "KB into " << encodedFileSize << "KB" << endl;
}

int main()
{
	//rle_time();
	//huffman_time();
	//rle_memory();
	//huffman_memory();

	system("PAUSE");
}