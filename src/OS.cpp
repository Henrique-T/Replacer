#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "OS.h"

OS::OS() {}
OS::~OS() {}

void OS::moveFrameToDisk(Block _block)
{
	disk.push_back(_block);
}

Block &OS::getFrameFromDisk(int _id)
{
	if (disk.empty())
		throw std::out_of_range("Disk is empty");
	for (size_t i = 0; i < disk.size(); i++)
	{
		if (disk[i].getId() == _id)
		{
			return disk[i];
		}
	}
	static Block block;
	return block;
}

Block &OS::removeFrameFromDisk(int _id) {}

FIFO &OS::getFifo() { return fifo; }
LRU &OS::getLru() { return lru; }
Optimal &OS::getOptiomal() { return optimal; }