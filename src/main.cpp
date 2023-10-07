#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Table.h"

using namespace std;

/* WARNING: The size variable in Table is causing confusion. That's why
the prints are not how they should be.
*/
int main(int argc, char *argv[])
{
	int qtyFrames = atoi(argv[1]);
	vector<string> references;

	/* store file data into vector references */
	for (std::string line; std::getline(std::cin, line);)
	{
		references.push_back(line);
	}

	/* Create instance of Table */
	Table table("page table", references.size());

	/* Populate table */
	for (size_t i = 0; i < references.size(); i++)
	{
		table.pushBack(references[i]);
	}

	std::cout << "SIZE: " << table.getSize() << std::endl;

	/* Print table content */
	for (size_t i = 0; i < table.getSize(); i++)
	{
		std::cout << i << ":" << table.at(i) << std::endl;
	}

	printf("\n");
	table.popBack();
	printf("\n");

	for (size_t i = 0; i < table.getSize(); i++)
	{
		std::cout << i << ":" << table.at(i) << std::endl;
	}

	printf("\n");
	table.pushBack("8");
	printf("\n");

	for (size_t i = 0; i < table.getSize(); i++)
	{
		std::cout << i << ":" << table.at(i) << std::endl;
	}

	printf("\n");
	table.blocks[22] = "8";
	printf("\n");

	for (size_t i = 0; i < table.getSize(); i++)
	{
		std::cout << i << ":" << table.at(i) << std::endl;
	}

	printf("\n");
	return 0;
}