#pragma once
#include "Compression.h"
class Rle : public Compression
{
public:
	Rle();
	~Rle();
	void rle_decode(string str);
	void rle_encode(string str);
};

