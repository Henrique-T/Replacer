#ifndef OS_H
#define OS_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Table.h"
#include "Block.h"
#include "FIFO.h"
#include "LRU.h"
#include "Optimal.h"
#include "Algorithm.h"

/*
* Represents the operating system.
* The MMU is integrated in here.
* Responsible for inserting and removing pages and frames of pages.
*/
class OS
{
private:
	std::vector<Block> disk;
	FIFO fifo;
	LRU lru;
	Optimal optimal;

public:
	OS();
	OS(std::vector<std::string> &_references);
	~OS();

	void moveFrameToDisk(Block _block);
	Block &getFrameFromDisk(int _id);
	Block &removeFrameFromDisk(int _id);
	FIFO &getFifo();
	LRU &getLru();
	Optimal &getOptiomal();
};

#endif