#pragma once
#include <vector>
#include <map>
#include <string>
#include <queue>
#include "Compression.h"
#include <string>
using namespace std;


// Huffman Tree Nodes.
struct node {
	char data;
	int freq; // how often the data is repeated
	node *left, *right;

	// Leaf [ I BELIEVE]!!!! *****
	node(char data, int freq) {
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

// check if left or right has a higher frequency
struct compare {
	bool operator()(node* l, node* r) {
		return(l->freq > r->freq);
	}
};
class Huffman :
	public Compression
{
public:
	Huffman();
	~Huffman();	

	void printCodes(struct node* root, string str);
	void storeCodes(struct node* root, string str);
	void calcFreq(int n);
	void buildTree(int size);
	map<char, string> getCodes();
	string getCodesInfo(int i);
	map<char, int> getFreq();
	void huffman_encode(std::string text);
	priority_queue<node*, vector<node*>, compare> getTree();
	void huffman_encode_print();
	void huffman_decode(struct node* root);

private:
	string str;
	map<char, string> codes;
	map<char, int> freq;
	priority_queue<node*, vector<node*>, compare> tree;

};

