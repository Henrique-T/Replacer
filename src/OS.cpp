#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "OS.h"

OS::OS() {}
OS::OS(std::vector<std::string> &_references)
{
	/* This is terrible, but it is what it is. */
	fifo.getPageTable().setKind("page table");
	fifo.getPageTable().setMaxSize(_references.size());
	fifo.getPageTable().setBlocks();
	fifo.getPageTable().setSize(-1);

	fifo.setReferences(_references); // This should set references for all algos
	fifo.fillPageTable();			 // This should fill PT for all algos
}
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