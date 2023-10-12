#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::Algorithm(std::vector<std::string> &_references)
{
	references = _references;

	/* Populate PT with the new blocks.
	*  Presence bit = 0 for each block.
	*/
	for (size_t i = 0; i < _references.size(); i++)
	{
		Block newBlock(atoi(_references[i].c_str()), "Page");
		pageTable.pushBack(newBlock);
	}
}

Algorithm::~Algorithm() {}

std::vector<std::string> &Algorithm::getReferences()
{
	return references;
}

void Algorithm::runAlgorithm()
{
	// FIFO
	for (const std::string &reference : references)
	{
		// 1. try to find that reference in PT
		// 2. If found, go to FT to get the pageinsert to FT the necessary page
		// 3. If not found, print "PAGE FAULT"
		// 3.1 Get the first inserted page in FT and remove it
		// 3.2 bring the requested page from disk and insert that into FT.
		// 3.3. Update PT mapping
	}

	// LRU
	// Optimal
}
