#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include "Table.h"
#include "Block.h"
#include "OS.h"

using namespace std;

int main(int argc, char *argv[])
{
	int QTY_FRAMES = atoi(argv[1]);
	vector<string> references;

	/* Store input file data into vector references */
	for (std::string line; std::getline(std::cin, line);)
	{
		references.push_back(line);
	}

	/* Create OS instance and call algorithms */
	OS os(references, QTY_FRAMES);

	os.runFIFO();
	// os.runLRU();
	// os.runOptimal();

	/* TESTS */
	/* 
	* What data should we initialize them with? 
	*/
	// Table pageTable("page table", VIRTUAL_SPACE_SIZE);
	// Table frameTable("frame table", QTY_FRAMES);

	/* Create blocks with presence=0 and populate page table */
	// for (size_t i = 0; i < references.size(); i++)
	// {
	// 	Block newBlock(atoi(references[i].c_str()), "Page");
	// 	pageTable.pushBack(newBlock);
	// }

	// /* Print table content */
	// for (size_t i = 0; i < pageTable.getSize(); i++)
	// {
	// 	std::cout << i << ":" << pageTable.at(i).getId() << ":" << pageTable.at(i).isBlockPresent() << std::endl;
	// }

	/* Create instance of Table */
	// Table table("page table", references.size());

	// /* Populate table */
	// for (size_t i = 0; i < references.size(); i++)
	// {
	// 	Block newBlock(atoi(references[i].c_str()), "Page");
	// 	table.pushBack(newBlock);
	// }

	// /* Print table content */
	// for (size_t i = 0; i < table.getSize(); i++)
	// {
	// 	std::cout << i << ":" << table.at(i).getId() << std::endl;
	// }

	/* Test Block creation and get variables */
	// Block block(0, "Page");
	// std::cout << block.getId() << std::endl;
	// std::cout << block.getKind() << std::endl;
	// std::cout << block.isBlockPresent() << std::endl;

	return 0;
}