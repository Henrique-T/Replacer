#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::~Algorithm() {}

std::vector<std::string> &Algorithm::getReferences()
{
	return references;
}

void Algorithm::setReferences(std::vector<std::string> &_references)
{
	references = _references;
}


void Algorithm::runAlgorithm(Table pageTable, Table frameTable)
{
	int pageFaults = 0;
	// FIFO
	// For each reference in references
	// 1. try to find that reference in PT
	// 2. If found, go to FT to get the page
	// 3. If not found, print "PAGE FAULT"
	// 3.1 Get the first inserted page in FT and remove it.
	// 3.2 bring the requested page from disk and insert that into FT.
	// 3.3. Update PT mapping (meaning, set presence bits)

	std::cout << "FIFO" << std::endl;

	// for (std::size_t i = 0; i < references.size(); i++)
	// {
	// 	std::cout << references.at(i) << std::endl;
	// }

	for (std::size_t i = 0; i < references.size(); i++)
	{
		if (pageTable.contains(references[i]))
		{
			std::cout << "Page found in PT!" << std::endl;

			std::size_t blockIndex = pageTable.find(references[i]);
			std::string address = pageTable.at(blockIndex).getAddressInFT(); /* How to define position? */
			Block block = frameTable.at(atoi(address.c_str()));
			std::cout << "Block " << block.getId() << "was gotten from FT" << std::endl;
		}
		else
		{
			std::cout << "Page fault!" << std::endl;
			pageFaults += 1;
			
			Block oldestBlockInFT = frameTable.popFront();
			// _os.moveFrameToDisk(oldestBlockInFT);
			// Block requestedBlock = _os.getFrameFromDisk(atoi(references[i].c_str()));
			// pageTable.pushFront(requestedBlock);
		}
	}

	// LRU
	// Each page has a counter.
	// Every clock interruption we update the counter -> page counter = page counter + presence bit.
	// For each reference in references
	// 1. try to find that reference in PT.
	// 2. if found, go to FT to get the page.
	// 3. if not found, print "PAGE FAULT".
	// 3.1 Get the page with the biggest counter in FT and remove it.
	// 3.2 bring the requested page from disk and insert that into FT.
	// 3.3 update PT mapping (meaning, set presence bits).
	// Should we apply aging????????

	// Optimal
	// For each page in PT
	// We lable the page according to how many refrerences it will have in the future.
	// For each reference in references
	// 1. try to find that reference in PT
	// 2. If found, go to FT to get the page
	// 3. If not found, print "PAGE FAULT"
	// 3.1 ?
}
