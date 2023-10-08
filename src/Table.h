#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>

/*
* Represents a page table or a frame page table.
* It can be one of two kinds: "page table" or "frame table".
*/
class Table
{
private:
	std::string kind;
	std::size_t size;	 /* Current size. WARNING: this points to the position of the last item. */
	std::size_t maxSize; /* Actual size of the table */

public:
	std::string *blocks; /* Later on it will be changed to a vector of Blocks */
	Table(std::string _kind, std::size_t _maxSize);
	Table(std::string _kind);
	~Table(); /* No need to explicitly call it */

	void pushBack(const std::string &_data);
	void insert(const std::string &_data, std::size_t _index);

	std::string popBack();
	std::string popFront();

	bool full();
	bool empty();

	std::string &at(size_t _index);

	std::size_t getMaxSize();
	std::size_t getSize();
};

#endif