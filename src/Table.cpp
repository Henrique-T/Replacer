#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <limits.h>
#include <bits/stdc++.h>
#include "Table.h"

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

Table::Table() {}

Table::Table(std::string _kind, std::size_t _maxSize)
{
	kind = _kind;
	maxSize = _maxSize;
	std::vector<Block> blocks;
}

Table::Table(std::string _kind)
{
	kind = _kind;
	maxSize = 20; /* Default size */
	std::vector<Block> blocks;}

Table::~Table()
{
	blocks.clear();
}

void Table::pushBack(const Block &_data)
{
	if (full()) {
		throw std::out_of_range("Table is full");
		return;
	}
	blocks.push_back(_data);

	// printf("Contém [");
	// for (std::size_t i = 0; i < blocks.size(); i++) 
	// {
	// 	// Set a really big number for reach (meaning big numbers represent blocks that won't be referenced anymore)
	// 	int blockId = blocks.at(i).getId();
	// 	std::cout << blockId;
	// 	printf(",");
	// }
}

void Table::pushFront(const Block &_data)
{
	if (full()) {
		throw std::out_of_range("Table is full");
		return;
	}
	blocks.insert(blocks.begin(), _data);
}


bool Table::full()
{
	return (getSize() == getMaxSize());
}

bool Table::empty()
{
	return (getSize() == 0);
}

Block* Table::at(size_t _index)
{
	if (empty())
		throw std::out_of_range("table is empty");

	return &blocks.at(_index);
}

std::size_t Table::find(const std::string &_blockId)
{
	std::size_t position = 0;
	int blockId = atoi(_blockId.c_str());
	while (position < getSize() && !(blockId == blocks.at(position).getId()))
	{
		position += 1;
	}
	return position;
}

bool Table::isPresentInFT(const std::string &_blockId)
{
	/* This method checks if a certain block has its present bit = 1, which means it's currently in the Frame Table */
	int blockId = atoi(_blockId.c_str());
	for (std::size_t i = 0; i < blocks.size(); i++) 
	{
		Block currentBlock = blocks.at(i);
		if (currentBlock.getId() == blockId && currentBlock.isBlockPresent())
		{
			return true;
		}
	}
	return false;
}

bool Table::contains(const std::string &_blockId)
{
	std::size_t position = 0;
	int blockId = atoi(_blockId.c_str());
	while (position < getSize())
	{
		Block currentBlock = blocks.at(position);
		if (currentBlock.getId() == blockId)
		{
			return true;
		}
		position += 1;
	}
	return false;
}

std::size_t Table::getMaxSize()
{
	return maxSize;
}

std::size_t Table::getSize()
{
	/* Returns size + 1 because size points to the position of the last item inserted. */
	return blocks.size();
}

void Table::setKind(const std::string &_kind) { kind = _kind; }
void Table::setMaxSize(const std::size_t _maxSize) { maxSize = _maxSize; }
void Table::resetReachCounters() {
	for (std::size_t i = 0; i < blocks.size(); i++) 
	{
		// Set a really big number for reach (meaning big numbers represent blocks that won't be referenced anymore)
		int infinity = INT_MAX;
		blocks.at(i).setReachCounter(infinity);
	}
}
void Table::recalculateReach(int line, std::vector<std::string> &_references) {
	resetReachCounters();
	int numberOfInstructions = 0;
	for (std::size_t i = line; i < _references.size(); i++) // We iterate starting from the 'line' index reference
	{
		Block* currentBlock = at(find(_references[i]));
		if (currentBlock->getReachCounter() > numberOfInstructions) {
			// Only replace the reach counter in case the upcoming number of instructions is less than the one already stored
			currentBlock->setReachCounter(numberOfInstructions); 
		}
		numberOfInstructions += 1;
	}
}