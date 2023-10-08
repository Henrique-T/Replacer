#ifndef BLOCK_H
#define BLOCK_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

/*
* Represents a block inside a Page or Frame table.
* A page or a page frame.
*/
class Block
{
private:
	int id;
	int presence;
	std::string kind; /* "Page" or "Frame" */

public:
	Block();
	Block(int _id, std::string _kind);
	~Block();

	int getId();
	bool isBlockPresent();
	std::string getKind();
};

#endif