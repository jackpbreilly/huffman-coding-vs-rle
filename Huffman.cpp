#include "Huffman.h"
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <fstream>

using namespace std;


Huffman::Huffman()
{
}

Huffman::~Huffman()
{
}




void Huffman::printCodes(struct node* root, string str){
	if (!root)
		return;
	else if (root->data != '$')
		cout << root->data << ": " << str << endl;
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void Huffman::storeCodes(struct node* root, string str) {
	if (root == NULL)
		return;
	if (root->data != '$')
		codes[root->data] = str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}
// build tree
void Huffman::buildTree(int size) {
	struct node *left, *right, *top;
	for (map<char, int>::iterator v = freq.begin(); v != freq.end(); v++)
		tree.push(new node(v->first, v->second));
	while (tree.size() != 1){
		left = tree.top();
		tree.pop();
		right = tree.top();
		tree.pop();
		top = new node('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		tree.push(top);
	}
	storeCodes(tree.top(), "");
}

void Huffman::calcFreq(int n){
	for (int i = 0; i < getText().size(); i++)
		freq[getText()[i]]++;
}

void Huffman::huffman_decode(struct node* root){
	string ans = "";
	struct node* curr = root;
	for (int i = 0; i < getText().size(); i++)
	{
		if (getText()[i] == '0')
			curr = curr->left;
		else
			curr = curr->right;

		// reached leaf node 
		if (curr->left == NULL and curr->right == NULL)
		{
			ans += curr->data;
			curr = root;
		}
	}
	ofstream outfile("huffman_decoded.txt"); // creates file
	outfile << ans;
	outfile.close();
}
map<char, string> Huffman::getCodes(){
	return codes;
}

string Huffman::getCodesInfo(int i)
{
	return codes[i];
}
map<char, int> Huffman::getFreq(){
	return freq;
}
priority_queue<node*, vector<node*>, compare> Huffman::getTree(){
	return tree;
}
 void Huffman::huffman_encode_print() {
	string encodedStr;
	for (auto i : getText())
		encodedStr += codes[i];

	ofstream outfile("huffman_encoded.txt"); // creates file
	outfile << encodedStr;
	outfile.close();
}
void Huffman::huffman_encode(std::string text) {
	setText(readText(text));
	calcFreq(getText().length());
	buildTree(getText().length());
	huffman_encode_print();
	setText(readText("huffman_encoded"));
}