#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
#include "Algorithm.h"
#include "Table.h"
#include "Block.h"
#include "FIFO.h"

FIFO::FIFO(std::vector<std::string> &_references) : Algorithm(_references)
{
	for (size_t i = 0; i < _references.size(); i++)
	{
		Block newBlock(atoi(_references[i].c_str()), "Page");
		pageTable.pushBack(newBlock);
	}
}

FIFO::~FIFO() {}

void FIFO::runAlgorithm()
{
	std::vector<std::string> &references = getReferences();
	for (const std::string &reference : references)
	{
		// 1. try to find that reference in PT
		// 2. If found, go to FT to get the pageinsert to FT the necessary page
		// 3. If not found, print "PAGE FAULT"
		// 3.1 Get the first inserted page in FT and remove it
		// 3.2 bring the requested page from disk and insert that into FT.
	}
}