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
	int counter;
	int reachCounter; /* This counter represents the amount of instructions needed to reach this block again starting from a certain instruction */

public:
	Block();
	Block(int _id);
	~Block();

	int getId() const;
	bool isBlockPresent();
	int getCounter();
	void incrementCounter(int _increment);
	void setPresenceBit(const bool _bit);
	int getReachCounter() const;
	void setReachCounter(int &_value);
};

#endif