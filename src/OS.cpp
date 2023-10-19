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
		std::string blockIdStr = references[i];
		int blockId = atoi(blockIdStr.c_str());
		if (!pageTable.contains(blockIdStr))
		{
			Block newBlock(blockId, "Page");
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
	// We should think how we can free the memory allocated by the previous FT
	/**
	 * If we use delete[] pageTable.blocks here, we will have to initialize it again.
	 * For example:
	 * 1. delete[] pageTable.blocks;
	 * 2. pageTable.blocks = new Block[size]
	*/

	// ERRATA!!! A gente tem que resetar a frame table, e não a page table. (e acredito que esvaziar o disco)
	// Renomeei as funçoes
	/*
	We could simply empty the Table and the disk vector
	*/
	// frameTable.clear(); We need to implement a method for tables
	// Reset all presence bits from PageTable
	disk.clear();
}

void OS::runFIFO()
{
	getFifo().run(
		pageTable,
		frameTable,
		std::bind(&OS::moveFrameToDisk, this, std::placeholders::_1),
		std::bind(&OS::getFrameFromDisk, this, std::placeholders::_1));
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