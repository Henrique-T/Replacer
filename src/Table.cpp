#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Table.h"

Table::Table() {}

Table::Table(std::string _kind, std::size_t _maxSize)
{
	kind = _kind;
	maxSize = _maxSize;
	blocks = new Block[_maxSize];
	size = -1;
}

Table::Table(std::string _kind)
{
	kind = _kind;
	maxSize = 20; /* Default size */
	blocks = new Block[maxSize];
	size = -1;
}

Table::~Table()
{
	delete[] blocks;
}

void Table::pushBack(const Block &_data)
{
	if (full())
		throw std::out_of_range("table is full");
	size = size + 1;
	blocks[size] = _data;
}

void Table::pushFront(const Block &_data)
{
	if (full())
		throw std::out_of_range("List is full");
	size += 1;
	size_t position = size;
	while (position > 0)
	{
		blocks[position] = blocks[position - 1];
		position = position - 1;
	}
	blocks[0] = _data;
}

void Table::insert(const Block &_data, std::size_t _index) {}

Block Table::popBack()
{
	if (empty())
		throw std::out_of_range("table is empty");

	Block aux;
	aux = blocks[size];
	size = size - 1;
	return aux;
}

Block Table::popFront()
{
	if (empty())
		throw std::out_of_range("table is empty");

	Block aux = blocks[0];
	std::size_t position = 0;
	while (position < size)
	{
		blocks[position] = blocks[position + 1];
		position = position + 1;
	}
	size -= 1; // Why do we need this instruction after the while?
	return aux;
}

bool Table::full()
{
	return (size == maxSize - 1);
}

bool Table::empty()
{
	size_t a = -1;
	return (size == a);
}

Block &Table::at(size_t _index)
{
	if (empty())
		throw std::out_of_range("table is empty");

	return blocks[_index];
}

std::size_t Table::find(const std::string &_blockId)
{
	std::size_t position = 0;
	int blockId = atoi(_blockId.c_str());
	while (position < getSize() && !(blockId == blocks[position].getId()))
	{
		position += 1;
	}
	return position;
}

bool Table::contains(const std::string &_blockId)
{
	std::size_t position = 0;
	int blockId = atoi(_blockId.c_str());
	while (position < getSize())
	{
		if (blocks[position].getId() == blockId && blocks[position].isBlockPresent())
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
	return size + 1;
}

void Table::setKind(const std::string &_kind) { kind = _kind; }
void Table::setSize(const std::size_t _size) { size = _size; }
void Table::setMaxSize(const std::size_t _maxSize) { maxSize = _maxSize; }
void Table::setBlocks() { blocks = new Block[maxSize]; }
void Table::recalculateReach(int line) {}