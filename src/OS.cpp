#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "OS.h"

using namespace std;

/* HELPER FUNCTIONS AREA */

// Used to convert any value to strings
template <typename T>
std::string to_string(T value)
{
	std::ostringstream os;
	os << value;
	return os.str();
}

/* END OF HELPER FUNCTIONS AREA */

OS::OS() {}

OS::OS(std::vector<std::string> &_references, int &QTY_FRAMES)
{
	/* 
	* If we create an instance of Table here to then assign it to frameTable,
	* it causes seg fault.
	*/
	references = _references;

	pageTable.setKind("page table");
	pageTable.setMaxSize(_references.size());
	pageTable.setBlocks();
	pageTable.setSize(-1);

	fillPageTable();

	frameTable.setKind("frame table");
	frameTable.setMaxSize(QTY_FRAMES);
	frameTable.setBlocks();
	frameTable.setSize(-1);
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

Table &OS::getPageTable()
{
	return pageTable;
}

void OS::fillPageTable()
{
	/* Populate PT with the new blocks.
	*  Presence bit = 0 for each block.
	*/
	std::cout << "PT initial size: " << pageTable.getSize() << std::endl;
	for (std::size_t i = 0; i < references.size(); i++)
	{
		string blockId = references[i];
		if (!pageTable.contains(blockId))
		{
			Block newBlock(atoi(blockId.c_str()), "Page");
			getPageTable().pushBack(newBlock);
		}
	}

	// Table pageTable = getPageTable();
	// for (size_t i = 0; i < references.size(); i++)
	// {
	// 	string blockId = references[i];
	// 	Block newBlock(atoi(blockId.c_str()), "Page");
	// 	if (pageTable.contains(blockId)) {
	// 		delete &newBlock;
	// 		Block existingBlock = pageTable.at(blockId);
	// 	}

	// 	getPageTable().pushBack(newBlock);
	// }

	std::cout << "PT final size: " << pageTable.getSize() << std::endl;
}

void OS::resetPageTable()
{
	// We should think how we can free the memory allocated by the previous FT
	/**
	 * If we use delete[] pageTable.blocks here, we will have to initialize it again.
	 * For example:
	 * 1. delete[] pageTable.blocks;
	 * 2. pageTable.blocks = new Block[size]
	*/
	fillPageTable();
}

void OS::runFIFO()
{
	getFifo().run(
		pageTable,
		frameTable
		// specific FIFO parameters here
	);
	resetPageTable(); // Every end of algorithm resets the page table
}

void OS::runLRU()
{
	getLru().runAlgorithm(
		pageTable,
		frameTable
		// specific LRU parameters here
	);
	resetPageTable(); // Every end of algorithm resets the page table
}

void OS::runOptimal()
{
	getOptiomal().runAlgorithm(
		pageTable,
		frameTable
		// specific Optimal parameters here
	);
	resetPageTable(); // Every end of algorithm resets the page table
}