#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Block.h"

/*
* Represents a page table or a frame page table.
* It can be one of two kinds: "page table" or "frame table".
* It stores blocks with references to page frames.
*/
class Table
{
private:
	std::string kind;	 /* "page table" or "frame table" */
	std::size_t size;	 /* Current size. WARNING: this points to the position of the last item. */
	std::size_t maxSize; /* Actual size of the table */

public:
	Block *blocks;
	Table();
	Table(std::string _kind, std::size_t _maxSize);
	Table(std::string _kind);
	~Table(); /* No need to explicitly call it */

	void pushBack(const Block &_data);
	void pushFront(const Block &_data);
	void insert(const Block &_data, std::size_t _index);

	Block popBack();
	Block popFront();

	bool full();
	bool empty();

	/* Returns block at a given position */
	Block &at(std::size_t _index);
	/* Returns position of given block */
	std::size_t find(const std::string &_blockId);
	/* Checks if block exists and if it is present */
	bool contains(const std::string &_blockId);

	std::size_t getMaxSize();
	std::size_t getSize();
	void setKind(const std::string &_kind);
	void setSize(const std::size_t _size);
	void setMaxSize(const std::size_t _maxSize);
	void setBlocks();
};

#endif