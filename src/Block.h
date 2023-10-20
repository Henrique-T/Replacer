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
	int id;					 /* Given as program input */
	int presence;			 /* Presence bit */
	std::string kind;		 /* "Page" or "Frame" */
	std::string addressInFT; /* Address stored in PT that maps to FT */
	int counter;

public:
	Block();
	Block(int _id, std::string _kind);
	~Block();

	int getId();
	bool isBlockPresent();
	std::string getKind();
	std::string getAddressInFT();
	void setAddressInFT(std::string &_address);
	int getCounter();
	void incrementCounter(int _increment);
	void setPresenceBit(const bool _bit);
};

#endif