#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Table.h"

using namespace std;

int main(int argc, char *argv[])
{
	int qtyFrames = atoi(argv[1]);
	vector<string> references;

	/* Store file data into vector references */
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

	/* Print table content */
	for (size_t i = 0; i < table.getSize(); i++)
	{
		std::cout << i << ":" << table.at(i) << std::endl;
	}

	return 0;
}