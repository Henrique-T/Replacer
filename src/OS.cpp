#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <functional>
#include <bits/stdc++.h>
#include "OS.h"

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

OS::OS(std::vector<std::string> &_references, int &_QTY_FRAMES)
{
	/* 
	* If we create an instance of Table here to then assign it to frameTable,
	* it causes seg fault.
	*/
	references = _references;
	QTY_FRAMES = _QTY_FRAMES;

	pageTable.setKind("page table");
	pageTable.setMaxSize(_references.size());
	fillPageTable();

	fifo.setReferences(_references);
}

OS::~OS() {}

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
		std::string blockIdStr = references[i];
		int blockId = atoi(blockIdStr.c_str());
		if (!pageTable.contains(blockIdStr))
		{
			Block newBlock(blockId);
			getPageTable().pushBack(newBlock);
		}
		else
		{
			// If this block already exists in the table, it means that we are referencing it again,
			// and we will increase its number of references.
			Block existentBlock = getPageTable().at(getPageTable().find(blockIdStr));
			existentBlock.incrementCounter(1);
		}
	}

	std::cout << "PT final size: " << pageTable.getSize() << std::endl;
}

void OS::resetTables()
{
	/* Reset presence bits in PT */
	for (std::size_t i = 0; i < pageTable.getSize(); i++)
	{
		pageTable.at(i).setPresenceBit(0);
	}
}

void OS::runFIFO()
{
	getFifo().run(
		pageTable
	);
	resetTables(); // Every end of algorithm resets the page table
}

void OS::runLRU()
{
	// getLru().runAlgorithm(
	// 	pageTable,
	// 	frameTable,
	// 	moveFrameToDisk,
	// 	getFrameFromDisk,
	// );
	resetTables(); // Every end of algorithm resets the page table
}

void OS::runOptimal()
{
	// getOptiomal().runAlgorithm(
	// 	pageTable,
	// 	frameTable,
	// 	moveFrameToDisk,
	// 	getFrameFromDisk
	// );
	resetTables(); // Every end of algorithm resets the page table
}